#include <stdio.h>

int main(int argc, char const *argv[]){

    int base10, base2, armazem = 0, decimal = 0;

    scanf("%d", &base10);

    for (int expoente = 15; expoente >= 0; expoente--){
        
        int potencia = 1;
        for (int i = 0; i < expoente; i++){
            potencia *= 2;
        }

        for (base2 = 1; base2 < 2; base2++){
            
            decimal = base2 * potencia;
            
            if (decimal + armazem > base10){
                base2 -= 1;
                break;
            }
        }
        
        if (base2 > 1){
            base2 -= 1;
        }

        decimal = base2 * potencia;
        armazem += decimal;

        printf("%d", base2);
    }
    
    printf("\n");
    
    return 0;
}