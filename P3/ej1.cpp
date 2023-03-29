// Ejemplo 1
/* La respuesta obtenida sería que estos valores son diferentes, a la variable a
   le asignamos el valor que apunta p multiplicado por el propio valor de a,
   pero p no esta inicializado por tanto no apunta a ningún sitio. */

// Ejemplo 2
/* Este ejemplo dará error de ejecución porque no podemos asignar un valor a p
   en base a su valor cuando no está inicializado. */

// Ejemplo 3
/* Obtendremos que ambos son iguales, inicializamos p a la dirección de
   memoria de a, por tanto funcionaría como un alias, todo lo que le
   hagamos al valor de p se traducirá en a. */

// Ejemplo 4
/* En la primera línea del main, se inicializa todo apuntando a lo mismo
   en la segunda linea como todo es igual, se cambia el valor a 5 + (5/5),
   se vuelve a cambiar el valor a 6+1, y el último cambio que deja todo
   con valor 5/2 = 2.5 -> 3. */

// Ejemplo 5
// Solo las declaraciones de v1 y v3 son correctas, v2 y v4 necesitan un valor.
    // Asignaciones de v1
    // Solo la primera se puede hacer

    // Asignaciones de v2
    // No se puede editar una variable constante

    // Asignaciones de v3
    // Todo funciona, el const solo afecta al puntero de v3

    // Asignaciones de v4
    // No se puede editar una variable constante

    // Asignaciones de *v1
    // Como el puntero no ha sido inicializado, no se puede acceder a *v1

    // Asignaciones de *v2
    // No se puede editar el valor de una variable constante mediante un puntero

    // Asignaciones de *v3
    // No se puede editar un puntero constante

    // Asignaciones de *v4
    // No se puede editar un puntero constante
