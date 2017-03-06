#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"Pila.h"

int prior(char);
int EsParIz(char);
int EsParDer(char);
int EsDigito(char);

void InAPos(char *pal){
    Elem c;
    Pila op = empty();
    int i = 0;

    while(c = pal[i]){
        if(operando(c)){
            ImpElem(c);
        }
        else    if(isempty(op)||EsParIz(top(op))){
                    op = push(c, op);
                }
                else    if(EsParIz(c)){
                            op = push(c,op);
                        }
                        else    if(EsParDer(c)){
                                    while(!EsParIz(top(op))){
                                        ImpElem(top(op));
                                        op = pop(op);
                                    }
                                    op = pop(op);
                                }
                                else{
                                    while(prior(c)<=prior(top(op))){
                                        ImpElem(top(op));
                                        op = pop(op);
                                    }
                                    op = push(c,op);
                                }
    i++;
    }

    while(!isempty(op)){
        ImpElem(top(op));
        op = pop(op);
    }
}

int prior(char c){
    switch(c){
        case '+': 
            return 1;
            break;
        case '-': 
            return 1;
            break;
        case '/': 
            return 2;
            break;
        case '*': 
            return 2;
            break;
        case '^': 
            return 3;
            break;
    }
};

int EsParIz(char c){
    return '(';
};

int EsParDer(char c){
    return ')';
};

int EsDigito(char c){
    return (c >= 0) && (c <= 9);
};
