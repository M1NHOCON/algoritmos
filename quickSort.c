#include <stdio.h>
#include <stdlib.h>


void quickSort(int *vetor, int tam){
    if(tam <= 1){
        return;
    }
    int pivo = 0; //pivo é o primeiro elemento
    int a = 0;
    int b = tam - 1;
    while(a <= b){
        while(vetor[a] < pivo){
            a++;
        }
        while(vetor[b] > pivo){
            b--;
        }
        if(a <= b){
            int aux = vetor[a];
            vetor[a] = vetor[b];
            vetor[b] = aux;
            a++;
            b--;
        }
    }
    quickSort(vetor, b + 1);
    quickSort(vetor + a, tam - a);
}
int main(){
    int vetor[10] = {5, 3, 2, 4, 7, 1, 0, 6, 9, 8};
    quickSort(vetor, 10);
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    return 0;
}