#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word1[1000], word2[1000];
    int i, str;

    printf("Digite a 1st palavra: ");
    fgets(word1, sizeof(word1), stdin);
    
    printf("Digite a 2nd palavra: ");
    fgets(word2, sizeof(word2), stdin);

    if (strlen(word1) < strlen(word2)){
        str = strlen(word1);
    } else {
        str = strlen(word2);
    }
    
    i = 0;
    while (i <= str){
        if (word1[i] < word2[i]){
            printf("A 1st palavra vem antes da 2nd na ordem alfabetica.");
            i = str+1;
        } else if (word2[i] < word1[i]){
            printf("A 2nd palavra vem antes da 1st na ordem alfabetica.");
            i = str+1;
        } else {
            i++;
        }
    }

    return 0;
}