// cadastro.c
#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"

// Função para criar N alunos
cadastro* criarAlunos(int n) {
    cadastro *alunos = (cadastro*) malloc(n * sizeof(cadastro));
    if (alunos != NULL) {
        for (int i = 0; i < n; i++) {
            alunos[i].RA = i + 1;
            alunos[i].P1 = 0.0;
            alunos[i].P2 = 0.0;
            alunos[i].media = 0.0;
        }
    }
    return alunos;
}

// Função para modificar a nota de um aluno específico
void modificarNota(cadastro *aluno, int n, int RA, int P) {
    // verifica se o ra é válido (qualquer ra com valor superior ao nº de alunos cadastrados é inválido)
    if (RA < 1 || RA > n) {
        printf("RA inválido.\n");
        return;
    }

    float nota;
    printf("Digite a nota para o aluno %d: ", RA);
    scanf("%f", &nota);

    if (P == 1) {
        aluno[RA - 1].P1 = nota;
    } else if (P == 2) {
        aluno[RA - 1].P2 = nota;
    } else {
        printf("Prova inválida.\n");
    }
}

// Função para calcular a média do aluno com um RA específico
void calcularMedia(cadastro *aluno, int RA) {
    aluno[RA - 1].media = (aluno[RA - 1].P1 + aluno[RA - 1].P2) / 2;
}

// Função para determinar o aluno com a maior média
void determinarMaiorMedia(cadastro *aluno, int n) {
    int RAMaiorMedia = 1;
    float maiorMedia = aluno[0].media;

    for (int i = 1; i < n; i++) {
        if (aluno[i].media > maiorMedia) {
            maiorMedia = aluno[i].media;
            RAMaiorMedia = aluno[i].RA;
        }
    }

    printf("Aluno com maior Media: RA %d, Media %.2f\n", RAMaiorMedia, maiorMedia);
}
