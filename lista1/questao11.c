/*Faça um programa para resolver um sistema de equações do primeiro grau.*/
/*ax  +(-) b = 0*/
#include <stdio.h>

int main(){
    float a, b, result;

    printf("Forneça o primeiro termo da equação (a): ");
    scanf("%f", &a);
    printf("Forneça o segundo termo da equação (b): ");
    scanf("%f", &b);
    
    result = b/a;

    printf("X = %.2f", result);

    return 0;
}