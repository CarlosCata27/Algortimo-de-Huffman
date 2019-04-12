#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    //Nodo *lista=NULL,*arbol;
    FILE *original=NULL;
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt";

    //puts("Nota: El + es la sustitucion del 'espacio'\n");

    int q=0,asies=1,c;
    int *caracteres = (int*)malloc (asies*sizeof(int));
    char *letras = (char*)malloc (asies*sizeof(char));
    Nodo *lista=NULL;
    if ((original = fopen(nombre, "rt")) == NULL) {
        puts("Este archivo no existe");
        exit(-1);
    }
    int i=0;
    while ((c =getc(original))!=EOF) {
        fscanf_s(original, "%c", &letras[i]);
        i++;
    }
    while(letras!='\0')
    {
        printf("%c",letras[q]);
        q++;
    }



    /*while (letras[q] != '\0') {
        if (letras[q] >= ' ' && letras[q] <= '~' )
            caracteres[letras[q]-'a']++;
        q++;
    }*/


    //lista = listwfile(original,nombre);
    //mostrar(lista);

    //arbol = buildArbol(lista);


    return 0;
}