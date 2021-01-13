//gestão de funções relativas às Aulas

#ifndef GESTAO_AULAS_H_INCLUDED
#define GESTAO_AULAS_H_INCLUDED

#include "funcoes_auxiliares.h"
#include "gestao_UCs.h"


#define MAX_STRING 50

typedef struct{

    int codigoAula; //unico, necessita implementação de um incremento por cada nova aula agendada, string - "<tipoUCs codigo>+<tipoUCs tipoAula>+i++" de modo a automaticamente contar o numero de aulas realizadas
    tipoUCs codigo;
    tipoUCs tipoAula;
    char nomeDocente[MAX_STRING];
    tipoData data;
    tipoHora horaInicio;
    tipoHora horaFim;
    char estadoAula; //agendada, a decorrer, realizada
    char opcaoGravacao;
} tipoAulas;











#endif // GESTAO_AULAS_H_INCLUDED
