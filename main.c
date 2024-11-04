// main.c
#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"

int main() {
    int n;
    printf("Digite o numero de alunos a serem cadastrados: ");
    scanf("%d", &n);

    // Criar alunos e salvar o ponteiro inicial em 'aluno'
    cadastro *aluno = criarAlunos(n);

    while (1) {
        int RA, P;

        // Pergunta ao usuário o RA do aluno e qual nota alterar
        printf("\nDigite o RA do aluno e a prova (1 para prova 1, 2 para prova 2) para alterar ou 0 para sair: ");
        scanf("%d", &RA);

        if (RA == 0) {
            determinarMaiorMedia(aluno, n);
            break;
        }

        scanf("%d", &P);
        modificarNota(aluno, n, RA, P);
        calcularMedia(aluno, RA);
        printf("Aluno %d - Media: %.2f\n", RA, aluno[RA - 1].media);
    }

    free(aluno);
    return 0;
}
