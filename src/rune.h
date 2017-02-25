#pragma once

#include <cstdint>
#include <string>
#include <vector>

class Rune {
 private:
  uint32_t d;
 public:
  Rune(uint32_t v);
  uint32_t getCodepoint() const;
};


std::vector<Rune> runesFromString(const std::string &s);
std::vector<std::vector<Rune>> splitWords(const std::vector<Rune> &input);

std::string to_string(const Rune &r);
std::string to_string(const std::vector<Rune> &rv);
