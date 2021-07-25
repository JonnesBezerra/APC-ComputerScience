#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char word[100];

    printf("Digite uma palavra: ");
    fgets(word, 100, stdin);
    word[strlen(word)-1] = '\0';

    printf("Palavra ao contrario:");
    for (int i = strlen(word); i >= 0; i--){
        printf("%c", word[i]);
    }
    printf("\n");

    return 0;
}