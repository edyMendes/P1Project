#ifndef GESTAO_AULAS_H_INCLUDED
#define GESTAO_AULAS_H_INCLUDED

#include "funcoes_auxiliares.h"
#include "gestao_UCs.h"


typedef struct{
    tipoUCs codigo;
    tipoUCs tipoAula;
    int codigoAula; //unico, necessita implementação de um incremento por cada nova aula agendada, string - "<tipoUCs codigo>+<tipoUCs tipoAula>+i++" de modo a automaticamente contar o numero de aulas realizadas
    char nomeDocente;
    tipoData data;
    tipoHora horaInicio;
    tipoHora horaFim;
    char estadoAula;
    char opcaoGravacao;
} tipoAulaOnline;






#endif // GESTAO_AULAS_H_INCLUDED
