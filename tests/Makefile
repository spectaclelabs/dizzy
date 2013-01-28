# Source files
SRC =  $(wildcard *.cc)
EXE = $(SRC:.cc=)

GMOCK_DIR = ../../gmock-1.6.0

# Compiler options
CXX = g++
CXXFLAGS = -Werror -Wall -g -std=c++11 -Wno-missing-braces
INC = -I ../ -I $(GMOCK_DIR)/include -I $(GMOCK_DIR)/gtest/include
LIB = -L $(GMOCK_DIR) -l gmock -l pthread

all: $(EXE)

.cc:
	$(CXX) $(INC) $(CXXFLAGS) $< -o $@ $(LIB)

clean:
	rm -f $(EXE)

