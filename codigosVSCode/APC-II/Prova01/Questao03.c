#include<stdio.h>
#include<stdlib.h>

typedef struct funcionario {
    long int matricula;
    float salario_bruto;
    int carga_horaria;
} funcionario;

void mostrar_funcionarios(funcionario f[], int qtd);
void delete_funcionario(funcionario f[], int qtd);
int menu();
void novo_funcionario(funcionario *novo);
void inclui_funcionario(funcionario f[], funcionario novo, int qtd);

int main(){
    int qtd_funcionario = 0, opcao;
    funcionario funcionarios[10], novo;

    do{
        opcao = menu();
        switch (opcao){
            case 1:
                novo_funcionario(&novo);
                inclui_funcionario(funcionarios, novo, qtd_funcionario);
                qtd_funcionario++;
                break;
            case 2:
                delete_funcionario(funcionarios, qtd_funcionario);
                qtd_funcionario--;
                break;
            case 3:
                mostrar_funcionarios(funcionarios, qtd_funcionario);
                break;
            case 4:
                break;
            default:
                printf("!!!Opção invalida!!!");
                break;
        }
    } while (opcao != 4);

    return 0;
}

void mostrar_funcionarios(funcionario f[], int qtd){
    float soma_salario = 0.00, media = 0.00, calc = 0.00;
    printf("Lista de todos os Funcionarios:\n");
    for (int i = 0; i < qtd; i++){
        printf("--------------------------------------\n");
        printf("Funcionario %d\n", i+1);
        printf("Matricula: %ld\n", f[i].matricula);
        printf("Salario Bruto: $%.2f\n", f[i].salario_bruto);
        printf("Carga Horaria: %d\n", f[i].carga_horaria);
        printf("--------------------------------------\n");
        soma_salario += f[i].salario_bruto;
        calc += (f[i].salario_bruto/(float)f[i].carga_horaria);
    }
    media = calc/(float)qtd;
    printf("Soma de todos os salarios brutos: %.2f\n", soma_salario);
    printf("Valor medio da hora da empresa: $%.2f\n", media);
    printf("--------------------------------------\n");
}

void delete_funcionario(funcionario f[], int qtd){
    long int matri;
    printf("Digite a matricula do Funcionario que deseja deletar: ");
    scanf("%ld", &matri);
    for (int i = 0; i < qtd; i++){
        if (matri == f[i].matricula){
            for(int j = i; j < qtd-1; j++){
                f[j] = f[j + 1];
            }
        }
    }
    printf("Funcionario deletado com sucesso!\n");
}

int menu(){
    int opcao;
    printf("1 - Incluir funcionario\n");
    printf("2 - Remover funcionario\n");
    printf("3 - Mostrar folha de pagamento\n");
    printf("4 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

void novo_funcionario(funcionario *novo){
    printf("Preencha o cadastro do novo funcionario:\n");
    printf("Insira a Matricula: ");
    scanf("%ld", &novo->matricula);
    printf("Insira o Salario Bruto: $");
    scanf("%f", &novo->salario_bruto);
    printf("Insira a Carga Horaria: ");
    scanf("%d", &novo->carga_horaria);
}

void inclui_funcionario(funcionario f[], funcionario novo, int qtd){
    f[qtd] = novo;
}