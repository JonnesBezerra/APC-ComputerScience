/*
Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas. 
Cada pessoa deve ser representada por uma struct dentro de um vetor. 
A data de nascimento também deve ser uma struct.
O nome e a altura de cada pessoa devem ser informados pelo teclado.
A geração da data de nascimento deve ser feita aleatoriamente através da função abaixo
*/
/*
    O programa deve, na tela de abertura, apresentar opções para:
    inserir um nome;
    listar todos os nomes e respectivas alturas;
    listar os nomes das pessoas que nasceram antes de uma certa data fornecida.
Cada uma destas opções deve ser implementada em uma função separada.
Para realizar o exercício, utilize como base o programa apresentado abaixo.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int dia, mes, ano;
} Data;

void CriaData(Data *D){
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 49);
    D->dia = 1 + (rand() % 30);
}

typedef struct Pessoa{
    long int matricula;
    char nome[21];
    float altura;
    Data nascimento;
} Pessoa;

void ImprimeTelaDeOpcoes();
int EscolheOpcao();
void LePessoaDeTeclado(Pessoa *p);
void AdicionaPessoa(Pessoa povo[], Pessoa p, int qtdPessoas, int *quantidade);
void LeDataDeTeclado(Data *dia);
void ImprimeMaisVelhos(Pessoa povo[], int qtdPessoas, Data dia);
void ImprimeTodasAsPessoas(Pessoa povo[], int qtdPessoas);
void quantidade(int *qtdPessoas);

int main(){
    Pessoa povo[10];
    Pessoa p;
    int opcao, qtdPessoas = 0;
    Data dia;

    ImprimeTelaDeOpcoes();
    do{
        opcao = EscolheOpcao();
        if (opcao == 1){
            LePessoaDeTeclado(&p);
            AdicionaPessoa(povo, p, qtdPessoas, &qtdPessoas);
        } else if (opcao == 2){
            ImprimeTodasAsPessoas(povo, qtdPessoas);
        } else if (opcao == 3){
            LeDataDeTeclado(&dia);
            ImprimeMaisVelhos(povo, qtdPessoas, dia);
        }
    } while (opcao != 4);
}

void ImprimeTelaDeOpcoes(){
    printf("----Selecione uma opcao:----\n");
    printf("Para inserir uma pessoa - 1\n");
    printf("Para listar pessoas     - 2\n");
    printf("Para filtrar por data   - 3\n");
    printf("Para sair               - 4\n");
}

int EscolheOpcao(){
    int opcao;
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void LePessoaDeTeclado(Pessoa *p){
    printf("Matricula: ");
    scanf("%ld", &p->matricula);
    printf("Nome: ");
    scanf("%s", &p->nome);
    printf("Altura: ");
    scanf("%f", &p->altura);
    printf("Data de Nascimento: ");
    CriaData(&p->nascimento);
    printf("%d / %d / %d \n", p->nascimento.dia, p->nascimento.mes,  p->nascimento.ano);
}

void AdicionaPessoa(Pessoa povo[], Pessoa p, int qtdPessoas, int *quantidade){
    povo[qtdPessoas].matricula = p.matricula;
    for (int i = 0; i < 21; i++){
        povo[qtdPessoas].nome[i] = p.nome[i];
    }
    povo[qtdPessoas].altura = p.altura;
    povo[qtdPessoas].nascimento.dia = p.nascimento.dia;
    povo[qtdPessoas].nascimento.mes = p.nascimento.mes;
    povo[qtdPessoas].nascimento.ano = p.nascimento.ano;
    *quantidade += 1;
}

void ImprimeTodasAsPessoas(Pessoa povo[], int qtdPessoas){
    for (int i = 0; i < 3; i++){
        printf("------------------------------\n");
        printf("Matricula: %ld\n", povo[i].matricula);
        printf("Nome: %s\n", povo[i].nome);
        printf("Altura: %f\n", povo[i].altura);
        printf("Data de Nascimento: %d/%d/%d\n", povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
        printf("------------------------------\n");
    }
}

void LeDataDeTeclado(Data *dia){
    printf("Digite um dia: ");
    scanf("%d", &dia->dia);
    printf("Digite um mes: ");
    scanf("%d", &dia->mes);
    printf("Digite um ano: ");
    scanf("%d", &dia->ano);
}

void ImprimeMaisVelhos(Pessoa povo[], int qtdPessoas, Data dia){
    for (int i = 0; i < qtdPessoas; i++){
        if (povo[i].nascimento.ano < dia.ano){
            printf("Nome: %s Data de Nascimento: %d/%d/%d \n", povo[i].nome, povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
        } else if ((povo[i].nascimento.ano == dia.ano) && (povo[i].nascimento.mes < dia.mes)){
            printf("Nome: %s Data de Nascimento: %d/%d/%d \n", povo[i].nome, povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
        } else if ((povo[i].nascimento.mes == dia.mes) && (povo[i].nascimento.dia < dia.dia)){
            printf("Nome: %s Data de Nascimento: %d/%d/%d \n", povo[i].nome, povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
        } else {
            printf("Ninguem nasceu antes desta data.\n");
        }
    }
}