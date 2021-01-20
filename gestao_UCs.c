//gestão de funções relativas às UCs

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "gestao_UCs.h"
#include "funcoes_auxiliares.h"

void lerFicheiroBinarioUCs(tipoUCs vetorUc[], int *quantUcs)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosUCs.bin", "rb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: Falha na abertura do ficheiro das UCs!!");
    }
    else
    {
        controlo = fread(quantUcs, sizeof(int), 1, ficheiro);
        if (controlo != 1)
        {
            printf("\n\nERRO: Falha na leitura dos dados das UCs!!");
        }
        else
        {
            controlo = fread(vetorUc, sizeof(tipoUCs), *quantUcs, ficheiro);
            if (controlo != *quantUcs)
            {
                printf("\n\nERRO: Falha na leitura dos dados das UCs!!");
                *quantUcs = 0;
            }
            else
            {
                printf("\n\nLeitura dos dados das UCs realizada com sucesso!!");
            }
        }
        fclose(ficheiro);
    }
}

void gravarFicheiroBinarioUCs(tipoUCs vetorUC[], int quantUCs)
{
    FILE *ficheiro;
    int controlo;

    ficheiro = fopen("dadosUCs.bin", "wb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: Falha na abertura/criacao do ficheiro das UCs!!");
    }
    else
    {
        controlo = fwrite(&quantUCs, sizeof(int), 1, ficheiro);
        if (controlo != 1)
        {
            printf("\n\nERRO: Falha na escrita dos dados das UCs!!");
        }
        else
        {
            controlo = fwrite(vetorUC, sizeof(tipoUCs), quantUCs, ficheiro);
            if (controlo != quantUCs)
            {
                printf("\nERRO: falha na escrita dos dados\n\n");
            }
            else
            {
                printf("\n\nGravacao dos dados das UCs efetuada com sucesso!!");
            }
        }
        fclose(ficheiro);
    }
}

void alterarUc(tipoUCs vetorUC[], int quantUCs)
{
    int codigoUC, posicao;
    int opcao;

    printf("\nIndique o codigo da UC a alterar");
    codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
    posicao = procuraUCCodigo(vetorUC, quantUCs, codigoUC);
    if (posicao == -1)
    {
        printf("\n\nERRO: A UC nao existe!!");
    }
    else
    {
        opcao = menuAlterarUCs(vetorUC, posicao);

        switch(opcao)
        {
        case 1: //Designacao da UC
            lerString("\nDesignacao da UC: ", vetorUC[posicao].designacao, MAX_STRING);
            alterarStringMaiusculas(vetorUC[posicao].designacao);
            break;
        case 2: //Tipo de UC
            vetorUC[posicao].tipoUC = lerInteiro("\nTipo de UC", OBRIGATORIO, OPCIONAL);
            break;
        case 3: //Semestre da UC
            vetorUC[posicao].semestre = lerInteiro("\nSemestre da UC", MIN_SEMESTRE, MAX_SEMESTRE);
            break;
        case 4: //Regime da UC
            vetorUC[posicao].regime = lerInteiro("\nRegime da UC", DIURNO, POSLABORAL);
            break;
        case 5: //Quantidade Prevista de aulas T da UC
            if(vetorUC[posicao].quantPrevistaT == 0)
            {
                vetorUC[posicao].quantPrevistaT = lerInteiro("\nQuantidade prevista para as aulas T", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
                if(vetorUC[posicao].quantPrevistaT != 0)
                {
                    vetorUC[posicao].duracaoT = lerInteiro("\nDuracao para as aulas T", MIN_DURACAOAULA, MAX_DURACAOAULA);
                }
            }
            else
            {
                vetorUC[posicao].quantPrevistaT = lerInteiro("\nQuantidade prevista para as aulas T", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);

                opcao = menuAlterarDuracao();
                switch(opcao)
                {
                case 'S':
                    vetorUC[posicao].duracaoT = lerInteiro("\nDuracao para as aulas T", MIN_DURACAOAULA, MAX_DURACAOAULA);
                    break;
                case 'N':
                    break;
                }
            }
            break;
        case 6: //Quantidade Prevista de aulas TP da UC
            if(vetorUC[posicao].quantPrevistaTP == 0)
            {
                vetorUC[posicao].quantPrevistaTP = lerInteiro("\nQuantidade prevista para as aulas TP", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
                if(vetorUC[posicao].quantPrevistaTP != 0)
                {
                    vetorUC[posicao].duracaoTP = lerInteiro("\nDuracao para as aulas TP", MIN_DURACAOAULA, MAX_DURACAOAULA);
                }
            }
            else
            {
                vetorUC[posicao].quantPrevistaTP = lerInteiro("\nQuantidade prevista para as aulas TP", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);

                opcao = menuAlterarDuracao();
                switch(opcao)
                {
                case 'S':
                    vetorUC[posicao].duracaoTP = lerInteiro("\nDuracao para as aulas TP", MIN_DURACAOAULA, MAX_DURACAOAULA);
                    break;
                case 'N':
                    break;
                }
            }
            break;
        case 7: //Quantidade Prevista de aulas PL da UC
            if(vetorUC[posicao].quantPrevistaPL == 0)
            {
                vetorUC[posicao].quantPrevistaPL = lerInteiro("\nQuantidade prevista para as aulas PL", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
                if(vetorUC[posicao].quantPrevistaPL != 0)
                {
                    vetorUC[posicao].duracaoPL = lerInteiro("\nDuracao para as aulas PL", MIN_DURACAOAULA, MAX_DURACAOAULA);
                }
            }
            else
            {
                vetorUC[posicao].quantPrevistaPL = lerInteiro("\nQuantidade prevista para as aulas PL", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);

                opcao = menuAlterarDuracao();
                switch(opcao)
                {
                case 'S':
                    vetorUC[posicao].duracaoPL = lerInteiro("\nDuracao para as aulas PL", MIN_DURACAOAULA, MAX_DURACAOAULA);
                    break;
                case 'N':
                    break;
                }
            }
            break;
        }

        printf("\n\nAlteracao da UC efetuada com sucesso!!");
    }
}

char menuAlterarDuracao(void)
{
    char opcao;

    do
    {
        printf("\n\nDeseja Alterar a duracao da aula?(S/N)");
        printf("\n\t\tOPCAO -> ");

        scanf("%c", &opcao);
        limpaBufferStdin();

        opcao = toupper (opcao);

        if (strchr("SN", opcao) == NULL)
        {
            printf("\n\nERRO: Opcao Invalida!!");
        }
    }
    while (strchr("SN", opcao) == NULL);

    return opcao;
}

int menuAlterarUCs(tipoUCs vetorUC[], int i)
{
    int opcao;

    printf("\n\n**************** %s ****************", vetorUC[i].designacao);
    printf("\nIndique o campo que deseja alterar: ");
    printf("\n\t(1)Designacao da UC_________________________________(%s)", vetorUC[i].designacao);
    printf("\n\t(2)Tipo de UC_______________________________________(%d)", vetorUC[i].tipoUC);
    printf("\n\t(3)Semestre da UC___________________________________(%d)", vetorUC[i].semestre);
    printf("\n\t(4)Regime da UC_____________________________________(%d)", vetorUC[i].regime);
    printf("\n\t(5)Quantidade Prevista de aulas T da UC_____________(%d)", vetorUC[i].quantPrevistaT);
    printf("\n\t(6)Quantidade Prevista de aulas TP da UC____________(%d)", vetorUC[i].quantPrevistaTP);
    printf("\n\t(7)Quantidade Prevista de aulas PL da UC____________(%d)", vetorUC[i].quantPrevistaPL);

    opcao = lerInteiro("\n\t\t\tOPCAO ->", 1, 7);

    return opcao;
}


/*void eliminarUC(tipoUCs vetorUC[], int *quantUCs)
{
    int codigoUC, i, posicao;

    printf("\nIndique o codigo da UC a eliminar");
    codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
    posicao = procuraUCCodigo(vetorUC, *quantUCs, codigoUC);
    if (posicao == -1)
    {
        printf("\n\nERRO: A UC nao existe!!");
    }
    else
    {
        for(i=posicao; i < *quantUCs-1; i++)
        {
            vetorUC[i]=vetorUC[i+1];
        }
        *quantUCs-=1;
    }
}*/

void mostrarDadosUCs (tipoUCs vetorUC[], int quantUCs)
{
    int i;

    if (quantUCs == 0)
    {
        printf("\n\nERRO: Nao existem UCs Inseridas\n\n");
    }
    else
    {
        printf("\n\n**************** DADOS DAS UCS ****************\n");
        for (i=0; i < quantUCs; i++)
        {
            escreverDadosUC(vetorUC[i]);
        }
    }
}

void escreverDadosUC (tipoUCs uc)
{
    printf("\n\n**************** %s ****************", uc.designacao);
    printf("\nCodigo: %2d", uc.codigoUC);

    if (uc.tipoUC == 1)
    {
        printf("\nTipo: Obrigatorio");
    }
    else
    {
        printf("\nTipo: Opcional");
    }

    printf("\nSemestre: %d", uc.semestre);

    if (uc.regime == 1)
    {
        printf("\nRegime: Diurno");
    }
    else
    {
        printf("\nRegime: Pos-Laboral");
    }

    printf("\n******** QUANTIDADE PREVISTA DE AULAS ********");
    if(uc.quantPrevistaT != 0)
    {
        printf("\nEnsino Teorico(T): %d", uc.quantPrevistaT);
        printf("\nDuracao: %d", uc.duracaoT);
    }
    if(uc.quantPrevistaTP != 0)
    {
        printf("\nEnsino Teorico-Pratico(TP): %d", uc.quantPrevistaTP);
        printf("\nDuracao: %d", uc.duracaoTP);
    }
    if(uc.quantPrevistaPL != 0)
    {
        printf("\nEnsino Pratico e Laboratorial(PL): %d", uc.quantPrevistaPL);
        printf("\nDuracao: %d", uc.duracaoPL);
    }
}


void acrescentarUC (tipoUCs vetorUC[], int *quantUCs)
{
    if (*quantUCs == MAX_UCS)
    {
        printf("\n\nERRO: Impossivel acrescentar uma nova UC!!");
        printf("\n  O limite de UCs foi atingido!!\n\n");
    }
    else
    {
        vetorUC[*quantUCs] = lerDadosUc(vetorUC, quantUCs);

        (*quantUCs)++;
    }
}

int procuraUCCodigo (tipoUCs vetorUCs[], int quantUCs, int codigoUC)
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

tipoUCs lerDadosUc(tipoUCs vetorUC[], int *quantUCs)
{
    tipoUCs uc;
    int codigoUC, posicao;
    uc.duracaoT = 0, uc.duracaoTP = 0, uc.duracaoPL = 0;

    printf("\n**************** NOVA UC ****************\n");
    do
    {
        codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
        posicao = procuraUCCodigo(vetorUC, *quantUCs, codigoUC);
        if(posicao != -1)
        {
            printf("\n\nERRO: O codigo relativo a UC ja existe!!");
            printf("\n  O codigo tem que ser unico!!\n\n");
        }
        else
        {
            uc.codigoUC = codigoUC;
        }
    }
    while(posicao != -1);

    lerString("\nDesignacao da UC: ", uc.designacao, MAX_STRING);
    alterarStringMaiusculas(uc.designacao);
    uc.tipoUC = lerInteiro("\nTipo de UC", OBRIGATORIO, OPCIONAL);
    uc.semestre = lerInteiro("\nSemestre da UC", MIN_SEMESTRE, MAX_SEMESTRE);
    uc.regime = lerInteiro("\nRegime da UC", DIURNO, POSLABORAL);

    do
    {
        uc.quantPrevistaT = lerInteiro("\nQuantidade prevista para as aulas T", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
        if(uc.quantPrevistaT != 0)
        {
            uc.duracaoT = lerInteiro("\nDuracao para as aulas T", MIN_DURACAOAULA, MAX_DURACAOAULA);
        }

        uc.quantPrevistaTP = lerInteiro("\nQuantidade prevista para as aulas TP", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
        if(uc.quantPrevistaTP != 0)
        {
            uc.duracaoTP = lerInteiro("\nDuracao para as aulas TP", MIN_DURACAOAULA, MAX_DURACAOAULA);
        }

        uc.quantPrevistaPL = lerInteiro("\nQuantidade prevista para as aulas PL", MIN_QUANTPREVISTA, MAX_QUANTPREVISTA);
        if(uc.quantPrevistaPL != 0)
        {
            uc.duracaoPL = lerInteiro("\nDuracao para as aulas PL", MIN_DURACAOAULA, MAX_DURACAOAULA);
        }
        if(uc.quantPrevistaT == 0 && uc.quantPrevistaTP == 0 && uc.quantPrevistaPL == 0)
        {
            printf("\n\nERRO: A UC %s não tem quantidade de aulas previstas!!", uc.designacao);
        }
    }
    while(uc.quantPrevistaT == 0 && uc.quantPrevistaTP == 0 && uc.quantPrevistaPL == 0);

    return uc;
}
