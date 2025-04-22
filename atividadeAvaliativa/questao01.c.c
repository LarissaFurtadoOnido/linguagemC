/*Dados três valores A, B e C, verificar se eles podem ser comprimentos de lados de um triângulo.
Caso formem, calcule e imprima:
• o tipo do triângulo, ou seja: equilátero: todos os 3 lados têm a mesma medida
                                isósceles: dois dos 3 lados têm a mesma medida
                                escaleno: os 3 lados têm medidas diferentes
                                
• a área e o perímetro do triângulo: area =  
Obs. o comprimento de um lado do triângulo é menor que a soma dos dois outros lados. */

#include <stdio.h>

int main(){
    float ladoA, ladoB, ladoC, altura, area, perimetro;
    
    printf("Forneça o comprimento do lado A do triângulo: ");
    scanf("%f", &ladoA);
    printf("Forneça o comprimento do lado B do triângulo: ");
    scanf("%f", &ladoB);
    printf("Forneça o comprimento do lado C (base) do triângulo: ");
    scanf("%f", &ladoC);
    printf("Forneça o comprimento da altura do triângulo: ");
    scanf("%f", &altura);
    
    if (((ladoA+ladoB) > ladoC) || ((ladoB+ladoC) > ladoA) || ((ladoA+ladoC) > ladoB)){
        if((ladoA == ladoB) && (ladoA == ladoC) && (ladoC == ladoB)){
            printf("\nTriângulo Equilátero");
            
        }else if((ladoA == ladoB) || (ladoA == ladoC) || (ladoC == ladoB)){
            printf("\nTriângulo Isósceles");
            
        }else
            printf("\nTriângulo Escaleno");
            
    }else
        printf("\nTriângulo não existe!");
        
    area = (ladoC * altura)/2;
    perimetro = ladoA + ladoB + ladoC;
    
    printf("\nÁrea do triângulo = %.2f\nPerímetro = %.2f", area, perimetro);
        
    return 0;
}