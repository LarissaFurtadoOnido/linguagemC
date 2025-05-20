/*Questão 18
 Escrever um programa que leia uma quantidade desconhecida de números e conte quantos deles
 estão nos seguintes intervalos: [0.25], [26,50], [51,75] e [76,100]. A entrada de dados deve
 terminar quando for lido um número negativo.*/

#include <stdio.h>

int main(){
    int cont1=0,cont2=0,cont3=0,cont4=0, numero;
    
    printf("Forneça o número ou um número negativo para sair: ");
    scanf("%d", &numero);
    
    while(numero>=0){
        if(numero<=25){
            cont1++;
        }else if(numero<=50)
            cont2++;
        else if(numero<=75)
            cont3++;
        else if(numero<=100)
            cont4++;
        else
            printf("Valor maior que 100!");
        
        printf("Forneça o número ou um número negativo para sair: ");
        scanf("%d", &numero);
    }
    
    printf("\nQuantidade de números no intervalo [0,25] = %d", cont1);
    printf("\nQuantidade de números no intervalo [26,50] = %d", cont2);
    printf("\nQuantidade de números no intervalo [51,75] = %d", cont3);
    printf("\nQuantidade de números no intervalo [76,100] = %d", cont4);
    
    return 0;
}