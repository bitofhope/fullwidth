/*
* BunnySay.h
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


#ifndef BUNNYSAY_H_
#define BUNNYSAY_H_

#include <string> // wstring
#include <locale> // locale for wstring
#include <iostream> // io
#include <algorithm> // min
#include <stack>
#include <vector>
#include <sstream>
#include <codecvt>
namespace bunnysay {

class BunnySay {
private:
  static const std::wstring bunny;
  static const std::wstring bunny2;
public:
  static std::string ws2s(const std::wstring& wstr);
  static std::wstring replaceString(std::wstring input);
  static void writeBunnySay(std::wstring input);
  static std::vector<std::wstring> splitAtWidth(std::wstring wstring, int width);
};

} /* namespace bunnysay */

#endif /* BUNNYSAY_H_ */