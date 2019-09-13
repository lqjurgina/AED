#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int k, int j);
void liberaMemoria (int **v);
int main(){
	int **matriz, m, n;
	printf("Informe o numero de linhas e de colunas\n");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("Numero de linhas: %d, Numero de colunas: %d\n", m, n);
	matriz  = alocaMatriz(m, n);
	liberaMemoria(matriz);
	return 0;
}
int **alocaMatriz(int k, int j){
	int **m, i, n;
	m = (int**) malloc (sizeof (int*) * k);
	if (m==NULL){
		printf("erro!");
		}
		for (i=0;i<k;i++){
			m[i] = (int*) malloc (sizeof (int)*j);
			for (n=0;n<j;n++){
				m[i][n] = i+1;
				printf("%d", m[i][n]);
				}
		}
	return m;
}

void liberaMemoria (int **v){
	free (v);
}
