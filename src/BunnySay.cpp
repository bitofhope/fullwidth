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

const int width = 10;
const std::wstring BunnySay::bunny =
L"｜￣￣￣￣￣￣￣￣￣￣｜\n";
const std::wstring BunnySay::bunny2 =
L"｜＿＿＿＿＿＿＿＿＿＿｜\n"
L"(\\__/) ||\n"
L"(•ㅅ•) ||\n"
L"/ 　 づ";

void BunnySay::writeBunnySay(std::wstring input) {
  input = replaceString(input);
  std::wcout << bunny;
  std::wstring curstring;
  while (input.size() != 0) {
    // If the string is small enough or we cannot find a space just use
    // the whole string
    if (input.size() < width) {
      curstring = input;
    } else {
      std::size_t pos = input.rfind(L'　', width);
      if (pos == std::string::npos) {
        pos = width;
      }
      curstring = input.substr(0, pos);
    }
    input = input.substr(curstring.size());

    // Pad left and right with spaces
    bool left = true;
    while (curstring.size() < width) {
      if (left) {
        curstring = L"　" + curstring;
      } else {
        curstring = curstring + L"　";
      }
      left = !left;
    }

    // Add the pipes
    curstring = L"｜" + curstring + L"｜\n";
    std::wcout << curstring;
  }
  std::wcout << bunny2 << std::endl;
}

std::wstring BunnySay::replaceString(std::wstring input) {
  wchar_t zerow = L'０';
  std::stack<size_t> cstack;

  for(size_t i = 0; i < input.size(); ++i) {
    if(input[i] >= L'!' && input[i] <= L'z') {
      cstack.push(i);
    }
  }

  while(!cstack.empty()) {
    size_t pos = cstack.top();
    cstack.pop();
    //std::cout << pos << std::endl;

    wchar_t charmod = wchar_t(zerow + (input[pos] - '0'));// - 'a';
    if (input[pos] == ' ')
      charmod = 0x3000;
    input.erase(pos, 1);
    input.insert(pos, std::wstring(1, charmod));
  }

  return input;
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
    inputstring += L"　" + temp;
  }
  bunnysay::BunnySay::writeBunnySay(inputstring);
  return 0;
}
