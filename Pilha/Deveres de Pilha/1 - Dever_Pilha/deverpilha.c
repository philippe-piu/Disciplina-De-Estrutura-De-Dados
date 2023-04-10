#include<stdio.h>
#define TAMANHO_PILHA 3

/*
Escreva um programa que cria uma pilha de números inteiros 
e insere os valores 1, 2 e 3 nessa pilha. Em seguida, remova os elementos da 
pilha e imprima-os na tela.

Para resolver esse exercício, você pode seguir os seguintes passos:

1 - Crie uma pilha vazia de números inteiros.
2 - Adicione os valores 1, 2 e 3 à pilha usando a função push.
3 - Use a função pop para remover os elementos da pilha e imprima-os na tela.
*/
//Variaveis Globais 
int pilha[TAMANHO_PILHA];
int topo = -1;

//Chamada das Funções
void push(int valor);
int pop();
void imprime();

int main(){
	//Preenchendo pilha
	push(1);
	push(2);
	push(3);
	
	
	//Imprimindo valores preencidos na pilha
	printf("Valores passados para a pilha\n");
	imprime();
	
	//Remomendo o ultimo valor da pilha
	printf("Valor removido da pilha %d\n",pop());
	imprime();
	
	return(0);
}

//Função para preencher Pilha
void push(int valor){
	if(topo == TAMANHO_PILHA -1){
		printf("Pilha se encontra Cheia\n");
	}else{
		topo++;
		pilha[topo] = valor;
	}
}


//Função para remover elementos da pilha;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
int pop(){
	int auxiliar;
	if(topo == -1){
		printf("Pilha Vazia\n");
	}else{
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
		printf("[%d]\n", pilha[i]);
	}

	printf("\n");
}