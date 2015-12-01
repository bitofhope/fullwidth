/*
* BunnySay.h
*
*  Created on: 2015-11-30
*      Author: brad
*/


#ifndef BUNNYSAY_H_
#define BUNNYSAY_H_

#include <string>
#include <locale>
#include <iostream>
#include <algorithm> // min

namespace bunnysay {

class BunnySay {
private:
  static const std::wstring bunny;
  static const std::wstring bunny2;
public:
  static void writeBunnySay(std::wstring input);

};

} /* namespace bunnysay */

#endif /* BUNNYSAY_H_ */
