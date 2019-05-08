#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    int m;
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\frase.txt";
    char *salida = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\arbol_codificado.txt";
    char *salida2 = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\frase_codificada.bin";
    char *salida3 = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\frase_binaria.txt";

    puts("ALGORITMO DE HUFFMAN\n"
         "1 >> Codificar\n"
         "2 >> Decodificar\n"
         "0 >> Salir\n");
    scanf_s("%d", &m);
    switch (m) {
        case 1:
            char abc[29] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                            'r',
                            's', 't',
                            'u', 'v', 'w', 'x', 'y', 'z', '+', '.', ','}, frase[100], *codbinario = "";
            int count[29] = {0};
            FILE *archivo = fopen(nombre, "rt"), *out2 = fopen(salida2, "wb"), *out = fopen(salida,
                                                                                            "w"), *out3 = fopen(
                    salida3, "w"), *ropen = fopen(salida3, "rt");

            if (!archivo || !out || !out2) {
                puts("Este archivo no existe");
                exit(-1);
            }
            Nodo *lista = NULL, *arbol = NULL, *aux;
            Binario *listacod = NULL;
            fgets(frase, 100, archivo);
            textoconvertido(frase);
            contador(frase, count);
            for (int j = 0; j < 29; j++) {
                if (count[j] != 0) {
                    lista = altafinal(count[j], lista, abc[j]);
                }
            }
            lista = ordenar_seleccion(lista);
            mostrar(lista);
            arbol = lista;
            while (arbol && arbol->sig) {
                int nv = arbol->dato + arbol->sig->dato;
                aux = allocateMem(nv, '*');
                aux->L = arbol;
                aux->R = arbol->sig;
                arbol = arbol->sig->sig;
                Buildtree(&arbol, aux);
            }
            preOrdenimpresion(arbol, out);
            Buildbinary(arbol, 0, 0, &listacod, 0);
            mostrarbin(listacod);
            obtbinarch(listacod, frase, out3);
            fclose(out3);
            fgets(codbinario, 500, ropen);
            fclose(ropen);
            while (strlen(codbinario) % 8 != 0) {
                sprintf(codbinario, "%s0", codbinario);
            }
            int q = strlen(codbinario) / 8;
            int *caracteres = (int *) malloc(q * sizeof(int)), rec = 0;
            for (int i = 0; i < q; i++) {
                char byte[8];
                for (int j = 0; j < 8; j++) {
                    byte[j] = codbinario[rec];
                    rec++;
                }
                caracteres[i] = toDecimal(atoi(byte));
            }
            fwrite(&q, sizeof(int), 1, out2);
            for (int k = 0; k < q; k++) {
                fprintf(out2, "%c", caracteres[k]);
                printf("%d | %c\n", caracteres[k], caracteres[k]);
            }
            fclose(out);
            fclose(out2);
            fclose(archivo);
            break;

        case 2:
            Nodo *arboldec = NULL, *listaaux = NULL;
            int i = 0, c, j = 0;
            FILE *farbol = fopen(salida, "rt"), *ffrasec = fopen(salida2, "rb");
            if (!farbol || !ffrasec) {
                puts("Error en la apertura de los archivos");
                exit(-1);
            }
            fread(&c, sizeof(int), 1, ffrasec);
            int *digitos = (int *) malloc(c * sizeof(int));
            for (int l = 0; l < c; ++l) {
                int a = 0;
                fread(&a, sizeof(char), 1, ffrasec);
                digitos[l] = a;
            }
            fclose(ffrasec);
            while ((c = fgetc(farbol)) != EOF) {
                if (c == ' ')
                    i++;
            }
            i /= 2;
            int *valor = (int *) malloc(i * sizeof(int));
            char *letter = (char *) malloc(i * sizeof(char));
            rewind(farbol);
            while (!feof(farbol)) {
                fscanf(farbol, "%d %c ", &valor[j], &letter[j]);
                listaaux = altafinal(valor[j], listaaux, letter[j]);
                j++;
            }
            fclose(farbol);
            arboldec = Reconstruirtree(letter, valor, recorrido(listaaux));
            preOrden(arboldec);

            break;

        case 0:
            puts("CHI CHENOL");
            break;

        default:
            puts("Inserte una opcion valida");
            break;
    }

    puts("--------------------------------------------------------------------------\n"
         "REFERENCIAS SACADAS DE LAS SIGUIENTES PAGINAS:\n"
         "https://www.geeksforgeeks.org/huffman-decoding/\n"
         "https://elcodigoascii.com.ar/\n"
         "https://travesuras.wordpress.com/2010/08/25/20100825-1/\n"
         "http://www.csfieldguide.org.nz/en/interactives/huffman-tree/index.html\n"
         "https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/\n"
         "--------------------------------------------------------------------------\n");
    return 0;
}