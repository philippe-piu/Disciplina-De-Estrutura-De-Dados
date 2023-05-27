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

//Chamada de Funções
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
	
	//Chamada da Função filainiciada
	filainiciada(&prioritario);
	filainiciada(&normal);
	
	//Chamada da função de leitura
	opcao(&prioritario, &normal);

	//Chamada para imprimir as filas
	imprimir(&prioritario);
	imprimir(&normal);

	//bloco para calcular o tempo medio de espera
	tempoMedioEspera = tempo(&prioritario);
	tempoMedioEspera += tempo(&normal);
	//soma o numero total de pessoas
	
	int numPessoasChamadas = prioritario.tamanho + normal.tamanho;
	if (numPessoasChamadas > 0)
	{
		//media to tempo de espera e de numero de pessoas
		tempoMedioEspera /= numPessoasChamadas;
	}

	//Impri o tempo de espera
	printf("%.2f\n", tempoMedioEspera);

	return 0;
}

//Função para iniciar a minha fila
void filainiciada(Fila *f)
{
	/*o inicio e o fim me ajuda a me locomover na fila onde eu insiro e onde removo algo da fila*/
	f->iniciofila = 0;
	f->finalfila = 0;
	/*tamanho vai inicar em 0 me mostrando que fila está vazia e vai me ajudar contabilizando quantas
	elementos se encontram na minha fila */
	f->tamanho = 0;
}

//Função de preencimento da fila
void preenchimentoFila(Fila *f, int senha, int idade)
{	//Se o tamanho da fila for igual o tamanho do vetor ele está cheio
	if (f->tamanho == NUM_INFORMACAO)
	{
		printf("Fila se encontra Cheia\n");
	}
	else
	{
		//Chamando a Struct Informação
		Informacao in;
		in.senha = senha;
		in.idade = idade;

		f->informacao[f->finalfila] = in;
		//Se o final da fila chegar no final ele volta para 0
		f->finalfila = (f->finalfila + 1) % NUM_INFORMACAO;
		//fila no caso o final da fila ta andando até encher a fila
		f->tamanho++;
	}
}

//Função de Remoção da fila
void removerElementosFila(Fila *f)
{
	//Se o tamanho da fila for igual zero a fila ta vazia
	if (f->tamanho == 0)
	{
		printf("Fila se encontra Vazia\n");
	}
	else
	{
		//Se o inicio da fila chegar no final ele volta para zero
		f->iniciofila = (f->iniciofila + 1) % NUM_INFORMACAO;
		//quando removido um elemento diminue um tamanho da fila
		f->tamanho--;
	}
}

//Função de Chamada da fila
void chamadaFila(Fila *fp, Fila *fn)
{
	//Se a fila prioritaria possuir pessoas vai mostras a pessoa chamada e remover ela da filao msm com o normal
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

//Função de imprimir fila
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

//Função tempo de espera
float tempo(Fila *f)
{
	float tempo = 0;
	int posicaofila, i;
	
	//to acompanhando a fila
	posicaofila = f->iniciofila;

	for (i = 0; i < f->tamanho; i++)
	{
		//Soma do tempo acumulado com o andar da posicão
		tempo += posicaofila;
		posicaofila = (posicaofila + 1) % NUM_INFORMACAO;
	}

	return tempo;
}

//Função de leitura
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























