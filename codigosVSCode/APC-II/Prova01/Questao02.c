#include<stdio.h>
#include<stdlib.h>

typedef struct funcionario {
    long int matricula;
    float salario_bruto;
    int carga_horaria;
} funcionario;

void preenche_jack(funcionario *jack);
void mostra_jack(funcionario f);

int main(){

    funcionario jack;

    preenche_jack(&jack);
    mostra_jack(jack);

    return 0;
}

void preenche_jack(funcionario *jack){
    printf("Preencha o cadastro de Jack:\n");
    printf("Insira a Matricula de Jack: ");
    scanf("%ld", &jack->matricula);
    printf("Insira o Salario Bruto de Jack: ");
    scanf("%f", &jack->salario_bruto);
    printf("Insira a Carga Horaria de Jack: ");
    scanf("%d", &jack->carga_horaria);
}

void mostra_jack(funcionario f){
    printf("--------------------------------------\n");
    printf("Cadastro de Jack:\n");
    printf("Matricula: %ld\n", f.matricula);
    printf("Salario Bruto: %.2f\n", f.salario_bruto);
    printf("Carga Horaria: %d\n", f.carga_horaria);
    printf("--------------------------------------\n");
}