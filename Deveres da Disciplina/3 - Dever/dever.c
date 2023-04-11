/*LEMBRETE AINDA N�O ENCONTREI O ERRO DESSE DEVER*/
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

//Chamada de Fun��es
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

//Fun��o de inicializa��o da pilha
void inicializa(PILHA *p)
{
	//Tamanho inicial da Pilha 0
	p->tamanho = 0;
	//Topo definido como nulo
	p->topo = NULL;
}

//Fun��o de preenchimento da pilha
void push(PILHA *p, int valor)
{
	//Aloca��o dinamica para um novo n�
	NODE *novo = (NODE*)malloc(sizeof(NODE));
	//Em caso de erro
	if(novo == NULL)
	{
		//Mensagem de Pilha Cheia
		printf("Pilha se encontra cheia\n");
	}
	else
	{
		//Define valor do dado do n� como valor recebido como argumento
		novo->info = valor;
		//Define antetior como topo anterior da pilha
		novo->ant = p->topo;
		//Define topo como n�
		p->topo = novo;
		//Incrementa tamanho da pilha
		p->tamanho++;
	}
}

//Fun��o de remo��o de valores da pilha
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
		//Define o topo com o n� anterior
		p->topo = (p->topo)->ant;
		//Libera a memoria
		free(auxiliar);
		p->tamanho--;
		return(valor);
	}
}

//Fun��o de imprimir a pilha
void imprime(PILHA *p)
{
	printf("Estado da pilha:\n");
	// Cria um n� auxiliar para o topo da pilha
	NODE *aux = p->topo;
	// Percorre todos os n�s da pilha, come�ando do topo
	while(aux != NULL)
	{
		// Imprime o valor do dado do n� atual
		printf("%d\n", aux->info);
		// Define o n� atual como o anterior na pilha
		aux = aux->ant;
	}
}

//Fun��o Menu
void menu()
{
	printf("MENU\n");
	printf("Escolha uma Letra\n");
	printf("e - Preenche a pilha, d Desempilha a Pilha\n");
	printf("i - Imprime a pilha, s - Fecha programa\n");
}


