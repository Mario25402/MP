################################################################################
# Macros

SRC = ./src
BIN = ./bin
OBJ = ./obj
LIB = ./lib
INCLUDE = ./include

################################################################################
# Ejecutable

$(BIN)/palabras : $(OBJ)/palabras.o $(OBJ)/main.o $(LIB)/libpalabras.a
	@echo Creando ejecutable
	g++ -o $(BIN)/palabras $(OBJ)/palabras.o  $(OBJ)/main.o -L $(LIB) -lpalabras
	@echo

# Ficheros Objeto

$(OBJ)/palabras.o : $(SRC)/palabras.cpp $(INCLUDE)/palabras.h
	@echo Creando ficheros objeto
	g++ -c $(SRC)/palabras.cpp -o $(OBJ)/palabras.o -I $(INCLUDE)
	@echo	

$(OBJ)/main.o : $(SRC)/main.cpp $(INCLUDE)
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I $(INCLUDE)
	@echo

# Librerias

$(LIB)/libpalabras.a : $(OBJ)/palabras.o
	@echo Creando librerias
	ar rvs $(LIB)/libpalabras.a $(OBJ)/palabras.o
	@echo

################################################################################
# Targets

all:  $(BIN)/palabras

clean:
	@echo Borrando ficheros objeto
	rm $(OBJ)/*.o

c-all: clean
	@echo
	@echo Borrando ejecutables y librerias
	rm $(BIN)/*
	rm $(LIB)/*.a
