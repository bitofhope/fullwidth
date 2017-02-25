
SRC  = src/bunnysay.cc
TESTSRC = src/rune.cc
CXXFLAGS = -Wall -Wextra -std=c++11
DEBUG = -g

ifndef $(prefix)
	prefix=/usr
endif

bunnysay: $(SRC) src/rune.cc
	$(CXX) -O2 $(CXXFLAGS) -o bunnysay $(SRC)

tests: $(TESTSRC) src/runetests.cc src/bunnysay.cc
	$(CXX) $(DEBUG) $(CXXFLAGS) -o tests $(TESTSRC) src/runetests.cc src/bunnysay.cc

.PHONY: install
install : bunnysay
	install -m 0755 bunnysay $(prefix)/bin
