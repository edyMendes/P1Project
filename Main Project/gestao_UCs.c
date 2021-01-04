//gestão de funções relativas às UCs

#include <stdio.h>

#include "gestao_UCs.h"
#include "funcoes_auxiliares.h"

tipoUCs lerDadosUC(void)
{
    tipoUCs uCs;

    printf("\n------- Nova Uc --------\n");
    lerString("Codigo: ", uCs.codigoUC, MAX_STRING);
    lerString("Designacao: ", uCs.designacao, MAX_STRING);

    return aluno;
}
