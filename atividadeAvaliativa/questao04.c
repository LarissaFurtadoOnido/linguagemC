/*As tarifas de certo parque de estacionamento são as seguintes:
• 1 a e 2a hora - R$ 1,00 cada
• 3 a e 4a hora - R$ 1,40 cada
• 5 a hora e seguintes - R$ 2,00 cada

O número de horas a pagará e sempre inteiro e arredondado por excesso. Deste modo, quem
estacionar durante 61 minutos pagara por duas horas, que é o mesmo que pagaria se tivesse
permanecido 120 minutos. Os momentos de chegada ao parque e partida deste são apresentados na
forma de pares de inteiros, representando horas e minutos. Por exemplo, o par 12 50 representa
“dez para a uma da tarde”. Pretende-se criar um programa que, lidos pelo teclado os momentos de
chegada e de partida, escreva na tela o preço cobrado pelo estacionamento. Admite-se que a
chegada e a partida se dão com intervalo não superior a 24 horas. Portanto, se uma dada hora de
chegada for superior a da partida, isso não é uma situação de erro, antes significará que a partida
ocorreu no dia seguinte ao da chegada.*/

#include <stdio.h>

#define TARIFA1 1.00
#define TARIFA2 1.40
#define TARIFA3 2.00

int main(){
    int horaE, minutoE, horaS, minutoS, minutoConvertido;
    int valorTotal, minutoTotal;
    float valorAPagar;
    
    printf("Forneça a hora e minutos de entrada, respectivamente: ");
    scanf("%d %d", &horaE, &minutoE);
    printf("Forneça a hora e minutos de saída, respectivamente: ");
    scanf("%d %d", &horaS, &minutoS);
    
    minutoConvertido = (horaS*60+minutoS) - (horaE*60+minutoE);
    valorTotal = (minutoConvertido/60);
    minutoTotal = (minutoConvertido%60);
    if (minutoTotal != 0) {
        valorTotal++;
    }
    if(valorTotal < 3){
        valorAPagar = valorTotal * TARIFA1;
    }else if(valorTotal < 5){
        valorAPagar = valorTotal * TARIFA2;
    }else {
        valorAPagar = valorTotal * TARIFA3;
    }
    
    printf("Valor total R$%.2f", valorAPagar);
    
    return 0;
}