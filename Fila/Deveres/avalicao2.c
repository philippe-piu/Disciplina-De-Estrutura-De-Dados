//Philippe Aparecido de Lima RA:2102765 Avaliação 2
#include<stdio.h>
#include<stdlib.h>
#define NUM_INFORMACAO 4

//Struct de informação sobre idade e senha da pessoa na espera na fila
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
	/*tamanho vai inicar em 0 me mostrando que fila está vazia e vai me ajudar contabilizando quantas
	elementos se encontram na minha fila */
	int tamanho;
}Fila;

//Chamada de Funções
void filainiciada(Fila *f);
void preenchimentodafila(Fila *p, int senha, int idade);
void removerelemento(Fila *f);
int main(){
	
  
    
	return(0);

}

//Função para iniciar a minha fila
void filainiciada(Fila *f){
	f->iniciofila = 0;
	f->finalfila = -1;
	//Lembrando a minha fila no começo não tem nenhum elemento por isso o tamanho ta como 0
	f->tamanho = 0;
}

//Função de preenchimento da fila
void preenchimentodafila(Fila *f, int senha, int idade){
	/*Se A fila estiver cheia deve me retornar uma mensagem de erro
	se o tamanho me conta quantas pessoas estão na fila for igual ao tamanho maximo da fila da erro*/
	if(f->tamanho == NUM_INFORMACAO){
		printf("Fila se encontra lotada\n");
	}else{
		//Se a fila não estiver Cheia começo a preencher
		
		/*Estou movimentando meu final fila que é meu final de fila para uma casa na frente no vetor
		 ele está com menos -1 no primeiro vai para 0 no segundo moviemto vai para 1*/
		f->finalfila++;
		//Se a final fila for igual NUM_INFORMACAO meu final fila volta para zero na posição inicial dele
		if(f->finalfila == NUM_INFORMACAO){
			
			f->finalfila = 0;
		}
		
		//Agora eu pego as informações de idade e senha e armazeno no final da fila
		//basicamente to armazenando minha fila no vetor
		f->informacao[f->finalfila].senha = senha;
		f->informacao[f->finalfila].idade = idade;
		
		//To informando que o tamanho ta contabilizando quantas pessoas tem na fila acada vez que preencher ela
		//Aqui já ta adicionado na fila
		f->tamanho++;
	}
}

//Função de Remoção de Pessoas da fila
void removerelemento(Fila *f){
	/*Se minha fila estiver vazia ele vai o olhar se o tamanho que conta quantas pessoas estão na fila 
	que vai estar em 0 se for 0 fila está vazia*/
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

//Função de 
void opcao(){
	char acao;
	int senha, idade;
	
	Fila prioritario;
	Fila normal
	//if de opções
	if(acao == 'i'){
		//Se idade for maior e igual a 60 ele insere um elemento na fila prioritario se não normal
		if(idade >=60){
			preenchimentodafila(&prioritario, &senha, &idade);
		}else{
			preenchimentodafila(&normal, &seha, &idade);
		}
	}else if(acao == 'r'){
		op
	}
}

