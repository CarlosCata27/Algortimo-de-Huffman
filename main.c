#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    Nodo *lista=NULL,*arbol;
    FILE *original=NULL;
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt";

    puts("Nota: El + es la sustitucion del 'espacio'\n");

    lista = listwfile(original,nombre);
    mostrar(lista);


    return 0;
}