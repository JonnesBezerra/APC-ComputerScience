#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string[1000], c;
    int i;

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    printf("Insira o caractere a ser buscado: ");
    scanf("%c", &c);
    printf("Buscar a partir da posicao...: ");
    scanf("%d", &i);

    while ((string[i] != c) && string[i] != '\0'){
        i++;
    }

    printf("O caractere %c foi encontrado no indice %d\n", c, i);

    return 0;
}