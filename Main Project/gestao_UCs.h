//gestão de funções relativas às UCs

#ifndef GESTAO_UCS_H_INCLUDED
#define GESTAO_UCS_H_INCLUDED

#include "funcoes_auxiliares.h"

#define MAX_STRING 50
#define MAX_UCS 40

#define MIN_CODUC 1
#define MAX_CODUC 9999

#define MIN_TIPOUC 1
#define MAX_TIPOUC 2

#define MIN_SEMESTRE 1
#define MAX_SEMESTRE 6

#define MIN_REGIME 1
#define MAX_REGIME 2

typedef struct{
    int codigoUC; // 1 a 9999
    char designacao[MAX_STRING]; // designacao da UC
    int tipoUc; // 1-obrigatorio ou 2-opcional
    int semestre; // 1 a 6
    int regime; // 1-diurno ou 2-pos-laboral
    int quantPrevistaT; // quantidade prevista do tipo de aulas T
    int duracaoT; // duracao em minutos do tipo de aulas T
    int quantPrevistaTP; // quantidade prevista do tipo de aulas TP
    int duracaoTP; // duracao em minutos do tipo de aulas TP
    int quantPrevistaPL; // quantidade prevista do tipo de aulas PL
    int duracaoPL; // duracao em minutos do tipo de aulas PL
    char tipoAula; // designação da aula
} tipoUCs;



#endif // GESTAO_UCS_H_INCLUDED
