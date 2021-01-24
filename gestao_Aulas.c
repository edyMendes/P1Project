//gestão de funções relativas às Aulas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestao_Aulas.h"
#include "gestao_UCs.h"
#include "funcoes_auxiliares.h"

tipoAulas *acrescentarAula(tipoAulas vetorAula[], int *quantAulas, tipoUCs vetorUC[], int quantUCs)
{
    tipoAulas *pAula;
    pAula = vetorAula;

    if (vetorUC == 0)
    {
        printf("\n\nERRO: Nao existem UCs inseridas para que possa agendar uma aula!!");
    }
    else
    {
        lerDadosAula(vetorAula, quantAulas, vetorUC, quantUCs);
        vetorAula = realloc(vetorAula, (*quantAulas+1)*sizeof(tipoAulas));
        if(vetorAula == NULL)
        {
            printf("\n\nERRO: Impossivel agendar a aula!!");
            vetorAula = pAula;
        }
        else
        {
            (*quantAulas)++;
        }
    }

    return vetorAula;
}

int procuraAulaNome(tipoAulas vetorAula[], int quantAulas, char nome[])
{
    int i, posicao;

    posicao = -1;

    for(i=0; i<quantAulas; i++)
    {
        if(strcmp(vetorAula[i].designacao, nome)==0)
        {
            posicao = i;
            i=quantAulas;
        }
    }
    return posicao;
}

void lerDadosAula(tipoAulas vetorAula[], int *quantAulas, tipoUCs vetorUC[], int quantUCs)
{
    tipoAulas *pAula;
    int posicaoUC, posicaoAula, codigoUC, opcao, erro;
    char designacao[MAX_STRING];

    lerString("\nDesignacao da aula: ", designacao, MAX_STRING);
    posicaoAula = procuraAulaNome(vetorAula, *quantAulas, designacao);
    if(posicaoAula != -1)
    {
        printf("\n\nERRO: A aula já existe!!");
    }
    else
    {
        do
        {
            codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
            posicaoUC = procuraUCCodigo(vetorUC, quantUCs, codigoUC);
            if(posicaoUC == -1)
            {
                printf("\n\nERRO: A UC não existe!!");
            }
            else
            {
                pAula->codigoUC = codigoUC;
            }
        }
        while(posicaoUC == -1);

        do
        {
            opcao = menuTipoAula(vetorUC, posicaoUC);
            switch(opcao)
            {
            case 1: //T
                if(vetorUC[posicaoUC].quantPrevistaT == 0)
                {
                    printf("\n\nERRO: A UC nao tem quantidade prevista de aulas T!!");
                    erro=1;
                }
                else
                {
                    pAula->tipoAula = 1;
                    vetorUC[posicaoUC].quantPrevistaT -= 1;
                    *quantAulas += 1;
                    erro=0;
                }
                break;
            case 2: //TP
                if(vetorUC[posicaoUC].quantPrevistaTP == 0)
                {
                    printf("\n\nERRO: A UC nao tem quantidade prevista de aulas TP!!");
                    erro=1;
                }
                else
                {
                    pAula->tipoAula = 1;
                    vetorUC[posicaoUC].quantPrevistaTP -= 1;
                    *quantAulas += 1;
                    erro=0;
                }
                break;
            case 3: //PL
                if(vetorUC[posicaoUC].quantPrevistaPL == 0)
                {
                    printf("\n\nERRO: A UC nao tem quantidade prevista de aulas PL!!");
                    erro=1;
                }
                else
                {
                    pAula->tipoAula = 1;
                    vetorUC[posicaoUC].quantPrevistaPL -= 1;
                    *quantAulas += 1;
                    erro=0;
                }
                break;
            }
        }
        while(erro=1);

        lerString("\nNome do Docente: ", pAula->nomeDocente, MAX_STRING);
        pAula->data = lerData("\nData da aula: ");
        pAula->horaInicio = lerHora("\nHora da aula: ");
        //contar o tempo!!!
        pAula->estadoAula = 1; //agendada

    }
}

int menuTipoAula(tipoUCs vetorUC[], int i)
{
    int opcao;


    printf("\nIndique o tipo de aula que deseja: ");
    printf("\n\t(1)T________(%d)", vetorUC[i].quantPrevistaT);
    printf("\n\t(2)TP_______(%d)", vetorUC[i].quantPrevistaTP);
    printf("\n\t(3)PL_______(%d)", vetorUC[i].quantPrevistaPL);

    opcao = lerInteiro("\n\t\t\tOPCAO ->", 1, 3);

    return opcao;
}
