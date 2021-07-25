//exerciciostruct4.c
/*
Faça um programa que armazene em um registro de dados (estrutura composta) os da-dos 
de um funcionario de uma empresa, compostos de: Matricula, Idade, Sexo (1 - M/2 - F), 
CPF, Data de Nascimento( outra struct), Codigo do Setor onde trabalha (0-99), 
e Salário.
Os dados devem ser digitados pelo usuário, armazenados na estrutura e exibidos na tela.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int day, month, year;
}date;

void generatesDate(date *D){
    srand(time(0));
    D->day = 1 + (rand() % 30);
    D->month = 1 + (rand() % 12);
    D->year = 1950 + (rand() % 49);
}

typedef struct {
    char name[21];
    long int registration;
    date birthday;
    int age;
    int gender;
    double cpf;
    int sectorCode;
    float salary;
} company;

int getSector();
void showOptions();
int getOption();
void addEmployee(company team[], company new, int teamSize);
void newEmployee(company *new);
void showTeam(company team[], int teamSize);

int main(){
    
    company team[10], new;
    int teamSize = 0, option;

    do{
        showOptions();
        option = getOption();
        switch (option){
            case 1:
                newEmployee(&new);
                addEmployee(team, new, teamSize);
                teamSize += 1;
                break;
            case 2:
                showTeam(team, teamSize);
                break;
            case 0:
                break;
        }
        
    } while(option != 0);

    return 0;    
}

void showOptions(){
    printf("To insert new employee press - 1.\n");
    printf("To show all team press ------- 2.\n");
    printf("To quit press ---------------- 0.\n");
}

int getOption(){
    int opt;
    printf("Option: ");
    scanf("%d", &opt);
    return opt;
}
    
void newEmployee(company *new){
    printf("Insert the new employee data::::\n");
    printf("Name: ");
    scanf("%s", &new->name);
    printf("Registration: ");
    scanf("%ld", &new->registration);
    printf("Date of Birth: ");
    generatesDate(&new->birthday);
    printf("%d / %d / %d\n", new->birthday.day, new->birthday.month, new->birthday.year);
    new->age = (2020 - new->birthday.year);
    printf("Age: %d\n", new->age);
    do{
        printf("Gender (1 - M/2 - F): ");
        scanf("%d", &new->gender);
    } while ((new->gender != 1) && (new->gender != 2));
    printf("CPF: ");
    scanf("%lf", &new->cpf);
    new->sectorCode = getSector();
    printf("Sector code: %d\n", new->sectorCode);
    printf("Salary: ");
    scanf("%f", &new->salary);
}

void addEmployee(company team[], company new, int teamSize){
    team[teamSize] = new;
}

void showTeam(company team[], int teamSize){
    printf("--------------------------------------\n");
    for (int i = 0; i < teamSize; i++){
        printf("Name: %s\n", team[i].name);
        printf("Registration: %.2ld\n", team[i].registration);
        printf("Birthday: %d/%d/%d\n", team[i].birthday.day, team[i].birthday.month, team[i].birthday.year);
        printf("Age: %d\n", team[i].age);
        if (team[i].gender == 1){
            printf("Gender: %d - Male\n", team[i].gender);
        } else {
            printf("Gender: %d - Female\n", team[i].gender);
        }
        printf("CPF: %.2lf\n", team[i].cpf);
        printf("Sector Code: %d\n", team[i].sectorCode);
        printf("Salary: %.2lf\n", team[i].salary);
        printf("--------------------------------------\n");
    }
}

int getSector(){
    srand(time(0));
    int sector;
    sector = (rand() % 100);
    return sector;
}