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
  bool left = true;
  std::vector<std::wstring> vs;
  vs = BunnySay::splitAtWidth(input + L"　", width);
  for (auto i = vs.begin(); i != vs.end(); ++i) {
    std::wstring curstring = (*i);
    // Pad left and right with spaces
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
std::vector<std::wstring> BunnySay::splitAtWidth(std::wstring wstring, int width) {
  std::vector<std::wstring> vwstrings;
  std::wstringstream ws(wstring);
  std::wstring bufferstr;
  std::wstring workstring; 
  bool toolongcarry = false;
  while(true) {
    while(true) {
      if (!toolongcarry) {
	std::getline(ws, bufferstr, L'　');

      }
      toolongcarry = false;
      
      if (!ws.good()) { break; }
      if (bufferstr.size() + workstring.size() + 1 > width) {
	if (workstring.size() == 0) {
	  // Add as much as we can
	  workstring = bufferstr.substr(0, width);
	  bufferstr = bufferstr.substr(width);
	}
	toolongcarry = true;
	break;
      }
      // CHANGE TO WIDE SPACE
      if (workstring.size() != 0) workstring += L'　';
      workstring += bufferstr; 
    }
    vwstrings.push_back(workstring);
    workstring = L"";
    if (!ws.good()) break; 
  }
  return vwstrings; 
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

