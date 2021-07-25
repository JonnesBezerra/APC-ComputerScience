#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int line_counter(char fileName[]);

int main(){

    char fileName[100];
    int count = 0;

    fgets(fileName, 100, stdin);
    fileName[strlen(fileName) - 1] = '\0';

    count = line_counter(fileName);
    printf("Quantidade de linhas no arquivo: %d\n", count);

    return 0;
}

int line_counter(char fileName[]){
    int count = 0;
    FILE *f; // f de file
    f = fopen(fileName, "r");
    if (f == NULL){
        printf("ERRO!");
    } else {
        char c;
        for (c = fgetc(f); c != EOF; c = fgetc(f)){
            if (c == '\n'){
                count++;
            }
        }
    }
    fclose(f);
    return ++count;
}