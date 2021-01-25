//gestão de funções relativas aos alunos

#ifndef GESTAO_ALUNOS_H_INCLUDED
#define GESTAO_ALUNOS_H_INCLUDED

#include "funcoes_auxiliares.h"

#define MAX_STRING 50

#define MIN_NUMALUNO 1
#define MAX_NUMALUNO 500

typedef struct{
    int numero;
    char nome[MAX_STRING];
    int acessoAula;
}tipoAluno;

void lerDadosAluno(tipoAluno *pAluno);
int procuraAlunoNumero(tipoAluno vetorAluno[], int quantAlunos, int numero);
tipoAluno *acrescentarAluno(tipoAluno vetorAluno[], int *quantAlunos);

void escreverDadosAluno(tipoAluno aluno);
void mostrarDadosAlunos(tipoAluno vetorAluno[], int quantAlunos);

#endif // GESTAO_ALUNOS_H_INCLUDED
