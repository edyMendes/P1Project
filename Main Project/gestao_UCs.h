//gestão de funções relativas às UCs

#ifndef GESTAO_UCS_H_INCLUDED
#define GESTAO_UCS_H_INCLUDED

#include "funcoes_auxiliares.h"

#define MAX_UCS 40

typedef struct{
    char codigoUC; //modificação de int para char - o código da UC pode ser designafo com letras e numeros
    char designacao;
    char tipoUc;
    int semestre;
    char regime;
    int quantPrevista;
    char tipoAula;
    int duracao;
} tipoUCs;



#endif // GESTAO_UCS_H_INCLUDED
