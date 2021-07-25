#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int vowels_counter(char fileName[]);

int main(){

    char fileName[50];
    int vowels = 0;

    fgets(fileName, 50, stdin);
    fileName[strlen(fileName) - 1] = '\0';

    vowels = vowels_counter(fileName);

    printf("Quantidade de vogais no arquivo: %d\n", vowels);

    return 0;
}

int vowels_counter(char fileName[]){
    FILE *f;
    int vowels = 0;
    f = fopen(fileName, "r");

    if (f == NULL){
        printf("ERRO!\n");
    } else {
        char c;
        for (c = fgetc(f); c != EOF; c = fgetc(f)){
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vowels++;
            } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                vowels++;
            }
        }
    }
    fclose(f);
    return vowels;
}