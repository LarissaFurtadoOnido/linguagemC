/*Questã0 02
Faça um programa que imprima os 100 primeiros inteiros positvos pares*/

#include <stdio.h>

int main(){
    int numero=0;
    
    while(numero <= 100){
        if(numero%2==0)
            printf("\n%d", numero);
            numero++;
    }
    
    

    return 0;
}
