#include <stdio.h>
#include <stdlib.h>
int *criaVetor(int tam);
void imprimeVetor(int* v, int tamanho);
void liberaMemoria(int* v);
int main() {
	int *vetor,k, n;
	printf("Informe o tamanho do vetor \n");
	scanf("%d", &n);
	printf("tamanho do vetor: %d \n", n);
	vetor = criaVetor(n);
	for (k=0;k<n;k++){
		vetor[k]= k+1;
	}
	imprimeVetor(vetor,n);
	liberaMemoria(vetor);
	return 0;
}

int *criaVetor(int n) {
	int *v;
	v = (int*) malloc (sizeof(int) * n);
	return v;
}

void imprimeVetor(int* v, int tamanho) {
	int i, n2;
	printf("Quantos valores gostaria de imprimir, sendo o vetor com tamanho %d \n", tamanho);
	scanf("%d", &n2);
	for (i = 0; i < n2; i++) {
		printf("%d ", v[i]);
	}

}
void liberaMemoria(int* v) {
	free(v);
}
