/*Dever de Revisão de Struct
Escreva um programa para ler os dados para todos os motoristas.
*/
#include <stdio.h>

typedef struct corrida{
    int numeroDaCorrida;
    int IDdoPassageiro;
    float km;
    float valor;
} CORRIDA;

typedef struct motorista{
    int IDdoMotorista;
    CORRIDA minhasCorridas[100];
    float valorTotal;
} MOTORISTA;

MOTORISTA motoristas[200];

int main() {
    int i,n,j; // número de motoristas a serem lidos
    printf("Digite o número de motoristas a serem lidos: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("\nDigite o ID do motorista %d: ", i+1);
        scanf("%d", &motoristas[i].IDdoMotorista);
        motoristas[i].valorTotal = 0; // inicializa o valorTotal com zero
        
        int numCorridas;
        printf("Digite o número de corridas do motorista %d: ", i+1);
        scanf("%d", &numCorridas);
        
        for (j = 0; j < numCorridas; j++) {
            printf("\nDigite o número da corrida %d do motorista %d: ", j+1, i+1);
            scanf("%d", &motoristas[i].minhasCorridas[j].numeroDaCorrida);
            
            printf("Digite o ID do passageiro da corrida %d do motorista %d: ", j+1, i+1);
            scanf("%d", &motoristas[i].minhasCorridas[j].IDdoPassageiro);
            
            printf("Digite a distância percorrida na corrida %d do motorista %d: ", j+1, i+1);
            scanf("%f", &motoristas[i].minhasCorridas[j].km);
            
            printf("Digite o valor da corrida %d do motorista %d: ", j+1, i+1);
            scanf("%f", &motoristas[i].minhasCorridas[j].valor);
            
            motoristas[i].valorTotal += motoristas[i].minhasCorridas[j].valor; // adiciona o valor da corrida ao valorTotal do motorista
        }
    }
    
    return 0;
}