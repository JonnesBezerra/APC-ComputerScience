#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int character_occurrence(char fileName[], char charUser);

int main(){

    int occurence;
    char fileName[50], charUser;

    fgets(fileName, 50, stdin);
    fileName[strlen(fileName) -1] = '\0';

    charUser = fgetc(stdin);

    occurence = character_occurrence(fileName, charUser);

    printf("Quantas vezes o caractere [ %c ] aparece: %d", charUser, occurence);

    return 0;
}

int character_occurrence(char fileName[], char charUser){
    int times = 0;
    FILE *f;
    f = fopen(fileName, "r");
    if (f == NULL){
        printf("ERRO!");
    } else {
        char c;
        for (c = fgetc(f); c != EOF; c = fgetc(f)){
            if (c == charUser){
                times++;
            }
        }
    }
    fclose(f);
    return times;
}