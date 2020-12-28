#ifndef GESTAO_AULAS_H_INCLUDED
#define GESTAO_AULAS_H_INCLUDED

#include "funcoes_auxiliares.h"

typedef struct{
    int designacao;
    int codigoUC;
    char tipoAula;
    char nomeDocente;
    tipoData data;
    tipoHora horaInicio;
    tipoHora horaFim;
    char estadoAula;
    char opcaoGravacao;
} tipoAulaOnline;

#endif // GESTAO_AULAS_H_INCLUDED
