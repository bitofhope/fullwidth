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
  std::wstring curstring;
  while (input.size() != 0) {
    // If the string is small enough or we cannot find a space just use
    // the whole string
    if (input.size() < 18)
      curstring = input;
    else {
      std::size_t pos = input.rfind(' ', 18);
      if (pos == std::string::npos) pos = 18;
      curstring = input.substr(0, pos);
    }
    input = input.substr(curstring.size());

    // Pad left and right with spaces
    while (curstring.size() < 19)
      curstring = L" " + curstring + L" ";
      
    // Add the pipes
    curstring = L"|" + curstring + L"|\n";
    std::wcout << curstring;
  }
  std::wcout << bunny2 << std::endl;
}

} /* namespace bunnysay */

int main(int argc, char** argv) {
  std::locale::global(std::locale("")); // System locale

  std::wstring inputstring = L"";
  std::wstring temp = L"";
  std::wcin >> inputstring;
  while(true) {
    std::wcin >> temp;
    if (std::wcin.eof()) break;
    inputstring += L" " + temp;
  }
  bunnysay::BunnySay::writeBunnySay(inputstring);
  return 0;
}
