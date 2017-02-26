#pragma once

#include <cstdint>
#include <string>
#include <vector>

// Rune is a class the represents a unicode codepoint and can be encoded
// and decoded from UTF-8 streams
class Rune {
 private:
  uint32_t d;
 public:
  Rune(uint32_t v);
  uint32_t getCodepoint() const;
};

// Looks for UTF-8 strings in s and will return runes that represent the input
// if an error occurs then it will throw a std::string as an exception
std::vector<Rune> runesFromString(const std::string &s);

// Splits the Rune vector into words by splitting on 0x20 (' ')
std::vector<std::vector<Rune>> splitWords(const std::vector<Rune> &input);

// Converts a single rune to a string of up to 4 bytes with UTF-8 encoding
std::string to_string(const Rune &r);
// Converts a whole vector into a UTF-8 string of upto 4 bytes per input Rune
std::string to_string(const std::vector<Rune> &rv);
