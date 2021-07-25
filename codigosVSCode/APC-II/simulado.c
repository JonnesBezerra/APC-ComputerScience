#include<stdio.h>
#include<stdlib.h>


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
    char name[21], email[30], note[30];
    Address address;
    Telephone tel;
    Date birthday;
}Contact;

int main(){
    Contact agenda[100], newPerson;
    int qttPerson = 0;

    return 0;
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