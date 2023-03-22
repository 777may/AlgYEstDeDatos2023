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
tipo primerElemento(LISTA L);
LISTA insertar(LISTA L, tipo datoNodo);
LISTA borrar(LISTA L);
int longitud(LISTA L);
int pertenece(LISTA L, tipo dato);
LISTA borrarUltimo(LISTA L);


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
tipo primerElemento(LISTA L){
    if (!esListaVacia(L)){
        return L->dato;
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
    return L;
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
// // // H
int pertenece(LISTA L, tipo datoBuscado){
    int valor = 0;
    while (!esListaVacia(L) && valor == 0){
        if (L->dato == datoBuscado){
            valor = 1;
        }
    }
    return valor;
}

// // // I
LISTA borrarUltimo(LISTA L){
    LISTA previo;
    while (!esListaVacia(L)){
        previo = L;
        L = L->siguiente;
    }
    free(L);
    return previo;
}

