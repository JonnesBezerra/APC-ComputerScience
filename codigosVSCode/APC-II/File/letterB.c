#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file;
    char line;
    int namesB = 0;

    file = fopen("nomes.txt", "r");

    if (file == NULL){
        printf("ERRO AO ABRIR O ARQUIVO!\n");
    } else {
        for (line = getc(file); line != EOF; line = getc(file)){
            if (line == 'B'){
                namesB++;
            }
        }
    }
    
    printf("A quantidade de nomes que iniciam com a letra B eh: %d\n", namesB);


    return 0;
}