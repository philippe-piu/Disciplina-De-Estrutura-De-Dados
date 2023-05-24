//Philippe Aparecido de Lima RA:2102765 Avalia��o 2
#include<stdio.h>
#include<stdlib.h>
#define NUM_INFORMACAO 4

//Struct de informa��o sobre idade e senha da pessoa na espera na fila
typedef struct informcao{
	int idade;
	int senha;
}Informacao;

//Struct da fila de atendimento
typedef struct filaat{
	Informacao informacao[NUM_INFORMACAO];
	/*o inicio e o fim me ajuda a me locomover na fila onde eu insiro e onde removo algo da fila*/
	int iniciofila;
	int finalfila;
	/*tamanho vai inicar em 0 me mostrando que fila est� vazia e vai me ajudar contabilizando quantas
	elementos se encontram na minha fila */
	int tamanho;
}Fila;

//Chamada de Fun��es
void filainiciada(Fila *f);
void preenchimentodafila(Fila *p, int senha, int idade);
void removerelemento(Fila *f);
void opcao();

int main(){
	//fun��o leitura op��o
	opcao();
  
    
	return(0);

}

//Fun��o para iniciar a minha fila
void filainiciada(Fila *f){
	f->iniciofila = 0;
	f->finalfila = -1;
	//Lembrando a minha fila no come�o n�o tem nenhum elemento por isso o tamanho ta como 0
	f->tamanho = 0;
}

//Fun��o de preenchimento da fila
void preenchimentodafila(Fila *f, int senha, int idade){
	/*Se A fila estiver cheia deve me retornar uma mensagem de erro
	se o tamanho me conta quantas pessoas est�o na fila for igual ao tamanho maximo da fila da erro*/
	if(f->tamanho == NUM_INFORMACAO){
		printf("Fila se encontra lotada\n");
	}else{
		//Se a fila n�o estiver Cheia come�o a preencher
		
		/*Estou movimentando meu final fila que � meu final de fila para uma casa na frente no vetor
		 ele est� com menos -1 no primeiro vai para 0 no segundo moviemto vai para 1*/
		f->finalfila++;
		//Se a final fila for igual NUM_INFORMACAO meu final fila volta para zero na posi��o inicial dele
		if(f->finalfila == NUM_INFORMACAO){
			
			f->finalfila = 0;
		}
		
		//Agora eu pego as informa��es de idade e senha e armazeno no final da fila
		//basicamente to armazenando minha fila no vetor
		f->informacao[f->finalfila].senha = senha;
		f->informacao[f->finalfila].idade = idade;
		
		//To informando que o tamanho ta contabilizando quantas pessoas tem na fila acada vez que preencher ela
		//Aqui j� ta adicionado na fila
		f->tamanho++;
	}
}


//Fun��o de Remo��o de Pessoas da fila
void removerelemento(Fila *f){
	/*Se minha fila estiver vazia ele vai o olhar se o tamanho que conta quantas pessoas est�o na fila 
	que vai estar em 0 se for 0 fila est� vazia*/
	if(f->tamanho == 0){
		printf("Fila se encontra vazia\n");
	}else{
		
		//Movendo a inicio fila
		f->iniciofila++;
		f->iniciofila = f->iniciofila % NUM_INFORMACAO;
	
		//Estou fazendo ele decrementar um valor do tamanho que contabiliza quantas pessoas eu tenho na fila
		f->tamanho--;
	}
}

void opcao(){
	char opcao;
	
	printf("i - insere elementos na fila\n");
	printf("r - remove elementos da fila\n");
	
	//La�o de repeti��o para caso o usuario erre a letra
	do{
    //Leitura das op��es de acesso a fila
     scanf("%c", &opcao);
	//Se a op��o for i insere senha e idade na fila
	if(opcao == 'i'){
		
	}else if(opcao == 'r'){
		//Se a op��o for r remove pessoas da fila
		
	}else if(opcao == 'f'){
		//Se a op��o for f imprime o tempo de espera 
		break;
	}
		
	}while(opcao != 'i' && opcao != 'r' && opcao != 'f');

}








