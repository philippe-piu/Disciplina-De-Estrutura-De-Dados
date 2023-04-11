/*Pilha exemplo do professor com Alocação dinâmica*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char info;//dado
    struct node *ant; //ponteiro para o nó anterior.
}NODE;

typedef struct pilha{
    NODE *topo;
    int tamanho;
}PILHA;

void inicializa(PILHA *p){
    p->tamanho = 0;
    p->topo = NULL;
}

void push(PILHA *p, char c){
    NODE *novo = (NODE *)malloc(sizeof(NODE));
    if(novo == NULL){printf("Pilha cheia!\n");}
    else{
        novo->info = c;
        novo->ant = p->topo;
        p->topo = novo;
        p->tamanho++;
    }
}

char pop(PILHA *p){
    if(p->topo == NULL){
        printf("Pilha vazia!\n");
        return '\0';
    }else{
        NODE *aux = p->topo;
        char c = (p->topo)->info;
    
        p->topo = (p->topo)->ant;
        free(aux);
        return c;
    }
}



int main(){
    PILHA container1, container2;
    inicializa(&container1);
    inicializa(&container2);
    push(&container1,'A');
    push(&container2,'B');
    printf("CTA=%c\n",pop(&container1));
    printf("CTB=%c\n",pop(&container2));
    printf("CTB=%c\n",pop(&container2));
    
}



