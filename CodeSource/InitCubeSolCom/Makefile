BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lpthread
EXECUTABLE	:= InitCubeSolCOM

CXX		  := g++
CXX_FLAGS := -W -Wall -ansi -pedantic -std=c++11 $(shell pkg-config --cflags --libs libmongocxx) -v -I$(INCLUDE)


all: $(LIB)/ComInitCube.o $(LIB)/Commande.o $(LIB)/DispatcheurMeasure.o $(LIB)/DispatcheurMission.o $(LIB)/DispatcheurReponse.o $(LIB)/GestionCommandes.o $(LIB)/GestionConfiguration.o $(LIB)/Image.o $(LIB)/InitCube.o $(LIB)/Matrice.o $(LIB)/Measure.o $(LIB)/Serial.o $(LIB)/Serveur.o $(LIB)/ServeurReceptionTelemesure.o $(LIB)/ServeurTransmitionCommande.o $(LIB)/Simple.o $(LIB)/SimpleMission.o $(LIB)/Status.o
	@echo "Compilation programme principal"
	$(CXX) $(CXX_FLAGS) $(SRC)/main.cpp $(LIB)/ComInitCube.o $(LIB)/Commande.o $(LIB)/DispatcheurMeasure.o $(LIB)/DispatcheurMission.o $(LIB)/DispatcheurReponse.o $(LIB)/GestionCommandes.o $(LIB)/GestionConfiguration.o $(LIB)/Image.o $(LIB)/InitCube.o $(LIB)/Matrice.o $(LIB)/Measure.o $(LIB)/Serial.o $(LIB)/Serveur.o $(LIB)/ServeurReceptionTelemesure.o $(LIB)/ServeurTransmitionCommande.o $(LIB)/Simple.o $(LIB)/SimpleMission.o $(LIB)/Status.o -o $(BIN)/$(EXECUTABLE) $(LIBRARIES) -lboost_system
	@echo "Compilation terminée"

$(LIB)/ComInitCube.o : $(SRC)/ComInitCube.cpp $(INCLUDE)/ComInitCube.h
	@echo "Compilation classe ComInitCube"
	$(CXX) -c $(SRC)/ComInitCube.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/Commande.o : $(SRC)/Commande.cpp $(INCLUDE)/Commande.hpp
	@echo "Compilation classe Commande"
	$(CXX) -c $(SRC)/Commande.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/DispatcheurMeasure.o : $(SRC)/DispatcheurMeasure.cpp $(INCLUDE)/DispatcheurMeasure.hpp
	@echo "Compilation classe DispatcheurMeasure"
	$(CXX) -c $(SRC)/DispatcheurMeasure.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/DispatcheurMission.o : $(SRC)/DispatcheurMission.cpp $(INCLUDE)/DispatcheurMission.hpp
	@echo "Compilation classe DispatcheurMission"
	$(CXX) -c $(SRC)/DispatcheurMission.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/DispatcheurReponse.o : $(SRC)/DispatcheurReponse.cpp $(INCLUDE)/DispatcheurReponse.hpp
	@echo "Compilation classe DispatcheurReponse"
	$(CXX) -c $(SRC)/DispatcheurReponse.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/GestionCommandes.o : $(SRC)/GestionCommandes.cpp $(INCLUDE)/GestionCommandes.h
	@echo "Compilation classe GestionCommandes"
	$(CXX) -c $(SRC)/GestionCommandes.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/GestionConfiguration.o : $(SRC)/GestionConfiguration.cpp $(INCLUDE)/GestionConfiguration.h
	@echo "Compilation classe GestionConfiguration"
	$(CXX) -c $(SRC)/GestionConfiguration.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/Image.o : $(SRC)/Image.cpp $(INCLUDE)/Image.hpp
	@echo "Compilation classe Image"
	$(CXX) -c $(SRC)/Image.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/InitCube.o : $(SRC)/InitCube.cpp $(INCLUDE)/InitCube.hpp
	@echo "Compilation classe InitCube"
	$(CXX) -c $(SRC)/InitCube.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/Matrice.o : $(SRC)/Matrice.cpp $(INCLUDE)/Matrice.hpp
	@echo "Compilation classe Matrice"
	$(CXX) -c $(SRC)/Matrice.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/Measure.o : $(SRC)/Measure.cpp $(INCLUDE)/Measure.hpp
	@echo "Compilation classe Measure"
	$(CXX) -c $(SRC)/Measure.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/Serial.o : $(SRC)/Serial.cpp $(INCLUDE)/Serial.h
	@echo "Compilation classe Serial"
	$(CXX) -c $(SRC)/Serial.cpp $(CXX_FLAGS) $(LIBRARIES) -lboost_system -o $@

$(LIB)/Serveur.o : $(SRC)/Serveur.cpp $(INCLUDE)/Serveur.hpp
	@echo "Compilation classe Serveur"
	$(CXX) -c $(SRC)/Serveur.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/ServeurReceptionTelemesure.o : $(SRC)/ServeurReceptionTelemesure.cpp $(INCLUDE)/ServeurReceptionTelemesure.hpp
	@echo "Compilation classe ServeurReceptionTelemesure"
	$(CXX) -c $(SRC)/ServeurReceptionTelemesure.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/ServeurTransmitionCommande.o : $(SRC)/ServeurTransmitionCommande.cpp $(INCLUDE)/ServeurTransmitionCommande.hpp
	@echo "Compilation classe ServeurTransmitionCommande"
	$(CXX) -c $(SRC)/ServeurTransmitionCommande.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/Simple.o : $(SRC)/Simple.cpp $(INCLUDE)/Simple.hpp
	@echo "Compilation classe Simple"
	$(CXX) -c $(SRC)/Simple.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/SimpleMission.o : $(SRC)/SimpleMission.cpp $(INCLUDE)/SimpleMission.hpp
	@echo "Compilation classe SimpleMission"
	$(CXX) -c $(SRC)/SimpleMission.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

$(LIB)/Status.o : $(SRC)/Status.cpp $(INCLUDE)/Status.hpp
	@echo "Compilation classe Status"
	$(CXX) -c $(SRC)/Status.cpp $(CXX_FLAGS) $(LIBRARIES) -o $@

