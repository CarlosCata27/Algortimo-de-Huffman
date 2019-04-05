#ifndef PRACTICA_4_FUNCIONES_H
#define PRACTICA_4_FUNCIONES_H

typedef struct _Nodo{
    int dato;
    char caracter;
    struct _Nodo *L;
    struct _Nodo *R;
}Nodo;

typedef  struct _Arco{
    int dato;
    struct _Arco *sig;
};

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

void ordenar_seleccion(int a[],int n)
{
    int indiceMenor;
    int q=0;

    for(int i=0;i<n-1;i++)
    {
        indiceMenor=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[indiceMenor])
                indiceMenor=j;
        if(i!=indiceMenor)
        {
            int aux=a[i];
            a[i]=a[indiceMenor];
            a[indiceMenor]=aux;
        }
    }
    for (q=0;q<n;q++)
    {
        printf("%d\n",a[q]);
    }
}

Nodo* altainicio(int dato, Nodo* top)
{
    int t = recorrido(top);
    Nodo *box;
    box = allocateMem(dato);
    if(top != NULL){
        if(t>0)
        {
            box->R=top;
            top->L=box;
        }
    }
    top = box;
    puts("Agregado");
    return top;
}

Nodo* altafinal(int dato, Nodo* top) {
    Nodo *box, *aux;
    box = allocateMem(dato);
    if (top != NULL) {
        aux = top;
        while (aux->R != NULL) {
            aux = aux->R;
        }
        aux->R = box;
        box->L = aux;
        box->R = NULL;
    }
    puts("Agregado");
    return top;
}

#endif