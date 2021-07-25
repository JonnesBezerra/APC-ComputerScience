#include <stdio.h>
#include <stdlib.h>
// complete as funções restantes!
typedef struct aluno{
   int matricula;
   float notas[3];
} aluno;

void LeAluno(aluno *aluno);
void ImprimeTurma(aluno *turma);
float CalculaMediaAluno(float notas[]);

int main(){
    int i;
    float media;
    aluno turma[5];

    // LeAluno(.......);  // função que lê de teclado
    //                    // os dados do aluno
    for (i = 0; i < 5; i++){
        LeAluno(&turma[i]);
    }
    printf("\n");
    // ImprimeTurma(Turma); Função que imprime os dados de todos os alunos
    for (i = 0; i < 5; i++){
        printf("Aluno %d\n", i);
        ImprimeTurma(&turma[i]);
    }
    
    for(i=0; i < 5; i++){
        // media = CalculaMediaAluno(.......);// função que calcula a média das notas de um aluno
        media = CalculaMediaAluno(turma[i].notas);
        printf("Aluno %d  - Media = %.2f\n", turma[i].matricula, media); // imprime os dados do aluno
    }
    return 0;
}

void LeAluno(aluno *dados){
    printf("Matricula: ");
    scanf("%d", &dados->matricula);
    for (int j = 0; j < 3; j++){
        printf("Nota %d: ", j+1);
        scanf("%f", &dados->notas[j]);
    }
}

void ImprimeTurma(aluno *turma){
    printf("Matricula: %d\n", turma->matricula);
    for (int i = 0; i < 3; i++){
        printf("Nota %d: %.1f\n", i+1, turma->notas[i]);
    }
}

float CalculaMediaAluno(float notas[]){
    float soma = 0.0;
    for (int i = 0; i < 3; i++){
        soma += notas[i];
    }
    return soma/3.0;
}