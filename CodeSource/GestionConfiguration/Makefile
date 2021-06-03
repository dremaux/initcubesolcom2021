CXX       := g++
CXX_FLAGS := --std=c++11 $(shell pkg-config --cflags --libs libmongocxx) -v
 
BIN     := bin
SRC     := src
INCLUDE := include
LIB     := lib
 
LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX)  $^ -o $@ $(LIBRARIES) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB)

clean:
	-rm $(BIN)/*