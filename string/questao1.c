/*Implemente uma função que receba duas strings: uma string principal e uma substring. A função
deve procurar a primeira ocorrência da substring dentro da string principal e retornar sua posição
inicial (índice). Caso a substring não seja encontrada, a função deve retornar -1.
Observação: Não é permitido utilizar a função strstr da biblioteca padrão. */

#include <stdio.h>
#include <string.h>

void limparEnter(char *s){
    s[strcspn(s, "\n")] = '\0';
}

int EncontrarSubstring(char *str, char *substr){
    int i, k;
    for(i=0; str[i]!='\0'; i++){
        for(k=0; substr[k]!='\0'; k++){
            if(str[i+k]!=substr[k])
                break;
        }
        if(substr[k]=='\0')
            return i;
    }
    return -1;
}

int main() {
    char texto[] = {"Text aqui!"};
    char procura[] = {"qui"};

    int pos = EncontrarSubstring(texto, procura);

    if (pos != -1) {
        printf("Substring encontrada no índice %d.\n", pos);
    } else {
        printf("Substring não encontrada.\n");
    }

    return 0;
}
