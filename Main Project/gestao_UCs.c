//gestão de funções relativas às UCs

#include <stdio.h>

#include "gestao_UCs.h"
#include "funcoes_auxiliares.h"

void escreverUc(tipoUCs uc)
{

}

tipoUCs leDadosUc(void)
{
    tipoUCs uc;

    printf("\n******** NOVA UC ********\n");
    uc.codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
    lerString("\nDesignação da UC: ", uc.designacao, MAX_STRING);
    uc.tipoUc = lerInteiro("\nTipo de UC: ", MIN_TIPOUC, MAX_TIPOUC);
    uc.semestre = lerInteiro("\nSemestre da UC: ", MIN_SEMESTRE, MAX_SEMESTRE);
    uc.regime = lerInteiro("\nRegime da UC: ", MIN_REGIME, MAX_REGIME);
    uc.quantPrevistaT = 0;
    uc.duracaoT = 0;
    uc.quantPrevistaTP = 0;
    uc.duracaoTP = 0;
    uc.quantPrevistaPL = 0;
    uc.duracaoPL = 0;
}
