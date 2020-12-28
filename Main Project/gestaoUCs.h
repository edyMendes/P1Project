#ifndef GESTAOUCS_H_INCLUDED
#define GESTAOUCS_H_INCLUDED

#include "funcoes_auxiliares.h"

#define MAX_UCS 40

typedef struct{
    int codigo;
    char designacao;
    char tipoUc;
    int semestre;
    char regime;
    int quantPrevista;
    char tipoAula;
    int duracao;
} tipoUCs;



#endif // GESTAOUCS_H_INCLUDED
