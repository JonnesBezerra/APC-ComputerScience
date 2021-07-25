#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Address{
    char street[50], district[50], complement[50], city[50], state[50], country[50];
    int number, cep;
}Address;

typedef struct Telephone{
    int ddd, number;
}Telephone;

typedef struct Date{
    int day, month, year;
}Date;

typedef struct Contact{
    char name[30], email[30], note[30];
    Address address;
    Telephone tel;
    Date birthday;
}Contact;

int main(){
    Contact agenda[100], newPerson;
    int qttPerson = 0, option;

    do{
        menu();
        option = getOption();
        switch (option){
            case 1:
                readPerson(&newPerson);
                break;
            case 2:
                char firstName[20];
                printf("Digite o nome que deseja buscar: ");
                scanf("%s", &firstName);
                searchByName(agenda, firstName);
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 0:
                /* code */
                break;
            default:
                break;
        }
    } while (option != 0);
    return 0;
}

void menu(){
    printf("Insert new contact ------------- 1\n");
    printf("Search by first name ----------- 2\n");
    printf("Search by birth month ---------- 3\n");
    printf("Search by birth day and month -- 4\n");
    printf("Delete a contact --------------- 5\n");
    printf("Quit --------------------------- 0\n");
}

int getOption(){
    int option;
    printf("Option: ");
    scanf("%d", &option);
    return option;
}

void search_First_Name(){
    for (int i = 0; i < 100; i++){
        
    }
}

void readPerson(Contact *new){
    printf("Nome: ");
    scanf("%s", &new->name);
    printf("E-mail: ");
    scanf("%s", &new->email);
    printf("Endereco: \n");
    printf("Rua: ");
    scanf("%s", &new->address.street);
    printf("Numero: ");
    scanf("%d", &new->address.number);
    printf("Complemento: ");
    scanf("%s", &new->address.complement);
    printf("Bairro: ");
    scanf("%s", &new->address.district);
    printf("CEP: ");
    scanf("%d", &new->address.cep);
    printf("Cidade: ");
    scanf("%s", &new->address.city);
    printf("Estado: ");
    scanf("%s", &new->address.state);
    printf("Pais: ");
    scanf("%s", &new->address.country);
    printf("Telefone: \n");
    printf("DDD: ");
    scanf("%d", &new->tel.ddd);
    printf("Numero: ");
    scanf("%d", &new->tel.number);
    printf("Data de Nascimento: ");
    scanf("%d/%d/%d", &new->birthday.day, &new->birthday.month, &new->birthday.year);
    printf("Observacao: ");
    scanf("%s", &new->note);
}

void addPerson(Contact agenda[], Contact new, int qtdPerson){
    agenda[qtdPerson] = new;
    
    
    
}

void searchByName(Contact agenda[], char firstName[]){
    char nameAux[20];
    int j;
    for (int i = 0; i < 100; i++){
        for (j = 0; j < strlen(agenda[i].name) && agenda[i].name[j] != ' '; j++){
            nameAux[j] = agenda[i].name[j];
        }
        nameAux[j] = '\0';
        
        if (strcmp(nameAux, firstName) == 0){
            showContact(agenda[i]);
        }
    }
}

void showContact(Contact c){
    int i;
    printf("-----------------------------------");
    printf("Nome: %s\n", c.name);
    printf("E-mail: %s\n", c.email);
    printf("Endereco-- \n");
    printf("Rua: %s\n", c.address.street);
    printf("Numero: %d\n", c.address.number);
    printf("Complemento: %s\n", c.address.complement);
    printf("Bairro: %s\n", c.address.district);
    printf("CEP: %d\n", c.address.cep);
    printf("Cidade: %s\n", c.address.city);
    printf("Estado: %s\n", c.address.state);
    printf("Pais: %s\n", c.address.country);
    printf("Telefone: %d %d\n", c.tel.ddd, c.tel.number);
    printf("Data de Nascimento: %d/%d/%d", c.birthday.day, c.birthday.month, c.birthday.year);
    printf("Observacao: %s", c.note);
    printf("-----------------------------------");
}