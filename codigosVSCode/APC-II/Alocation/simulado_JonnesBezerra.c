#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[21];
    int registry;
    float *scores, average;
} Student;

float averageCalculation(float scores[], int qtt_scores);

int main(){

    Student *class;
    int n, qtt_scores;

    printf("Quantos alunos tem na turma: ");
    scanf("%d", &n);
    class = (Student *) malloc(n * sizeof(Student)); //alocando o vetor class dinamicamente

    for (int i = 0; i < n; i++){
        printf("Insira os dados do aluno %d\n", i+1);
        printf("Nome: ");
        scanf("%s", &class[i].name[0]); //no linux só funciona se colocar name[0], mas o Win aceita colocar só name
        printf("Matricula: ");
        scanf("%d", &class[i].registry);
        printf("Quantidade de Notas do aluno: ");
        scanf("%d", &qtt_scores);
        class[i].scores = (float *) malloc(qtt_scores * sizeof(float)); //alocando o vetor de notas dinamicamente
        for (int j = 0; j < qtt_scores; j++){
            printf("Digite a nota %d: ", j+1);
            scanf("%f", &class[i].scores[j]);
        }
        class[i].average = averageCalculation(class[i].scores, qtt_scores);
    }

    for (int i = 0; i < n; i++){
        printf("-----------------------------\n");
        printf("Aluno %d:\n", i+1);
        printf("Nome: %s\n", class[i].name);
        printf("Matricula: %d\n", class[i].registry);
        printf("Media: %.2f\n", class[i].average);
    }

    return 0;
}

float averageCalculation(float scores[], int qtt_scores){
    float sum = 0;
    for (int i = 0; i < qtt_scores; i++){
        sum += scores[i];
    }
    return (sum / qtt_scores);
}