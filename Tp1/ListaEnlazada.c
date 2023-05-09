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
int primerElemento(LISTA L);
LISTA insertar(LISTA L, int datoNodo);
LISTA borrar(LISTA L);
int longitud(LISTA L);
int pertenece(LISTA L, int dato);
LISTA borrarUltimo(LISTA L);

// // // // 3
int iguales(LISTA A, LISTA B);


/////////
void main(){
// // // // // 4
    LISTA A = crearLista();
    LISTA B = crearLista();
    LISTA C = crearLista();
    LISTA D = crearLista();//vacia
    LISTA E = crearLista();
    
    A = insertar(A, 7); // a = c
    B = insertar(B, 4);
    B = insertar(B, 5);
    C = insertar(C, 7);
    E = insertar(E, 6);
    E = insertar(E, 3);
    E = insertar(E, 9);

    if (esListaVacia(A)){
        printf("A esta vacia\n");
    }else if(esListaVacia(B)){
        printf("B esta vacia\n");
    }else if (esListaVacia(C)){
        printf("C esta vacia\n");
    }else if (esListaVacia(D)){
        printf("D esta vacia\n");
    }else if (esListaVacia(E)){
        printf("E esta vacia\n");
    }
    
    mostrar(A);
    mostrar(B);
    mostrar(C);
    mostrar(D);

    printf("Primer elemento: B: %d\n", primerElemento(B));
    
    printf("Pertenece a B el 5: ");
    if (pertenece(B, 5))
    {
        printf("si\n");
    }else{
        printf("no\n");
    }
    
    B = borrar(B);
    printf("Luego de borrar: Longitud B = %d \n",longitud(B));

    printf("Pertenece a B el 5: ");
    if (pertenece(B, 5))
    {
        printf("si\n");
    }else{
        printf("no\n");
    }
    printf("Mostrar E:\n");
    mostrar(E);
    printf("Antes de borrarUltimo: Longitud E = %d \n",longitud(E));
    E = borrarUltimo(E);
    printf("Luego de borrarUltimo: Longitud E = %d \n",longitud(E));
    mostrar(E);

    if (iguales(A,C))
    {
        printf("¡A y C son iguales!");
    }
    if (iguales(E,B))
    {
        printf("A y C son distintos");
    }
    
    C = borrarUltimo(C);
        if (iguales(A,C))
    {
        printf("¡Son iguales!");
    }
    if (iguales(E,B))
    {
        printf("algo esta mal");
    }
    
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
    if (esListaVacia(L)){
        printf("La lista esta vacia");
    };
    while (!esListaVacia(L)){
        printf("%d  ", L->dato);
        L = L->siguiente;
    } ;
    printf("\n");
}
// // // D
int primerElemento(LISTA L){
    if (!esListaVacia(L)){
        return L->dato;
    }else{
        // printf("La lista está vacia\n");
        return 0;
    };
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
int pertenece(LISTA L, int datoBuscado){
    while (!esListaVacia(L)){
        if (L->dato == datoBuscado){
            return 1;
        }
        L = L->siguiente;
    }
    return 0;
}

// // // I
LISTA borrarUltimo(LISTA L){
    LISTA previo = L, ultimo=L->siguiente;
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

// // // // 3
//dretorne verdadero si los contenidos de los nodos de las listas son iguales.
int iguales(LISTA A, LISTA B){
    if(longitud(A) == longitud(B) && longitud(A)>0)
    {
        do
        {
            if (primerElemento(A)!= primerElemento(B))
            {
                return 0;
            }
            A = borrar(A);
            B = borrar(B); 
        } while (!esListaVacia(A));
        return 1;
    }else
    {
        return 0;
    }
    
}