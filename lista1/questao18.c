/* Faça um programa que leia um número inteiro de 4 dígitos e imprima o digito da centena.*/

#include <stdio.h>

int main(){
    int num, centena;

    printf("Forneça um número de 4 dígitos: ");
    scanf("%d", &num);

    centena = (num / 100) % 10;

    printf("\nCentena = %d\n", centena);

    return 0;
}