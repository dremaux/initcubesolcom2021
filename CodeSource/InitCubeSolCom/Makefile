CXX		  := g++
CXX_FLAGS := -W -Wall -ansi -pedantic -std=c++11 $(shell pkg-config --cflags --libs libmongocxx) -v


BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lpthread -lboost_system
EXECUTABLE	:= InitCubeServeurCommande


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
