#ifndef PRACTICA_4_FUNCIONES_H
#define PRACTICA_4_FUNCIONES_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct _Nodo{
    int dato;
    char caracter;
    struct _Nodo *L;
    struct _Nodo *R;
    struct _Nodo *sig;
}Nodo;

typedef struct _Binario{
    char caracter;
    int binario;
    int bits;
    int nbits;
    struct _Binario *sig;
}Binario;

Nodo* allocateMem(int dato,char caracter) {
    Nodo *dummy = (Nodo *) malloc(sizeof(Nodo));
    dummy->dato = dato;
    dummy->caracter = caracter;
    dummy->sig=NULL;
    dummy->R = NULL;
    dummy->L = NULL;
    return dummy;
}

Binario *allocateMemo(int binariodec,char caracter,int nbits, int binario) {
    Binario *dummy = (Binario *) malloc(sizeof(Binario));
    dummy->caracter = caracter;
    dummy->bits = binariodec;
    dummy->nbits = nbits;
    dummy->binario = binario;
    dummy->sig = NULL;
}

int binario (int n ) {
    if(n==0) return n;
    else return binario(n/2) *10 + n%2;
}

int contarDigitos(int Num) {
    int Contador = 0;
    do {
        Num /= 10;
        Contador++;
    } while (Num != 0);
    return Contador;
}

int toDecimal(int n){
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0){
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        i++;
    }
    return decimalNumber;
}

void mostrar(Nodo* top) {
    if (top != NULL) {
        while (top != NULL) {
            printf("Caracter %c >> %d\n", top->caracter, top->dato);
            top = top->sig;
        }
    } else {
        printf("No contiene elementos tu Lista\n");
    }
}

void mostrarbin(Binario *top) {
    while (top) {
        if (contarDigitos(top->binario)== (top->nbits)-1)
            printf("Caracter >> %c | Bits >> 0%d | Profundidad >> %d\n", top->caracter, top->binario, top->nbits);

        else
            printf("Caracter >> %c | Bits >> %d | Profundidad >> %d\n", top->caracter, top->binario, top->nbits);

        top = top->sig;
    }
}

void obtbinarch(Binario *listaBin, char frase[],FILE *out3) {
    Binario *aux;
    char *array="";
    if (listaBin != NULL) {
        for (int i = 0; i < strlen(frase); i++) {
            aux = listaBin;
            while (aux != NULL) {
                if (aux->caracter == frase[i]) {
                    sprintf(array, "%d", aux->binario);
                    if (strlen(array) == (aux->nbits - 1))
                        sprintf(array, "0%d", aux->binario);

                    fprintf(out3, "%s", array);
                    break;
                }
                aux = aux->sig;
            }
        }
    }
}

void obtbin(Binario *listaBin, char frase[]) {
    Binario *aux;
    char *array="";
    if (listaBin != NULL) {
        for (int i = 0; i < strlen(frase); i++) {
            aux = listaBin;
            while (aux != NULL) {
                if (aux->caracter == frase[i]) {
                    sprintf(array, "%d", aux->binario);
                    if (strlen(array) == (aux->nbits - 1))
                        sprintf(array, "0%d", aux->binario);

                    printf("%s", array);
                    break;
                }
                aux = aux->sig;
            }
        }
    }
}

void inOrden (Nodo *top) {
    if (top != NULL) {
        inOrden(top->L);
        printf("Elemento %c = %d\n", top->caracter, top->dato);
        inOrden(top->R);
    }
}

void preOrden (Nodo *top) {
    if (top != NULL) {
        printf("%c >> %d\n", top->caracter, top->dato);
        preOrden(top->L);
        preOrden(top->R);
    }
}

void preOrdenimpresion (Nodo *top,FILE *out) {
    if (top != NULL) {
        printf("%c >> %d\n", top->caracter, top->dato);
        fprintf(out,"%d %c ",top->dato,top->caracter);
        preOrdenimpresion(top->L, out);
        preOrdenimpresion(top->R, out);
    }
}

void postOrden (Nodo *top) {
    if (top != NULL) {
        postOrden(top->L);
        postOrden(top->R);
        printf("Elemento %c = %d\n", top->caracter, top->dato);
    }
}

void alta(Nodo ** top, int dato,char caracter) {
    if (*top == NULL) {
        *top = allocateMem(dato, caracter);
    } else if (dato < (*top)->dato) {
        alta(&(*top)->L, dato, caracter);
    } else {
        alta(&(*top)->R, dato, caracter);
    }
}

void moveleft(Nodo **top) {
    Nodo *a, *p;
    p = (*top);
    a = (*top)->L;
    while (a->R != NULL) {
        p = a;
        a = a->R;
    }
    (*top)->dato = a->dato;
    if (p == (*top)) {
        p->L = a->L;
    } else {
        p->R = a->L;
    }
    (*top) = a;
}

void baja(Nodo **top,int dato) {
    Nodo *aux;
    if (*(top) == NULL) {
        puts("El arbol esta vacio");
    } else {
        if (dato < (*top)->dato) {
            baja(&(*top)->L, dato);
        } else if (dato > (*top)->dato) {
            baja(&(*top)->R, dato);
        }
        if (dato == (*top)->dato) {
            aux = (*top);
            if (aux->L == NULL) {
                (*top) = aux->R;
            } else if (aux->R == NULL) {
                (*top) = aux->L;
            } else {
                moveleft(&aux);
            }
            free(aux);
        }
    }
}

void textoconvertido(char* letras) {
    int q = 0;
    if (letras != NULL) {
        while (letras[q] != '\0') {
            letras[q] = tolower(letras[q]);
            if (letras[q] == '\361' || letras[q] == '\321')
                letras[q] = 'n';
            else if (letras[q] == '\300' || letras[q] == '\301' || letras[q] == '\340' || letras[q] == '\341')
                letras[q] = 'a';
            else if (letras[q] == '\310' || letras[q] == '\311' || letras[q] == '\350' || letras[q] == '\351')
                letras[q] = 'e';
            else if (letras[q] == '\314' || letras[q] == '\315' || letras[q] == '\354' || letras[q] == '\355')
                letras[q] = 'i';
            else if (letras[q] == '\322' || letras[q] == '\323' || letras[q] == '\326' || letras[q] == '\362' ||
                     letras[q] == '\363' || letras[q] == '\366')
                letras[q] = 'o';
            else if (letras[q] == '\331' || letras[q] == '\332' || letras[q] == '\334' || letras[q] == '\371' ||
                     letras[q] == '\372' || letras[q] == '\374')
                letras[q] = 'u';
            else if(letras[q]==' ')
                letras[q] = '+';
            q++;
        }
    }
}

void contador(char s[],int count[]) {
    int c = 0;
    while (s[c] != '\0') {
        if (s[c] >= 'a' && s[c] <= 'z')
            count[s[c] - 'a']++;
        else if (s[c] == '+')
            count[26]++;
        else if(s[c] == '.')
            count[27]++;
        else if(s[c] == ',')
            count[28]++;
        c++;
    }
}

void Buildtree(Nodo** arbol, Nodo *raiz) {
    Nodo *aux, *aux2;
    if (*arbol==NULL) {
        *arbol = raiz;
        (*arbol)->sig = NULL;
    } else {
        aux = *arbol;
        aux2 = NULL;
        while (aux && aux->dato < raiz->dato) {
            aux2 = aux;
            aux = aux->sig;
        }
        raiz->sig = aux;
        if (aux2!=NULL)
            aux2->sig = raiz;
        else
            *arbol = raiz;
    }
}

void Makelist(Binario **Listabin,char caracter,int longitud,int binariosdec,int binarios) {
    Binario *aux, *aux2, *aux3;

    aux = allocateMemo(binariosdec, caracter, longitud,binarios);
    if (*Listabin == NULL) {
        *Listabin = aux;
        (*Listabin)->sig = NULL;
    } else
    {
        aux2 = *Listabin;
        aux3 = NULL;
        while (aux2 && aux2->nbits<aux->nbits)
        {
                aux3 = aux2;
                aux2 = aux2->sig;
        }
        aux ->sig=aux2;
        if(aux3!=NULL)
            aux3->sig = aux;
        else
            *Listabin = aux;
    }
}

void Buildbinary(Nodo *Arbol,int longitud,int binariosdec,Binario **Listabin,int binarios)
{
    if(Arbol->L!=NULL)
        Buildbinary(Arbol->L,longitud+1,binariosdec<<1,Listabin,binarios);

    if(Arbol->R!=NULL)
        Buildbinary(Arbol->R,longitud+1,(binariosdec<<1)|1,Listabin,binarios);

    if(Arbol->L==NULL&&Arbol->R==NULL)
    {
        binarios = binario(binariosdec);
        Makelist(Listabin,Arbol->caracter,longitud,binariosdec,binarios);
    }
}

int sizetree(Nodo *top) {
    if (top == NULL)
        return 0;
    else
        return (sizetree(top->L) + 1 + sizetree(top->R));
}

int recorrido(Nodo *top) {
    int i = 0;
    if (top != NULL) {
        while (top != NULL) {
            top = top->sig;
            i++;
        }
    }
    return i;
}

char  *decode_file(Nodo *root, char *s) {
    char *ans = "";
    Nodo *curr = root;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '0')
            curr = curr->L;
        else
            curr = curr->R;

        // reached leaf node
        if (curr->L == NULL && curr->R == NULL) {
            ans += curr->dato;
            curr = root;
        }
    }
    return strcat(ans,"\0");
}

Nodo* altainicio(int dato, Nodo* top,char caracter) {
    Nodo *box;
    box = allocateMem(dato, caracter);
    if (top != NULL) {
        box->sig = top;
    }
    top = box;
    return top;
}

Nodo* altafinal(int dato, Nodo* frente,char caracter) {
    Nodo *box, *aux;
    box = allocateMem(dato, caracter);
    if (frente == NULL) {
        return box;
    } else {
        aux = frente;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = box;
    }
    return frente;
}

Nodo *ordenar_seleccion(Nodo *top) {
    Nodo *aux, *aux2;
    aux = top;

    if (top != NULL) {
        while (aux->sig != NULL) {
            aux2 = aux->sig;
            while (aux2 != NULL) {
                if (aux->dato > aux2->dato) {
                    int var = aux->dato;
                    aux->dato = aux2->dato;
                    aux2->dato = var;

                    char let = aux->caracter;
                    aux->caracter = aux2->caracter;
                    aux2->caracter = let;
                }
                aux2 = aux2->sig;
            }
            aux = aux->sig;
        }
    }
    return top;
}

Nodo *Ayudantexd (char letra[],int pre[], int* preIndex, int low, int high, int size){
    if (*preIndex >= size || low > high) {
        return NULL;
    }

    Nodo *root;
    root = allocateMem(pre[*preIndex],letra[*preIndex]);
    *preIndex = *preIndex + 1;

    if (low == high) {
        return root;
    }

    int i;
    for (i = low; i <= high; i++ ) {
        if (pre[i] > root->dato) {
            break;
        }
    }

    root->L = Ayudantexd (letra, pre, preIndex, *preIndex, i - 1, size );
    root->R = Ayudantexd (letra, pre, preIndex, i, high, size );

    return root;
}

Nodo *Reconstruirtree(char letra[], int pre[], int size){
    int preIndex = 0;
    return Ayudantexd (letra ,pre, &preIndex, 0, size - 1, size);
}

#endif