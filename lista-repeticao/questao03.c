/*Questão 03
Faça um programa que imprima todos os números inteiros de 200 a 100 (em ordem decrescente).*/

#include <stdio.h>

int main(){
    int numero=200;
    
    while(numero >= 100){
        printf("%d ", numero);
        numero--;
    }
    
    

    return 0;
}
