/*
* BunnySay.cpp
*
*  Created on: 2015-11-30
*      Author: brad
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
    int subsubstringindex = std::min(15, (int) input.size());
    int splitloc = input.substr(subsubstringindex).find(' ') + subsubstringindex;

    if (splitloc == std::string::npos || input.size() < 15)
      curstring = input;
    else
      curstring = input.substr(0, splitloc);

    while (curstring.size() < 19)
      curstring = L" " + curstring + L" ";

    curstring = L"|" + curstring + L"|\n";
    std::wcout << curstring;
    if (splitloc == input.size()) break;
    input = input.substr(splitloc + 1);
    lastloc = splitloc;
  }
  std::wcout << bunny2 << std::endl;

}

} /* namespace bunnysay */

int main(int argc, char** argv) {
  std::locale::global(std::locale(""));
  std::wstring inputstring = L"";
  std::wstring temp = L"";
  while(!std::wcin.eof()) {
    std::wcin >> temp;
    inputstring += L" " + temp;
  }
  bunnysay::BunnySay::writeBunnySay(inputstring);
  return 0;
}
