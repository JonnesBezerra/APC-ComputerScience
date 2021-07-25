#include <stdlib.h>
#include <stdio.h>

typedef struct aluno {
    char nome[8];
    int idade;
    float media;
} aluno;

int main(){

    aluno *turma;
    int qtt;

    scanf("%d", &qtt);

    turma = (aluno *) malloc(qtt * sizeof(aluno));

    for (int i = 0; i < qtt; i++){
        scanf("%s", &turma[i].nome);
        scanf("%d", &turma[i].idade);
        scanf("%f", &turma[i].media);
    }

    for (int i = 0; i < qtt; i++){
        printf("%s\n", turma[i].nome);
        printf("%d\n", turma[i].idade);
        printf("%.2f\n", turma[i].media);
    }
    

    return 0;
}