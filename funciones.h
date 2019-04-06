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

Nodo *ordenar_seleccion(Nodo *top,int n) {
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

Nodo *listwfile(Nodo *top,FILE *archivo,char *nombre) {

    int q,caracteres[14]={0};
    char letras[14] = {'s','i','m','e','+','a','t','p','y','o','k','r','c','l'};
    Nodo *lista=NULL;
    if ((archivo = fopen(nombre, "rt")) == NULL) {
        puts("Este archivo no existe");
        exit(-1);
    }
    while ((q=fgetc(archivo))!=EOF)
    {
        if(q == 's')
            caracteres[0]++;
        else if(q == 'i')
            caracteres[1]++;
        else if(q == 'm')
            caracteres[2]++;
        else if(q == 'e')
            caracteres[3]++;
        else if(q == ' ')
            caracteres[4]++;
        else if(q == 'a')
            caracteres[5]++;
        else if(q == 't')
            caracteres[6]++;
        else if(q == 'p')
            caracteres[7]++;
        else if(q == 'y')
            caracteres[8]++;
        else if(q == 'o')
            caracteres[9]++;
        else if(q == 'k')
            caracteres[10]++;
        else if(q == 'r')
            caracteres[11]++;
        else if(q == 'c')
            caracteres[12]++;
        else if(q == 'l')
            caracteres[13]++;
        else
            putchar(q);
    }
    fclose(archivo);
    for (int j = 0; j < 14; ++j) {
        lista = altafinal(caracteres[j],lista,letras[j]);
    }
    int tam = recorrido(lista);
    lista = ordenar_seleccion(lista,tam);
    return lista;
}

#endif