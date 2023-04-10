/*Crie uma estrutura pilha com um array de inteiros e um topo inteiro.
A estrutura deve ser capaz de armazenar no máximo 10 elementos. Crie funções push
e pop que adicionem e removam elementos da pilha, respectivamente. Além disso,
crie uma função imprime que imprima todos os elementos da pilha.

Para implementar a função push, você deve receber como parâmetros a pilha e o
valor a ser adicionado. A função deve verificar se a pilha está cheia e, se não
estiver, adicionar o valor ao topo da pilha.

Para implementar a função pop, você deve receber como parâmetro a pilha e
retornar o valor do topo da pilha. A função deve verificar se a pilha está vazia
e, se não estiver, remover o valor do topo da pilha.

Para implementar a função imprime, você deve receber como parâmetro a pilha e
imprimir todos os valores armazenados na pilha, do topo até a base.
*/

#include<stdio.h>
#define TAMANHO_PILHA 10

//Estrutura da PILHA
typedef struct pilha
{
	int pilha[TAMANHO_PILHA];
	int topo;
} PILHA;

//Chamada das funções;
void push(int valor, PILHA *p);
int pop(PILHA *p);
void imprime(PILHA *p);

int main()
{
	PILHA *p = malloc(sizeof(PILHA));
	p->topo = -1;
	
	//Preenchendo a Pilha
	push(1,p);
	push(10,p);
	push(100,p);
	push(1000,p);
	push(10000,p);
	push(100000,p);
	push(1000000,p);
	push(10000000,p);
	push(100000000,p);
	push(1000000000,p);
	
	//Imprimindo a pilha
	printf("Pilha Preenchida\n");
	imprime(p);
	
	//Removendo elemento da pilha
	printf("Valor removido da pilha %d\n\n",pop(p));
	printf("Pilha apos remocao\n");
	imprime(p);
	
	free(p);
	return(0);
}

//Função de preenchimento da pilha
void push(int valor, PILHA *p)
{
	if(p->topo == TAMANHO_PILHA - 1)
	{
		printf("Pilha Cheia\n");
	}
	else
	{
		p->topo++;
		p->pilha[p->topo] = valor;
	}
}

//Função Removendo pilha
int pop(PILHA *p)
{
	int auxiliar;
	if(p->topo == -1)
	{
		printf("Pilha Vazia\n");
	}
	else
	{
		auxiliar = p->pilha[p->topo];
		p->topo--;
		return(auxiliar);
	}
}

void imprime(PILHA *p)
{
	int i;
	for(i = 0; i <= p->topo; i++)
	{
		printf("Posicao na pilha %d [%d]\n",i, p->pilha[i]);
	}
	printf("\n");
}
