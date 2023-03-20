#include<stdio.h>
#include<stdlib.h>
//    1
    typedef int tipo;

    struct Nodo{
        tipo dato;
        LISTA* siguiente;
    }; 
    typedef struct Nodo* LISTA;

// // 2
LISTA crearLista();
int esListaVacia(LISTA L);
void mostrar(LISTA L);
void primerElemento(LISTA L);
LISTA insertar(LISTA L, tipo datoNodo);
LISTA borrar(LISTA L);


/////////
void main(){

    // LISTA A = crearLista();
    
    // printf("%d\n", esListaVacia(A));
    // mostrar(A);

    // LISTA B;
    // A = &B;
    // A->dato = 13;
    // A->siguiente = crearLista();
    // mostrar(A);
}
/////////
// // 2
// // // A
LISTA crearLista(){
    return NULL;
}
// // // B
int esListaVacia( LISTA L){
    return L == NULL;
}
// // // C
void mostrar(LISTA L){
    if (!esListaVacia(L)){
        while (!esListaVacia(L)){
            if (sizeof(tipo) == sizeof(int)){
                printf("%d \n", L->dato);
            } else if (sizeof(tipo) == sizeof(char))
            {
                printf("%s \n", L->dato);
            }
            L = L->siguiente;
        }
    }else{
        printf("La lista está vacia\n");
    };
}
// // // D
void primerElemento(LISTA L){
    if (!esListaVacia(L)){
        if (sizeof(tipo) == sizeof(int)){
            printf("%d \n", L->dato);
        } else if (sizeof(tipo) == sizeof(char))
        {
            printf("%s \n", L->dato);
        }
    }else{
        printf("La lista está vacia\n");
    };
}
// // // E
LISTA insertar(LISTA L, tipo datoNodo){
    LISTA Nuevo;
    Nuevo = malloc(sizeof(LISTA));
    Nuevo->dato = datoNodo;
    Nuevo->siguiente = L; 
    L = Nuevo;
    return L;
}

// // // F
LISTA borrar(LISTA L){
    if (!esListaVacia(L)){
        LISTA aux;
        aux = L;
        L = L->siguiente;
        free(aux);
    }else{
        printf("La lista está vacia\n");
    };
}
// // // G

// // // H
// // // I
