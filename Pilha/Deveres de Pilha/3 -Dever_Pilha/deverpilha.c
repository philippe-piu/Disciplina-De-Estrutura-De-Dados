/*Crie uma estrutura pilha com um array de inteiros e um topo inteiro.
A estrutura deve ser capaz de armazenar no m�ximo 10 elementos. Crie fun��es push
e pop que adicionem e removam elementos da pilha, respectivamente. Al�m disso,
crie uma fun��o imprime que imprima todos os elementos da pilha.

Para implementar a fun��o push, voc� deve receber como par�metros a pilha e o
valor a ser adicionado. A fun��o deve verificar se a pilha est� cheia e, se n�o
estiver, adicionar o valor ao topo da pilha.

Para implementar a fun��o pop, voc� deve receber como par�metro a pilha e
retornar o valor do topo da pilha. A fun��o deve verificar se a pilha est� vazia
e, se n�o estiver, remover o valor do topo da pilha.

Para implementar a fun��o imprime, voc� deve receber como par�metro a pilha e
imprimir todos os valores armazenados na pilha, do topo at� a base.
*/

#include<stdio.h>
#define TAMANHO_PILHA 10

//Estrutura da PILHA
typedef struct pilha
{
	int pilha[TAMANHO_PILHA];
	int topo;
} PILHA;

//Chamada das fun��es;
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

//Fun��o de preenchimento da pilha
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

//Fun��o Removendo pilha
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
