/*Exemplo Professor em aula
Escreva um programa para ler os dados para todos os motoristas.
*/

#include <stdio.h>
#include <stdlib.h>

// define a estrutura CORRIDA
typedef struct corrida
{
	int numeroDaCorrida;
	int IDdoPassageiro;
	float km;
	float valor;
} CORRIDA;

// define a estrutura MOTORISTA
typedef struct motorista
{
	int IDdoMotorista;
	CORRIDA minhasCorridas[100]; // array de corridas do motorista
	float valorTotal; // valor total ganho pelo motorista com as corridas
} MOTORISTA;

// declara um array de MOTORISTA com 200 posi��es
MOTORISTA motoristas[200];

// declara��o das fun��es push e pop para a pilha de MOTORISTA
typedef struct node
{
	MOTORISTA motorista;
	struct node *next;
} NODE;

NODE *top = NULL; // inicializa a pilha como vazia

void push(MOTORISTA m)
{
	NODE *newNode = (NODE*) malloc(sizeof(NODE)); // cria um novo n�
	newNode->motorista = m;
	newNode->next = top;
	top = newNode; // atualiza o topo da pilha
}

MOTORISTA pop()
{
	NODE *temp;
	MOTORISTA m;

	if (top == NULL)   // verifica se a pilha est� vazia
	{
		printf("A pilha est� vazia.\n");
		exit(1);
	}

	temp = top; // guarda o topo da pilha em uma vari�vel tempor�ria
	m = temp->motorista; // guarda o MOTORISTA do topo da pilha em uma vari�vel
	top = top->next; // atualiza o topo da pilha
	free(temp); // libera a mem�ria alocada pelo n� que foi removido

	return m; // retorna o MOTORISTA removido
}

int main()
{
	int n; // n�mero de motoristas a serem lidos
	printf("Digite o n�mero de motoristas a serem lidos: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("\nDigite o ID do motorista %d: ", i + 1);
		int idMotorista;
		scanf("%d", &idMotorista);

		int numCorridas;
		printf("Digite o n�mero de corridas do motorista %d: ", i + 1);
		scanf("%d", &numCorridas);

		MOTORISTA m;
		m.IDdoMotorista = idMotorista;
		m.valorTotal = 0; // inicializa o valorTotal com zero

		// l� os dados de cada corrida do motorista e atualiza o valorTotal
		for (int j = 0; j < numCorridas; j++)
		{
			printf("\nDigite o n�mero da corrida %d do motorista %d: ", j + 1, i + 1);
			scanf("%d", &m.minhasCorridas[j].numeroDaCorrida);

			printf("Digite o ID do passageiro da corrida %d do motorista %d: ", j + 1, i + 1);
			scanf("%d", &m.minhasCorridas[j].IDdoPassageiro);

			printf("Digite a dist�ncia percorrida na corrida %d do motorista %d: ", j + 1, i + 1);
			scanf("%f", &m.minhasCorridas[j].km);

			// calcula o valor da corrida com base na dist�ncia percorrida (considerando R$ 2,50 por km)
			m.minhasCorridas[j].valor = 2.5 * m.minhasCorridas[j].km;
			m.valorTotal += m.minhasCorridas[j].valor; // atualiza o valorTotal com o valor da corrida
		}

		push(m); // adiciona o motorista lido na pilha
	}

	// imprime os dados de cada motorista desempilhando a pilha
	while (top != NULL)
	{
		MOTORISTA m = pop();
		printf("\nID do motorista: %d\n", m.IDdoMotorista);
		printf("Corridas:\n");
		for (int i = 0; i < 100; i++)
		{
			if (m.minhasCorridas[i].numeroDaCorrida == 0)
			{
				break;
			}
			printf("  Corrida %d - Passageiro: %d, Dist�ncia: %.2f km, Valor: R$ %.2f\n", m.minhasCorridas[i].numeroDaCorrida, m.minhasCorridas[i].IDdoPassageiro, m.minhasCorridas[i].km, m.minhasCorridas[i].valor);
		}
		printf("Valor total ganho: R$ %.2f\n", m.valorTotal);
	}

	return 0;
}
