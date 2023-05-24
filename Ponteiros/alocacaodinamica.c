#include <stdio.h>
#include <stdlib.h>

int xi;
int *pXi;

int main(){
    printf("Endereco: %p\n\n", pXi);
    pXi = (int *) malloc(sizeof(int));
    printf("Endereco: %p\nValor: %d\n\n", pXi,*pXi);
    *pXi = 10;
    printf("Endereco: %p\nValor: %d\n\n", pXi,*pXi);

    int x;
    x = 20;
    pXi = &x;
    printf("Endereco: %p\nValor: %d\n\n", pXi,*pXi);
    pXi = (int *) malloc(sizeof(int));
    printf("Endereco: %p\nValor: %d\n", pXi,*pXi);

    system("Pause");
    return (0);
}
