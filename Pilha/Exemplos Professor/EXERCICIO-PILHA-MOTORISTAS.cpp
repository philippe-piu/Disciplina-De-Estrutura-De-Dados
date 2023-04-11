#include<stdio.h>
#include <stdlib.h>

#define N_CORRIDAS 200
#define N_MOTORISTAS 15

typedef struct corrida{
    int numeroDaCorrida;
    int IDdoPassageiro;
    float km;
    float valor;
}CORRIDA;

typedef struct motorista{
    int IDdoMotorista;
    CORRIDA minhasCorridas[N_CORRIDAS];
    float valorTotal;
}MOTORISTA;

MOTORISTA motoristas[N_MOTORISTAS];
/* e se... fizer com pilha */

typede struct pilha{
    MOTORISTA pilha[N_MOTORISTAS];
    int topo;
}PILHA;

void push(MOTORISTA m){
    if(topo == N_MOTORISTAS-1){
        printf("Pilha cheia!\n");
    }else{
        topo++;
        pilha[topo] = m;
    }
}

/* .. MOTORISTA pop(){} */


int main(){
    /* preenche os valores */
    for(int i=0; i<N_MOTORISTAS; i++){
       motoristas[i].IDdoMotorista = rand()%1000;
        for(int j=0; j<N_CORRIDAS; j++){
            motoristas[i].minhasCorridas[j].numeroDaCorrida=rand()%100;
            motoristas[i].minhasCorridas[j].IDdoPassageiro=rand()%1000;
            motoristas[i].minhasCorridas[j].km=rand()%30;
            motoristas[i].minhasCorridas[j].valor=motoristas[i].minhasCorridas[j].km*2.5;
            motoristas[i].valorTotal += motoristas[i].minhasCorridas[j].valor;
            
        }
    }


    /*mostra os valores*/
    for(int i=0; i<N_MOTORISTAS; i++){
        printf("Motorista:%d\n",motoristas[i].IDdoMotorista);
        for(int j=0; j<N_CORRIDAS; j++){
            printf("\tCorrida:%d\n",motoristas[i].minhasCorridas[j].numeroDaCorrida);
            printf("\t\tPassageiro:%d\n",motoristas[i].minhasCorridas[j].IDdoPassageiro);
            printf("\t\tKm:%4.2f\n",motoristas[i].minhasCorridas[j].km);
            printf("\t\tValor:%4.2f\n",motoristas[i].minhasCorridas[j].valor);
        }
        printf("Saldo do dia:%4.2f\n",motoristas[i].valorTotal);

    }



    
}
