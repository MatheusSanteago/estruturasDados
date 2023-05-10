import os

pilha = {
    "dados": [None for _ in range(5)],
    "inicio": 0,
    "fim": 0
}


def empilhar():
    if len(pilha['dados']) == 5 and pilha["dados"][len(pilha['dados']) - 1] is not None:
        print('\nPilha cheia!\n')
    else:
        valor = int(input('\nDigite um valor para empilhar: ').replace(' ', ''))
        pilha['dados'][pilha['fim']] = valor
        pilha['fim'] += 1


def desempilhar():
    if pilha["fim"] == pilha["inicio"]:
        print('Pilha Vazia')
    else:
        pilha['dados'][pilha['fim']] = None
        pilha['fim'] -= 1


if __name__ == '__main__':
    op = int(input('\n\nDigite a opção \n 1 - Empilhar \n 2 - Desempilhar \n 3 - Ver Pilha \n 0 - Sair\n\n'))
    while op != 0:
        match op:
            case 1:
                empilhar()
                op = int(input('\n\nDigite a opção \n 1 - Empilhar \n 2 - Desempilhar \n 3 - Ver Pilha \n 0 - Sair\n\n'))
            case 2:
                desempilhar()
                op = int(input('\n\nDigite a opção \n 1 - Empilhar \n 2 - Desempilhar \n 3 - Ver Pilha \n 0 - Sair\n\n'))
            case 3:
                print(pilha["dados"])
                op = int(input('\n\nDigite a opção \n 1 - Empilhar \n 2 - Desempilhar \n 3 - Ver Pilha \n 0 - Sair\n\n'))
