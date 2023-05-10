class Pilha:
    def __init__(self):
        self.inicio = 0
        self.fim = 0
        self.dados = [0, 0, 0, 0, 0]

    def empilhar(self, content):
        if len(self.dados) == 5 and self.dados[len(self.dados) - 1] != 0:
            print('\nPilha cheia!\n')
        else:
            data = content
            self.dados[self.fim] = data
            self.fim += 1

    def desempilhar(self):
        if self.inicio == self.fim:
            print('Pilha Vazia')
        else:
            print('Desempilhando ...')
            self.dados[self.fim] = 0
            self.fim -= 1

    def ver_pilha(self):
        print(self.dados)


stack = Pilha()
stack.empilhar("Matheus")
stack.empilhar("Marcos")
stack.empilhar("Marcelo")

stack.desempilhar()  # Sai Marcelo
stack.desempilhar()  # Sai Marcos
stack.desempilhar()  # Sai Matheus
stack.desempilhar()  # Pilha vazia

stack.ver_pilha()  # Mesmo vazia imprimi o "Matheus"['Matheus', 0, 0, 0, 0]

stack.empilhar("Mylena")
stack.ver_pilha()  # ['Mylena', None, None, None, None]
