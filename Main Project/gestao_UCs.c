//gestão de funções relativas às UCs

#include <stdio.h>

#include "gestao_UCs.h"
#include "funcoes_auxiliares.h"

int procuraUC (tipoUCs vetorUCs[], int quantUCs, int codigoUC)
{
    int i, posicao=-1;

    for (i=0; i < quantUCs; i++)
    {
        if (vetorUCs[i].codigoUC == codigoUC)
        {
            posicao = i;
            i = quantUCs;
        }
    }

    return posicao;
}

tipoUCs escreverDadosUc(tipoUCs vetorUC[], int *quantUCs)
{
    tipoUCs uc;
    int codigoUC, posicao;
    uc.duracaoT = 0, uc.duracaoTP = 0, uc.duracaoPL = 0;

    printf("\n******** NOVA UC ********\n");
    codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
    posicao = procuraUC(vetorUC, *quantUCs, codigoUC);
    if(posicao != -1)
    {
        printf("\n\nERRO: O codigo relativo a UC já existe!!");
        printf("\nO codigo tem que ser unico!!");
    }
    else
    {
        uc.codigoUC = codigoUC;

        lerString("\nDesignação da UC: ", uc.designacao, MAX_STRING);
        uc.tipoUC = lerInteiro("\nTipo de UC: ", OBRIGATORIO, OPCIONAL);
        uc.semestre = lerInteiro("\nSemestre da UC: ", MIN_SEMESTRE, MAX_SEMESTRE);
        uc.regime = lerInteiro("\nRegime da UC: ", DIURNO, POSLABORAL);

        uc.quantPrevistaT = lerInteiro("\nQuantidade prevista para as aulas T: ", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
        if(uc.quantPrevistaT != 0)
        {
            uc.duracaoT = lerInteiro("\nDuração para as aulas T: ", MIN_DURACAOAULA, MAX_DURACAOAULA);
        }

        uc.quantPrevistaTP = lerInteiro("\nQuantidade prevista para as aulas TP: ", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
        if(uc.quantPrevistaTP != 0)
        {
            uc.duracaoTP = lerInteiro("\nDuração para as aulas TP: ", MIN_DURACAOAULA, MAX_DURACAOAULA);
        }

        uc.quantPrevistaPL = lerInteiro("\nQuantidade prevista para as aulas PL: ", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
        if(uc.quantPrevistaPL != 0)
        {
            uc.duracaoPL = lerInteiro("\nDuração para as aulas PL: ", MIN_DURACAOAULA, MAX_DURACAOAULA);
        }
    }

    return uc;
}
