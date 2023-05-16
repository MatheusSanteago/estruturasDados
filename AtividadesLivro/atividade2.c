#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 5

typedef struct {
    int horas[3]; //
    char nome[40];
} Clientes;
Clientes clientes[tamanho];

struct tm *p;

int ini;
int fim;
int op;
int hora;
int min;
int sec;

void enfileirar();
void desenfileirar();
void ver_fila();
void adicionar_cliente();

int main(){
    op = 1;
    ini = 0;
    fim = 0;

    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);

    while(op != 0){
        system("cls");
        ver_fila();
        printf("\n Dia %d/%d/%d\n", p->tm_mday, p->tm_mon + 1,p->tm_year + 1900);
        printf(" Hora: %d:%d:%d\n", p->tm_hour,p->tm_min,p->tm_sec);
        printf(" Menu\n 1 - Entrar na fila\n 2 - Sair da fila\n 0 - Sair\n\n => ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                enfileirar();
                break;
            case 2:
                desenfileirar();
                break;
            default:
                printf("Digite um valor correto...\n");
                system("cls");
                break;
        }
    }
}

void ver_fila(){
    int i;
    for(i=0; i < tamanho; i++){
        printf(" O Cliente, %s chegou as %d:%d:%d\n", clientes[i].nome, clientes[i].horas[0], clientes[i].horas[1], clientes[i].horas[2]);
    }
}

void enfileirar(){
    if(fim == tamanho){
        printf("Cheio...");
        system("Pause");
    } else {
       adicionar_cliente();
       fim++;
    }
}
void desenfileirar(){
    if(fim == ini){
        printf("Vazia...\n");
        system("Pause");
    } else {
        int i;
        for(i=0; i < tamanho; i++){
            clientes[i] = clientes[i+1];
        }
        fim--;
    }
}

void adicionar_cliente(){
    printf("Nome do cliente: ");
    scanf("%s",  clientes[fim].nome);
    hora = p->tm_hour;
    min = p->tm_min;
    sec = p->tm_sec;
    clientes[fim].horas[0] = hora;
    clientes[fim].horas[1] = min;
    clientes[fim].horas[2] = sec;

    system("cls");
}

