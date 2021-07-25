#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char phrase[100];
    int count = 0;

    printf("Digite uma frase: ");
    fgets(phrase, 100, stdin);

    for (int i = 0; i < strlen(phrase); i++){
        if (phrase[i] == ' '){
            count++;
        }
    }

    printf("Quantidade de espacos na frase: %d\n", count);

    return 0;
}