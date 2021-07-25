#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char phrase1[1000], phrase2[1000];

    printf("Digite a frase 1: ");
    fgets(phrase1, sizeof(phrase1), stdin);
    printf("Digite a frase 2: ");
    fgets(phrase2, sizeof(phrase2), stdin);

    printf("Frase 1 invertida e trocando A por *:\n");
    int str = (strlen(phrase1)-2);
    while (str >= 0){
        if (phrase1[str] == 'A'){
            phrase1[str] = '*';
            printf("%c", phrase1[str]);
            str--;
        } else {
            printf("%c", phrase1[str]);
            str--;
        }
    }

    printf("\nFrase 2 invertida e trocando A por *:\n");
    str = (strlen(phrase2)-2);
    while (str >= 0){
        if (phrase2[str] == 'A'){
            phrase2[str] = '*';
            printf("%c", phrase2[str]);
            str--;
        } else {
            printf("%c", phrase2[str]);
            str--;
        }
    }

    

    return 0;
}