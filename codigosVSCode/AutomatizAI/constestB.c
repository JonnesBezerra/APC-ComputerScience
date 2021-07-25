#include <stdio.h> // para entrada e saida
#include <string.h> // para eu manipular as strings
#include <stdlib.h> // para as macros e funçao de conversão

typedef struct Twitter {
    char *phrase; //o vetor vai ser alocado dinamicamente
} Twitter;

void get_phrases(Twitter *tweets, int analyze); 
void analyzing_tweets(Twitter *tweets, int analyze);
void classification(int *alphabet);

int main(){

    Twitter *tweets; //o vetor vai ser alocado dinamicamente
    char number[BUFSIZ], *p; //guardar a quantidade de tweets para analizar, e converter
    long int analyze; //quantidade de tweets para analisar
    

    if (fgets(number, sizeof(number), stdin) != NULL)
        analyze = strtol(number, &p, 10);
    
    tweets = (Twitter *) malloc(analyze * sizeof(Twitter)); // alocando memória dinamicamente pro vetor

    get_phrases(tweets, analyze);

    analyzing_tweets(tweets, analyze);

    return 0;
}

void get_phrases(Twitter *tweets, int analyze){
    char string[1002]; //1002 pra acomodar o '\n' e o '\0' caso a string tenha 1000 caracteres
    int j;
    for (int i = 0; i < analyze; i++){
        fgets(string, sizeof(string), stdin);
        string[strlen(string)-1] = '\0'; //retiro o '\n' que o fgets insere na string
        j = 0;
        while (string[j] != '\0'){ //contagem do tamanho do vetor
            j++;
        }
        j++;
        tweets[i].phrase = (char *) malloc(j * sizeof(char)); //aqui defino a quantidade de memoria pra cada phrase
        j = 0;
        while (string[j] != '\0'){
            tweets[i].phrase[j] = string[j]; //copio o que está em string pra phrase
            j++;
        }
        tweets[i].phrase[j] = '\0';
    }
}

//funcao que analiza o tweet
void analyzing_tweets(Twitter *tweets, int analyze){
    for (int i = 0; i < analyze; i++){
        int alphabet[26] = {0};
        int j = 0;
        while (tweets[i].phrase[j] != '\0'){
            if ((tweets[i].phrase[j] >= 'a') && (tweets[i].phrase[j] <= 'z')){
                alphabet[tweets[i].phrase[j] - 'a']++; //a letra da posiçao j - 'a' me dá a posição da letra do alphabeto no vetor alphabet
            } else if ((tweets[i].phrase[j] >= 'A') && (tweets[i].phrase[j] <= 'Z')){
                alphabet[tweets[i].phrase[j] - 'A']++; //a mesma coisa aqui vai me dar a mesma posiçao das minúsculas referente às maiusculas
            }
            j++;
        }
        classification(alphabet); //já chamo a funçao que mostra a classificação
    }
}

//funcao que mostra a classificacao do tweet
void classification(int alphabet[]){
    int letters = 0;
    for (int i = 0; i < 26; i++){
        if (alphabet[i] != 0){ //se a posicao i tiver sido incrementada na função analyzing_tweets entao a letra consta na string
            letters++; //conta quantas letras diferrentes do alfabeto foram usadas no tweet
        }
    }
    if (letters == 26){
        printf("HIGH\n");
    } else if (letters >= 13){
        printf("MID\n");
    } else {
        printf("LOW\n");
    }
}