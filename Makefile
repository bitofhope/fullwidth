# Setup variables for what files are going to be built
# TEST and BUN are seperate because runbunnysay.o and runetests.o both
# Contain a main method and therefore cannot link together
OBJECTS = bunnysay.o rune.o 
OBJECTS_BUN = $(OBJECTS) runbunnysay.o
OBJECTS_TEST = $(OBJECTS) runetests.o


CXXFLAGS = -Wall -Wextra -std=c++11
DEBUG = -g

# The install rule below uses this variable to determine where to install
ifndef $(prefix)
	prefix=/usr
endif

# Main target, requires objects to be built
bunnysay: $(OBJECTS_BUN)
	$(CXX) -O2 $(CXXFLAGS) -o bunnysay $(OBJECTS_BUN)

# Builds all the object files we need
# This is an implicit rule and pattern rule, this one tells us how to make .o
# file from src/%.cc files. Thereby, when the bunnysay target needs the
# prequisites from $(OBJECTS_BUN) it will use this rule to make them
#
# The $@ refers to the target and $< to the first prerequisite
# The -c requests an object file be created
%.o : src/%.cc
	$(CXX) -O2 $(CXXFLAGS) -c -o $@ $<

# Makes some tests and runs the test
tests: $(OBJECTS_TEST)
	$(CXX) $(DEBUG) $(CXXFLAGS) -o tests $(OBJECTS_TEST)
	./tests

# Phony prevents make from thinking "install" is a file
.PHONY: install
install : bunnysay
	install -m 0755 bunnysay $(prefix)/bin

.PHONY: clean
clean : 
	rm *.o tests bunnysay

