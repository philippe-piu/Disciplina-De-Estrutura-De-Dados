#include<stdio.h>
#include<stdlib.h>
/*1 - Dever Revisão de struct e ponteiros em C

1) Crie as variáveis t1,t2,t3 do tipo triângulo.

2) Crie uma variável chamada ponteiro que seja um ponteiro para uma variável do tipo triângulo

3) Faça ponteiro apontar para t1

4) Preencha e imprima dos dados de t2 usando a variável t2 diretamente

5) Preencha e imprima os dados de t1 a partir da variável ponteiro

6) Crie um outro ponteiro para o tipo triângulo chamado novo.

7) Instancie uma variável do tipo triângulo com a função malloc e faça novo apontar para esta variável. 

8) Preencha os dados da variável apontada por novo

9) Copie o conteúdo da variável apontada por novo para a variável t3

10) Crie um vetor de triângulos chamado vetordetriangulos com 3 posições e preencha estes dados usando 
o vetor.
 */
typedef struct triangulo{
    float base;
    float altura;
}TRIANGULO;

int main(){
	TRIANGULO t1,t2,t3;
	TRIANGULO *ponteiro;
	
	t1.base = 2.0;
	t1.altura = 3.0;
	t2.base = 1.0;
	t2.altura = 3.5;
	t3.base = 4.0;
	t3.altura = 5.0;
	
	ponteiro =&t1;
	
	printf("T2 - %.1f, %.1f\n",t2.base,t2.altura);
	printf("T1 - %.1f, %.1f\n",ponteiro->base,ponteiro->altura);
	
	TRIANGULO *novo = (TRIANGULO *) malloc (sizeof (TRIANGULO));
	
	novo->base = 8.0;
	novo->altura = 7.0;
	
	t3 = *novo;
	
	printf("T3 - %.1f, %.1f\n",novo->base,novo->altura);
	free(novo);
	
	//Vetor
	TRIANGULO vetordetriangulos[3];
	
	printf("Preecher o Vetor\n");
	int i;
	for(i = 0; i < 3; i++){
		printf("Base\n");
		scanf("%f",&vetordetriangulos[i].base);
		printf("Altura\n");
		scanf("%f",&vetordetriangulos[i].altura);
	}
	
	int j;
	
	for(j = 0; j < 3; j++){
		printf("Vetor = Base %.1f, Altura %.1f\n",vetordetriangulos[j].base,vetordetriangulos[j].altura);
	}
	
	
	return(0);
}