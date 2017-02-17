#include "Elem.h"

typedef struct Nodo{
    Elem dato;
    struct Nodo *sig;
} *Lista;

Lista vacia(){
    return NULL;
}

Lista cons(Elem e, Lista l){
    Lista t = (Lista) malloc(sizeof(struct Nodo));

    t -> dato = e;
    t -> sig = l;

    return t;
}

Lista resto(Lista l){
    return l -> sig;
}

Elem cabeza(Lista l){
    return l -> dato;
}

Lista esvacia(Lista l){
    return l == NULL;
}
