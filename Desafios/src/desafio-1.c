#include <stdio.h>
#include <stdlib.h>

/* Observe o trecho de código abaixo: int INDICE = 12, SOMA = 0, K = 1; enquanto K < INDICE faça { K = K + 1; SOMA = SOMA + K; } imprimir(SOMA);*/
// Resposta: 230
int main(){
    int INDICE = 21;
    int soma =0;
    int k = 1;

    while(k<INDICE){
        k+=1;
        soma+=k;
    }

    printf("%d",soma);
}
