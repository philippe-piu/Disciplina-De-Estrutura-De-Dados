/*PILHA COM VETOR*/
#include<stdio.h>
#include<stdlib.h>
#define PILHA_TAMANHO 4

//Estrutura
typedef struct pilha
{
    int pilh[PILHA_TAMANHO];
    int topo;
} PILHA;

//Chamada da função
void inicializacao(PILHA *p);
void push(PILHA *p, int valor);
int pop(PILHA *p);
void imprime(PILHA *p);

int main()
{
	PILHA *p = malloc(sizeof(PILHA));
	
	inicializacao(p);
	
	int i, numero = 0;
	
	for(i = 0; i < PILHA_TAMANHO; i++)
	{
		printf("Informe Valores da Pilha\n");
		scanf("%d", &numero);
		push(p, numero);
	}
	printf("\n");
	
	imprime(p);
	
	printf("\n");
	printf("VAlor retirado da pilha %d\n",pop(p));
	imprime(p);
	
	free(p);

	return(0);
}

//Função de inicialização da pilha
void inicializacao(PILHA *p){
	p->topo = -1;
}

//Preenchendo a pilha
void push(PILHA *p, int valor)
{
	//Se a pilha estiver chei manda uma mensagem se não preenche a pilha
	if(p->topo == PILHA_TAMANHO - 1)
	{
		//Mensagem caso a pilha esteja cheia
		printf("Pilha Cheia\n");
	}
	else
	{
		p->topo++;
		p->pilh[p->topo] = valor;
	}
}

//Função de retirada de elementos da pilha
int pop(PILHA *p)
{
	int auxiliar;
	//Se a pilha estiver Vazia mostra um mensagem se não ele retitra um elemento da pilha
	if(p->topo == -1)
	{
		printf("Pilha Vazia\n");
	}
	else
	{
		auxiliar = p->pilh[p->topo];
		p->topo--;
		return auxiliar;
	}
}

//Fuinção de imprimir a pilha
void imprime(PILHA *p)
{
	int i;
	for(i = p->topo; i >= 0; i--)
	{
		printf("[%d]\n", p->pilh[i]);
	}
	printf("\n");
}
