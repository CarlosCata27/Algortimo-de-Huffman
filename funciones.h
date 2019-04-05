#ifndef PRACTICA_4_FUNCIONES_H
#define PRACTICA_4_FUNCIONES_H

typedef struct _Nodo{
    int dato;
    struct _Nodo *L;
    struct _Nodo *R;
}Nodo;

Nodo* allocateMem(int dato)
{
    Nodo* dummy;
    dummy = (Nodo*)malloc(sizeof(Nodo));
    dummy -> dato = dato;
    dummy -> R = NULL;
    dummy -> L = NULL;
    return dummy;
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

void alta(Nodo ** top, int dato)
{
    if(*top == NULL){
        *top = allocateMem(dato);
    }
    else if(dato < (*top)->dato){
        alta(&(*top)->L,dato);
    }
    else{
        alta(&(*top)->R,dato);
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

#endif