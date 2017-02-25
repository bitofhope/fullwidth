
#include <vector>
#include "rune.h"
#include "bunnysay.h"


std::vector<std::vector<Rune>> splitLines(const std::vector<Rune> &input,
    size_t cols) {
  std::vector<std::vector<Rune>> result;
  auto words = splitWords(input);
  std::vector<Rune> curline;
  for (auto &word: words) {
    if (word.size() > cols) { // Long words require multiple lines anyway
      std::vector<Rune> lineleft = word;
      if (curline.size() != 0) {
        while (curline.size() < cols) {
          curline.push_back(lineleft.at(0));
          lineleft.erase(lineleft.begin());
        }
        result.push_back(curline);
        curline.clear();
      }
      while(lineleft.size() > cols) {
        std::vector<Rune> longline;
        for (size_t i = 0; i < cols; i++) {
          longline.push_back(lineleft.at(0));
          lineleft.erase(lineleft.begin());
        }
        result.push_back(longline);
      }
      // Rest of the word
      for (auto r: lineleft) {
        curline.push_back(r);
      }
      if (curline.size() != cols) {
        curline.push_back(Rune(0x20));
      }

    } else if (word.size() > cols - curline.size()) { // Make new row
      result.push_back(curline);
      curline.clear();
      for (auto r: word) {
        curline.push_back(r);
      }
      if (curline.size() != cols) {
        curline.push_back(Rune(0x20));
      }
    } else { // Space for word on this line
      for (auto r: word) {
        curline.push_back(r);
      }
      if (curline.size() != cols) {
        curline.push_back(Rune(0x20));
      }
    }
  }
  if (curline.size() != 0) {
    result.push_back(curline);
  }
  return result;
}

void fullWidth(std::vector<Rune> *input) {
  // TODO add to the codepoints here
}

void fullWidth(std::vector<std::vector<Rune>> *input) {
  for (auto &rv: *input) {
    fullWidth(&rv);
  }
}

std::vector<std::vector<Rune>> applyTrailerHeader(const 
    std::vector<std::vector<Rune>> &input) {

}

std::string bunnyify(const std::string &text) {
  // Use 10 as width
  return "";
}
