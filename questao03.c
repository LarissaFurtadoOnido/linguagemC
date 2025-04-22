/*Faça um programa que receba um número de três dígitos e verifique:
• Se os dígitos são todos diferentes
• Se a soma dos dois primeiros é igual ao terceiro
• Se o número invertido (sem usar string) é múltiplo de 7*/

#include <stdio.h>

int main(){
    int num1, num2, num3, numero;
    
    printf("Forneça o primeiro dígito: ");
    scanf("%d", &num1);
    printf("Forneça o segundo dígito: ");
    scanf("%d", &num2);
    printf("Forneça o terceiro dígito: ");
    scanf("%d", &num3);
    
    if(num1 != num2 && num1 != num3 && num2 != num3)
        printf("\nTodos os dígitos são diferentes!\n");
        
    if(num1+num2==num3)
        printf("\n%d + %d = %d", num1, num2, num3);
        
    else if(num1+num3==num2)
        printf("\n%d + %d = %d", num1, num3, num2);
     
    else if(num3+num2==num1)
        printf("\n%d + %d = %d", num3, num2, num1);
        
    numero = num3*100+num2*10+num1;
    
    if(numero%7==0)
        printf("\nO número invertido %d é múltiplo por 7!", numero);
    

    return 0;
}