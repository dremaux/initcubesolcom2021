CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb 

BIN		:= bin
SRC		:= src
INCLUDE	:= defs
LIB		:= lib

LIBRARIES	:= -lpthread
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
