/*Faça um programa em C que leia dois pontos P1 = (x1; y1) e P2 = (x2; y2) e, calcule e imprima a
distância entre esses dois pontos, cujo valor e dado pela seguinte fórmula:
d = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2))
*/

#include <stdio.h>
#include <math.h>

int main(){
    double x1, y1, x2, y2, distancia;

    printf("Forneça o x1 do primeiro ponto: ");
    scanf("%lf", &x1);
    printf("Forneça o y1 do primeiro ponto: ");
    scanf("%lf", &y1);
    printf("Forneça o x2 do segundo ponto: ");
    scanf("%lf", &x2);
    printf("Forneça o y2 do segundo ponto: ");
    scanf("%lf", &y2);

    distancia = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));

    printf("\nA distância dos pontos P1 = (%.2lf, %.2lf) e P2 = (%.2lf, %.2lf) é %.2lf\n", x1, y1, x2, y2, distancia);

    return 0;
}