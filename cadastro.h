// cadastro.h
#ifndef CADASTRO_H
#define CADASTRO_H

typedef struct {
    int RA;
    float P1;
    float P2;
    float media;
} cadastro;

// Funções do TAD: criação de alunos, modificação das notas, cálculo da média e função para determinar qual aluno teve a maior média
cadastro* criarAlunos(int n);
void modificarNota(cadastro *aluno, int n, int RA, int P);
void calcularMedia(cadastro *aluno, int RA);
void determinarMaiorMedia(cadastro *aluno, int n);

#endif // CADASTRO_H
