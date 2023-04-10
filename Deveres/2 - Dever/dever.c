#include<stdio.h>

/*2 - Dever de Revisão de Struct
Escreva um programa para ler os dados para todos os motoristas.
*/
typedef struct corrida{
    int numeroDaCorrida;
    int IDdoPassageiro;
    float km;
    float valor;
}CORRIDA;

typedef struct motorista{
    int IDdoMotorista;
    CORRIDA minhasCorridas[100];
    float valorTotal;
}MOTORISTA;

MOTORISTA motoristas[200];

int main(){
	
	return(0);
}