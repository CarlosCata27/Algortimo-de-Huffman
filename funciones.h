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
        int i = 1;
        while(top != NULL){
            printf("Elemento %d de la lista = %d\n",i, top -> dato);
            top = top -> R;
            i++;
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

void listwfile(Nodo *top,FILE *archivo,char *nombre) {

    int q,s=0,i=0,m=0,e=0,espacio=0,a=0,t=0,p=0,y=0,o=0,k=0,r=0,c=0,l=0;
    int caracteres[14]={0};
    char letras[14] = {''};
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
    ordenar_seleccion(caracteres,14);
    for (int j = 0; j < 14; ++j) {
        lista = altafinal(caracteres[j],lista);
    }
    mostrar(lista);



}

#endif