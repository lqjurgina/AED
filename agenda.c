#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct contatos{
        char nome[50];
        char telefone[12];
    };

    struct contatos * agenda = NULL;
    int tamanho_da_agenda = 0;

    int busca_contato(){
        int i;
        char nome[50];
        printf("Digite o nome do contato:\n");
        fgets(nome, sizeof(nome), stdin);
        for(i = 0; i < tamanho_da_agenda; i++){
            if(strcmp(nome, agenda[i].nome) == 0){
                printf("Achou o contato\n");
                return 1;
            }
        }
        printf("Contato nao encontrado");
        return 0;
    }

    void inserir_contato(){
        /*Atualizar o tamanho da variávei*/
        tamanho_da_agenda++;
        agenda = realloc(agenda, tamanho_da_agenda*sizeof(struct contatos));
        printf("Digite o nome do contato:\n");
        fgets(agenda[tamanho_da_agenda-1].nome, sizeof(agenda[tamanho_da_agenda-1].nome), stdin);
        printf("Digite o telefone do contato:\n");
        fgets(agenda[tamanho_da_agenda-1].telefone, sizeof(agenda[tamanho_da_agenda-1].telefone), stdin);
    }

    void remover_contato(){
        struct contatos aux;
        int i, j;
        char nome[50];
        printf("Digite o nome do contato:\n");
        fgets(nome, sizeof(nome), stdin);
        for(i = 0; i < tamanho_da_agenda; i++){

            if(strcmp(nome, agenda[i].nome) == 0){

                /*Verifica se é a última posição*/
                if(i != tamanho_da_agenda-1){
                    for(j = i; j < tamanho_da_agenda-1; j++){
                        aux = agenda[i];
                        agenda[i] = agenda[i+1];
                        agenda[i+1] = aux;
                    }
                    //agenda[tamanho_da_agenda-1] = NULL;
                }

                tamanho_da_agenda--;
                agenda = realloc(agenda, tamanho_da_agenda*sizeof(struct contatos));
                break;
            }
        }
    }

    void mostra_contatos(){
        int i;

        if(tamanho_da_agenda == 0)
            printf("Agenda vazia\n");

        for(i = 0; i < tamanho_da_agenda; i++){
            printf("Nome: %s", agenda[i].nome);
            printf("Telefone: %s", agenda[i].telefone);
        }
    }

    int main(){
        int op;
        printf("Digite sua opcao: \n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("4 - Mostrar\n");
        while(1){
            scanf("%d", &op);
            fflush(stdin);
            if(op == 1)
                inserir_contato();
            if(op == 2)
                remover_contato();
            if(op == 3)
                busca_contato();
            if(op == 4)
                mostra_contatos();
            fflush(stdin);
        }
        return 0;
    }
