//gestão de funções relativas às Aulas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestao_Aulas.h"
#include "funcoes_auxiliares.h"

void escreverFicheiroTexto(tipoAulas vetorAula[], int quantAulas)
{
    FILE *ficheiro;
    int i;

    ficheiro = fopen("aulas.txt", "w");

    if(ficheiro == NULL)
    {
        printf("\nImpossivel abrir o ficheiro");
    }
    else
    {
        for(i=0; i<quantAulas; i++)
        {
            fprintf(ficheiro,"\n\n**************** /* %s */ ****************", vetorAula[i].designacao);
            fprintf(ficheiro, "\nAulas agendadas: %d", quantAulas);

            fprintf(ficheiro, "\nCodigo da UC: %2d", vetorAula[i].codigoUC);

            switch(vetorAula[i].tipoAula)
            {
            case 1:
                fprintf(ficheiro, "\nTipo: T");
                break;
            case 2:
                fprintf(ficheiro, "\nTipo: TP");
                break;
            case 3:
                fprintf(ficheiro, "\nTipo: PL");
                break;
            }
            fprintf(ficheiro, "\nNome do Docente: %s", vetorAula[i].nomeDocente);
            fprintf(ficheiro, "\nData da aula: ");
            fprintf(ficheiro, "%02d-%02d-%d", vetorAula[i].data.dia, vetorAula[i].data.mes, vetorAula[i].data.ano);
            fprintf(ficheiro, "\nHora do inicio da aula: ");
            fprintf(ficheiro, "%02d:%02d", vetorAula[i].horaInicio.hora, vetorAula[i].horaInicio.minuto);
            fprintf(ficheiro,"\nHora do fim da aula: ");
            fprintf(ficheiro, "%02d:%02d", vetorAula[i].horaFim.hora, vetorAula[i].horaFim.minuto);
            fprintf(ficheiro,"\nEstado da aula: ");
            switch(vetorAula[i].estadoAula) //agendada, a decorrer, realizada
            {
            case 1:
                fprintf(ficheiro, "Agendada");
                break;
            case 2:
                fprintf(ficheiro, "A decorrer");
                break;
            case 3:
                fprintf(ficheiro, "Realizada");
                break;
            }
        }
        fclose(ficheiro);
    }
}

void escreverFicheiroBinario(tipoAulas vetorAula[], int quantAulas)
{
    FILE *ficheiro;

    ficheiro = fopen("aulas.dat", "wb");

    if(ficheiro==NULL)
    {
        printf("ERRO: Impossivel abrir o ficheiro!!");
    }
    else
    {
        fwrite(&quantAulas, sizeof(int), 1, ficheiro);
        fwrite(vetorAula, sizeof(tipoAulas), quantAulas, ficheiro);
        fclose(ficheiro);
    }
}

//void lerFicheiroBinarioUCs(tipoUCs vetorUc[], int *quantUcs)

//void gravarFicheiroBinarioUCs(tipoUCs vetorUC[], int quantUCs)

tipoAulas *eliminarAula(tipoAulas vetorAula[], int *quantAulas)
{
    tipoAulas *pAula;
    int i, posicao;
    char nome[MAX_STRING];

    pAula = vetorAula;

    if(*quantAulas != 0)
    {
        printf("\nIndique a designacao da aula a eliminar");
        lerString("\nDesignacao da aula: ", nome, MAX_STRING);
        posicao = procuraAulaNome(vetorAula, *quantAulas, nome);
        if(posicao == -1)
        {
            printf("\n\nERRO: A aula nao existe!!");
        }
        else
        {
            for(i=posicao; i < *quantAulas-1; i++)
            {
                vetorAula[i] = vetorAula[i+1];
            }
            vetorAula = realloc(vetorAula, (*quantAulas-1)*sizeof(tipoAulas));
            if(vetorAula == NULL && (*quantAulas-1)!=0)
            {
                printf("\n\nERRO: Erro na alocacao de memoria!!");
                vetorAula = pAula;
            }
            (*quantAulas)--;
        }
    }
    return vetorAula;

    /*printf("\nIndique a designacao da aula a eliminar");
    lerString("\nDesignacao da aula: ", designacaoAula, MAX_STRING);
    posicao = procuraAulaNome(vetorAula, *quantUCs, designacaoAula);
    if (posicao == -1)
    {
        printf("\n\nERRO: A aula nao existe!!");
    }
    else
    {
        for(i=posicao; i < *quantAulas-1; i++)
        {
            vetorAula[i]=vetorAula[i+1];
        }
        (*quantAulas)--;
    }*/
}

void mostrarDadosAulas(tipoAulas vetorAula[], int quantAulas)
{
    int i;

    if (quantAulas == 0)
    {
        printf("\n\nERRO: Nao existem UCs Inseridas\n\n");
    }
    else
    {
        printf("\n\n**************** /* DADOS DAS AULAS */ ****************\n");
        for (i=0; i < quantAulas; i++)
        {
            escreverDadosAula(vetorAula[i]);
        }
    }
}

void escreverDadosAula (tipoAulas aula)
{
    printf("\n\n**************** /* %s */ ****************", aula.designacao);
    printf("\nCodigo da UC: %2d", aula.codigoUC);

    switch(aula.tipoAula)
    {
    case 1:
        printf("\nTipo: T");
        break;
    case 2:
        printf("\nTipo: TP");
        break;
    case 3:
        printf("\nTipo: PL");
        break;
    }
    printf("\nNome do Docente: %s", aula.nomeDocente);
    printf("\nData da aula: ");
    escreverData(aula.data);
    printf("\nHora do inicio da aula: ");
    escreverHora(aula.horaInicio);
    printf("\nHora do fim da aula: ");
    escreverHora(aula.horaFim);
    printf("\nEstado da aula: ");
    switch(aula.estadoAula) //agendada, a decorrer, realizada
    {
    case 1:
        printf("Agendada");
        break;
    case 2:
        printf("A decorrer");
        break;
    case 3:
        printf("Realizada");
        break;
    }

}

tipoAulas *acrescentarAula(tipoAulas vetorAula[], int *quantAulas, tipoUCs vetorUC[], int quantUCs)
{
    int codigoUC, posicaoUC, posicaoAula, opcao, erro, duracaoAula;
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
                                duracaoAula = vetorUC[posicaoUC].duracaoT;
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
                                vetorAula[*quantAulas].tipoAula = 2;
                                vetorUC[posicaoUC].quantPrevistaTP -= 1;
                                duracaoAula = vetorUC[posicaoUC].duracaoTP;
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
                                vetorAula[*quantAulas].tipoAula = 3;
                                vetorUC[posicaoUC].quantPrevistaPL -= 1;
                                duracaoAula = vetorUC[posicaoUC].duracaoPL;
                                erro=0;
                            }
                            break;
                        }
                    }
                    while(erro==1);

                    lerString("\nNome do Docente: ", vetorAula[*quantAulas].nomeDocente, MAX_STRING);
                    vetorAula[*quantAulas].data = lerData("\nData da aula");
                    if(vetorUC[posicaoUC].regime == 1)
                    {
                        vetorAula[*quantAulas].horaInicio = lerHora("\nHora da aula", MIN_HORADIURNO, MAX_HORADIURNO);
                    }
                    else
                    {
                        vetorAula[*quantAulas].horaInicio = lerHora("\nHora da aula", MIN_HORAPOSLABORAL, MAX_HORAPOSLABORAL);
                    }

                    vetorAula[*quantAulas].horaFim = contarHoraFim(vetorAula[*quantAulas].horaInicio, duracaoAula);

                    vetorAula[*quantAulas].estadoAula = 1; //agendada

                    (*quantAulas)++;
                }
            }
        }
    }
    return vetorAula;
}

tipoHora contarHoraFim(tipoHora horaInicio, int duracaoAula)
{
    tipoHora vetorhoraFim;
    int horaMinutos, minutos, horaFim;

    horaMinutos = horaInicio.hora * 60;
    minutos = horaInicio.minuto + horaMinutos;

    horaFim = minutos + duracaoAula;

    vetorhoraFim.hora = horaFim / 60;
    vetorhoraFim.minuto = horaFim % 60;

    printf("\nHora final: ");
    escreverHora(vetorhoraFim);

    return vetorhoraFim;
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
