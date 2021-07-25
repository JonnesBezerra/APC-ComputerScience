#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *file;

    file = fopen("arq.txt", "w+");
    if (file == NULL){
        printf("ERRO AO ABRIR ARQUIVO!");
    } else {
        char c;
        while (c != '0'){
            c = fgetc(stdin);
            if (c != '0'){
                fprintf(file, "%c", c);
            }
        }
    }

    fclose(file);

    return 0;
}