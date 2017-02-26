#include "rune.h"
#include "bunnysay.h"
#include <cassert>
#include <iostream>
#include <cinttypes>

bool testSingle(uint32_t correct, std::string s) {
  uint32_t cp = runesFromString(s).at(0).getCodepoint();
  if (cp != correct) {
    return false;
  }
  return true;
}

bool testMulti(uint32_t *correct, size_t num, std::string s) {
  auto cp = runesFromString(s);
  for (size_t i = 0; i < num; ++i) {
    if (cp.at(i).getCodepoint() != correct[i]) {
      return false;
    }
  }
  return true;
}

void testStrings() {
  uint32_t t[] = {0x20, 0x20AC};
  try {
    assert(testSingle(0x20, " "));
    assert(testSingle(0x20AC, "€"));
    assert(testSingle(0x00A2, "¢"));
    assert(testSingle(0x10348, "𐍈"));
    assert(testSingle(0x2192, "→"));
    assert(!testSingle(0x2193, "→"));
    assert(testMulti(t, 2, " €"));

    assert(!testMulti(t, 2, "  €"));
  } catch (char const* s) {
    std::cout << s << std::endl;
  }
  try {
    testSingle(0x20, "\xFF");
    assert(false); // Should never get here
  } catch (char const* s) {
    // Meant to fail
  } catch (std::string s) {
  }
  try {
    testSingle(0x20, "\xBF");
    assert(false); // Should never get here
  } catch (char const* s) {
  } catch (std::string s) {
  }
  try {
    testSingle(0x20, "\x0F\xBF");
    assert(false); // Should never get here
  } catch (char const* s) {
  } catch (std::string s) {
  }
  try {
    testSingle(0x20, "\x0F\xBF");
    assert(false); // Should never get here
  } catch (char const* s) {
  } catch (std::string s) {
  }
}

bool testPrintOne(std::string exp, Rune r) {
  std::string out = to_string(r);
  //std::cout << exp << " == " << out << std::endl;
  return out == exp;
}

void testPrints() {
  assert(testPrintOne("\x20", Rune(0x20)));
  assert(testPrintOne("\xC2\xA2", Rune(0xA2)));
  assert(testPrintOne("\xE2\x82\xAC", Rune(0x20AC)));
  assert(testPrintOne("\xF0\x90\x8D\x88", Rune(0x10348)));
}

void testSplits() {
  auto cp = runesFromString("jq w3 24b →");
//  for (auto &a: cp) {
//    std::cout << to_string(a) << std::endl;
//  }
  auto split = splitWords(cp);
//  for (auto &a: split) {
//    std::cout << to_string(a) << std::endl;
//  }
  assert(split.size() == 4);
  auto rv = runesFromString("jqw324b → ayy lmao, what hey! who");
  for (size_t width = 2; width < 12; width++) {
    //std::cout << std::endl << width << std::endl;
    auto lines = splitLines(rv, width);
    for (const auto &line: lines) {
      assert(line.size() <= width);
      //std::cout << to_string(line) << std::endl;
    }
  }

  rv = runesFromString("abcdefghijklmnopqrstuvwxyz!~");
  fullWidth(&rv);
  //std::cout << to_string(rv) << std::endl;
  assert (to_string(rv) == 
    "ａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ！～");
  rv = runesFromString("abcdef asdffghj 12 23 34");
  auto lines = splitLines(rv, 6);
  padTo(&lines, 8);
//  for (auto &line: lines) {
//    std::cout << to_string(line) << std::endl;
//  }
}

void testBunnify() {
  auto rv = runesFromString("We are testing the functionality of all functions");
  auto lines = splitLines(rv, 8);
  padTo(&lines, 8);
  fullWidth(&lines);

  auto bun = applyTrailerHeader(lines, 10);
//  for (auto &bunline: bun) {
//    std::cout << to_string(bunline) << std::endl;
//  }

  //std::cout << bunnyify("Testing one last time") << std::endl;
}

int main() {
  testBunnify();
  testSplits();
  testPrints();
  testStrings();
  std::cout << bunnyify("Looks good boss!") << std::endl;
  return 0;
}
