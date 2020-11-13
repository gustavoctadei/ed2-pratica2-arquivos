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
    int i, j, k;
    char linha[200], caractere;

    for(i = 0; i < TAM; i++) {
        for(j = 0; j < 30; j++) {
            alunos[i].nome[j] = '\0';
            alunos[i].curso[j] = '\0';
        }
        for(j = 0; j < 100; j++) {
            alunos[i].endereco[j] = '\0';
        }
    }

    arquivo = fopen("saida_2.txt", "r");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(i = 0; i < TAM; i++) {
        fscanf(arquivo, "%s", linha);
        j = 0;
        k = 0;
        
        do {
            caractere = linha[j];
            if(caractere == '|') break;
            alunos[i].nome[k] = caractere;
            j++;
            k++;
        } while(1);

        k = 0;
        j++;
        
        do {
            caractere = linha[j];
            if(caractere == '|') break;
            alunos[i].endereco[k] = caractere;
            j++;
            k++;
        } while(1);

        k = 0;
        j++;

        do {
            caractere = linha[j];
            if(caractere == '|') break;
            alunos[i].curso[k] = caractere;
            j++;
            k++;
        } while(1);

    }

    fclose(arquivo);

    //////////////////////////////////////////////////////////////////////////////////////

    arquivo = fopen("saida_3.txt", "w");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(i = 0; i < TAM; i++) {
        printf("%s|%s|%s|\n", alunos[i].nome, alunos[i].endereco, alunos[i].curso);
        fprintf(arquivo, "Nome=%s|Endereco=%s|Curso=%s|\n", alunos[i].nome, alunos[i].endereco, alunos[i].curso);
    }

    fclose(arquivo);

    return 0;
}