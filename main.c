#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    Nodo *lista=NULL,*arbol;
    FILE *archivo = NULL;
    char abc[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','+'};
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt";
    char *letras = (char *) malloc(sizeof(char));
    int i =0,m;

    if ((archivo = fopen(nombre, "rt")) == NULL) {
        puts("Este archivo no existe");
        exit(-1);
    }

    while (!feof(archivo)) {
        fgets(letras, 100, archivo);
    }

    letras = textoconvertido(letras);
    lista = contador(letras);

    do{
        puts("ALGORITMO DE HUFFMAN\n"
             "1 >> Codificar\n"
             "2 >> Decodificar\n"
             "0 >> Salir\n");
        scanf("%d",&m);

        switch (m)
        {
            case 1:
                arbol = buildArbol(lista);
                preOrden(arbol);
                break;

            case 2:
                break;

            case 0:
                puts("CHI CHENOL");
                break;

            default:
                puts("Inserte una opcion valida");
                break;
        }
    }while (m!=0);
    fclose(archivo);
    return 0;
}