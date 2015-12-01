/*
* BunnySay.cpp
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

#include "BunnySay.h"

namespace bunnysay {

const std::wstring BunnySay::bunny =
L"|\uffe3\uffe3\uffe3\uffe3\uffe3\uffe3|\n";
const std::wstring BunnySay::bunny2 =
L"|\uff3f\uff3f\uff3f\uff3f\uff3f__|\n"
L"(\\__/) ||\n"
L"(•\u3145•) ||\n"
L"/ \u3000 \u3065"; // Spaces = 19

void BunnySay::writeBunnySay(std::wstring input) {
  std::wcout << bunny;
  int lastloc = 0;
  std::wstring curstring;
  while (input.size() > 0) {
    // Find a spot to split the string on
    int subsubstringindex = std::min(15, (int) input.size());
    int splitloc = input.substr(subsubstringindex).find(' ') + subsubstringindex;
    // If the string is small enough or we cannot find a space just use
    // the whole string
    if (splitloc == std::string::npos || input.size() < 15)
      curstring = input;
    else
      curstring = input.substr(0, splitloc);
    // Pad left and right with spaces
    while (curstring.size() < 19)
      curstring = L" " + curstring + L" ";
    // Add the pipes
    curstring = L"|" + curstring + L"|\n";
    std::wcout << curstring;
    // Break if we are out of charactors
    if (splitloc == input.size()) break;
    // Split the string to what we have left
    input = input.substr(splitloc + 1);
    lastloc = splitloc;
  }
  std::wcout << bunny2 << std::endl;

}

} /* namespace bunnysay */

int main(int argc, char** argv) {
  std::locale::global(std::locale("")); // System locale

  std::wstring inputstring = L"";
  std::wstring temp = L"";
  while(!std::wcin.eof()) {
    std::wcin >> temp;
    inputstring += L" " + temp;
  }
  bunnysay::BunnySay::writeBunnySay(inputstring);
  return 0;
}
