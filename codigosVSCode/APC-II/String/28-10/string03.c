#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 
    char noVowels[100];

    printf("Digite algo com vogais: ");
    fgets(noVowels, 100, stdin);

    for (int i = 0; i < strlen(noVowels); i++){
        if (noVowels[i] == 'A' || noVowels[i] == 'E' || noVowels[i] == 'I' || noVowels[i] == 'O' || noVowels[i] == 'U'){
            for (int j = i; j < strlen(noVowels); j++){
                noVowels[j] = noVowels[j+1];
            }
            i--;
        }
        if (noVowels[i] == 'a' || noVowels[i] == 'e' || noVowels[i] == 'i' || noVowels[i] == 'o' || noVowels[i] == 'u'){
            for (int j = i; j < strlen(noVowels); j++){
                noVowels[j] = noVowels[j+1];
            }
            i--;
        }
    }

    printf("Palavra sem vogais: %s", noVowels);
    
    return 0;
}