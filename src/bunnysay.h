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
#pragma once
#include <vector>
#include "rune.h"

// Splits the input into lines of length col, it does this by attempting
// to cut the string into chunks that will fit on a line without wrapping.
// If the line will not fit on any line without wrapping it will be pushed
// to the next line
std::vector<std::vector<Rune>> splitLines(const std::vector<Rune> &input,
    size_t cols);

// helper function that runes fullWidth over multiple lines
void fullWidth(std::vector<std::vector<Rune>> *input);

// fullWidth converts input to unicode characters in the Fullwidth
// section 0xFF01+
void fullWidth(std::vector<Rune> *input);

// padTo pads the text fairly on both sides until it reaches width
// it does so by padding with 0x20 (' ')
void padTo(std::vector<std::vector<Rune>> *input, size_t width);

// applyTrailerHeader takes in Runes in lines and adds the sides, top and
// bottom of the bunny sign. It assumes fullWidth has been applied already
// and will create the top and bottom based on the size given by width
std::vector<std::vector<Rune>> applyTrailerHeader(const 
    std::vector<std::vector<Rune>> &input, size_t width);

// bunnyify takes in a UTF-8 string and returns a UTF-8 encoded string of
// the input string with the bunny adornments as seen on @bunnysay_ebooks
std::string bunnyify(const std::string &text);
