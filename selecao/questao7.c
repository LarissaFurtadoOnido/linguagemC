/*Faça um algoritmo que dada a idade de um nadador classifica-o em uma das seguintes categorias:
baby care = menos de 5 anos
infantil A = 5 - 7 anos
infantil B = 8-10 anos
juvenil A = 11-13 anos
juvenil B = 14-17 anos
adulto = maiores de 18 anos*/

#include <stdio.h>

int main(){
    int idade;
    
    printf("Forneça a idade do nadador: ");
    scanf("%d", &idade);
    
    if(idade < 0)
        printf("\nIdade inválida!"); 
        
    else if(idade < 5)
        printf("\nBaby care");
        
    else if(idade <= 7)
        printf("\nInfantil A");
        
    else if(idade <= 10)
        printf("\nInfantil B");
        
    else if(idade <= 13)
        printf("\nJuvenil A");
        
    else if(idade <= 17)
        printf("\nJuvenil B");
        
    else
        printf("\nAdulto");
    
    return 0;
}