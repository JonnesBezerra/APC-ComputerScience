#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int matr;
    char nome[33];
    float n1, n2, n3, media;
} aluno;

void media(char line[], aluno *a);

int main(){

    FILE *bf;
    char line[1000];
    aluno a;

    if ((bf = fopen("alunos.bin", "rb")) == NULL){
        printf("Erro no .bin!");
        exit(1);
    }

    while (fgets(line, 1000, bf) != NULL){
        media(line, &a);
        printf("matricula: %d nome: %s media: %.2f ", a.matr, a.nome, a.media);
        if (a.media >= 8.5){
            printf("excelente\n");
        } else if (a.media < 8.5 && a.media >= 7.0){
            printf("bom\n");
        } else if (a.media < 7.0){
            printf("preocupante\n");
        }
        
    }

    return 0;
}

void media(char line[], aluno *a){
    char matr[3], nome[30], n1[5], n2[5], n3[5];
    int i, j = 0;
    for (i = 0; i < 3; i++){
        matr[j++] = line[i];
    }
    a->matr = atoi(matr);

    i = strlen(line);
    printf("%d\n", i);
    for (i = 0; i < strlen(line); i++){
        if (((line[i] >= 'a') && (line[i] <= 'z')) || ((line[i] >= 'A') && (line[i] <= 'Z'))){
            a->nome[i] = line[i];
        }
    }
    a->nome[33] = '\0';

    for (i = 33; i < 38; i++){
        n1[i] = line[i];
    }
    a->n1 = atof(n1);

    for (i = 38; i < 43; i++){
        n2[i] = line[i];
    }
    a->n2 = atof(n2);

    for (i = 43; i < 48; i++){
        n3[i] = line[i];
    }
    a->n3 = atof(n3);

    a->media = ((a->n1 + a->n2 + a->n3) / 3);
    
}