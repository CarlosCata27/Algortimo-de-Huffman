#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    Nodo *lista = NULL, *arbol = NULL;
    FILE *archivo = NULL;
    char abc[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                    'u', 'v', 'w', 'x', 'y', 'z', '+'};
    int count[27] = {0}, m, i = 0, j = 0;
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt", letras[100];


    if ((archivo = fopen(nombre, "rt")) == NULL) {
        puts("Este archivo no existe");
        exit(-1);
    }

    fgets(letras, 100, archivo);
    textoconvertido(letras);
    contador(letras, count);
    for (j = 0; j < 27; j++) {
        if (count[j] != 0) {
            lista = altainicio(count[j], lista, abc[j]);
        }
    }
    lista = ordenar_seleccion(lista);
    mostrar(lista);

    do {
        puts("ALGORITMO DE HUFFMAN\n"
             "1 >> Codificar\n"
             "2 >> Decodificar\n"
             "3 >> Mostrar arbol\n"
             "0 >> Salir\n");
        scanf_s("%d", &m);

        switch (m) {
            case 1:
                j = 0, i = 0;
                Nodo *aux = lista, *raices[14] = {NULL}, *subarboles[7] = {
                        NULL}, *izq = NULL, *der = NULL, *raiz = NULL, *aux2 = NULL;
                if (aux != NULL) {
                    while (aux != NULL) {
                        if (aux->R != NULL) {
                            int nv = aux->dato + aux->R->dato;
                            raiz = allocateMem(nv, '*');
                            izq = allocateMem(aux->dato, aux->caracter);
                            der = allocateMem(aux->R->dato, aux->R->caracter);
                            raiz->L = izq;
                            raiz->R = der;
                            raices[i] = raiz;
                            /*int nv = aux->dato + aux->R->dato;
                            Nodo *aux2 = allocateMem(nv, '*');
                            izq = allocateMem(aux->dato,aux->caracter);
                            der = allocateMem(aux->R->dato,aux->R->caracter);
                            aux = altadato(aux, nv, nv, '*');
                            aux2 -> L = izq;
                            aux2 -> R = der;
                            ordenarbol(&arbol, aux2);*/
                        } else {
                            raiz = allocateMem(aux->dato, '*');
                            izq = allocateMem(aux->dato, aux->caracter);
                            raiz->L = izq;
                            raices[i] = raiz;
                            /*Nodo *aux2 = allocateMem(aux->dato, '*');
                            aux = altadato(aux, aux->dato, aux->dato, '*');
                            izq = allocateMem(aux->dato,aux->caracter);
                            aux2 -> L = izq;
                            ordenarbol(&arbol, aux2);*/
                            break;
                        }
                        aux = aux->R->R;
                        i++;
                    }
                    int bandera = 1;
                    i=0;
                    do {
                        switch (bandera) {
                            case 1:
                                if (raices[j + 1] != NULL) {
                                    int nv = raices[j]->dato + raices[j + 1]->dato;
                                    raiz = allocateMem(nv, '*');
                                    raiz->L = raices[j];
                                    raiz->R = raices[j + 1];
                                    subarboles[i] = raiz;
                                    j+=2;
                                    bandera = 1;
                                } else {
                                    j+=3;
                                    bandera = 2;
                                }
                                i++;
                                break;

                            case 2:
                                raiz = allocateMem(raices[j]->dato, '*');
                                raiz->L = raices[j];
                                subarboles[i] = raiz;
                                bandera = 0;
                                i++;
                                break;

                            case 0:
                                break;

                        }
                    } while (bandera != 0);
                }
                break;


            case 2:
                break;

            case 3:
                preOrden(arbol);
                break;

            case 0:
                puts("CHI CHENOL");
                break;

            default:
                puts("Inserte una opcion valida");
                break;
        }
    } while (m != 0);
    fclose(archivo);
    return 0;
}
