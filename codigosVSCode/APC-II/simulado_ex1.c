#include <stdio.h>
#include <stdlib.h>

typedef struct contato{

  char nome[20];
  char email[20];

  char rua[20];
  int n_casa[10];
  char complemento[20];
  char bairro[20];
  int cep[10];
  char cidade[20];
  char estado [20];
  char pais[20];

  int ddd[5];
  int telefone[10];

  int dia;
  int mes;
  int ano;

  int contato_existente;

}contato;

int busca_por_primeiro_nome(contato * agenda);
//void busca_por_mes_de_aniversario(contato * agenda);
//void busca_por_dia_mes_de_anversario(contato * agenda);
void inserir_contato(contato * agenda);
//void deletar_contato(contato * agenda);
void menu();

int main(){

  contato agenda[100];
  char input;

  do{
    menu();
    scanf("%c", &input);
    if(input == 'c'){
      for(int i = 0; i < 100; i++){
        if(agenda[i].contato_existente == 1){
          int busca_completa = busca_por_primeiro_nome(&agenda[i]);
          if(busca_completa == 0){
            printf("Contato nao encontrado");
          }
          break;
        }
      }
    }
    //if(input == 'd'){
      //busca_por_mes_de_aniversario(&agenda[0]);
      //}
      //if(input == 'e'){
        //busca_por_dia_mes_de_anversario(&agenda[0]);
        //}
    if(input == 'f'){
      for(int i = 0; i < 100; i++){
        if(agenda[i].contato_existente == 0){
          inserir_contato(&agenda[i]);
          break;
        }
      }
    }
        //if(input == 'g'){
          //deletar_contato(&agenda[0]);

          //}
          //if(input == 'h'){

            //}

  }while(input != 'x');

  return 0;
}

void menu(){
  printf("Que funcao deseja acessar?\n");
  printf("(c) Buscar uma pessoa pelo primeiro nome\n");
  printf("(d) Buscar uma pessoa pelo mes de aniversario\n");
  printf("(e) Buscar uma pessoa pelo dia e mes de aniversario\n");
  printf("(f) Inserir um novo contato\n");
  printf("(g) Retirar um contato existente\n");
  printf("(h) Imprimir agenda\n");
}

int busca_por_primeiro_nome(contato *agenda){
  char pessoa[20];
  int busca_completa = 0;
  printf("\nInsira o primeiro nome: ");
  scanf("%s", &pessoa);

  if(agenda->contato_existente == 1){
    for(int j = 0; j < 20; j++){
      if(agenda->nome[j] != pessoa[j]){
        busca_completa = 0;
        break;
      }
      if(agenda->nome[j] == '\0' && pessoa[j] == '\0'){

        printf("%s\n", agenda->nome);
        printf("%s\n", agenda->email);
        printf("%s\n", agenda->rua);
        printf("%d\n", agenda->n_casa);
        printf("%s\n", agenda->complemento);
        printf("%s\n", agenda->bairro);
        printf("%d\n", agenda->cep);
        printf("%s\n", agenda->cidade);
        printf("%s\n", agenda->estado);
        printf("%s\n", agenda->pais);
        printf("%d\n", agenda->ddd);
        printf("%d\n", agenda->telefone);
        printf("%d\n", agenda->dia);
        printf("%d\n", agenda->mes);
        printf("%d\n", agenda->ano);
        printf("\n");
        busca_completa = 1;
        break;
      }
    }
    return busca_completa;
  }
}

/*void busca_por_mes_de_aniversario(contato *agenda){
  int mes_busca, busca_completa = 0;
  scanf("%d", &mes_busca);
  for(int i = 0; i < 100 ; i++){
    if(agenda[i]->mes == mes_busca){
      printf("%s\n", agenda[i]->nome);
      printf("%s\n", agenda[i]->email);
      printf("%s\n", agenda[i]->rua);
      printf("%d\n", agenda[i]->n_casa);
      printf("%s\n", agenda[i]->complemento);
      printf("%s\n", agenda[i]->bairro);
      printf("%d\n", agenda[i]->cep);
      printf("%s\n", agenda[i]->cidade);
      printf("%s\n", agenda[i]->estado);
      printf("%s\n", agenda[i]->pais);
      printf("%d\n", agenda[i]->ddd);
      printf("%d\n", agenda[i]->telefone);
      printf("%d\n", agenda[i]->dia);
      printf("%d\n", agenda[i]->mes);
      printf("%d\n", agenda[i]->ano);
      printf("\n");
      busca_completa = 1;
    }
  }
  if(busca_completa == 0){
    printf("\n Contato nao encontrado");
  }
}

/*void busca_por_dia_mes_de_anversario(contato *agenda){
  int dia_busca, mes_busca, busca_completa = 0;
  printf("\n Insira o dia e o mes: ");
  scanf("%d %d", &dia_busca, &mes_busca);
  for(int i = 0; i < 100 ; i++){
    if(agenda[i]->dia == dia_busca && agenda[i]->mes == mes_busca){
      printf("%s\n", agenda[i]->nome);
      printf("%s\n", agenda[i]->email);
      printf("%s\n", agenda[i]->rua);
      printf("%d\n", agenda[i]->n_casa);
      printf("%s\n", agenda[i]->complemento);
      printf("%s\n", agenda[i]->bairro);
      printf("%d\n", agenda[i]->cep);
      printf("%s\n", agenda[i]->cidade);
      printf("%s\n", agenda[i]->estado);
      printf("%s\n", agenda[i]->pais);
      printf("%d\n", agenda[i]->ddd);
      printf("%d\n", agenda[i]->telefone);
      printf("%d\n", agenda[i]->dia);
      printf("%d\n", agenda[i]->mes);
      printf("%d\n", agenda[i]->ano);
      printf("\n");
      busca_completa = 1;
      break;
    }
  }
  if(busca_completa == 0){
    printf("\n Contato nao encontrado");
  }
}
*/

void inserir_contato(contato *agenda){

  printf("Insira o nome do contato:\n");
  scanf("%s", &agenda->nome);
  printf("Insira o email do contato:\n");
  scanf("%s", &agenda->email);
  printf("Insira a rua do contato:\n");
  scanf("%s", &agenda->rua);
  printf("Insira o numero da casa do contato:\n");
  scanf("%d", &agenda->n_casa);
  printf("Insira o complemento do endereco:\n");
  scanf("%s", &agenda->complemento);
  printf("Insira o bairro do contato:\n");
  scanf("%s", &agenda->bairro);
  printf("Insira o cep do contato:\n");
  scanf("%d", &agenda->cep);
  printf("Insira a cidade do contato:\n");
  scanf("%s", &agenda->cidade);
  printf("Insira o estado do contato:\n");
  scanf("%s", &agenda->estado);
  printf("Insira o pais do contato:\n");
  scanf("%s", &agenda->pais);
  printf("Insira o DDD e telefone do contato:\n");
  scanf("%d %d",&agenda->ddd, &agenda->telefone);
  printf("Insira o aniversario contato:\n");
  scanf("%d %d %d", &agenda->dia, &agenda->mes, &agenda->ano);
  agenda->contato_existente = 1;
}


//void deletar_contato(contato *agenda){


//}
