#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_word(FILE *f, char word[]);

int main(){

    FILE *f;
    char sWord[40], fileName[50];


    printf("Digite uma palavra: ");
    fgets(sWord, 20, stdin);
    sWord[strlen(sWord) - 1] = '\0';

    printf("Digite o nome de um arquivo sem '.txt': ");
    fgets(fileName, 50, stdin);
    fileName[strlen(fileName) - 1] = '\0';
    strcat(fileName, ".txt");

    f = fopen(fileName, "r");

    get_word(f, sWord);
    

    return 0;
}

void get_word(FILE *f, char word[]){
    char c;
    for (fgetc(c)){
        int lineSize = strlen(fileLine);
        for (int i = 0; i < lineSize; i++){
            if (fileLine)
            {
                /* code */
            }
            
        }
                
    }
    
}