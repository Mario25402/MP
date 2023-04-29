/*
 
 * FICHERO: lienzo.h
 * Autor: David A. Pelta
 * para guión de prácticas de Metodología de la Programación
 * Curso: 2022 - 2023
 
 */

#ifndef LIENZO_H
#define LIENZO_H

struct Lienzo{
    char **M = 0;
    int nf = 0, nc = 0;
};



/**
 * @brief reserva memoria para el lienzo. Requiere que img.nf, img.nc sean válidos 
 * @param img el lienzo donde crearemos la matriz.
  */
void reservaMemoria(Lienzo & img);


/**
 * @brief libera la memoria del lienzo. Requiere que img.nf, img.nc sean válidos 
 * @param img el lienzo que contiene la memoria a liberar.
  */
void liberaMemoria(Lienzo & img);


/**
 * @brief muestra por pantalla el contenido del lienzo
 * @param img el lienzo a imprimir.
  */
void imprimir(const Lienzo & img);


/**
 * @brief rellena el lienzo con un valor
 * @param img el lienzo.
 * @param simbolo es el carácter de relleno
  */
void rellenar(Lienzo & img, char simbolo);


/**
 * @brief redimensiona el lienzo, solamente si la nueva dimension es 
 * mayor que la actual. En otro caso, no hace nada.
 * @param img el lienzo.
 * @param nuevaF, nuevaC  nuevos valores para filas y columnas
 * @param c es el carácter de relleno para las nuevas posiciones
  */
void redimensiona(Lienzo & img, int nuevaF, int nuevaC, char c);


/**
 * @brief "dibuja" un rectángulo en el lienzo. Supone que el lienzo esta 
 * inicializado correctamente. El origen de coordenadas (0,0) se corresponde 
 * con el extremo superior izquierdo del lienzo. 
 * @param img el lienzo.
 * @param x,y  coordenadas del vértice superior izquierdo del rectángulo. 
 * Si alguno de los valores es negativo, se pone a cero
 * @param ancho, alto las dimensiones del rectángulo. Si el rectángulo "se sale" del lienzo, 
 * debe ignorar las posiciones inválidas.
 * @param simbolo es el carácter de relleno
  */
void dibujaRectangulo(Lienzo & img, int x, int y, int ancho, int alto, char c);
    

/**
 * @brief voltea la imagen en el eje arriba/abajo. El resultado se almacena en la misma variable
 * @param img el lienzo 
  */
void flipV(Lienzo & img);

/**
 * @brief voltea la imagen en el eje izq/derecha. El resultado se almacena en la misma variable
 * @param img el lienzo 
  */
void flipH(Lienzo & img);


/**
 * @brief crea un gráfico de barras en un lienzo. Debe reservar la memoria necesaria 
 * y dibujar las barras utilizando la función dibujaRectangulo
 * 
 * @param img el lienzo 
 * @param barras un array de valores enteros
 * @param n el tamaño del array
 * @param c el simbolo para "pintar" las barras
  */

void pintaBarras(Lienzo & img, int *barras, int n, char c);

/**
 * @brief rota el lienzo 90º en sentido horario
 *        cuidado si el lienzo no es cuadrado!!
 * @param img es el lienzo a rotar
 */

void rotar(Lienzo & img);

/**
 * @brief comprueba si dos lienzos son iguales
 * devuelve true si tienen las mismas dimensiones
 * y coinciden todos los elementos. 
 * @param L1, L2 son los datos de tipo Lienzo a comparar
 */
bool sonIguales(const Lienzo & L1, const Lienzo & L2);

#endif


