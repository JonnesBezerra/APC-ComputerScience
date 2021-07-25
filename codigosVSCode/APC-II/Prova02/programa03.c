#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data{
    int dia, mes, ano;
} data;

typedef struct carro{
    int ano;
    char modelo[30], marca[30];
    data * revisoes;
    int qtd_revisoes;
} carro;

void show_revisoes(carro cars[], int xRevisoes, int qtt);
void read_car(carro *car);

int main(){

    carro *nCars;
    int qtdCars, xRevisoes;

    printf("Digite quantos carros: ");
    scanf("%d", &qtdCars);
    fflush(stdin);
    nCars = (carro *) malloc(qtdCars * sizeof(carro));

    for (int i = 0; i < qtdCars; i++){
        printf("Carro %d\n", i+1);
        read_car(&nCars[i]);
    }

    printf("Digite um numero de revisoes: ");
    scanf("%d", &xRevisoes);

    show_revisoes(nCars, xRevisoes, qtdCars);

    return 0;
}

void show_revisoes(carro cars[], int xRevisoes, int qtt){
    printf("Carros que passaram por %d revisoes:::\n", xRevisoes);
    for (int i = 0; i < qtt; i++){
        if (cars[i].qtd_revisoes == xRevisoes){
            printf("Marca: %s\n", cars[i].marca);
            printf("Modelo: %s\n", cars[i].modelo);
            printf("Ano: %d\n", cars[i].ano);
            printf("Quantidade de revisoes: %d\n", cars[i].qtd_revisoes);
            for (int j = 0; j < cars[i].qtd_revisoes; j++){
                printf("Revisao %d: ", j+1);
                printf("%d/%d/%d\n", cars[i].revisoes[j].dia, cars[i].revisoes[j].mes, cars[i].revisoes[j].ano);
            }
            printf("----------------\n");
        }
    }
    
}

void read_car(carro *car){
    printf("Marca: ");
    fgets(car->marca, 30, stdin);
    fflush(stdin);
    car->marca[strlen(car->marca) - 1] = '\0';
    
    printf("Modelo: ");
    fgets(car->modelo, 30, stdin);
    fflush(stdin);
    car->modelo[strlen(car->modelo) - 1] = '\0';
    
    printf("Ano: ");
    scanf("%d", &car->ano);
    fflush(stdin);

    printf("Quantidade de revisoes: ");
    scanf("%d", &car->qtd_revisoes);
    fflush(stdin);

    car->revisoes = (data *) malloc(car->qtd_revisoes * sizeof(data));

    for (int j = 0; j < car->qtd_revisoes; j++){
        printf("Data da revisao %d: ", j+1);
        scanf("%d/%d/%d", &car->revisoes[j].dia, &car->revisoes[j].mes, &car->revisoes[j].ano);
        fflush(stdin);
    }
    
}