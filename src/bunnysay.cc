/*
* bunnysay
*
*  Created on: 2015-11-30
*      Author: brad
*
*   This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

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
  uint32_t ch;
  for (size_t i = 0; i < input->size(); ++i) {
    ch = input->at(i).getCodepoint();
    if (ch == ' ') {
      (*input)[i] = Rune(0x3000);
    } else if (ch >= '!' && ch <= '~') {
      (*input)[i] = Rune(0xFF01 + (ch - '!'));
    }
  }
}

void fullWidth(std::vector<std::vector<Rune>> *input) {
  for (auto &rv: *input) {
    fullWidth(&rv);
  }
}

void padTo(std::vector<std::vector<Rune>> *input, size_t width) {
  bool left = true;
  for (auto &rv: *input) {
    while(rv.size() < width) {
      if (left) {
        rv.insert(rv.begin(), Rune(0x20));
      } else {
        rv.insert(rv.end(), Rune(0x20));
      }
      left = !left;
    }
    left = true;
  }
}

std::vector<std::vector<Rune>> applyTrailerHeader(const 
    std::vector<std::vector<Rune>> &input, size_t width) {
  static const Rune vertbar(0xFF5C);
  static const Rune topbar(0xFFE3);
  static const Rune botbar(0xFF3F);
  static const std::vector<Rune> bun1 = runesFromString("(\\__/) ||");
  static const std::vector<Rune> bun2 = runesFromString("(•ㅅ•) ||");
  static const std::vector<Rune> bun3 = runesFromString("/ 　 づ");

  std::vector<std::vector<Rune>> res;
  std::vector<Rune> templine;
  templine.push_back(vertbar);
  for (size_t i = 0; i < width - 2; ++i) {
    templine.push_back(topbar);
  }
  templine.push_back(vertbar);
  res.push_back(templine);

  for (const auto &line: input) {
    templine = line;
    templine.insert(templine.begin(), vertbar);
    templine.insert(templine.end(), vertbar);
    res.push_back(templine);    
  }
  templine.clear();
  templine.push_back(vertbar);
  for (size_t i = 0; i < width - 2; ++i) {
    templine.push_back(botbar);
  }
  templine.push_back(vertbar);
  res.push_back(templine);

  res.push_back(bun1);
  res.push_back(bun2);
  res.push_back(bun3);

  return res;
}

std::string bunnyify(const std::string &text) {
  auto rv = runesFromString(text);
  auto lines = splitLines(rv, 10);
  padTo(&lines, 10);
  fullWidth(&lines);

  auto bun = applyTrailerHeader(lines, 12);
  std::string result;
  for (auto &bunline: bun) {
    result += to_string(bunline) + "\n";
  }
  return result;
}
