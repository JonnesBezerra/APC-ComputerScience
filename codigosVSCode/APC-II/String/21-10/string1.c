#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    char name[30];
    int vowels = 0;

    printf("Digite o seu Nome: ");
    fgets(name, 30, stdin);

    for (int i = 0; i < strlen(name); i++){
        if (name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U'){
            vowels++;
        }
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u'){
            vowels++;
        }
    }

    printf("%d vogais.\n", vowels);

    return 0;
}