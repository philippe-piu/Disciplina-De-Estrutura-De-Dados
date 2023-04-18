//Exemplo feito pelo professor na Aula Pilha com Aloca��o din�mica
#include <stdio.h>
#include <stdlib.h>
typedef struct node  // Defini��o de uma estrutura chamada node
{
	char info; // O tipo do dado que ser� armazenado em um n� � char
	struct node *ant; // Um ponteiro para o n� anterior da pilha
} NODE;

typedef struct pilha  // Defini��o da estrutura pilha
{
	NODE *topo; // Ponteiro para o topo da pilha (�ltimo n� adicionado)
	int tamanho; // Vari�vel para armazenar o tamanho atual da pilha
} PILHA;

void inicializa(PILHA *p)  // Fun��o para inicializar uma pilha
{
	p->tamanho = 0; // Tamanho inicial � zero
	p->topo = NULL; // O topo inicial � nulo (n�o h� nenhum n� na pilha)
}

void push(PILHA *p, char c)  // Fun��o para adicionar um elemento � pilha
{
	NODE *novo = (NODE *)malloc(sizeof(NODE)); // Aloca mem�ria para um novo n�
	if(novo == NULL)
	{
		printf("Pilha cheia!\n");   // Verifica se a aloca��o falhou
	}
	else  // Se a aloca��o foi bem sucedida:
	{
		novo->info = c; // Armazena o dado no novo n�
		novo->ant = p->topo; // Faz o ponteiro do novo n� apontar para o topo da pilha (n� anterior)
		p->topo = novo; // Atualiza o topo da pilha para o novo n�
		p->tamanho++; // Incrementa o tamanho da pilha
	}
}

char pop(PILHA *p)  // Fun��o para remover o elemento do topo da pilha e retornar seu valor
{
	if(p->topo == NULL)  // Verifica se a pilha est� vazia
	{
		printf("Pilha vazia!\n"); // Se estiver vazia, imprime uma mensagem de erro
		return '\0'; // E retorna o caractere nulo
	}
	else   // Se a pilha n�o estiver vazia:
	{
		NODE *aux = p->topo; // Cria um ponteiro auxiliar para o topo da pilha
		char c = (p->topo)->info; // Armazena o dado do topo da pilha em uma vari�vel
		p->topo = (p->topo)->ant; // Atualiza o topo da pilha para o n� anterior
		free(aux); // Libera a mem�ria do n� removido
		return c; // Retorna o valor do elemento removido
	}
}

int main()  // Fun��o principal
{
	PILHA container1, container2; // Cria duas pilhas do tipo PILHA
	inicializa(&container1); // Inicializa a pilha container1
	inicializa(&container2); // Inicializa a pilha container2
	push(&container1, 'A'); // Adiciona o caractere 'A' na pilha container1
	push(&container2, 'B'); // Adiciona o caractere 'B' na pilha container2
	printf("CTA=%c\n", pop(&container1)); // Remove e imprime o topo da pilha container1
	printf("CTB=%c\n", pop(&container2)); // Remove e imprime o topo da pilha container2
	// Tenta remover outro elemento da segunda pilha (que j� est� vazia)
    printf("CTB=%c\n",pop(&container2));
    // Encerra o programa
	return 0;
}
