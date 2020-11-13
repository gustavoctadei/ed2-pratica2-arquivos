#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2

typedef struct aluno {
    char nome[30];
    char endereco[100];
    char curso [30];
} Aluno;

int main() {
    FILE *arquivo;
    Aluno alunos[TAM];
    int i;

    arquivo = fopen("entrada.txt", "r");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(i = 0; i < TAM; i++) {
        fscanf(arquivo, "%s %s %s", alunos[i].nome, alunos[i].endereco, alunos[i].curso);
    }

    fclose(arquivo);

    //////////////////////////////////////////////////////////////////////////////////////

    arquivo = fopen("saida_1.txt", "w");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(i = 0; i < TAM; i++) {
        printf("%.2d %s ", strlen(alunos[i].nome), alunos[i].nome);
        printf("%.2d %s ", strlen(alunos[i].endereco), alunos[i].endereco);
        printf("%.2d %s\n", strlen(alunos[i].curso), alunos[i].curso);

        fprintf(arquivo, "%.2d%s", strlen(alunos[i].nome), alunos[i].nome);
        fprintf(arquivo, "%.2d%s", strlen(alunos[i].endereco), alunos[i].endereco);
        fprintf(arquivo, "%.2d%s", strlen(alunos[i].curso), alunos[i].curso);
    }

    fclose(arquivo);

    return 0;
}