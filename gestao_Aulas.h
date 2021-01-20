//gestão de funções relativas às Aulas

#ifndef GESTAO_AULAS_H_INCLUDED
#define GESTAO_AULAS_H_INCLUDED

#include "funcoes_auxiliares.h"
#include "gestao_UCs.h"


#define MAX_STRING 50

typedef struct
{
    char designacao[MAX_STRING];    //Designacao da aula(unica)(ex: ProgIPL1)
    int codigoUC;   //Codigo da UC
    int tipoAula;   //Tipo de aula(T, TP ou PL)
    char nomeDocente[MAX_STRING];   //Nome do docente que ira apresentar a aula
    tipoData data;  //data da aula
    tipoHora horaInicio;
    tipoHora horaFim;
    char estadoAula;    //agendada, a decorrer, realizada
    char gravacao;  //(S/N)
} tipoAulas;






#endif // GESTAO_AULAS_H_INCLUDED
