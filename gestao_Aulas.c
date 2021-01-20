//gestão de funções relativas às Aulas

#include <stdio.h>

#include "gestao_Aulas.h"
#include "gestao_UCs.h"
#include "funcoes_auxiliares.h"

void lerDadosAula(tipoUCs vetorUc[], tipoAulas *pAula)
{
    int tipoAula, posicao;

    printf("\n**************** NOVA AULA ****************\n");
    lerString("\nDesignacao da aula: ", pAula->designacao, MAX_STRING);

    pAula->codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
    posicao = procuraUCCodigo(vetorUC, quantUCs, pAula->codigoUC);
    if (posicao == -1)
    {
        printf("\n\nERRO: A UC nao existe!!");
    }
    else
    {
    tipoAula = lerInteiro("\nTipo de aula: ", MIN_TIPOAULA, MAX_TIPOAULA);
    switch(tipoAula)
    {
    case 1:
        if(vetorUc[posicao].quantPrevistaT == 0)
        {
            printf("\n\nERRO: A UC nao tem quantidade prevista de aulas T!!");
        }
        break;
    case 2:
        if(vetorUc[posicao].quantPrevistaTP == 0)
        {
            printf("\n\nERRO: A UC nao tem quantidade prevista de aulas TP!!");
        }
        break;
    case 3:
        if(vetorUc[posicao].quantPrevistaPL == 0)
        {
            printf("\n\nERRO: A UC nao tem quantidade prevista de aulas PL!!");
        }
        break;
    }
    }

}

//temporario??
