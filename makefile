
OBJ  = src/bunnysay.cc
CXXFLAGS = -Wall -Wextra -std=c++11
DEBUG = -g

ifndef $(prefix)
	prefix=/usr
endif

bunnysay : $(OBJ)
	$(CXX) -O2 $(CXXFLAGS) -o bunnysay $(OBJ)


.PHONY: install
install : bunnysay
	install -m 0755 bunnysay $(prefix)/bin
