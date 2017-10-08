/*
* fullwidth
*
*  Created on: 2017-10-09
*      Original Program: bunnysay
*      Original Author: brad
*      Modified by bitofhope <bitofhope@kapsi.fi>
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
#include "fullwidth.h"


void runeToFW(std::vector<Rune> *input) {
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

void runeToFW(std::vector<std::vector<Rune>> *input) {
  for (auto &rv: *input) {
    runeToFW(&rv);
  }
}


std::string fullWidth(const std::string &text) {
  auto runes = runesFromString(text);
  runeToFW(&runes);

  return to_string(runes);
}

