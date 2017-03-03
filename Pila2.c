#include<stdio.h>
#include<stdlib.h>
#include"Pila.h"

int EsParIz(Elem e){
    return e=='(';
}

int EsBal(char *pal){
    int i = 0, pi = 1, c;
    Pila a = empty();

    while((c = *(pal + i))&&pi){
        if(EsParIz(c)){
            push(c,a);
        }
        else    if(isempty(a)){
                    pi = 0;
                }
                else a = pop(a);
        i++;
    }

    if(isempty(a)&&pi){
        return 0;
    }
    else    if(!isempty(a)&&pi){
                return 1;
            }
            else    if(isempty(a)&&!pi){
                        return -1;
                    }
}

int main(int argc, char *argv[]){
    char *pal = *(argv+1);
    int i;

    i = EsBal(pal);
    printf("%s esta ", pal);

    if(i == -1){
        puts("Des izq.");
    }
    else    if(i == 1){
                puts("Des der.");
            }
            else
                puts("Bal.");

    return 0;

}
