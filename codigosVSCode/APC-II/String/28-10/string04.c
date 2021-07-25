#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 
    char word[100], replace;
    int count = 0;

    printf("Digite uma palavra: ");
    fgets(word, 100, stdin);

    for (int i = 0; i < strlen(word); i++){
        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'){
            count++;
        }
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
            count++;
        }
    }
    printf("Quantidade de vogais: %d\n", count);

    printf("Qual o caractere de substituicao de vogais: ");
    scanf("%c", &replace);

    for (int i = 0; i < strlen(word); i++){
        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'){
            word[i] = replace;
        }
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
            word[i] = replace;
        }
    }

    printf("Palavra com vogais substituidas: %s", word);
    
    return 0;
}