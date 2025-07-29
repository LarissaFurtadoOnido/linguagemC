/*Implemente uma função que receba duas strings: uma string principal e uma substring. A função
deve procurar a primeira ocorrência da substring dentro da string principal e retornar sua posição
inicial (índice). Caso a substring não seja encontrada, a função deve retornar -1.
Observação: Não é permitido utilizar a função strstr da biblioteca padrão. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void converteMaiuscula(char *s){
    int i, tam = strlen(s);
    for(i=0;i<tam;i++){
        s[i]=toupper(s[i]);
    }
}

void limparEnter(char *s){
    s[strcspn(s, "\n")] = '\0';
}

char * EncontrarSubstring(char *str, char *substr){
    int i, k;
    limpaEnter(str);
    limpaEnter(substr);
    converteMaiusculo(str);
    converteMaiusculo(substr);
    for(i=0; str[i]!='\0'; i++){
        for(k=0; substr[k]!='\0'; k++){
            if(str[i+k]!=substr[k])
                break;
        }
        if(k==strlen(str2))
            return &str1[i];
    }
    return NULL;
}

int main() {
    char frase[] = {"Text aqui!"};
    char sub[] = {"qui"};

    char encontrou = EncontrarSubstring(frase, sub);

    if (encontrou != NULL) {
        printf("Substring encontrada no índice %d.\n", encontrou);
    } else {
        printf("Substring não encontrada.\n");
    }

    return 0;
}
