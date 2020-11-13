#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2

typedef struct aluno {
    char nome[30];
    char endereco[100];
    char curso[30];
} Aluno;

int main() {
    FILE *arquivo;
    Aluno alunos[TAM];
    int i, tamanho_campo;
    char inteiro[2];

    arquivo = fopen("saida_1.txt", "r");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(i = 0; i < TAM; i++) {
        fread(inteiro, sizeof(char), 2, arquivo);
        tamanho_campo = atoi(inteiro);
        fread(alunos[i].nome, sizeof(char), tamanho_campo, arquivo);
        alunos[i].nome[tamanho_campo] = '\0';

        fread(inteiro, sizeof(char), 2, arquivo);
        tamanho_campo = atoi(inteiro);
        fread(alunos[i].endereco, sizeof(char), tamanho_campo, arquivo);
        alunos[i].endereco[tamanho_campo] = '\0';

        fread(inteiro, sizeof(char), 2, arquivo);
        tamanho_campo = atoi(inteiro);
        fread(alunos[i].curso, sizeof(char), tamanho_campo, arquivo);
        alunos[i].curso[tamanho_campo] = '\0';
    }

    fclose(arquivo);

    //////////////////////////////////////////////////////////////////////////////////////

    arquivo = fopen("saida_2.txt", "w");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(i = 0; i < TAM; i++) {
        printf("%s|%s|%s|\n", alunos[i].nome, alunos[i].endereco, alunos[i].curso);
        fprintf(arquivo, "%s|%s|%s|\n", alunos[i].nome, alunos[i].endereco, alunos[i].curso);
    }

    fclose(arquivo);

    return 0;
}