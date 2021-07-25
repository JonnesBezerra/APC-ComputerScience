/*** HABITAT NATURAL AUTOMATIZAI ***/
#include <stdio.h> // para entrada e saida
#include <math.h> // para o arredondamento

typedef struct Prices {
    float chameleon[3]; //um vetor onde cada posição será relacionado a uma especie conforme linha 23
    float food, ornament_price, aquarium, package_price;
    int package_size;
} Prices;

float calculates_price(Prices p, float qtt_employees, int i);
float choose_chamaleon(Prices p, float qtt_employees, int i);
float food_price(Prices p, int grams);
float calculates_ornament(Prices p, float qtt_employees, int i);

int main(){
    int dev, intern, manager, qtt_employees = 0, aqua = 0, rest;
    float position_value[3], total = 0.0; //float pois irá guardar os valores dos calculos dos preços
    Prices p; //declaro só um p pois ela será alterada a cada cargo
    p.aquarium = 12354.0;

    scanf("%d %d %d", &dev, &intern, &manager);
    position_value[0] = dev; //posição 0 vai armazenar os valores para Devs e por consequencia para a especie Pardalis
    position_value[1] = intern; //posição 1 vai armazenar os valores para Estagiarios e por consequencia para a especie Calyptatus
    position_value[2] = manager; //posição 2 vai armazenar os valores para Gerentes e por consequencia para a especie Jacksonii

    //calculo da quantidade de aquarios
    for (int i = 0; i < 3; i++){
        qtt_employees += position_value[i]; //soma a quantidade em cada cargo
    }
    aqua = (qtt_employees / 12);
    rest = (qtt_employees % 12);
    if (rest > 0){
        aqua++;
    }

    //Passo a quantidade de funcionarios naquele cargo pra fazer o calculos ja na função
    for (int i = 0; i < 3; i++){
        position_value[i] = calculates_price(p, position_value[i], i);
    }

    for (int i = 0; i < 3; i++){
        total += position_value[i]; //somo os valores retornados nos 3 cargos
    }

    total += (aqua * p.aquarium); //adiciono o valor dos aquarios que serão necessários

    printf("%.2f\n", roundf(total * 100) / 100); //imprimo com arredondamento

    return 0;
}

//chama as funções de calculo dos preços dos itens e retorna a soma desses valores
float pardalis(Prices p, float qtt_employees, int i){
    p.food = (600 * 0.1);
    p.ornament_price = (4 * 221.52);
    
}

//calcula o preço de todos os pets por cargo
float choose_chamaleon(Prices p, float qtt_employees, int i){
    p.chameleon[0] = 4215.00;
    p.chameleon[1] = 2231.00;
    p.chameleon[2] = 5002.82;
    return (p.chameleon[i] * qtt_employees); //multiplico a quantidade total de funcionarios naquele cargo pelo preço de cada um da especie 
}

//calcula o preco de todas a comida necessaria para todos os pets da mesma especie
float food_price(Prices p, int grams){
    p.package_size = 200;
    p.package_price = 20.0;
    return p.food = (grams * (0.1)); //dividi o preco do pacote pela quantidade pra ter o preço por grama
}
//p.package_price / p.package_size
//calcula o preco de todos os enfeites necessarios para todos os pets da mesma especie
float calculates_ornament(Prices p, float qtt_employees, int i){
    p.ornament_price[0] = (4 * 221.52);
    p.ornament_price[1] = (3 * 221.52);
    p.ornament_price[2] = (1 * 221.52);
    return (qtt_employees * p.ornament_price[i]); //multiplica o valor total dos enfeites para a especie pela quantidade de funcionarios naquele cargo
}