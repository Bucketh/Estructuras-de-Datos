#include"Elem.h"

typedef struct NODO{
    Elem dato;
    struct NODO *sig;
} *Pila;

Pila empty(){
    return NULL;
}

Pila push(Elem e, Pila p){
    Pila t = (Pila) malloc(sizeof(struct NODO));
    t -> dato = e;
    t -> sig = p;
    return t;
}

int isempty(Pila p){
    return p == NULL;
}

Elem top(Pila p){
    return p -> dato;
}

Pila pop(Pila p){
    return p -> sig;
}
