#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 5

typedef struct {
    int cod;
    char nome[40];
    char autor[40];
} Livro;
Livro livros[tamanho];
Livro livroVazio[1];

struct plivro {
    int fim;
    int ini;
    int livros;
};

struct plivro biblioteca;
int op;


void ver_livros();
void adicionar_livro();
void empilhar();
void desempilhar();
void adicionar_livroVazio();

int main(){
    setlocale(LC_ALL, "Portuguese");
    adicionar_livroVazio();
    biblioteca.fim = 0;
    biblioteca.ini = 0;
    op = 1;

    while (op != 0){
        system("cls");
        ver_livros();
        printf("\n Escolha uma operacao \n 1 - Adicionar \n 2 - Remover \n 3 - Ver \n\n => ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                empilhar();
                break;
            case 2:
                desempilhar();
                break;
            case 3:
                ver_livros();
                break;
            default:
                break;
        }
    }
}

void adicionar_livro(){
    livros[biblioteca.fim].cod = biblioteca.livros;
    printf("Digite o nome do Livro: ");
    scanf("%s", livros[biblioteca.fim].nome);
    printf("Digite o nome do autor: ");
    scanf("%s", livros[biblioteca.fim].autor);
    system("cls");
    biblioteca.fim++;
}
void adicionar_livroVazio(){
    livroVazio[0].cod = 0;
    printf("Digite 'Vazio'\n");
    scanf("%s", livroVazio[0].nome);
    printf("Digite 'Vazio'\n");
    scanf("%s", livros[0].autor);
}

void ver_livros(){
    int i;
    for(i=0; i < tamanho; i++){
        printf("|%d| Livro : %s | Autor : %s\n", livros[i].cod,livros[i].nome,livros[i].autor);
    }
}

void desempilhar(){
    if(biblioteca.fim == biblioteca.ini){
        printf("Fila vazia...\n");
        system("Pause");
    } else {
        int i;
        livros[biblioteca.fim-1] = livroVazio[0];
        biblioteca.fim--;
    }
}

void empilhar(){
    if(biblioteca.fim == tamanho){
        printf("Fila cheia...\n");
        system("Pause");
    } else {
        adicionar_livro();
    }
}