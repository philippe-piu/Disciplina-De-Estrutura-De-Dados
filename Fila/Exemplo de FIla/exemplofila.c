//Exemplo de fila
#include<stdio.h>
#define TAMANHO_MAX 6

//Variáveis Globais
//Array que será utilizado na pilha
int queue[TAMANHO_MAX];
//Declaração de variaveis do primeiro e de ultimo item da fila
int front = -1;
int rear = -1;

//Chamada de Funções
void enqueue(int x);
void dequeue();
void imprimefila();

//Main
int main()
{
	//preenchendo a fila
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);

	printf("\n");

	//Imprime a Fila Adiicionada;
	imprimefila();
	printf("\n");

	//Removendo valores da fila
	dequeue();
	dequeue();
	dequeue();

	//Imprime a Fila depois da remoção;
	printf("\n");
	imprimefila();
	printf("\n");

	//novos valores da fila a fila
	enqueue(6);
	enqueue(7);

	//Imprime a Fila depois da remoção;
	printf("\n");
	imprimefila();
	printf("\n");

	return(0);
}

//Função para adicionar a fila;
void enqueue(int x)
{
	//Verificação se a pilha se encontra cheia
	if(rear == TAMANHO_MAX - 1)
	{
		//Mensagem de fila cheia
		printf("A fila se encontra Cheia!!!\n");
	}
	else   //Caso a pilha esteja Vazia
	{
		//Se a filha se encontar vazia define seu primeiro elemento
		if(front == -1)
		{
			front = 0;
		}
		//incrementa um valor ao ultimo elemento da fila
		rear++;
		//Coloca um elemento na fila
		queue[rear] = x;
		printf("%d esta inserido na fila\n",x);
	}
}

//Função para remoção de item da fila
void dequeue()
{
	//Verificação se a pilha está vazia;
	if(front == -1 || front > rear)
	{
		//Mensagem que a pilha se encontra vazia
		printf("Fila Vazia !!!!");
	}
	else   // Se não remove um valor da fila
	{
		printf("%d foi removido da fila com Sucesso !!!\n", queue[front]);
		//incrementa o indice do primeiro elemento da fila;
		front++;
	}
}

//Função de imprir a Fila
void imprimefila()
{
	//Verifica se fila se encontra vazia
	if(front == -1 || front > rear)
	{
		//Mensagem que a pilha se encontra vazia
		printf("Fila Vazia !!!!");
	}
	else
	{
		int i;
		printf("Elementos da fila\n");
		//Percorre toda a fila
		for(i = front; i <= rear; i++)
		{
			//Imprime a fila
			printf("%d \n", queue[i]);
		}
		printf("\n");
	}
}
