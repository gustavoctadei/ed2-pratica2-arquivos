#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[30];
    char endereco[100];
    char curso [30];
} Aluno;

int main() {
    FILE *arquivo;
    Aluno alunos[2];
    int i;

    arquivo = fopen("dados.dat", "wb");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    for(i = 0; i < 2; i++) {
        printf("Digite o nome do Aluno: ");
        fgets(alunos[i].nome, 30, stdin);

        printf("Digite o Endereco do Aluno: ");
        fgets(alunos[i].endereco, 100, stdin);
        
        printf("Digite o Curso do Aluno: ");
        fgets(alunos[i].curso, 30, stdin);

        printf("\n");
    }

    fwrite(alunos, sizeof(Aluno), 2, arquivo);

    fclose(arquivo);

    ///////////////////////////////////////////////

    printf("\n");
    printf("Lendo os alunos do arquivo\n\n");

    arquivo = fopen("dados.dat", "rb");
    if(arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    Aluno alunos_arquivo[2];

    fread(alunos_arquivo, sizeof(Aluno), 2, arquivo);

    for(i = 0; i < 2; i++) {
        printf("Aluno[%d]\n", i);
        printf("Nome: %s", alunos_arquivo[i].nome);
        printf("Endereco: %s", alunos_arquivo[i].endereco);
        printf("Curso: %s", alunos_arquivo[i].curso);
        printf("\n");
    }

    fclose(arquivo);

    return 0;
}