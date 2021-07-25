#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char string[100];

    printf("Digite algo com 0: ");
    fgets(string, 100, stdin);

    int i = 0;
    while (string[i] != '\n'){
        if (string[i] == '0'){
            string[i] = '1';
        }
        i++;
    }

    printf("Nova string: %s", string);

    return 0;
}