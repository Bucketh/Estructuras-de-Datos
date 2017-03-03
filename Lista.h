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

int esvacia(Lista l){
    return l == NULL;
}

Lista InsOrden(Elem e, Lista l){
    if(esvacia(l)){
        return cons(e,l);
    }
    else    if(EsMenor(e,cabeza(l))){
                return cons(e,l);
            }
            else{
                return cons(cabeza(l),InsOrden(e,resto(l)));
            }
}

Lista Duplica(Lista l){
    if(esvacia(l)){
        return l;
    }
    else{
        return cons(cabeza(l)*2, Duplica(resto(l)));
    }
}

int EstaEn(Elem e, Lista l){
    if(esvacia(l)){
        return 0;
    }
    else    if(SonIgualesE(e, cabeza(l))){
                return 1
            }
            else{
                return EstaEn(e, resto(l));
            }
}
