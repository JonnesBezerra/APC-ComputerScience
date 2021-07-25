#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string1[30], string2[30];
    int aux = 0;

    printf("Digite a 1st String: ");
    fgets(string1, 30, stdin);
    printf("Digite a 2nd String: ");
    fgets(string2, 30, stdin);

    string1[strlen(string1)-1] = '\0';
    string2[strlen(string2)-1] = '\0';

    if (strlen(string1) == strlen(string2)){
        for (int i = 0; i < strlen(string1); i++){
            if (string1[i] != string2[i]){
                aux++;
            }
        }
    }

    if (aux != 0){
        printf("As strings nao sao iguais.\n");
    } else {
        printf("As strings sao iguais.\n");
    }
        
    return 0;
}