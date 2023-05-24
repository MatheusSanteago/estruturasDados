#include <stdio.h>
#include <stdlib.h>

int xi;
int *pXi;


void imprimir(){
    printf("Valor de xi %d\n", xi);
    printf("Valor de &xi %p\n", &xi);
    printf("Valor de pXi %p\n", pXi);
    printf("Valor de *pXi %d\n\n", *pXi);
}

int main(){
    xi = 10;
    pXi = &xi;
    imprimir();

    system("Pause");
    return (0);
}

