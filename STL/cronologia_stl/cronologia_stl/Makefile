SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
C11 = -std=c++11



all: $(BIN)/usevent
# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
all: $(BIN)/usevent $(BIN)/usechronology

$(OBJ)/historical_event.o : $(SRC)/historical_event.cpp
	$(CXX) $(CPPFLAGS)	-o $(OBJ)/historical_event.o $(SRC)/historical_event.cpp

$(OBJ)/chronology.o : $(SRC)/chronology.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/chronology.o $(SRC)/chronology.cpp

$(BIN)/usevent: $(OBJ)/usevent.o
	$(CXX) -o $(BIN)/usevent $(OBJ)/usevent.o

$(OBJ)/usevent.o: $(INC)/historical_event.h $(SRC)/usevent.cpp $(SRC)/historical_event.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usevent.cpp  -o $(OBJ)/usevent.o $(C11) 

$(BIN)/usechronology: $(OBJ)/usechronology.o
	$(CXX) -o $(BIN)/usechronology $(OBJ)/usechronology.o

$(OBJ)/usechronology.o : $(INC)/chronology.h $(SRC)/usechronology.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/usechronology.o $(SRC)/usechronology.cpp $(C11)



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
