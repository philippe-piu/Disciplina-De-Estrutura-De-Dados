/*LEMBRETE AINDA NÃO ENCONTREI O ERRO DESSE DEVER*/
#include<stdio.h>
#include<stdlib.h>

//Estrutura
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

//Chamada de Funções
void inicializa(PILHA *p);
void push(PILHA *p, int valor);
int pop(PILHA *p);
void imprime(PILHA *p);
void menu();
void loopmenu(PILHA p);

int main()
{
	PILHA p;
	inicializa(&p);
	int numero;
	char opcao;

	do
	{
		//Menu
		menu();
		scanf(" %c", &opcao);
		switch(opcao)
		{
		case 'e':
			printf("Informe valor a ser preenchido na Pilha:\n");
			scanf("%d", &numero);
			push(&p, numero);
			break;
		case 'd':
				numero = pop(&p);
			printf("Removendo o %d\n", numero);
			break;
		case 'i':
				imprime(&p);
			break;
		case 's':
				exit(1);
			break;
		default:
			printf("Letra informada esta incorreta\n");
			break;
		}

	}
	while(opcao != 'e' && opcao != 'd' && opcao != 's' && opcao != 'i');
	
	return(0);
}

//Função de inicialização da pilha
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
		printf("Pilha se encontra cheia\n");
	}
	else
	{
		//Define valor do dado do nó como valor recebido como argumento
		novo->info = valor;
		//Define antetior como topo anterior da pilha
		novo->ant = p->topo;
		//Define topo como nó
		p->topo = novo;
		//Incrementa tamanho da pilha
		p->tamanho++;
	}
}

//Função de remoção de valores da pilha
int pop(PILHA *p)
{
	//Caso a pilha esteja vazia
	if(p->topo == NULL)
	{
		printf("Pilha esta Vazia\n");
		return 0;
	}
	else
	{
		//Cria um auxiliar para topo da pilha
		NODE *auxiliar = p->topo;
		//Variavel recebe o topo
		int valor = (p->topo)->info;
		//Define o topo com o nó anterior
		p->topo = (p->topo)->ant;
		//Libera a memoria
		free(auxiliar);
		p->tamanho--;
		return(valor);
	}
}

//Função de imprimir a pilha
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

//Função Menu
void menu()
{
	printf("MENU\n");
	printf("Escolha uma Letra\n");
	printf("e - Preenche a pilha, d Desempilha a Pilha\n");
	printf("i - Imprime a pilha, s - Fecha programa\n");
}


