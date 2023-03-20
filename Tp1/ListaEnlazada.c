#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//    1
    typedef int tipo;

    struct Nodo{
        tipo dato;
        struct Nodo* siguiente;
    }; 
    typedef struct Nodo* LISTA;

// // 2
LISTA crearLista();
int esListaVacia(LISTA L);
void mostrar(LISTA L);
/////////
void main(){

    LISTA A = crearLista();
    
    printf("%d", esListaVacia(A));

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
                printf("%d", L->dato);
            } else if (sizeof(tipo) == sizeof(char))
            {
                printf("%s", L->dato);
            }
            L = L->siguiente;
        }
    }else{
        printf("La lista está vacia");
    };
}
// // // D
// // // E
// // // F
// // // G
