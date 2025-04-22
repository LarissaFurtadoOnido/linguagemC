/*Faça um algoritmo que leia uma temperatura em graus Fahrenheit e converta / mostre em graus
centígrados. Centígrados = (Fahrenheit – 32) * 5 / 9. */

#include <stdio.h>

int main(){
    float F, C;

    printf("Forneça a temperatura em graus Fahrenheit: ");
    scanf("%f", &F);

    C = (F - 32) * 5.0/9;

    printf("A temperatura em graus Fahrenheit %.2f em celsius é igual a %.2f graus Celsius");

    return 0;
}