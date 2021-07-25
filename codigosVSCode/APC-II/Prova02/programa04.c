#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Address{
    char street[50], nbhd[50], city[50], state[50];
    long int cep;
} Address;

typedef struct Form{
    char name[30];
    Address addr;
    float salary;
    long int id;
    long int cpf;
    char maritalStatus[20];
    long int telephone;
    int age;
    int gender;
} Form;

void menu(int *opcao);
void search_id(Form cad[], int reg);
void higher_wages(Form cad[], int reg);
void older_people(Form cad[], int reg);
void male_people(Form cad[], int reg);
void fill_form(Form *cad);

int main(){

    Form Cadastro[5];
    int manyRegistration, opcao, registered = 0;

    do{
        menu(&opcao);
        switch (opcao){
            case 1:
                do {
                    printf("Quantos cadastros deseja fazer? - max 5: ");
                    scanf("%d", &manyRegistration);
                    fflush(stdin);
                    if ((manyRegistration > 5) || (manyRegistration < 1)){
                        printf("Favor insira valores entre 1 e 5!\n");
                    } else if ((manyRegistration + registered) > 5){
                        printf("Numero de cadastros excede 5 cadastros!\n");
                        printf("Cadastrados ate agora: %d\n", registered);
                        break;
                    }
                } while ((manyRegistration > 5) || (manyRegistration < 1));

                if ((manyRegistration + registered) <= 5){
                    for (int i = 0; i < manyRegistration; i++){
                        printf("Cadastro %d\n", registered+1);
                        fill_form(&Cadastro[registered++]);
                    }
                }
                break;
            case 2:
                older_people(Cadastro, registered);
                break;
            case 3:
                male_people(Cadastro, registered);
                break;
            case 4:
                higher_wages(Cadastro, registered);
                break;
            case 5:
                search_id(Cadastro, registered);
                break;
            case 6:
                break;
            default:
                printf("!!!Opcao invalida!!!\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

void menu(int *opcao){
    printf("1 - Novo Cadastro\n");
    printf("2 - Mostrar pessoa de maior idade\n");
    printf("3 - Mostrar pessoas do sexo masculino\n");
    printf("4 - Mostrar pessoas com salario maior que R$1000.00\n");
    printf("5 - Pesquisar por identidade\n");
    printf("6 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", opcao);
}

void search_id(Form cad[], int reg){
    long int id;
    int aux = 0;
    printf("Insira o numero de identidade desejado: ");
    scanf("%ld", &id);
    printf("Resultado :::\n");
    for (int i = 0; i < reg; i++){
        if (cad[i].id == id){
            printf("Cadastro %d::::::\n", i);
            printf("Nome: %s\n", cad[i].name);
            printf("Endereco::\n");
            printf("Rua: %s\n", cad[i].addr.street);
            printf("Bairro: %s\n", cad[i].addr.nbhd);
            printf("Cidade: %s\n", cad[i].addr.city);
            printf("Estado: %s\n", cad[i].addr.state);
            printf("CEP: %ld\n", cad[i].addr.cep);
            printf("Salario: %.2f\n", cad[i].salary);
            printf("Identidade: %ld\n", cad[i].id);
            printf("CPF: %ld\n", cad[i].cpf);
            printf("Estado Civil: %s\n", cad[i].maritalStatus);
            printf("Telefone: %ld\n", cad[i].telephone);
            printf("Idade: %d\n", cad[i].age);
            if (cad[i].gender == 1){
                printf("Genero: Feminino\n");
            } else if (cad[i].gender == 2){
                printf("Genero: Masculino\n");
            } else {
                printf("Genero: Pefere Nao Declarar\n");
            }
            aux++;
        }
    }
    if (aux == 0){
        printf("Nenhuma identidade encontrada!\n");
    }
    
    
}

void higher_wages(Form cad[], int reg){
    printf("Pessoas com salario maior que R$1000.00:::\n");
    for (int i = 0; i < reg; i++){
        if (cad[i].salary > 1000.00){
            printf("Nome: %s\n", cad[i].name);
            printf("Salario: %.2f\n", cad[i].salary);
        }
    }
    
}

void male_people(Form cad[], int reg){
    printf("Pessoas do sexo masculino:::\n");
    for (int i = 0; i < reg; i++){
        if (cad[i].gender == 2){
            printf("Nome: %s\n", cad[i].name);
        }
    }
}

void older_people(Form cad[], int reg){
    Form people;
    people.age = 0;
    int older = 0;
    for (int i = 0; i < reg; i++){
        if (cad[i].age > people.age){
            people = cad[i];
        }
    }
    printf("Pessoa mais velha:::\n");
    printf("Nome: %s\n", people.name);
    printf("Idade: %d\n", people.age);
    
}

void fill_form(Form *cad){
    printf("Nome: ");
    fgets(cad->name, 30, stdin);
    fflush(stdin);
    cad->name[strlen(cad->name) - 1] = '\0';

    printf("Endereco::: \n");
    printf("Rua: ");
    fgets(cad->addr.street, 50, stdin);
    fflush(stdin);
    cad->addr.street[strlen(cad->addr.street) - 1] = '\0';
    printf("Bairro: ");
    fgets(cad->addr.nbhd, 50, stdin);
    fflush(stdin);
    cad->addr.nbhd[strlen(cad->addr.nbhd) - 1] = '\0';
    printf("Cidade: ");
    fgets(cad->addr.city, 50, stdin);
    fflush(stdin);
    cad->addr.city[strlen(cad->addr.city) - 1] = '\0';
    printf("Estado: ");
    fgets(cad->addr.state, 50, stdin);
    fflush(stdin);
    cad->addr.state[strlen(cad->addr.state) - 1] = '\0';
    printf("CEP: ");
    scanf("%ld", &cad->addr.cep);
    fflush(stdin);

    printf("Salario: ");
    scanf("%f", &cad->salary);
    fflush(stdin);

    printf("Identidade: ");
    scanf("%ld", &cad->id);
    fflush(stdin);
    
    printf("CPF: ");
    scanf("%ld", &cad->cpf);
    fflush(stdin);

    printf("Estado Civil: ");
    fgets(cad->maritalStatus, 20, stdin);
    fflush(stdin);
    cad->maritalStatus[strlen(cad->maritalStatus) - 1] = '\0';

    printf("Telefone: ");
    scanf("%ld", &cad->telephone);
    fflush(stdin);

    printf("Idade: ");
    scanf("%d", &cad->age);
    fflush(stdin);

    do {
        printf("Sexo - 1 para Feminino ou 2 para Masculino ou 3 se prefere Nao Declarar: ");
        scanf("%d", &cad->gender);
        fflush(stdin);
    } while ((cad->gender != 1) && (cad->gender != 2) && (cad->gender != 3));
    
}