#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    Nodo *lista=NULL,*arbol;
    FILE *archivo = NULL;
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt";
    char *letras = (char *) malloc(sizeof(char));
    int i =0,m;

    puts("abre archivo\n");
    if ((archivo = fopen(nombre, "r")) == NULL) {
        puts("Este archivo no existe");
        exit(-1);
    }
    puts("asies");

    while (!feof(archivo)) {
        printf("while %d\n",i);
        fscanf(archivo, "%c", &letras[i]);
        i++;
    }
    puts("saca datos\n");

    puts("El espacio fue sustituido por un +\n");

    letras = textoconvertido(letras);
    puts("abemusarray de texto\n");
    lista = listapost(letras);
    mostrar(lista);
    /*do{
        puts("ALGORITMO DE HUFFMAN\n"
             "1 >> Codificar\n"
             "2 >> Decodificar\n"
             "0 >> Salir\n");
        scanf("%d",&m);

        switch (m)
        {
            case 1:
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
    }while (m!=0);*/
    fclose(archivo);
    puts("cierra archivo\n");
    return 0;
}