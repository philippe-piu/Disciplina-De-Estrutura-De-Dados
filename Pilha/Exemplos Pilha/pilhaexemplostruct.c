#include<stdio.h>
#include<stdlib.h>
#define TAMANHO_PILHA 4
/*Exemplo de Pilha com Struct*/

//Struct Pilha
typedef struct pilha
{
	//Array de armazenamento da pilha
	int pilha[TAMANHO_PILHA];
	//Topo da fila
	int topo;
} PILHA;

//Chamada de funções
void push(int valor, PILHA *p);
int pop(PILHA *p);
void imprime(PILHA *p);

int main()
{
	//Chamada da Struct PILHA
	PILHA *p = malloc(sizeof(PILHA));
	//Alocação de memoria para Struct pilha

	//Inicializar o topo da pilha
	p->topo = -1;

	//Preenchendo a pilha
	push(1, p);
	push(2, p);
	push(3, p);
	push(4, p);

	//Imprimindo a Pilha
	printf("Pilha preenchida\n");
	imprime(p);

	//Removendo valor do topo da pilha
	printf("Valor removido da pilha %d\n", pop(p));
	printf("Valor removido da pilha %d\n", pop(p));
	imprime(p);

	//Librera o valor de alocamento da pilha
	free(p);

	return(0);
}

//Função preenchimento de pilha
void push(int valor, PILHA *p)
{
	//Verifica se a pilha está cheia
	if(p->topo == TAMANHO_PILHA - 1)
	{
		//Mensagem pe pilha cheia
		printf("Pilha Cheia\n");
	}
	else
	{
		//Incrementa um indice ao topo
		p->topo++;
		//Insere um valor na pilha
		p->pilha[p->topo] = valor;
	}
}

//Função de desempilhar pilha
int pop(PILHA *p)
{
	int auxiliar;
	//Verifica se a pilha está vazia
	if(p->topo == -1)
	{
		//Mensagem de pilha cheia
		printf("Pilha VAzia");
		//Retorna um valor para indicar o erro
		return -1;
	}
	else
	{
		//Salva o valor no topo da variavel
		auxiliar = p->pilha[p->topo];
		//Decrementa um valor do indice da pilha
		p->topo--;
		//Retorna o valor removido da pilha
		return auxiliar;
	}
}

//Função para imprimir pilha
void imprime(PILHA *p)
{
	int i;
	for(i = p->topo; i >= 0; i--)
	{
		printf("[%d]\n", p->pilha[i]);
	}

	printf("\n");
}
