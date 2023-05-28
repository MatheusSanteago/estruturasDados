#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
    int dado;
    struct no *prox;
};

// Variáveis
typedef struct no *pointer_no;
typedef struct no no;
pointer_no pilha;
int op;

void menu_mostrar();
void menu_selecionar(int op);
void pilha_mostrar(pointer_no pilh);
void pilha_inserir(pointer_no pilh);
void pilha_remover(pointer_no pilh);

int main(){
    srand(time(NULL));
    op = 1;
    pilha = (pointer_no) malloc(sizeof(no));
    pilha->dado = 0;
    pilha->prox = NULL;
    // Laço Principal
    while(op != 0){
        system("cls");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }
    system("Pause");
    return (0);
}

void menu_mostrar(){
    pilha_mostrar(pilha);
    printf("\n\nSELECIONE: \n\n1- Inserir\n2- Remover\n0- Sair\n\n:");
}

void menu_selecionar(int o){
    switch (o) {
        case 1:
            pilha_inserir(pilha);
            break;
        case 2:
            pilha_remover(pilha);
            break;
        default:
            break;
    }
}


void pilha_mostrar(pointer_no pilh){
    system("cls");
    while(pilh->prox != NULL){
        printf("%d, ", pilh->dado);
        pilh = pilh->prox;
    }
    printf("%d, ", pilh->dado);
}

void pilha_inserir(pointer_no pilh){
    while(pilh->prox != NULL){
        pilh = pilh->prox;
    }
    pilh->prox = (pointer_no) malloc(sizeof(no));
    pilh = pilh->prox;
    pilh->dado = rand() % 100;
    pilh->prox = NULL;
    system("cls");
}

void pilha_remover(pointer_no pilh){
    system("cls");
    pointer_no atual;
    atual = (pointer_no) malloc(sizeof(no));
    while(pilh->prox != NULL){
        atual = pilh; // Salva endereço anterior
        pilh = pilh->prox; // Avança
    }
        atual->prox = pilh->prox; // O penúltimo item passa a apontar para NULL
}