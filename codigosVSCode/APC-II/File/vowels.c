#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *arq;

    char name[50], vowels[20];

    printf("Digite seu nome: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';

    int i, j = 0;
    for (i = 0; i < strlen(name); i++){
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u' || name[i] == 'A' || name[i] == 'E' || name[i] == 'I' || name[i] == 'O' || name[i] == 'U'){
            vowels[j++] = name[i];
        }
    }
    vowels[i] = '\0';

    arq = fopen("nome_do_usuario.txt", "w");
    if (arq == NULL){
        printf("ERRO AO ABRIR ARQUIVO!");
    } else {
        fprintf(arq, "%s", vowels);
    }
    
    return 0;
}