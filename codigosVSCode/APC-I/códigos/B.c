#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, X, auxiliar, contagem_s = 0, contagem_n = 0;
    scanf ("%d", &N);
    int v [N];

    if (N >= 2 && N <= 150){
        for (int i = 0; i < N; i++){
            scanf ("%d", &X);
            auxiliar = 1;
            while(X != auxiliar*auxiliar && auxiliar <= X/2){
                auxiliar++;
            }
            if(i % 2 == 0){
                if (X == auxiliar*auxiliar){
                    contagem_s++;
                }
            }else{
                if (X != auxiliar * auxiliar){
                    contagem_s++;
                }else{
                    contagem_n++;
                }
            }
        }
        if (contagem_n == 0){
            printf ("O MINISTRO FICA\n");
        }else{
            printf ("TROQUE DE MINISTRO\n");
        }
    }



    return 0;
}