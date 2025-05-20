/* Questão 21
 Faça um programa que tenha como entrada um conjunto não determinado de pares de valores a, b,
 e para cada par lido, obtém o M.D.C. e o M.M.C. de a,b, escrevendo-os juntamente com os valores
 lidos.*/

#include <stdio.h>

int main(){
    int a, b, mmc, mdc, result, auxA, auxB;
    
    printf("Forneça o valor de a: ");
    scanf("%d", &a);
    printf("Forneça o valor de b: ");
    scanf("%d", &b);
    
    auxA = a;
    auxB = b;
    
    while(auxB!=0){
        result = auxA % auxB;
        auxA = auxB;
        auxB = result;
    }
    
    mdc = auxA;
    mmc = (a*b)/mdc;
    
    printf("%d", mmc);
    printf("\n%d", mdc);

    return 0;
}