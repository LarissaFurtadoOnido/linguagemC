/*Elabore um algoritmo que leia um número r, calcule e imprima o comprimento da circunferência, a
área do círculo e o volume da esfera de raio r, dados por C = 2πr, A = r2 e V = 4/3πr3, respectivamente
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14

int main(){
    double raio, area, volume, comp;

    printf("Forneça o raio da circunferência: ");
    scanf("%lf", &raio);

    comp = 2 * PI * raio;
    area = raio * 2;
    volume = 4.0/3 * PI * pow(raio, 3);

    printf("Área = %lf\nComprimento = %lf\nVolume = %lf", area, comp, volume);

    return 0;
}