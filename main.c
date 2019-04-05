#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    FILE *original;
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt";
    original = fopen(nombre,"rt");

    if(original == NULL)
    {
        puts("Este archivo no existe");
        exit (-1);
    }
    else
    {
        puts("Ya abrio asies");
    }
    return 0;
}