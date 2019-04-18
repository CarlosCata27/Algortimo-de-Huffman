#ifndef PRACTICA_4_FUNCIONES_H
#define PRACTICA_4_FUNCIONES_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Nodo{
    int dato;
    char caracter;
    struct _Nodo *L;
    struct _Nodo *R;
}Nodo;

typedef  struct _Arco{
    int dato;
    struct _Arco *R;
}Arco;

Nodo* allocateMem(int dato,char caracter)
{
    Nodo* dummy;
    dummy = (Nodo*)malloc(sizeof(Nodo));
    dummy -> dato = dato;
    dummy -> caracter = caracter;
    dummy -> R = NULL;
    dummy -> L = NULL;
    return dummy;
}

void mostrar(Nodo* top){
    if(top != NULL){
        while(top != NULL){
            printf("Caracter %c aparece = %d\n",top->caracter, top -> dato);
            top = top -> R;
        }
    }else{
        printf("No contiene elementos tu Lista\n");
    }
}

void inOrden (Nodo *top){
    if (top != NULL){
        inOrden (top->L);
        printf("Elemento = %d\n",top->dato);
        inOrden(top->R);
    }
}

void preOrden (Nodo *top){
    if (top != NULL){
        printf("Elemento = %d\n",top->dato);
        preOrden (top->L);
        preOrden(top->R);
    }
}

void postOrden (Nodo *top){
    if (top != NULL){
        preOrden (top->L);
        preOrden(top->R);
        printf("Elemento = %d\n",top->dato);
    }
}

void alta(Nodo ** top, int dato,char caracter)
{
    if(*top == NULL){
        *top = allocateMem(dato,caracter);
    }
    else if(dato < (*top)->dato){
        alta(&(*top)->L,dato,caracter);
    }
    else{
        alta(&(*top)->R,dato,caracter);
    }
}

void moveleft(Nodo **top)
{
    Nodo *a,*p;
    p=(*top);
    a=(*top)->L;
    while(a->R!=NULL)
    {
        p=a;
        a=a->R;
    }
    (*top)->dato=a->dato;
    if(p==(*top))
    {
        p->L=a->L;
    }
    else
    {
        p->R=a->L;
    }
    (*top)=a;
}

void baja(Nodo **top,int dato)
{
    Nodo *aux;
    if(*(top)==NULL)
    {
        puts("El arbol esta vacio");
    }
    else
    {
        if(dato<(*top)->dato)
        {
            baja(&(*top)->L,dato);
        }
        else if(dato>(*top)->dato)
        {
            baja(&(*top)->R,dato);
        }
        if(dato==(*top)->dato)
        {
            aux = (*top);
            if (aux->L==NULL)
            {
                (*top)=aux->dato;
            }
            else if(aux->R==NULL)
            {
                (*top)=aux->L;
            }
            else
            {
                moveleft(&aux);
            }
            free(aux);
        }
    }
}

int size(Nodo *top)
{
    if (top==NULL)
        return 0;
    else
        return(size(top->L) + 1 + size(top->R));
}

int recorrido(Nodo *top) {
    int i = 0;
    if (top != NULL) {
        while (top != NULL) {
            top = top->R;
            i++;
        }
    }
    return i;
}

Nodo* altainicio(int dato, Nodo* top,char caracter)
{
    int t = recorrido(top);
    Nodo *box;
    box = allocateMem(dato,caracter);
    if(top != NULL){
        if(t>0)
        {
            box->R=top;
            top->L=box;
        }
    }
    top = box;
    return top;
}

Nodo* altafinal(int dato, Nodo* top,char caracter) {
    Nodo *box, *aux;
    box = allocateMem(dato,caracter);
    if (top==NULL)
    {
        top = altainicio(dato,top,caracter);
    }
    else{
        aux = top;
        while (aux->R != NULL) {
            aux = aux->R;
        }
        aux->R = box;
        box->L = aux;
        box->R = NULL;
    }
    return top;
}

Nodo* Alta_Dato(Nodo *top, int dato_nuevo, int dato_busqueda,char caracter){
    Nodo *aux, *nuevo;
    aux = top;
    nuevo = allocateMem(dato_nuevo,caracter);
    if (top == NULL){
        puts("Lista sin archivos");
        return top;
    } else {
        while(aux->R != NULL){
            if (aux->dato == dato_busqueda){

                /*nuevo->R = aux->R;
                nuevo -> L = aux;
                aux->R = nuevo;
                nuevo -> R -> L = nuevo;
                break;*/
            }else{
                aux = aux->R;
            }
        }
    }
    return top;
}

Nodo *ordenar_seleccion(Nodo *top) {
    Nodo *aux, *aux2;
    aux = top;

    while (aux->R != NULL) {
        aux2 = aux->R;
        while (aux2 != NULL) {
            if (aux->dato>aux2->dato) {
                int var = aux->dato;
                aux->dato = aux2->dato;
                aux2->dato = var;

                char let = aux->caracter;
                aux->caracter = aux2->caracter;
                aux2->caracter = let;
            }
            aux2 = aux2->R;
        }
        aux = aux->R;
    }
    return top;
}

char *textoconvertido() {
    FILE *archivo = NULL;
    char *nombre = "E:\\Escuela\\Estructura_de_datos\\Practica 4\\original.txt";
    char *letras = (char *) malloc(sizeof(char));
    int i =0,q=0;
    archivo = fopen(nombre, "rt");

    if (archivo == NULL) {
        puts("Este archivo no existe");
        exit(-1);
    }
    while (!feof(archivo)) {
        fscanf_s(archivo, "%c", &letras[i]);
        letras[i]= tolower(letras[i]);
        fflush(stdin);
        i++;
    }
    fclose(archivo);

    while(letras[q]!='\0')
    {
        if(letras[q]=='\361'||letras[q]=='\321')
            letras[q] = 'n';
        else if(letras[q]=='\212'||letras[q]=='\232')
            letras[q]= 's';
        else if(letras[q]=='\216'||letras[q]=='\236')
            letras[q]= 's';
        else if(letras[q]=='\237'||letras[q]=='\335'||letras[q]=='\375'||letras[q]=='\377')
            letras[q]= 'y';
        else if(letras[q]=='\300'||letras[q]=='\301'||letras[q]=='\302'||letras[q]=='\303'||letras[q]=='\304'||letras[q]=='\305'||letras[q]=='\340'||letras[q]=='\341'||letras[q]=='\342'||letras[q]=='\343'||letras[q]=='\344'||letras[q]=='\345')
            letras[q]= 'a';
        else if(letras[q]=='\307'||letras[q]=='\347')
            letras[q]= 'c';
        else if(letras[q]=='\310'||letras[q]=='\311'||letras[q]=='\312'||letras[q]=='\313'||letras[q]=='\350'||letras[q]=='\351'||letras[q]=='\352'||letras[q]=='\353')
            letras[q]='e';
        else if(letras[q]=='\314'||letras[q]=='\315'||letras[q]=='\316'||letras[q]=='\317'||letras[q]=='\354'||letras[q]=='\355'||letras[q]=='\356'||letras[q]=='\357')
            letras[q]='i';
        else if(letras[q]=='\322'||letras[q]=='\323'||letras[q]=='\324'||letras[q]=='\325'||letras[q]=='\326'||letras[q]=='\330'||letras[q]=='\362'||letras[q]=='\363'||letras[q]=='\364'||letras[q]=='\365'||letras[q]=='\366'||letras[q]=='\370')
            letras[q]='o';
        else if(letras[q]=='\331'||letras[q]=='\332'||letras[q]=='\333'||letras[q]=='\334'||letras[q]=='\371'||letras[q]=='\372'||letras[q]=='\373'||letras[q]=='\374')
            letras[q]='u';
        q++;
    }
    for (int j = 0; letras[j]!='\0'; j++) {
        printf("%c",letras[j]);
    }
    return letras;
}

/*
void frecuenciachar(char *s, int *count) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= ' ' && s[c] <= '~' )
            count[s[c]-'a']++;
        c++;
    }
}



void find_frequency(char [], int []){
    char string[100];
    int c, count[26] = {0};

    printf("Input a string\n");
    gets_s(string,100);

    frecuenciachar(string, count);

    printf("Character Count\n");

    for (c = 0 ; c < 26 ; c++)
        printf("%c \t  %d\n", c + 'a', count[c]);
}

Nodo *buildArbol(Nodo *Lista)
{
    Nodo *arbol;



    return arbol;
}*/

#endif