// Nao se preocupem com isso
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Função de Ordenação por Seleção
// Quick sort function
//Ordena o vetor pelo quick_sort, por ser o mais rápido
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

// mediana : recebe um vetor desordenado e seu tamanho e retorna o valor da mediana dos valor. Assuma que o tamanho eh sempre impar.
int mediana(int * vetor, int tamanho) {

    // SEU CODIGO AQUI
    quick_sort(vetor, 0, tamanho-1);
    return vetor[tamanho / 2];
}

// numNotificacoes : recebe um vetor, seu tamanho e o tamanho do intervalo.
// Retorna o numero de notificacoes que o cliente ira receber segundo o criterio estabelecido na especificacao do problema
int numNotificacoes(int * vetor, int tamanho, int intervalo) {
    int resultado = 0;
    int med;
    int i,j,k;
    int * vet;
    vet = malloc(intervalo*sizeof(int));
    for(i = intervalo; i < tamanho; i++){
        //j = i-1;
        j = i-1;
        k = 0;
        while(k < intervalo){
            vet[k] = vetor[j];
            k++;
            j--;
        }
        med = mediana(vet, intervalo);
        if(vetor[i] >= 2*med)
            resultado++;
    }
    //free(vet);
    return resultado;
}

int main() {
    int tamanho, intervalo, resultado;
    int * vetor;

    printf("---Testes de Validacao---\n");
    printf("1. ");

    tamanho = 9;
    intervalo = 5;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 2;
    vetor[1] = 3;
    vetor[2] = 4;
    vetor[3] = 2;
    vetor[4] = 3;
    vetor[5] = 6;
    vetor[6] = 8;
    vetor[7] = 4;
    vetor[8] = 5;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 2) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 2\n" RESET, resultado);
    }
    free(vetor);

    printf("2. ");

    tamanho = 5;
    intervalo = 3;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 4;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 1) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 0\n" RESET, resultado);
    }
    free(vetor);


    printf("3. ");

    tamanho = 12;
    intervalo = 7;
    vetor = (int *) malloc(tamanho * sizeof(int));
    vetor[0] = 17;
    vetor[1] = 23;
    vetor[2] = 44;
    vetor[3] = 11;
    vetor[4] = 3;
    vetor[5] = 17;
    vetor[6] = 31;
    vetor[7] = 55;
    vetor[8] = 12;
    vetor[9] = 91;
    vetor[10] = 47;
    vetor[11] = 19;
    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 3) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 3\n" RESET, resultado);
    }
    free(vetor);

    printf("4. ");

    tamanho = 27;
    intervalo = 3;
    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetor[i] = (i * 4) + 1;

    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 1) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 1\n" RESET, resultado);
    }
    free(vetor);

    printf("5. ");

    tamanho = 12;
    intervalo = 1;
    vetor = (int *) malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetor[i] = i * i;

    resultado = numNotificacoes(vetor, tamanho, intervalo);

    if (resultado == 3) {
        printf(GREEN " PASS!\n" RESET);
    }
    else {
        printf(RED " FAIL. %d != 3\n" RESET, resultado);
    }
    free(vetor);

    return 0;
}
