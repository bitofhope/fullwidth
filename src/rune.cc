
#include "rune.h"

Rune::Rune(uint32_t v) : d(v) {
}

uint32_t Rune::getCodepoint() const {
  return d;
}

std::string fromCodepointToByte(uint32_t b) {
  char c = b;
  std::string r(1, c);
  return r;
}

std::string to_string(const Rune &r) {
  using std::string;
  auto d = r.getCodepoint();
  std::string res;
  if (d < 0x80) { // 1 Byte
    res = fromCodepointToByte(d);
  } else if (d < 0x800) { // 2 Byte
    res = fromCodepointToByte(((d >> 6) & 0x1F) | 0xC0) +
        fromCodepointToByte((d & 0x3F) | 0x80);
  } else if (d < 0x10000) { // 3 Byte
    res = fromCodepointToByte(((d >> 12) & 0xF) | 0xE0) +
        fromCodepointToByte(((d >> 6) & 0x3F) | 0x80) + 
        fromCodepointToByte((d & 0x3F) | 0x80);
  } else if (d <= 0x10FFFF) { // 4 Byte
    res = fromCodepointToByte(((d >> 18) & 0x6) | 0xF0) +
        fromCodepointToByte(((d >> 12) & 0x3F) | 0x80) +
        fromCodepointToByte(((d >> 6) & 0x3F) | 0x80) +
        fromCodepointToByte((d & 0x3F) | 0x80);
  } else { // Invalid
    throw string("Value outside legal range: ") + std::to_string(d);
  }
  return res;
}

std::string to_string(const std::vector<Rune> &rv) {
  std::string base;
  for (size_t i = 0; i < rv.size(); ++i) {
    base += to_string(rv.at(i));
  }
  return base;
}

std::vector<std::vector<Rune>> splitWords(const std::vector<Rune> &input) {
  std::vector<std::vector<Rune>> result;
  size_t indexstart = 0;
  size_t indexend = 0;
  bool findingend = false;
  for (size_t i = 0; i < input.size(); ++i) {
    if (!findingend) {
      if (to_string(input.at(i)) != " ") {
        indexstart = i;
        findingend = true;
      }
    } else {
      if (to_string(input.at(i)) == " ") {
        indexend = i;
        std::vector<Rune> tempword;
        for (size_t i = indexstart; i < indexend; ++i) {
          tempword.push_back(input.at(i));
        }
        result.push_back(tempword);
        findingend = false;
      }
    }
  }
  // Last string
  if (findingend) {
    std::vector<Rune> tempword;
    for (size_t i = indexstart; i < input.size(); ++i) {
      tempword.push_back(input.at(i));
    }
    result.push_back(tempword);
  }
  return result;
}

std::vector<Rune> runesFromString(const std::string &s) {
  std::vector<Rune> res;
  uint32_t buffer = 0;
  uint8_t expectedbytes = 0;
  uint8_t bytes = 0;
  size_t index = 0;
  for (unsigned char a: s) {
    // If zero bytes and normal ASCII
    if (bytes == 0) {
      if (!(a & 0x80)) { // 1 byte
        res.push_back(Rune(a));
      } else if ((a & 0xE0) == 0xC0) { // 2 bytes
        bytes++;
        expectedbytes = 2;
        buffer = a & 0x1F;
        buffer <<= 6;
      } else if ((a & 0xF0) == 0xE0) { // 3 bytes
        bytes++;
        expectedbytes = 3; 
        buffer = a & 0x0F;
        buffer <<= 6;
      } else if ((a & 0xF8) == 0xF0) { // 4 bytes
        bytes++;
        expectedbytes = 4;
        buffer = a & 0x08;
        buffer <<= 6;
      } else {
        throw "Unexpected byte at " + std::to_string(index) + " " + std::to_string(a) + " of " + s;
      }
    } else if (bytes >= 1) {
      if ((a & 0xC0) == 0x80) {
        buffer |= a & 0x3F;
      } else {
        throw "Unexpected byte at " + std::to_string(index) + " " + std::to_string(a) + " of " + s;
      }
      bytes++;
      if (bytes == expectedbytes) {
        res.push_back(Rune(buffer));
        expectedbytes = bytes = 0;
      } else {
        buffer <<= 6;
      }
    }
    index++;
  }
  if ((expectedbytes | bytes) != 0) {
    throw std::string("Stream ended before rune was completed");
  }
  return res;
}
