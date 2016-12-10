SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -std=c++11 -c



# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************

all: $(BIN)/usechronology $(BIN)/usevent $(BIN)/union_cronologia $(BIN)/filtradoIntervalo

$(BIN)/usevent: $(OBJ)/usevent.o $(LIB)/libchronology.a
	$(CXX) -o $(BIN)/usevent $(OBJ)/usevent.o -L$(LIB) -lchronology

$(OBJ)/usevent.o: $(INC)/historical_event.h $(SRC)/usevent.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usevent.cpp  -o $(OBJ)/usevent.o

$(BIN)/usechronology: $(OBJ)/usechronology.o $(LIB)/libchronology.a
	$(CXX) -o $(BIN)/usechronology $(OBJ)/usechronology.o -L$(LIB) -lchronology

$(OBJ)/usechronology.o : $(INC)/chronology.h $(SRC)/usechronology.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usechronology.o $(SRC)/usechronology.cpp

$(LIB)/libchronology.a: $(OBJ)/historical_event.o $(OBJ)/chronology.o
	ar rvs $(LIB)/libchronology.a $(OBJ)/historical_event.o $(OBJ)/chronology.o

$(OBJ)/historical_event.o : $(SRC)/historical_event.cpp $(INC)/historical_event.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/historical_event.o $(SRC)/historical_event.cpp

$(OBJ)/chronology.o : $(SRC)/chronology.cpp $(INC)/chronology.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/chronology.o $(SRC)/chronology.cpp

$(BIN)/union_cronologia: $(OBJ)/union_cronologia.o $(LIB)/libchronology.a
		$(CXX) -o $(BIN)/union_cronologia $(OBJ)/union_cronologia.o -L$(LIB) -lchronology

$(OBJ)/union_cronologia.o : $(INC)/chronology.h $(SRC)/union_cronologia.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/union_cronologia.o $(SRC)/union_cronologia.cpp

$(BIN)/filtradoIntervalo: $(OBJ)/filtradoIntervalo.o $(LIB)/libchronology.a
		$(CXX) -o $(BIN)/filtradoIntervalo $(OBJ)/filtradoIntervalo.o -L$(LIB) -lchronology

$(OBJ)/filtradoIntervalo.o : $(INC)/chronology.h $(SRC)/filtradoIntervalo.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/filtradoIntervalo.o $(SRC)/filtradoIntervalo.cpp

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ $(INC)/*.gch ./*~ $(LIB)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
