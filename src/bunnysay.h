# pragma once
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
