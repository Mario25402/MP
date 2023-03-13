################################################################################
# Macros

SRC = ./src
BIN = ./bin
OBJ = ./obj
LIB = ./lib
INCLUDE = ./include

################################################################################
# Ejecutable

$(BIN)/tiempo : $(OBJ)/tiempo.o $(OBJ)/main.o $(OBJ)/registro.o \
				$(LIB)/libtiempo.a  $(LIB)/libregistro.a
	@echo Creando ejecutable
	g++ -o $(BIN)/tiempo $(OBJ)/tiempo.o  $(OBJ)/main.o \
	    -L $(LIB) -ltiempo -lregistro

# Ficheros Objeto

$(OBJ)/tiempo.o : $(SRC)/tiempo.cpp $(INCLUDE)/tiempo.h
	@echo Creando ficheros objeto
	g++ -c $(SRC)/tiempo.cpp -o $(OBJ)/tiempo.o -I $(INCLUDE)
	@echo

$(OBJ)/registro.o : $(SRC)/registro.cpp $(INCLUDE)/tiempo.h $(INCLUDE)/registro.h
	g++ -c $(SRC)/registro.cpp -o $(OBJ)/registro.o -I $(INCLUDE)
	@echo	

$(OBJ)/main.o : $(SRC)/main.cpp $(INCLUDE)
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I $(INCLUDE)
	@echo

# Librerias

$(LIB)/libtiempo.a : $(OBJ)/tiempo.o
	@echo Creando librerias
	ar rvs $(LIB)/libtiempo.a $(OBJ)/tiempo.o
	@echo

$(LIB)/libregistro.a : $(OBJ)/registro.o
	ar rvs $(LIB)/libregistro.a $(OBJ)/registro.o
	@echo

################################################################################
# Targets

all:  $(BIN)/tiempo

clean:
	@echo Borrando ficheros objeto
	rm $(OBJ)/*.o

c-all: clean
	@echo
	@echo Borrando ejecutables y librerias
	rm $(BIN)/*
	rm $(LIB)/*.a
