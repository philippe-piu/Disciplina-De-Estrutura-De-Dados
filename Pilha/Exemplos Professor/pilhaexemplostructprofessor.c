//Exemplo feito pelo professor na Aula Pilha com Alocação dinâmica
#include <stdio.h>
#include <stdlib.h>
typedef struct node  // Definição de uma estrutura chamada node
{
	char info; // O tipo do dado que será armazenado em um nó é char
	struct node *ant; // Um ponteiro para o nó anterior da pilha
} NODE;

typedef struct pilha  // Definição da estrutura pilha
{
	NODE *topo; // Ponteiro para o topo da pilha (último nó adicionado)
	int tamanho; // Variável para armazenar o tamanho atual da pilha
} PILHA;

void inicializa(PILHA *p)  // Função para inicializar uma pilha
{
	p->tamanho = 0; // Tamanho inicial é zero
	p->topo = NULL; // O topo inicial é nulo (não há nenhum nó na pilha)
}

void push(PILHA *p, char c)  // Função para adicionar um elemento à pilha
{
	NODE *novo = (NODE *)malloc(sizeof(NODE)); // Aloca memória para um novo nó
	if(novo == NULL)
	{
		printf("Pilha cheia!\n");   // Verifica se a alocação falhou
	}
	else  // Se a alocação foi bem sucedida:
	{
		novo->info = c; // Armazena o dado no novo nó
		novo->ant = p->topo; // Faz o ponteiro do novo nó apontar para o topo da pilha (nó anterior)
		p->topo = novo; // Atualiza o topo da pilha para o novo nó
		p->tamanho++; // Incrementa o tamanho da pilha
	}
}

char pop(PILHA *p)  // Função para remover o elemento do topo da pilha e retornar seu valor
{
	if(p->topo == NULL)  // Verifica se a pilha está vazia
	{
		printf("Pilha vazia!\n"); // Se estiver vazia, imprime uma mensagem de erro
		return '\0'; // E retorna o caractere nulo
	}
	else   // Se a pilha não estiver vazia:
	{
		NODE *aux = p->topo; // Cria um ponteiro auxiliar para o topo da pilha
		char c = (p->topo)->info; // Armazena o dado do topo da pilha em uma variável
		p->topo = (p->topo)->ant; // Atualiza o topo da pilha para o nó anterior
		free(aux); // Libera a memória do nó removido
		return c; // Retorna o valor do elemento removido
	}
}

int main()  // Função principal
{
	PILHA container1, container2; // Cria duas pilhas do tipo PILHA
	inicializa(&container1); // Inicializa a pilha container1
	inicializa(&container2); // Inicializa a pilha container2
	push(&container1, 'A'); // Adiciona o caractere 'A' na pilha container1
	push(&container2, 'B'); // Adiciona o caractere 'B' na pilha container2
	printf("CTA=%c\n", pop(&container1)); // Remove e imprime o topo da pilha container1
	printf("CTB=%c\n", pop(&container2)); // Remove e imprime o topo da pilha container2
	// Tenta remover outro elemento da segunda pilha (que já está vazia)
    printf("CTB=%c\n",pop(&container2));
    // Encerra o programa
	return 0;
}
