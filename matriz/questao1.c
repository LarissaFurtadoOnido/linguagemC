/*Implemente uma função que preencha um vetor de strings(sem valores repetidos) até no máximo a
capacidade do vetor. A função deve retornar o vetor lido e o índice da última posição
preenchida(parâmetro por referência). Um programa para testar tal função também deve ser
implementado*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 100
#define TAMV 1000

int pesquisaRepetidos(char vetor[][TAM], int *ultimaPos, char v[]){
    int i;
    for(i=0;i<*ultimaPos;i++){
        if(strcmp(vetor[i], v)==0)
            return 1;
    }    
    return 0;
}

void lerMatriz(char vetor[][TAM], int tamanho, int *ultimaPos){
    int i=0, opcao;
    do{
        setbuf(stdin, NULL);
        printf("Forneça uma palavra: ");
        fgets(vetor[i], 100, stdin);
        setbuf(stdin, NULL);
        vetor[i][strcspn(vetor[i], "\n")]='\0';
        if(pesquisaRepetidos(vetor, &i, vetor[i])==1)
            printf("Nome repetido");
        else  
            i++;

        printf("\nDeseja sair? 1-Sim 2-Não\n");
        scanf("%d", &opcao);
        
        *ultimaPos=i;

    }while(opcao!=1 && i<tamanho-1);
}

int main() {
    char palavras[TAMV][TAM];
    int ultimaPos = 0;

    lerMatriz(palavras, TAMV, &ultimaPos);

    printf("\nPalavras inseridas:\n");
    for (int i = 0; i < ultimaPos; i++) {
        printf("%s\n", palavras[i]);
    }

    return 0;
}
