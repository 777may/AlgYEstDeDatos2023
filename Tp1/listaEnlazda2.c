#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo * siguiente;
}typedef Nodo;

typedef Nodo * LISTA;
#define indef -9999;

void crearLista(LISTA * L); //crea una lista vacía.
int esListaVacia(LISTA L); //booleana, determina si la lista está vacía.
void mostrar(LISTA L); //muestra por pantalla el contenido de los nodos de la lista.
int primerElemento(LISTA L); //retorna el contenido del primer elemento de la lista.
void insertar(LISTA * L, int valor ); //inserta un nodo al comienzo de la lista.
void borrar(LISTA *L); //borra el nodo del comienzo de la lista.
int longitud(LISTA L); //cuenta la cantidad de nodos que tiene una lista.
int pertenece(LISTA L, int buscado); //booleana, determina si un dato pertenece a la lista.
void borrarUltimo(LISTA * L); //borra el nodo del final de la lista.
int iguales(LISTA * A, LISTA * B);


void main(){
    int valor;
    LISTA X, Y;
    crearLista(&X);
    crearLista(&Y);
    printf("\nLa lista X esta vacia?: %d - La lista Y esta vacia?: %d ", esListaVacia(X), esListaVacia(Y));
    printf("\nMostrar: ");
    mostrar(X);
    printf("\n---");
    mostrar(Y);
    printf("\nPrimer elemento X: %d - Primer elemento Y: %d", primerElemento(X), primerElemento(Y));
    printf("\nLongitud X: %d - Longitud Y: %d,", longitud(X), longitud(Y));
    printf("\nBorrar ultimo X: ");
    borrarUltimo(&X);
    printf("\nIguales X, Y: %d",iguales(&X, &Y));
    printf("\nInserte un num en X ");
    scanf("%d", &valor);    
    insertar(&X, valor);
    printf("\nInserte un num en ambos ");
    scanf("%d", &valor);    
    insertar(&X, valor);
    insertar(&Y, valor);
    printf("\nInserte un num en Y ");
    scanf("%d", &valor);    
    insertar(&Y, valor);
    printf("\nMostrar: ");
    mostrar(X);
    printf("\n---");
    mostrar(Y);
    printf("\nBusque un num en ambos: ");
    scanf("%d", &valor);    
    printf("\nPertenece %d?  a X: %d - a Y: %d,",valor, pertenece(X, valor), pertenece(Y, valor));
    printf("\nBusque un num en ambos: ");
    scanf("%d", &valor);    
    printf("\nPertenece %d?  a X: %d - a Y: %d,",valor, pertenece(X, valor), pertenece(Y, valor));
    printf("\nLongitud X: %d - Longitud Y: %d,", longitud(X), longitud(Y));
    printf("\nBorrar Y: ");
    borrar(&Y);
    printf("\nLongitud X: %d - Longitud Y: %d,", longitud(X), longitud(Y));
    printf("\nMostrar: ");
    mostrar(X);
    printf("\n---");
    mostrar(Y);
    printf("\nBorrar ultimo X: ");
    borrarUltimo(&X);
    printf("\nLongitud X: %d - Longitud Y: %d,", longitud(X), longitud(Y));
    printf("\nMostrar: ");
    mostrar(X);
    printf("\n---");
    mostrar(Y);
    printf("\nLa lista X esta vacia?: %d - La lista Y esta vacia?: %d ", esListaVacia(X), esListaVacia(Y));
    printf("\nPrimer elemento X: %d - Primer elemento Y: %d", primerElemento(X), primerElemento(Y));
    printf("\nIguales: %d", iguales(&X, &Y));
    printf("\nMostrar: ");
    mostrar(X);
    printf("\n---");
    mostrar(Y);
    printf("\nInserte un num en Y ");
    scanf("%d", &valor);    
    insertar(&Y, valor);
    printf("\nIguales: %d", iguales(&X, &Y));




}



void crearLista(LISTA * L)
{
    *L = NULL;
}
int esListaVacia(LISTA L)
{
    return L == NULL;
}
void mostrar(LISTA L)
{
    if(L){
        printf("\n%d", L->dato);
        L = L->siguiente;
    }else{
        printf("\nLa lista esta vacia");
    }
    while (L)
    {
        printf(", %d", L->dato);
        L = L->siguiente;
    }
    printf(".\n");
}
int primerElemento(LISTA L)
{
    if(L)
    {
        return L->dato;
    }else{
        return indef;
    }
}
void insertar(LISTA * L, int valor )
{
    Nodo * nuevo = malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *L;
    *L = nuevo;
}
void borrar(LISTA * L)
{
    Nodo * aux = *L;
    if(aux)
    {
        *L = (*L)->siguiente;
        free(aux);
    }
}
int longitud(LISTA L)
{
    int largo = 0;
    while(L)
    {
        largo ++;
        L = L->siguiente;
    }
    return largo;
}
int pertenece(LISTA L, int buscado)
{
    while (L &&  buscado != L->dato)
    {
        L = L->siguiente;
    }
    return L != NULL;
}
void borrarUltimo(LISTA * L)
{
    Nodo * previo = *L, * actual = *L; 
    while (actual && actual->siguiente)
    {
        previo = actual;
        actual = actual->siguiente;
    }
    if (previo == actual)
    {
        *L = NULL;
    }else{
        previo->siguiente = actual->siguiente;
        free(actual);
    }
}
int iguales(LISTA * A, LISTA * B)
{
    while (!esListaVacia(*A) && !esListaVacia(*B) && (primerElemento(*A) == primerElemento(*B)))
    {
        borrar(A);
        borrar(B);
    }
    return esListaVacia(*A) && esListaVacia(*B);
}
