#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file;
    char line;
    int lines1 = 0, lines2 = 0;

    file = fopen("file1.txt", "r");

    if (file == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!");
    } else {
        for (line = getc(file); line != EOF; line = getc(file)){
            if (line == '\n'){
                lines1++;
            }
        }
    }
    
    fclose(file);

    file = fopen("file2.txt", "r");

    if (file == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!");
        return 0;
    } else {
        for (line = getc(file); line != EOF; line = getc(file)){
            if (line == '\n'){
                lines2++;
            }
        }
    }

    fclose(file);

    if (lines1 == lines2){
        printf("file1.txt tem a mesma quantidade de linhas de file2.txt.\n");
    } else if (lines1 > lines2){
        printf("file1.txt tem mais linhas.\n");
    } else {
        printf("file2.txt tem mais linhas.\n");
    }

    return 0;

}