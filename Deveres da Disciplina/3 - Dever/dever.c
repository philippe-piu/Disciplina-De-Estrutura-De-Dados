/* Tem Erro  Lembrar de encontrar o erro
(1) Implemente  (em C) um programa para empilhar números inteiros.
O programa deve funcionar da seguinte forma:

- Recebe em um caractere indicando se empilha ('e') e na linha seguinte o
número a ser empilhado,

desempilha ('d') e mostra o caractere desempilhado,

imprime ('i') e mostra o estado da pilha

ou sai ('s') e fecha o programa.

Exemplo de entrada:

e
10
e
20
e
30
d
i
Saída correspondente:
desempilhado = 30
Estado da pilha
20
10
----
*/
#include<stdio.h>
#include<stdlib.h>

//Estruturas
typedef struct node
{
	//dados
	int info;
	//ponteiro anteior
	struct node *ant
		} NODE;

typedef struct pilha
{
	//ponteiro para o topo da pilha
	NODE *topo;
	//tamanho da pilha
	int tamanho;
} PILHA;


//Chamada de funções;
void inicializa(PILHA *p);
void push(PILHA *p, int valor);
int pop(PILHA *p);
void imprime(PILHA *p);
void menu(PILHA *p);

int main()
{
	PILHA p;
	inicializa(&p);
	menu(&p);

	return(0);
}

//Função de Inicialização da pilha

void inicializa(PILHA *p)
{
	//Tamanho inicial da Pilha 0
	p->tamanho = 0;
	//Topo definido como nulo
	p->topo = NULL;
}

//Função de preenchimento da pilha
void push(PILHA *p, int valor)
{
	//Alocação dinamica para um novo nó
	NODE *novo = (NODE*)malloc(sizeof(NODE));
	//Em caso de erro
	if(novo == NULL)
	{
		//Mensagem de Pilha Cheia
		printf("Pilha Cheia");
	}
	else
	{
		//Define valor do dado do nó como valor recebido como argumento
		novo->info = valor;
		//Define antetior como topo anterior da pilha
		novo->ant = p->topo;
		//Define topo como nó
		p->topo = novo;
		//incrementa tamanho da pilha
		p->tamanho++;
	}
}

//Função de remover valores da pilha
int pop(PILHA *p)
{
	int valor;
	//Caso a pilha esteja vazia
	if(p->topo == NULL)
	{
		//Mensagem de pilha Vazia
		printf("Pilha Vazia\n");
		return 0;
	}
	else
	{
		//Cria um auxiliar para topo da pilha
		NODE *auxiliar = p->topo;
		//VAriavel recebe o topo
		valor = (p->topo)->info;
		//Define o topo com o nó anterior
		p->topo = (p->topo)->ant;
		//Libera a memoria
		free(auxiliar);
		p ->tamanho--;
		return (valor);
	}
}

// Função que imprime o estado atual da pilha
void imprime(PILHA *p)
{
	printf("Estado da pilha:\n");
	// Cria um nó auxiliar para o topo da pilha
	NODE *aux = p->topo;
	// Percorre todos os nós da pilha, começando do topo
	while(aux != NULL)
	{
		// Imprime o valor do dado do nó atual
		printf("%d\n", aux->info);
		// Define o nó atual como o anterior na pilha
		aux = aux->ant;
	}
}


//Função menu
void menu(PILHA *p)
{
	char opcao;
	int valor;
	do
	{
		//Opção para o usuario
		printf("Escolha a Oprecao que deseja fazer\n");
		printf("Opcoes e - Empilha a Pilha\n");
		printf("Opcoes d - Desempilha a Pilha\n");
		printf("Opcoes i - Imprime a Pilha\n");
		printf("Opcoes s - Fecha programa\n");
		//Leitura da Opção
		scanf(" %c", &opcao);
		//Ações apartir da escolha
		switch(opcao)
		{
		case 'e':
			printf("Informe Valor para a pilha\n");
			scanf("%d", &valor);
			push(p, valor);
			break;
		case 'd':
			valor = pop(p);
			printf("Desenpilha a Pilha\n");
			break;
		case 'i':
			imprime(p);
			break;
		case 's':
			exit(0);
			break;
		default:
			printf("Opcao errada tente de novo\n");
			break;
		}

	}
	while((opcao != 'e') && (opcao != 'd') && (opcao != 'i') && (opcao != 's'));
}
