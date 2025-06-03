/*conversão decimal para binário */

#include <stdio.h>
#include <math.h>

//converter decimal para binário, complemento de 2
void DecimalBinario(int binario[16], int num){
    int i, result, aux, temp=1;
    aux=num;
    if(num<0)
        num*=-1;
        
    for(i=0; i<16; i++){
        if(i==0){
            binario[i] = num%2;
            result = num/2;
        }else{
            binario[i] = result%2;
            result = result/2;
        }
    }
    
    if(aux<0){
        //usando complemento de 1 (1 vira 0 e 0 vira 1)
        for(i=0;i<16;i++){
            if(binario[i] == 1){
                binario[i] = 0;
                
            }else{
                binario[i] = 1;
            }
        }
        
        //somando o resultado do complemento de 1 com 1
        for(i=0;i<16;i++){
            //o temp nesse caso tambem serve para nao gerar valor errado, toda vez que for um vai ser verdadeiro e o valor vai ser alterado sem necessidade 
            if(binario[i] == 1 && temp == 1){
                binario[i] = 0;
                
            }else if(binario[i] == 0 && temp == 1){
                binario[i] = 1; 
                temp = 0; 
            }
        }
    }
}

//calculando os dois valores
void CalcularBinario(int binario1[16], int binario2[16], int soma[16]){
    int i, temp=0;
    for(i=0;i<16;i++){
        if(temp==0 && ((binario1[i]==0 && binario2[i]==1) || (binario1[i]==1 && binario2[i]==0))){
            soma[i] = 1;
            
        }else if(temp==0 && binario1[i]==1 && binario2[i]==1){
            soma[i]=0;
            temp=1;
        }else if(temp==0 && binario1[i]==0 && binario2[i]==0){
            soma[i] = binario1[i];
                
        }else if(temp==1 && ((binario1[i]==0 && binario2[i]==1) || (binario1[i]==1 && binario2[i]==0))){
            soma[i]=0;
        }else if(temp==1 && binario1[i]==1 && binario2[i]==1){
            soma[i]=1;
        }else{
            soma[i]=1;
            temp=0;
        }

    }
}

//converter binario para decimal
void BinarioDecimal(int binario[16], int *decimal){
    int i, temp=1;
    *decimal=0;
    //verifica se o número é negativo, se for converte usando complemento de 2
    if(binario[15] == 1){
        for(i=0;i<16;i++){
            if(binario[i] == 1){
                binario[i] = 0;
                
            }else{
                binario[i] = 1;
            }
        }
        
        for(i=0;i<16;i++){
            if(binario[i] == 1 && temp == 1){
                binario[i] = 0;
                
            }else if(binario[i] == 0 && temp == 1){
                binario[i] = 1; 
                temp = 0; 
            }
        }
        
        for(i=0;i<16;i++){
            *decimal += binario[i]*pow(2, i);
        }
        *decimal*=-1;//receber o sinal negativo
        
    }else{
        for(i=0;i<16;i++){
            *decimal += binario[i]*pow(2, i);
        } 
    }
    
}

//imprimir na tela o número binário
void ImprimirBinario(int binario[16]){
    int i;
    for(i=15;i>=0;i--){
        printf("%d", binario[i]);
    }
}

int main(){
    int num1, num2, binario1[16]={0}, binario2[16]={0}, i, opcao, decimal=0, soma[16]={0}, aux;
    
    do{
        printf("\nForneça o primeiro número: ");
        scanf("%d", &num1);
        printf("\nForneça o segundo número: ");
        scanf("%d", &num2);
        printf("Forneça a operação desejada: \n1-Soma\n2-Subtração\n");
        scanf("%d", &opcao);
        
        //chamada da função para converter o número decimal para binário
        DecimalBinario(binario1, num1);
        DecimalBinario(binario2, num2);
        
        if(opcao==1){
            ImprimirBinario(binario1);
            printf(" = %d", num1);
            printf("\n + \n");
            ImprimirBinario(binario2);
            
            printf(" = %d", num2);
            printf("\n----------------\n");
            
            //chamada da função para calcular os dois valores
            CalcularBinario(binario1, binario2, soma);
            ImprimirBinario(soma);
            
            //chamada da função para converter binario para decimal
            BinarioDecimal(soma, &decimal);
            printf(" = %d", decimal);

        }else if(opcao==2){
            //se o segundo número é maior que zero, o mesmo é convertido para negativo
            //se ele for negativo é convertido para poositivo (menos com menos da mais)
            if(num2>0 || num2<0){
                aux=num2;
                num2*=-1;
                DecimalBinario(binario2, num2);
            }
                
            ImprimirBinario(binario1);
            printf(" = %d", num1);
            printf("\n - \n");
            
            ImprimirBinario(binario2);
            printf(" = (%d)", aux);
            printf("\n----------------\n");
            
            //chamada da função para calcular os dois valores
            CalcularBinario(binario1, binario2, soma);
            ImprimirBinario(soma);
            
            //chamada da função para converter binario para decimal
            BinarioDecimal(soma, &decimal);
            printf(" = %d", decimal);
            
        }else
            printf("\nOpção inválida!!");


        printf("\nDeseja sair?\n1-Sim\n2-Não\n");
        scanf("%d", &opcao);
        
    }while(opcao!=1);
    
    return 0;
}