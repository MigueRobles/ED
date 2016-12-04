SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c
C11 = -std=c++11



all: $(BIN)/usoevento
# ************ Generación de documentación ******************
#documentacion:
#	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/usoevento: $(OBJ)/usoevento.o
	$(CXX) -o $(BIN)/usoevento $(OBJ)/usoevento.o

$(OBJ)/usoevento.o: $(INC)/historical_event.h $(SRC)/usoevento.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usoevento.cpp  -o $(OBJ)/usoevento.o $(C11)



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
