//gestão de funções relativas às Aulas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestao_Aulas.h"
#include "funcoes_auxiliares.h"

tipoAulas *acrescentarAula(tipoAulas vetorAula[], int *quantAulas, tipoUCs vetorUC[], int quantUCs)
{
    int codigoUC, posicaoUC, posicaoAula, opcao, erro;
    char designacaoAula[MAX_STRING];
    tipoAulas *pAula = NULL;

    pAula = vetorAula;

    if (quantUCs == 0)
    {
        printf("\n\nERRO: Nao existem UCs inseridas para que possa agendar uma aula!!");
    }
    else
    {
        codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
        posicaoUC = procuraUCCodigo(vetorUC, quantUCs, codigoUC);
        if(posicaoUC == -1)
        {
            printf("\n\nERRO: A UC nao existe!!");
        }
        else
        {
            pAula = realloc(vetorAula, (*quantAulas+1)*sizeof(tipoAulas));
            if(pAula == NULL)
            {
                printf("\n\nERRO: Impossivel agendar a aula!!");
            }
            else
            {
                vetorAula = pAula;



                lerString("\nDesignacao da aula: ", designacaoAula, MAX_STRING);
                posicaoAula = procuraAulaNome(vetorAula, *quantAulas, designacaoAula);
                if(posicaoAula != -1)
                {
                    printf("\n\nERRO: A aula ja existe!!");
                }
                else
                {
                    strcpy(vetorAula[*quantAulas].designacao, designacaoAula);
                    vetorAula[*quantAulas].codigoUC = codigoUC;
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
                                vetorAula[*quantAulas].tipoAula = 1;
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
                                vetorAula[*quantAulas].tipoAula = 1;
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
                                vetorAula[*quantAulas].tipoAula = 1;
                                vetorUC[posicaoUC].quantPrevistaPL -= 1;
                                *quantAulas += 1;
                                erro=0;
                            }
                            break;
                        }
                    }
                    while(erro==1);

                    lerString("\nNome do Docente: ", vetorAula[*quantAulas].nomeDocente, MAX_STRING);
                    vetorAula[*quantAulas].data = lerData("\nData da aula: ");
                    if(vetorUC[posicaoUC].regime == 1)
                    {
                        vetorAula[*quantAulas].horaInicio = lerHora("\nHora da aula: ", MIN_HORADIURNO, MAX_HORADIURNO);
                    }
                    else
                    {
                        vetorAula[*quantAulas].horaInicio = lerHora("\nHora da aula: ", MIN_HORAPOSLABORAL, MAX_HORAPOSLABORAL);
                    }
                                        /*contar o tempo!!!

                                        */
                    vetorAula[*quantAulas].estadoAula = 1; //agendada
                }
            }
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
