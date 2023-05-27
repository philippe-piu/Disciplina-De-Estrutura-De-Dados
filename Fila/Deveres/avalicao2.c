//Philippe Aparecido de Lima RA:2102765 Avaliação 2

#include <stdio.h>

#define NUM_INFORMACAO 4

typedef struct informacao
{
	int idade;
	int senha;
} Informacao;

typedef struct filaat
{
	Informacao informacao[NUM_INFORMACAO];
	int iniciofila;
	int finalfila;
	int tamanho;
} Fila;

void filainiciada(Fila *f);
void preenchimentoFila(Fila *f, int senha, int idade);
void removerElementosFila(Fila *f);
void chamadaFila(Fila *fp, Fila *fn);
void imprimir(Fila *f);
float tempo(Fila *f);
void opcao(Fila *prioritario, Fila *normal);

int main()
{
	Fila prioritario, normal;
	float tempoMedioEspera;

	filainiciada(&prioritario);
	filainiciada(&normal);
	opcao(&prioritario, &normal);

	imprimir(&prioritario);
	imprimir(&normal);

	tempoMedioEspera = tempo(&prioritario);
	tempoMedioEspera += tempo(&normal);
	int numPessoasChamadas = prioritario.tamanho + normal.tamanho;
	if (numPessoasChamadas > 0)
	{
		tempoMedioEspera /= numPessoasChamadas;
	}

	printf("%.2f\n", tempoMedioEspera);

	return 0;
}

void filainiciada(Fila *f)
{
	/*o inicio e o fim me ajuda a me locomover na fila onde eu insiro e onde removo algo da fila*/
	f->iniciofila = 0;
	f->finalfila = 0;
	/*tamanho vai inicar em 0 me mostrando que fila está vazia e vai me ajudar contabilizando quantas
	elementos se encontram na minha fila */
	f->tamanho = 0;
}

void preenchimentoFila(Fila *f, int senha, int idade)
{
	if (f->tamanho == NUM_INFORMACAO)
	{
		printf("Fila se encontra Cheia\n");
	}
	else
	{
		Informacao in;
		in.senha = senha;
		in.idade = idade;

		f->informacao[f->finalfila] = in;
		f->finalfila = (f->finalfila + 1) % NUM_INFORMACAO;
		f->tamanho++;
	}
}

void removerElementosFila(Fila *f)
{
	if (f->tamanho == 0)
	{
		printf("Fila se encontra Vazia\n");
	}
	else
	{
		f->iniciofila = (f->iniciofila + 1) % NUM_INFORMACAO;
		f->tamanho--;
	}
}

void chamadaFila(Fila *fp, Fila *fn)
{
	if (fp->tamanho > 0)
	{
		printf("%d\n", fp->informacao[fp->iniciofila].senha);
		removerElementosFila(fp);
	}
	else if (fn->tamanho > 0)
	{
		printf("%d\n", fn->informacao[fn->iniciofila].senha);
		removerElementosFila(fn);
	}
}

void imprimir(Fila *f)
{
	int i, posicaofila;
	posicaofila = f->iniciofila;

	for (i = 0; i < f->tamanho; i++)
	{
		printf("%d\n", f->informacao[posicaofila].senha);
		posicaofila = (posicaofila + 1) % NUM_INFORMACAO;
	}
}

float tempo(Fila *f)
{
	float tempo = 0;
	int posicaofila, i;
	posicaofila = f->iniciofila;

	for (i = 0; i < f->tamanho; i++)
	{
		tempo += posicaofila;
		posicaofila = (posicaofila + 1) % NUM_INFORMACAO;
	}

	return tempo;
}

void opcao(Fila *prioritario, Fila *normal)
{
	char opcao;
	int senha, idade;

	printf("Exemplo de como se deve inserir\n");
	printf("i senha idade\n");
	printf("r senha idade\n");
	printf("f Finaliza\n");

	do
	{
		scanf(" %c %d %d", &opcao, &senha, &idade);

		if (opcao == 'i')
		{
			if (idade >= 60)
			{
				preenchimentoFila(prioritario, senha, idade);
			}
			else
			{
				preenchimentoFila(normal, senha, idade);
			}
		}
		else if (opcao == 'r')
		{
			chamadaFila(prioritario, normal);
		}
		else if (opcao == 'f')
		{
			break;
		}
	} while (opcao != 'f');
}























