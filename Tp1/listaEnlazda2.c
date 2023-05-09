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
void borrar(LISTA * L); //borra el nodo del comienzo de la lista.
int longitud(LISTA L); //cuenta la cantidad de nodos que tiene una lista.
int pertenece(LISTA L, int buscado); //booleana, determina si un dato pertenece a la lista.
void borrarUltimo(LISTA * L); //borra el nodo del final de la lista.
int iguales(LISTA * L);


void main(){


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
        printf("\nLa lista esta vacia. ");
    }
    while (L)
    {
        printf(", %d", L->dato);
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
    if(aux){
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
    if (L)
    {
        return L->dato == buscado   
    }else{
        return 0;
    }
}
void borrarUltimo(LISTA * L){

}
int iguales(LISTA * L){

}
