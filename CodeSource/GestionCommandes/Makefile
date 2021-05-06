CXX       := c++
CXX_FLAGS := --std=c++11 $(shell pkg-config --cflags --libs libmongocxx)
 
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
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*