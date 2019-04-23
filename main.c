#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    Nodo *lista=NULL,*aux;
    FILE *archivo = NULL;
    char abc[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','+'};
    int count[27]={0};
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt";
    char letras[100];
    int m;

    if ((archivo = fopen(nombre, "rt")) == NULL) {
        puts("Este archivo no existe");
        exit(-1);
    }

    fgets(letras, 100, archivo);
    textoconvertido(letras);
    contador(letras,count);
    for (int j = 0; j < 27; j++) {
        if (count[j] != 0) {
            lista = altainicio(count[j],lista,abc[j]);
        }
    }
    lista = ordenar_seleccion(lista);

    do{
        puts("ALGORITMO DE HUFFMAN\n"
             "1 >> Codificar\n"
             "2 >> Decodificar\n"
             "0 >> Salir\n");
        scanf_s("%d",&m);

        switch (m)
        {
            case 1:
                Nodo *arbol=lista;

                if(lista!=NULL)
                {
                    while(arbol->R!=NULL)
                    {
                        int nv = arbol->dato + arbol->R->dato;
                        aux = allocateMem(nv,'*');
                        ordenarbol(&arbol,aux);
                        arbol = arbol->R->R;
                    }
                }
                else
                {
                    puts("La lista esta vacia");
                }
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