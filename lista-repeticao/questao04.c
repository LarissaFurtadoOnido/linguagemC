/*Questão 04
Faça um programa que imprima todos os números múltiplos de 5, no intervalo fechado de 1 a
500.*/

#include <stdio.h>

int main(){
    int numero=1;
    
    while(numero <= 500){
        if(numero%5==0)
            printf("%d ", numero);
        numero++;
    }
    
    

    return 0;
}
