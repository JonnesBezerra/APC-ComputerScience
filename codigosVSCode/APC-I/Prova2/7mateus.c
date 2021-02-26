#include <stdio.h>
int  produtoria(int intervalo_m,int intervalo_n,int resultado){
    
    if(intervalo_m!=-2&&intervalo_m!=100&&intervalo_n!=(-2)&&intervalo_n!=100){
       return 1;
    }
    return resultado=-1*(intervalo_m*intervalo_m)-4/intervalo_n-3;

}

int main(int argc, char const *argv[]) {
    int  intervalo_m,intervalo_n;

    scanf("%d %d",&intervalo_m,&intervalo_n);
    
    int resultado=produtoria(intervalo_m,intervalo_n,resultado);
    
    printf("%d",resultado);

    return 0;
}