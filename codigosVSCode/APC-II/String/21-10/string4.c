#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[30];
    int count = 0;

    printf("Digite a string: ");
    fgets(string, 30, stdin);
    string[strlen(string)-1] = '\0';

    for (int i = 0; i < strlen(string); i++){
        if (string[i] == '1'){
            count++;
        }
    }

    printf("%s -> %d\n", string, count);

    return 0;
}