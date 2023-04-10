/*Escreva um programa que implemente uma pilha de caracteres (char) e permita que 
o usuário insira uma sequência de caracteres. O programa deve, em seguida, 
imprimir a sequência de caracteres na ordem inversa à ordem em que foram inseridos 
na pilha.

Para resolver esse exercício, você pode seguir os seguintes passos:

1 - Crie uma pilha vazia de caracteres.
2 - Permita que o usuário insira uma sequência de caracteres e insira cada 
caractere na pilha usando a função push.
3 - Use a função pop para remover os caracteres da pilha e imprima-os na tela na 
ordem inversa à ordem em que foram inseridos.
*/

#include<stdio.h>
#include<stdlib.h>
#define TAMANHO_PILHA 4

//Variaveis Globais
char pilha[TAMANHO_PILHA];
int topo = -1;

//Chamada de Funções;
void push(char valor);
char pop();
void imprime();

int main(){
	int i;
	char letra;
	//Preenchimento da pilha
	for(i = 0; i < TAMANHO_PILHA; i++){
		printf("Prencha a pilha com letras\n");
		scanf(" %c",&letra);
		push(letra);
	}
	
	system("cls");
	
	//Imprimir A Letras informadas pelo Usuario na ordem inversa  e remover uma letra
	printf("Imprimir informacoes da pilha\n");
	imprime();
	
	printf("Removendo a letra %c da pilha\n",pop());
	imprime();
	
	return(0);
}

//Função de preenchimento da pilha
void push(char valor){
	if(topo == TAMANHO_PILHA - 1){
		printf("Pilha Cheia");
	}else{
		topo++;
		pilha[topo] = valor;
	}
}

//Função para remover itens da pilha
char pop(){
	char auxiliar;
	if(topo == -1){
		printf("Pilha vazia\n");
	}else{
		auxiliar = pilha[topo];
		topo--;
		return(auxiliar);
	}
}

//Função para imprimir pilha
void imprime()
{
	int i;
	for(i = topo; i >=0; i--)
	{
		printf("[%c]\n", pilha[i]);
	}

	printf("\n");
}

