#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE *f; // f de file

    f = fopen("arq.txt", "r");
    if (f == NULL){
        printf("Erro!");
    } else {
        char c;
        for (c = fgetc(f); c != EOF; c = fgetc(f)){
            printf("%c ", c);
        }
                
    }
    
    fclose(f);

    return 0;
}