CFLAGS=-W -Wall -ansi -pedantic -std=c++11 -lpthread

all: InitCubeServeur



InitCubeServeur: main.o InitCubeServeur.o
		g++ -o InitCubeServeur InitCubeServeur.o main.o $(CFLAGS)
main.o: main.cpp
		g++ -o main.o -c main.cpp $(CFLAGS)
InitCubeServeur.o: InitCubeServeur.cpp Communication.cpp
		g++ -o InitCubeServeur.o -c InitCubeServeur.cpp  $(CFLAGS)
CubeEventServer.o: CubeEventServer.cpp Communication.cpp
		g++ -o CubeEventServer.o -c CubeEventServer.cpp  $(CFLAGS)
Communication.o: Communication.cpp 
		g++ -o Communication.o -c Communication.cpp $(CFLAGS)
clean: 
		rm -rf *.o
mrproper: clean
		rm -rf InitCubeServeur

