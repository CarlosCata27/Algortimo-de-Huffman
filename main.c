#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    Nodo *lista=NULL,*arbol;
    FILE *original=NULL;
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt";
    lista = listwfile(lista,original,nombre);
    mostrar(lista);


    return 0;
}