#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void alphabet_counter(char fileName[], int alphabet[]);

int main(){

    int alphabet[26] = {0};
    char fileName[50];

    fgets(fileName, 50, stdin);
    fileName[strlen(fileName)-1] = '\0';

    alphabet_counter(fileName, alphabet);

    for (int i = 0; i < 26; i++){
        printf("%c ou %c = %d\n", ('a'+i), ('A'+i), alphabet[i]);
    }
    

    return 0;
}

void alphabet_counter(char fileName[], int alphabet[]){
    char c;
    FILE *f;
    f = fopen(fileName, "r");
    if (f == NULL){
        printf("ERRO!\n");
    } else {
        for (c = fgetc(f); c != EOF; c = fgetc(f)){
            if ((c >= 'a') && (c <= 'z')){
                alphabet[c - 'a']++;
            } else if ((c >= 'A') && (c <= 'Z')){
                alphabet[c - 'A']++;
            }
        }
    }
    fclose(f);
}