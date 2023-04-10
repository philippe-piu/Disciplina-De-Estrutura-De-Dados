#include<stdio.h>
#define TAMANHO_PILHA 4

//Variaveis Globais
int pilha[TAMANHO_PILHA]; //Pilha
//topo inicio da pilha
int topo = -1 ;//Pilha Vazia

//Chamada das Funções
void push(int valor);
int pop();
void imprime();

//Exemplo de Pilha
int main()
{

	//Preencher a pilha
	push(1);
	push(2);
	push(3);
	push(4);

	//Imprimindo a Pilha
	printf("Imprimir conteudo da Pilha\n");
	imprime();
	
	//Remoção do ultimo conteudo da pilha
	printf("Removido da Pilha %d\n",pop());
	imprime();
	
	//Adicionar um novo Valor a Pilha 
	printf("Novo Valor adicionado na Pilha \n");
	push(10);
	imprime();
	
	return(0);
}


//Função para adicionar a elementos na pilha
void push(int valor)
{
	//Verificação para saber se a pilha já está cheia
	if(topo == TAMANHO_PILHA - 1)
	{
		//Se a pilha estiver cheia informa o usuario
		printf("Pilha Cheia e novo elemento não será enserido");
	}
	else
	{
		//Adicionar um valor na posição apontada pelo o ponteiro no topo
		topo++;
		pilha[topo] = valor;
	}
}


//Função para tirar valores da pilha;
int pop()
{
	int auxiliar;
	//Verificar se a pilha se encontra vazia
	if(topo == -1)
	{
		printf("Pilha Vazia");
	}
	else
	{
		//Decrementar um valo ao ponteiro do topo
		auxiliar = pilha[topo];
		topo--;
		return(auxiliar);
	}
}

//Função para emprimir a pilha
void imprime()
{
	int i;
	for(i = topo; i >= 0; i--)
	{
		printf("Posicao Pilha %d [%d]\n", i, pilha[i]);
	}

	printf("\n");
}
