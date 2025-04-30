/*Questão 05
Faça um programa que receba quinze números inteiros positivos do usuário e imprima a soma da
raiz quadrada de cada número.*/

#include <stdio.h>
#include <math.h>

int main(){
    int numero, cont = 0;
    double soma = 0;
   
    while(cont < 3){
        printf("Forneça número inteiro maior que zero ou zero para sair: ");
        scanf("%d", &numero);
        if(numero > 0)
            soma += sqrt(numero);
        else
            break;
        
        cont++;
    }
    
    printf("\nSoma da raiz de quadrada de cada número é %.2lf", soma);
    
    

    return 0;
}
