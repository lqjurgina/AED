#include <stdio.h>
#include <stdlib.h>
/*Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada.*/
void LeValores (int tam, int *vetor);
int main()
{
	int i, n, *v;
	scanf ("%d", &n);
	v = malloc (sizeof (int)* n);
	LeValores (n, v);
	for (i=0; i<n;i++){
		printf("%d ", v[i]);
		}
	free (v);
	return 0;
}
void LeValores (int tam, int*vetor )
{
	int i;
	for (i=0; i<tam; i++){
		scanf("%d", &vetor[i]);
		}
	
}
