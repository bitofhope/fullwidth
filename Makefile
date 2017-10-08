# Setup variables for what files are going to be built
# TEST and BUN are seperate because runfullwidth.o and runetests.o both
# Contain a main method and therefore cannot link together
OBJECTS = fullwidth.o rune.o 
OBJECTS_BUN = $(OBJECTS) runfullwidth.o

CXXFLAGS = -Wall -Wextra -std=c++11
DEBUG = -g

# The install rule below uses this variable to determine where to install
ifndef $(prefix)
	prefix=/usr/local
endif

# Main target, requires objects to be built
fullwidth: $(OBJECTS_BUN)
	$(CXX) -O2 $(CXXFLAGS) -o fullwidth $(OBJECTS_BUN)

# Man page, requires pandoc

doc/fullwidth.1 : doc/fullwidth.md
	pandoc $< -s -t man -o $@

# Builds all the object files we need
# This is an implicit rule and pattern rule, this one tells us how to make .o
# file from src/%.cc files. Thereby, when the fullwidth target needs the
# prequisites from $(OBJECTS_BUN) it will use this rule to make them
#
# The $@ refers to the target and $< to the first prerequisite
# The -c requests an object file be created
%.o : src/%.cc
	$(CXX) -O2 $(CXXFLAGS) -c -o $@ $<


# Phony prevents make from thinking "install" is a file
.PHONY: install
install : fullwidth
	install -m 0755 fullwidth $(prefix)/bin
	install -m 0644 doc/fullwidth.1 $(prefix)/man/man1

.PHONY: clean
clean : 
	rm *.o fullwidth

