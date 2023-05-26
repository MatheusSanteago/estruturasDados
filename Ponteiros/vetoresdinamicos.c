#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tam;
int *vetor;

int main(){
    printf("Select the size of vector: ");
    scanf("%d", &tam);
    vetor = (int *) malloc(sizeof(int)*tam);

    for(int i = 0; i < tam; i++){
        vetor[i] = pow(2,i);
        printf("Position: %d: %d\n",i,vetor[i]);
    }
    system("Pause");
    return (0);
}