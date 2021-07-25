#include <stdio.h> // para entrada e saida
#include <string.h> // para eu manipular as strings
#include <stdlib.h> // para as macros e funçao de conversão

//preferi usar struct pra organizar melhor os vetores
typedef struct DataBase{
    char *pass; //alocado dinamicamente
} DataBase;

//prototipagem das funçoes
void get_password(DataBase passwords[], int qtt_pass);
void remove_spaces(DataBase passwords[], int qtt_pass);
void calumma_12(DataBase *passwords, int qtt_pass);

int main(){

    DataBase *passwords; //alocado dinamicamente
    char numero[BUFSIZ], *p; //o vetor e o ponteiro para a converçao de tipo
    long int qtt_pass; //qtt_pass é a quantidade de senhas que o usuario deseja inserir no DB

    //recebo o numero como char e converto pra Long Integer
    if (fgets(numero, sizeof(numero), stdin) != NULL)
        qtt_pass = strtol(numero, &p, 10); //10 pois a converçao e para a base 10

    
    if (qtt_pass <= 10000){ //esse IF pra não ultrapassar o limite que o vetor password suporta
        passwords = (DataBase *) malloc(qtt_pass * sizeof(DataBase));

        //pegar as senhas do usuario
        get_password(passwords, qtt_pass);
        
        //remove os espaços das strings e termina a string na posiçao 12 do vetor
        remove_spaces(passwords, qtt_pass);
        
        //aplica a técnica calumma-12
        calumma_12(passwords, qtt_pass);

        //output
        for (int i = 0; i < qtt_pass; i++)
            printf("%s\n", passwords[i].pass);
    }

    free(passwords->pass);
    free(passwords);
    return 0;
}

//passando o endereço da 1st posiçao do vetor e a quantidade de senhas que o user deseja inserir
void get_password(DataBase *passwords, int qtt_pass){
    char string[1002]; //1002 pra acomodar o '\n' e o '\0', caso a string tenha 1000 caracteres
    int j, count;
    for (int i = 0; i < qtt_pass; i++){
        fgets(string, sizeof(string), stdin);
        string[strlen(string)-1] = '\0'; //isso é pra tirar o '\n' que o fgets insere no vetor
        j = 0, count = 0;
        while (string[j] != '\0'){
            count++;
            j++;
        }
        count++;
        passwords[i].pass = (char *) malloc(count * sizeof(char));
        j = 0;
        while (string[j] != '\0'){
            passwords[i].pass[j] = string[j];
            j++;
        }
        passwords[i].pass[j] = '\0';
    }
}

void remove_spaces(DataBase *passwords, int qtt_pass){
    int aux;
    for (int i = 0; i < qtt_pass; i++){
        aux = 0;
        for (int j = 0; j < strlen(passwords[i].pass); j++){ //passar por todos os indices da string até encontrar um '\0'
            if (passwords[i].pass[j] != ' '){ //se o caractere não for um espaço ele é copiado para o vetor na posiçao aux, assim eu elimino os espaços da string
                passwords[i].pass[aux] = passwords[i].pass[j];
                aux++;
            }
            if (aux == 12)
                passwords[i].pass[aux] = '\0'; //terminando a string na posiçao 12 do vetor pra não utilizar o resto
        }
        passwords[i].pass[aux] = '\0'; //aqui pra garantir que todas as strings vão ser terminadas com o '\0' independente do tamanho
    }
}

//os IFs estão nessa ordem pois achei que fica mais elegante
void calumma_12(DataBase *passwords, int qtt_pass){
    for (int i = 0; i < qtt_pass; i++){
        for (int j = 0; j < strlen(passwords[i].pass); j++){ 
            if (passwords[i].pass[j] == 'H' || passwords[i].pass[j] == 'R' || passwords[i].pass[j] == 'j' || passwords[i].pass[j] == 't'){
                passwords[i].pass[j] = '9';
            } else if (passwords[i].pass[j] == 'G' || passwords[i].pass[j] == 'Q' || passwords[i].pass[j] == 'a' || passwords[i].pass[j] == 'k' || passwords[i].pass[j] == 'u'){
                passwords[i].pass[j] = '0';
            } else if (passwords[i].pass[j] == 'I' || passwords[i].pass[j] == 'S' || passwords[i].pass[j] == 'b' || passwords[i].pass[j] == 'l' || passwords[i].pass[j] == 'v'){
                passwords[i].pass[j] = '1';
            } else if (passwords[i].pass[j] == 'J' || passwords[i].pass[j] == 'T' || passwords[i].pass[j] == 'e' || passwords[i].pass[j] == 'o' || passwords[i].pass[j] == 'y'){
                passwords[i].pass[j] = '4';
            } else if (passwords[i].pass[j] == 'A' || passwords[i].pass[j] == 'K' || passwords[i].pass[j] == 'U' || passwords[i].pass[j] == 'g' || passwords[i].pass[j] == 'q'){
                passwords[i].pass[j] = '6';
            } else if (passwords[i].pass[j] == 'C' || passwords[i].pass[j] == 'M' || passwords[i].pass[j] == 'W' || passwords[i].pass[j] == 'h' || passwords[i].pass[j] == 'r'){
                passwords[i].pass[j] = '7';
            } else if (passwords[i].pass[j] == 'B' || passwords[i].pass[j] == 'L' || passwords[i].pass[j] == 'V' || passwords[i].pass[j] == 'i' || passwords[i].pass[j] == 's'){
                passwords[i].pass[j] = '8';
            } else if (passwords[i].pass[j] == 'D' || passwords[i].pass[j] == 'N' || passwords[i].pass[j] == 'X' || passwords[i].pass[j] == 'f' || passwords[i].pass[j] == 'p' || passwords[i].pass[j] == 'z'){
                passwords[i].pass[j] = '5';
            } else if (passwords[i].pass[j] == 'E' || passwords[i].pass[j] == 'O' || passwords[i].pass[j] == 'Y' || passwords[i].pass[j] == 'c' || passwords[i].pass[j] == 'm' || passwords[i].pass[j] == 'w'){
                passwords[i].pass[j] = '2';
            } else if (passwords[i].pass[j] == 'F' || passwords[i].pass[j] == 'P' || passwords[i].pass[j] == 'Z' || passwords[i].pass[j] == 'd' || passwords[i].pass[j] == 'n' || passwords[i].pass[j] == 'x'){
                passwords[i].pass[j] = '3';
            }
        }
    }
}