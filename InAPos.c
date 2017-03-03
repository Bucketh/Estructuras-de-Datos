#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"Pila.h"

void InAPos(char *pal){
    Elem c;
    Pila op = empty();
    int i = 0;

    while(c = pal[i]){
        if(operando(c)){
            ImpElem(c);
        }
        else    if(isempty(op)||pi(top(op))){
                    op = push(c, op);
                }
                else    if(pi(c)){
                            op = push(c,op);
                        }
                        else    if(pd(c)){
                                    while(!pi(top(op))){
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
                                    op = push(op);
                                }
    }
    i++;

    while(!isempty(op)){
        ImpElem(top(op));
        op = pop(op);
    }
}
