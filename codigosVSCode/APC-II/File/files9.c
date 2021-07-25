#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void uppercase_converter(char line[]);

int main(){

    char line[1000], fileName[50];
    FILE *inFile, *outFile;

    printf("Input file name: ");
    fgets(fileName, 50, stdin);
    fileName[strlen(fileName)-1] = '\0';
    
    inFile = fopen(fileName, "r");
    if (inFile == NULL){
        printf("ERRO!");
    } else {
        printf("Output file name: ");
        fgets(fileName, 50, stdin);
        fileName[strlen(fileName)-1] = '\0';

        outFile = fopen(fileName, "w");

        while (fgets(line, 1000, inFile) != NULL){
            uppercase_converter(line);
            fprintf(outFile,"%s", line);
        }
    }
    fclose(inFile);
    fclose(outFile);

    return 0;
}

void uppercase_converter(char line[]){
    for (int i = 0; i < strlen(line); i++){
        line[i] = toupper(line[i]);
    }
    
}