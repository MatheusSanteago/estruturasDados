#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
    int dado;
    struct no *prox;
}; // Criando no com um valor e um ponteiro

// Variáveis
typedef struct no *pointer_no; // Fazer alocação
typedef struct no no;
pointer_no lista; // Aponta para o começo da lista
int op;

void menu_mostrar();
void menu_selecionar(int op);
void lista_mostrar2(pointer_no list);
void lista_inserir(pointer_no list);
void lista_remover(pointer_no pilh);

int main(){
    srand(time(NULL));
    op = 1;
    lista = (pointer_no) malloc(sizeof(no));
    lista->dado = 0;
    lista->prox = NULL;
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
    lista_mostrar2(lista);
    printf("\n\nSELECIONE: \n\n1- Inserir\n2- Remover\n0- Sair\n\n:");
}

void menu_selecionar(int o){
    switch (o) {
        case 1:
            lista_inserir(lista);
            break;
        case 2:
            lista_remover(lista);
            break;
        default:
            break;
    }
}


void lista_mostrar2(pointer_no list){
    system("cls");
    while(list->prox != NULL){
        printf("%d, ", list->dado);
        list = list->prox;
    }
    printf("%d, ", list->dado);
}

void lista_inserir(pointer_no list){
    while(list->prox != NULL){
        list = list->prox;
    }
    list->prox = (pointer_no) malloc(sizeof(no));
    list = list->prox;
    list->dado = rand() % 100;
    list->prox = NULL;
    system("cls");
}

void lista_remover(pointer_no list){
    system("cls");
    lista_mostrar2(lista);
    int dado;
    pointer_no atual;
    atual = (pointer_no) malloc(sizeof(no));
    printf("\n\nEscolha um dos itens para remover: \n");
    scanf("%d", &dado); // Dado a ser removido
    while((list->dado != dado)){
        if(list->prox == NULL){
            break;
        } // Se chegar ao final e não achar quebra o laço
        atual = list; // Salva endereço anterior
        list = list->prox; // Avança
    }
    if(list->dado == dado){
        atual->prox = list->prox; // Anterior passa apontar para o nó a frente do removido
    }
}