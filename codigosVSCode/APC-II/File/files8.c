#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void change_vowels(char line[]);

int main(){

    char line[1000], fileName[50];
    FILE *inFile, *outFile;

    fgets(fileName, 50, stdin);
    fileName[strlen(fileName)-1] = '\0';

    inFile = fopen(fileName, "r");
    if (inFile == NULL){
        printf("ERRO!\n");
    } else {
        outFile = fopen("OutFile.txt", "a+");
        while (fgets(line, 1000, inFile) != NULL){
            change_vowels(line);
            fprintf(outFile,"%s", line);
        }
        fprintf(outFile, "\n");
    }
    fclose(inFile);
    fclose(outFile);

    return 0;
}

void change_vowels(char line[]){
    for (int i = 0; i < strlen(line); i++){
        if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u' || line[i] == 'A' || line[i] == 'E' || line[i] == 'I' || line[i] == 'O' || line[i] == 'U'){
            line[i] = '*';
        }
    }
    
}