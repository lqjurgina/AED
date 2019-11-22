#include <stdio.h>
#include <stdlib.h>
#define capacidade 10

struct pilha {
	int topo, elemento[capacidade];
};

int verificaPilhaVazia (struct pilha *p);
void reset(struct pilha *p);
int verificaPilhaCheia(struct pilha *p);
int push (struct pilha *p, int valor);
int pop (struct pilha *p);
int printPilha (struct pilha *p);
int reempilha (struct pilha *p, struct pilha *pPar, struct pilha *pImpar);
int empilha (struct pilha *p);

int main(){
	struct pilha pilha1, pilhaPar, pilhaImpar;
	reset (&pilha1);
	reset (&pilhaPar);
	reset (&pilhaImpar);
	empilha (&pilha1);
    reempilha (&pilha1, &pilhaPar, &pilhaImpar);
    printf ("\nPilha Par:");
    printPilha (&pilhaPar);
    printf ("\n\nPilha Impar: ");
    printPilha (&pilhaImpar);
    printf("\n\n\n");
    return 0;
}

int verificaPilhaVazia(struct pilha *p){
	
	if (p->topo == -1){
		printf ("Pilha vazia!\n");
		return 1;
	} 
	else {
		printf ("Pilha já inicializada\n");
		return 0;
	}
}
int verificaPilhaCheia(struct pilha *p){
	
	if (p->topo == capacidade -1){
		printf ("Pilha cheia!\n");
		return 1;
	} 
	else {
		printf ("Pilha com espaco \n");
		return 0;
	}
}
void reset(struct pilha *p){
	p->topo = -1;
}
int push (struct pilha *p, int valor){
	return (p->elemento[++(p->topo)] = valor);
	}
int pop (struct pilha *p){
	int auxiliar;
	auxiliar = (p->elemento[(p->topo)--]);
	return auxiliar;
	}


int printPilha (struct pilha *p){
	int auxiliar;
	if (verificaPilhaVazia(p)){
		return 1;
		}
	else {
		auxiliar = pop (p);
		printf ("%d", auxiliar);
		printPilha (p);
		return 0;
	}
}
	int reempilha (struct pilha *p, struct pilha *pPar, struct pilha *pImpar){
		/*Separando a pilha em par e ímpar*/
		
		int auxiliar;
		if (verificaPilhaVazia (p)){
			return 1;
		}else{
			/*separando a pilha impar*/
			if (p->elemento[p->topo]%2){
				auxiliar = pop (p);
				push (pImpar, auxiliar);
				}else{
					auxiliar = pop (p);
					push (pPar, auxiliar);					
					}
			reempilha (p, pPar, pImpar);
			return 0;
		}
		
	}
	
	int empilha (struct pilha *p){
		
		int valor;
		printf ("Informe um valor para ser empilhado\n");
		scanf ("%d", &valor);
		
		if (verificaPilhaCheia (p)){
			return 1;
			}else{
				push (p, valor);
				empilha (p);
				return 0;
			}
		}
