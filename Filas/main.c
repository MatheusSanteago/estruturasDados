#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 5

struct tfila {
    int dados[tamanho];
    int ini;
    int fim;
};

struct tfila fila;
int op;

void entrar();
void sair();
void menu();
void fila_mostrar();


int main() {
    setlocale(LC_ALL, "Portuguese");
    op = 1;
    fila.ini = 0;
    fila.fim = 0;
    while(op != 0){
        system("cls");
        fila_mostrar();
        menu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                entrar();
                break;
            case 2:
                sair();
                break;
        }
    }
    return 0;
}


void entrar(){
    if(fila.fim == tamanho){
        printf("\nFILA CHEIA\n");
        system("pause");
    } else {
        printf("\nDigite um valor: ");
        scanf("%d", &fila.dados[fila.fim]);
        fila.fim++;
    }
}

void sair(){
    if (fila.ini == fila.fim ){
        printf("Fila vazia");
        system("pause");
    } else {
        int i;
        for (i = 0; i < tamanho; i++) {
           fila.dados[i] = fila.dados[i + 1];
        }
        fila.dados[fila.fim] = 0;
        fila.fim--;
    }
}

void fila_mostrar(){
    int i;
    printf("[  ");
    for (i = 0; i < tamanho; i++) {
        printf("%d", fila.dados[i]);
    }
    printf("  ]");
}

void menu(){
    printf("\n1 - Incluir na fila");
    printf("\n2 - Excluir da Fila");
    printf("\n0 - Sair \n\n");
}