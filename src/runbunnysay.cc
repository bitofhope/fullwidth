#include "bunnysay.h"
#include <iostream>
#include <string>

void usage(char *prog) {
  std::cout << "Usage: " + std::string(prog) + " [--] [WORDS]\n" +
    "\t--\tSpecifies that text will be read from standard in\n" +
    "\t[WORDS]\t Specifies the words that will be used, obviously, the first" +
    " cannot be \"--\"" << std::endl;
}

int main(int argc, char **argv) {
  std::string buff;
  if (argc >= 2 && std::string(argv[1]) == "--") {
    while(std::getline(std::cin, buff, '\n')) {}
  } else if (argc >= 2) {
    for (int i = 1; i < argc; i++) {
      if (i != 1) {
        buff += " ";
      }
      buff += std::string(argv[i]);
    }
  } else {
    usage(*argv);
    return 0;
  }
  std::cout << bunnyify(buff);
}
