#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Counter {
    int vowels, consonants;
} Counter;

Counter vowels_counter(Counter *i, char fileName[]);

int main(){

    Counter i;
    char fileName[50];

    fgets(fileName, 50, stdin);
    fileName[strlen(fileName) - 1] = '\0';

    vowels_counter(&i, fileName);

    printf("Quantidade de vogais no arquivo: %d\n", i.vowels);
    printf("Quantidade de consoantes no arquivo: %d\n", i.consonants);

    return 0;
}

Counter vowels_counter(Counter *i, char fileName[]){
    FILE *f;
    f = fopen(fileName, "r");

    if (f == NULL){
        printf("ERRO!\n");
    } else {
        char c;
        for (c = fgetc(f); c != EOF; c = fgetc(f)){
            if ((c >= 'a') && (c <= 'z')){
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                    i->vowels++;
                } else {
                    i->consonants++;
                }
            } else if ((c >= 'A') && (c <= 'Z')){
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                    i->vowels++;
                } else {
                    i->consonants++;
                }
            }
        }
    }
    fclose(f);
}