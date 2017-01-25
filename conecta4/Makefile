SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
CXX = g++
AR = ar rvs
AR_MACOSX = libtool -static -o
CPPFLAGS = -Wall -g  -I$(INC) -std=c++11 -c



all: $(BIN)/conecta4 $(BIN)/arboltablero_test
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/arboltablero_test: $(OBJ)/arboltablero_test.o $(LIB)/libtablero.a $(LIB)/libjugador_automatico.a
	$(CXX) -o $(BIN)/arboltablero_test $(OBJ)/arboltablero_test.o -I$(INC) -L$(LIB) -ltablero -ljugador_automatico

$(BIN)/conecta4: $(OBJ)/conecta4.o $(LIB)/libtablero.a $(LIB)/libmando.a $(LIB)/libjugador_automatico.a
	$(CXX) -o $(BIN)/conecta4 $(OBJ)/conecta4.o -I$(INC) -L$(LIB) -ltablero -lmando -ljugador_automatico

$(LIB)/libjugador_automatico.a: $(OBJ)/jugador_automatico.o
	$(AR) $(LIB)/libjugador_automatico.a $(OBJ)/jugador_automatico.o

$(LIB)/libtablero.a: $(OBJ)/tablero.o
	$(AR) $(LIB)/libtablero.a $(OBJ)/tablero.o

$(LIB)/libmando.a: $(OBJ)/mando.o
	$(AR)  $(LIB)/libmando.a $(OBJ)/mando.o

$(OBJ)/jugador_automatico.o: $(SRC)/jugador_automatico.cpp $(INC)/jugador_automatico.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/jugador_automatico.o $(SRC)/jugador_automatico.cpp -I$(INC)

$(OBJ)/tablero.o: $(SRC)/tablero.cpp $(INC)/tablero.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/tablero.o $(SRC)/tablero.cpp -I$(INC)

$(OBJ)/mando.o: $(SRC)/mando.cpp $(INC)/mando.h $(INC)/tablero.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/mando.o $(SRC)/mando.cpp -I$(INC)

$(OBJ)/arboltablero_test.o: $(SRC)/arboltablero_test.cpp $(INC)/tablero.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/arboltablero_test.o $(SRC)/arboltablero_test.cpp -I$(INC)

$(OBJ)/conecta4.o: $(SRC)/conecta4.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/conecta4.o $(SRC)/conecta4.cpp -I$(INC)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
