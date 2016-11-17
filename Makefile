
OBJ  = src/Bunnysay.cpp
CXXFLAGS = -Wall -std=c++11
DEBUG = -g
bunnysay : $(OBJ)
	$(CXX) $(DEBUG) $(CXXFLAGS) -o bunnysay $(OBJ)
