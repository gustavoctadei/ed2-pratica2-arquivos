#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct aluno {
    char nome[30];
    int numero_matricula;
} Aluno;

int main() {
    FILE *arquivo;
    Aluno alunos[TAM];
    int i;

    arquivo = fopen("alunos.dat", "wb");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(i = 0; i < TAM; i++) {
        printf("Digite o nome do Aluno: ");
        fflush(stdin);
        fgets(alunos[i].nome, 30, stdin);
        
        alunos[i].numero_matricula = i+1;
        printf("O Numero de matricula do Aluno eh: %d\n\n", alunos[i].numero_matricula);
    }

    fwrite(alunos, sizeof(Aluno), TAM, arquivo);

    fclose(arquivo);

    ///////////////////////////////////////////////

    arquivo = fopen("alunos.dat", "rb");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    Aluno alunos_arquivo[2];

    fread(alunos_arquivo, sizeof(Aluno), 2, arquivo);
    
    printf("Digite o Numero de Matricula a ser buscado: ");
    scanf("%d", &i);

    if(i < 1 || i > TAM) {
        printf("Matricula Inexistente.\n");
    }
    else {
        i--;
        printf("Aluno Encontrado\n");
        printf("Numero Matricula: %d | Nome: %s\n", alunos_arquivo[i].numero_matricula, alunos_arquivo[i].nome);
    }

    fclose(arquivo);

    return 0;
}