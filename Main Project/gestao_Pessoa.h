//gestão de funções relativas aos Alunos

#ifndef GESTAO_PESSOA_H_INCLUDED
#define GESTAO_PESSOA_H_INCLUDED

#include "funcoes_auxiliares.h"


#define MAX_ALUNOS 100
#define MAX_STRING 50


typedef struct {
  int num_Identificacao;
  char nome[MAX_STRING];
  char estatuto;
}tipoPessoa;
#endif // GESTAO_PESSOA_H_INCLUDED
