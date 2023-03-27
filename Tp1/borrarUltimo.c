#include<stdio.h>
#include<stdlib.h>
//    1
    struct Nodo{
        int dato;
        struct Nodo* siguiente;
    }; 
    typedef struct Nodo* LISTA;

// // 2
LISTA crearLista();
int esListaVacia(LISTA L);
void mostrar(LISTA L);
LISTA insertar(LISTA L, int datoNodo);
int longitud(LISTA L);
LISTA borrarUltimo(LISTA L);



/////////
void main(){
    LISTA A = crearLista();
    A = insertar(A, 2);
    A = insertar(A, 4);
    A = insertar(A, 5);
    mostrar(A);
    A = borrarUltimo(A);
    mostrar(A);



}
LISTA crearLista(){
    return NULL;
}
// // // B
int esListaVacia( LISTA L){
    return L == NULL;
}
// // // C
void mostrar(LISTA L){
    if (esListaVacia(L)){
        printf("La lista esta vacia\n");
    };
    while (!esListaVacia(L)){
        printf("%d \n", L->dato);
        L = L->siguiente;
    } ;
    printf("\n");
}

// // // E
LISTA insertar(LISTA L, int datoNodo){
    LISTA Nuevo;
    Nuevo = (LISTA)malloc(sizeof(LISTA));
    Nuevo->dato = datoNodo;
    Nuevo->siguiente = L; 
    L = Nuevo;
    return L;
    // return Nuevo;
}


// // // G
int longitud(LISTA L){
    int cant = 0;
    while (!esListaVacia(L)){
        cant ++;
        L = L->siguiente;
    }
    return cant;
}


// // // I
LISTA borrarUltimo(LISTA L){
    switch (longitud(L))
    {
    case 0:
        return L;
        break;
    case 1:
        free(L);
        return NULL;
        break;
    default:
        LISTA previo = L, ultimo=L->siguiente;
        while (ultimo->siguiente!=NULL)
        {
            previo = ultimo;
            ultimo = previo->siguiente;
        }
        free(ultimo);
        previo->siguiente = NULL;
        return L;
        break;
    }
}