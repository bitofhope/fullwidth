/*
* fullWidth
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
