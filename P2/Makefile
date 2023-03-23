################################################################################
# Macros

SRC = ./src
BIN = ./bin
OBJ = ./obj
LIB = ./lib
INCLUDE = ./include

################################################################################
# Ejecutable

$(BIN)/palabras : $(OBJ)/palabras.o $(OBJ)/justifica.o $(LIB)/libpalabras.a
	@echo Creando ejecutable
	g++ -o $(BIN)/palabras $(OBJ)/palabras.o  $(OBJ)/justifica.o -L $(LIB) -lpalabras
	@echo

# Ficheros Objeto

$(OBJ)/palabras.o : $(SRC)/palabras.cpp $(INCLUDE)/palabras.h
	@echo Creando ficheros objeto
	g++ -c $(SRC)/palabras.cpp -o $(OBJ)/palabras.o -I $(INCLUDE)
	@echo	

$(OBJ)/justifica.o : $(SRC)/justifica.cpp $(INCLUDE)
	g++ -c $(SRC)/justifica.cpp -o $(OBJ)/justifica.o -I $(INCLUDE)
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
