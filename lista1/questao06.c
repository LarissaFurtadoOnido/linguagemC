/*Faça um programa que calcule a área e o perímetro de uma superfície retangular.*/

#include <stdio.h>

int main(){
    double area, perimetro, base, altura;

    printf("Forneça a base do retângulo: ");
    scanf("%lf", &base);
    printf("Forneça a altura do retângulo: ");
    scanf("%lf", &altura);

    area = base * altura;
    perimetro = 2*(base+altura);

    printf("Área = %lf\nPerímetro = %lf", area, perimetro);

    return 0;
}