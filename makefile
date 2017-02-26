
SRC  = src/bunnysay.cc src/rune.cc
CXXFLAGS = -Wall -Wextra -std=c++11
DEBUG = -g

ifndef $(prefix)
	prefix=/usr
endif

bunnysay: $(SRC) src/runbunnysay.cc
	$(CXX) -O2 $(CXXFLAGS) -o bunnysay $(SRC) src/runbunnysay.cc

tests: $(SRC) src/runetests.cc 
	$(CXX) $(DEBUG) $(CXXFLAGS) -o tests $(SRC) src/runetests.cc
	./tests

.PHONY: install
install : bunnysay
	install -m 0755 bunnysay $(prefix)/bin
