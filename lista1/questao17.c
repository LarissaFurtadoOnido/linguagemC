/*Faça um programa que leia um valor de hora (hora:minutos) e informe (calcule) o total de minutos
se passaram desde o início do dia. */

#include <stdio.h>

int main(){
    int horas, minutos, result;

    printf("Forneça as horas: ");
    scanf("%d", &horas);
    printf("Forneça os minutos: ");
    scanf("%d", &minutos);

    result = horas * 60 + minutos;

    printf("%d:%d = %d minutos", horas, minutos, result);

    return 0;
}