//gestão de funções relativas às Aulas

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "gestao_Aulas.h"
#include "funcoes_auxiliares.h"

tipoAulas *lerFicheiroBinarioAulas(tipoAulas vetorAula[], int *quantAulas, int *quantAulasAgendadas, int *quantAulasDecorrer, int *quantAulasRealizadas)
{
    FILE *ficheiro;
    tipoAulas *pAula;

    ficheiro = fopen("aulas.dat", "rb");
    if(ficheiro == NULL)
    {
        printf("\n\nERRO: Impossivel abrir ficheiro!!");
    }
    else
    {
        fread(&(*quantAulas), sizeof(int), 1, ficheiro);

        pAula = vetorAula;
        vetorAula = realloc(vetorAula, (*quantAulas)*sizeof(tipoAulas));
        if(vetorAula == NULL && *quantAulas != 0)
        {
            printf("\n\nERRO: Erro ao reservar memoria!!");
            vetorAula = pAula;
        }
        else
        {
            fread(vetorAula, sizeof(tipoAulas), *quantAulas, ficheiro);

            procurarEstadosAulas(vetorAula, &(*quantAulas), &(*quantAulasAgendadas), &(*quantAulasDecorrer), &(*quantAulasRealizadas));

            printf("\n\nLeitura dos dados das aulas realizada com sucesso!!");
        }
        fclose(ficheiro);
    }
    return vetorAula;
}

void procurarEstadosAulas(tipoAulas vetorAula[], int *quantAulas, int *quantAulasAgendadas, int *quantAulasDecorrer, int *quantAulasRealizadas)
{
    int i;

    for(i=0; i<*quantAulas; i++)
    {
        switch(vetorAula[i].estadoAula)
        {
        case 1:
            (*quantAulasAgendadas)++;
            break;
        case 2:
            (*quantAulasDecorrer)++;
            break;
        case 3:
            (*quantAulasRealizadas)++;
            break;
        }
    }
}

void escreverFicheiroTextoAulas(tipoAulas vetorAula[], int quantAulasAgendadas, int quantAulasDecorrer, int quantAulasRealizadas)
{
    FILE *ficheiro;
    int i;
    int quantAulas=calcularQuantAulas(quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas);

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

void escreverFicheiroBinarioAulas(tipoAulas vetorAula[], int quantAulasAgendadas, int quantAulasDecorrer, int quantAulasRealizadas)
{
    FILE *ficheiro;

    int quantAulas=calcularQuantAulas(quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas);

    ficheiro = fopen("aulas.dat", "wb");

    if(ficheiro==NULL)
    {
        printf("\n\nERRO: Impossivel abrir o ficheiro!!");
    }
    else
    {
        fwrite(&quantAulas, sizeof(int), 1, ficheiro);
        fwrite(vetorAula, sizeof(tipoAulas), quantAulas, ficheiro);

        printf("\n\nGravacao dos dados das aulas efetuada com sucesso!!");

        fclose(ficheiro);
    }
}






void alterarAula(tipoAulas vetorAula[], int *quantAulasAgendadas, int quantAulasDecorrer, int quantAulasRealizadas, tipoUCs vetorUC[], int quantUCs)
{
    int codigoUC, posicaoUC, posicaoAula, opcao, erro, duracaoAula;
    char designacaoAula[MAX_STRING];
    int quantAulas=calcularQuantAulas(*quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas);

    printf("\nIndique a designacao da aula a alterar");
    lerString("\nDesignacao da aula: ", designacaoAula, MAX_STRING);
    posicaoAula = procuraAulaNome(vetorAula, quantAulas, designacaoAula);
    if (posicaoAula == -1)
    {
        printf("\n\nERRO: A aula nao existe!!");
    }
    else
    {
        if(vetorAula[posicaoAula].estadoAula!=1)
        {
            printf("\n\nERRO: A aula ja esta a decorrer/foi realizada!!");
        }
        else
        {
            opcao = menuAlterarAula(vetorAula, posicaoAula);

            switch(opcao)
            {
            case 1: //Codigo da UC
                codigoUC = lerInteiro("\nCodigo da UC: ", MIN_CODUC, MAX_CODUC);
                posicaoUC = procuraUCCodigo(vetorUC, quantUCs, codigoUC);
                if(posicaoUC == -1)
                {
                    printf("\n\nERRO: A UC nao existe!!");
                }
                else
                {
                    vetorAula[posicaoAula].codigoUC = codigoUC;
                }
                break;
            case 2: //Tipo de aula
                do
                {
                    posicaoUC = procuraUCCodigo(vetorUC, quantUCs, vetorAula[posicaoAula].codigoUC);

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
                            vetorAula[posicaoAula].tipoAula = 1;
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
                            vetorAula[posicaoAula].tipoAula = 2;
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
                            vetorAula[posicaoAula].tipoAula = 3;
                            vetorUC[posicaoUC].quantPrevistaPL -= 1;
                            duracaoAula = vetorUC[posicaoUC].duracaoPL;
                            erro=0;
                        }
                        break;
                    }
                }
                while(erro==1);
                break;
            case 3: //Nome do docente
                lerString("\nNome do Docente: ", vetorAula[posicaoAula].nomeDocente, MAX_STRING);
                break;
            case 4: //Data da aula
                vetorAula[posicaoAula].data = lerData("\nData da aula");
                break;
            case 5: //Hora de inicio da aula
                posicaoUC = procuraUCCodigo(vetorUC, quantUCs, vetorAula[posicaoAula].codigoUC);

                switch(vetorAula[posicaoAula].tipoAula)
                {
                case 1: //T
                    if(vetorUC[posicaoUC].quantPrevistaT == 0)
                    {
                        duracaoAula = vetorUC[posicaoUC].duracaoT;
                    }
                    break;
                case 2: //TP
                    if(vetorUC[posicaoUC].quantPrevistaTP == 0)
                    {
                        duracaoAula = vetorUC[posicaoUC].duracaoTP;
                    }
                    break;
                case 3: //PL
                    if(vetorUC[posicaoUC].quantPrevistaPL == 0)
                    {
                        duracaoAula = vetorUC[posicaoUC].duracaoPL;
                    }
                    break;
                }

                if(vetorUC[posicaoUC].regime == 1)
                {
                    vetorAula[posicaoAula].horaInicio = lerHora("\nHora da aula", MIN_HORADIURNO, MAX_HORADIURNO);
                }
                else
                {
                    vetorAula[posicaoAula].horaInicio = lerHora("\nHora da aula", MIN_HORAPOSLABORAL, MAX_HORAPOSLABORAL);
                }

                vetorAula[posicaoAula].horaFim = contarHoraFim(vetorAula[posicaoAula].horaInicio, duracaoAula);

                break;
            }
            printf("\n\nAlteracao da aula efetuada com sucesso!!");
        }
    }
}

int menuAlterarAula(tipoAulas vetorAula[], int i)
{
    int opcao;

    printf("\n\n**************** /* %s */ ****************", vetorAula[i].designacao);
    printf("\nIndique o campo que deseja alterar: ");
    printf("\n\t(1)Codigo da UC_________(%d)", vetorAula[i].codigoUC);
    printf("\n\t(2)Tipo de aula_________(%d)", vetorAula[i].tipoAula);
    printf("\n\t(3)Nome do docente______(%s)", vetorAula[i].nomeDocente);
    printf("\n\t(4)Data da aula_________(%02d-%02d-%d)", vetorAula[i].data.dia, vetorAula[i].data.mes, vetorAula[i].data.ano);
    printf("\n\t(5)Hora de inicio_______(%02d:%02d)", vetorAula[i].horaInicio.hora, vetorAula[i].horaInicio.minuto);

    opcao = lerInteiro("\n\t\t\tOPCAO ->", 1, 5);

    return opcao;
}

tipoAulas *eliminarAula(tipoAulas vetorAula[], int *quantAulasAgendadas, int quantAulasDecorrer, int quantAulasRealizadas)
{
    tipoAulas *pAula;
    int i, posicao;
    char nome[MAX_STRING];
    int quantAulas=calcularQuantAulas(*quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas);

    pAula = vetorAula;

    if(quantAulas != 0)
    {
        printf("\nIndique a designacao da aula a eliminar");
        lerString("\nDesignacao da aula: ", nome, MAX_STRING);
        posicao = procuraAulaNome(vetorAula, quantAulas, nome);
        if(posicao == -1)
        {
            printf("\n\nERRO: A aula nao existe!!");
        }
        else
        {
            if(vetorAula[posicao].estadoAula!=1)
            {
                printf("\n\nERRO: A aula ja esta a decorrer/foi realizada!!");
            }
            else
            {
                for(i=posicao; i < quantAulas-1; i++)
                {
                    vetorAula[i] = vetorAula[i+1];
                }
                vetorAula = realloc(vetorAula, (quantAulas-1)*sizeof(tipoAulas));
                if(vetorAula == NULL && (quantAulas-1)!=0)
                {
                    printf("\n\nERRO: Erro na alocacao de memoria!!");
                    vetorAula = pAula;
                }
                printf("\nOperacao executada com sucesso!!");
                (*quantAulasAgendadas)--;
            }
        }
    }
    return vetorAula;
}

void mostrarDadosAulas(tipoAulas vetorAula[], int quantAulasAgendadas, int quantAulasDecorrer, int quantAulasRealizadas)
{
    int i;

    int quantAulas= quantAulasAgendadas+quantAulasDecorrer+quantAulasRealizadas;

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

void acrescentarAulaRealizada(tipoAulas vetorAula[], int quantAulasAgendadas, int *quantAulasDecorrer, int *quantAulasRealizadas, int *quantAulasGravadas)
{
    char designacaoAula[MAX_STRING];
    int posicaoAula;

    int quantAulas= quantAulasAgendadas+*quantAulasDecorrer+*quantAulasRealizadas;

    if (*quantAulasDecorrer == 0)
    {
        printf("\n\nERRO: Nao existem aulas a decorrer!!");
    }
    else
    {
        lerString("\nInsira a designacao da aula que esteja a decorrer que deseja concluir: ", designacaoAula, MAX_STRING);
        posicaoAula = procuraAulaNome(vetorAula, quantAulas, designacaoAula);
        if(posicaoAula == -1)
        {
            printf("\n\nERRO: A aula nao existe!!");
        }
        else
        {
            if(vetorAula[posicaoAula].estadoAula!=2)
            {
                printf("\n\nERRO: A aula nao esta a decorrer!!");
            }
            else
            {
                vetorAula[posicaoAula].estadoAula = 3; //realizada
                (*quantAulasDecorrer)--;
                (*quantAulasRealizadas)++;
                if(vetorAula[posicaoAula].gravacao=='S')
                {
                   (*quantAulasGravadas)++;
                }

                printf("\n\nAula efectuada!!");
            }
        }
    }
}

void acrescentarAulaDecorrer(tipoAulas vetorAula[], int *quantAulasAgendadas, int *quantAulasDecorrer, int quantAulasRealizadas)
{
    char designacaoAula[MAX_STRING];
    int posicaoAula;
    char opcao;

    int quantAulas= *quantAulasAgendadas+*quantAulasDecorrer+quantAulasRealizadas;

    if (*quantAulasAgendadas == 0)
    {
        printf("\n\nERRO: Nao existem aulas agendadas!!");
    }
    else
    {
        lerString("\nInsira a designacao da aula que deseja comecar: ", designacaoAula, MAX_STRING);
        posicaoAula = procuraAulaNome(vetorAula, quantAulas, designacaoAula);
        if(posicaoAula == -1)
        {
            printf("\n\nERRO: A aula nao existe!!");
        }
        else
        {
            if(vetorAula[posicaoAula].estadoAula!=1)
            {
                printf("\n\nERRO: A aula ja esta a decorrer/foi realizada!!");
            }
            else
            {
                vetorAula[posicaoAula].estadoAula = 2; //a decorrer
                (*quantAulasAgendadas)--;
                (*quantAulasDecorrer)++;

                opcao = menuGravacaoAula();
                switch(opcao)
                {
                case 'S':
                    vetorAula[posicaoAula].gravacao='S';
                    break;
                case 'N':
                    vetorAula[posicaoAula].gravacao='N';
                    break;
                }

                printf("\n\nOperacao executada com sucesso!!");
            }
        }
    }

}

char menuGravacaoAula(void)
{
    char opcao;
    do
    {
        printf("\nDeseja gravar a aula? (S/N)");
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


tipoAulas *acrescentarAulaAgendada(tipoAulas vetorAula[], int *quantAulasAgendadas, int quantAulasDecorrer, int quantAulasRealizadas, tipoUCs vetorUC[], int quantUCs)
{
    int codigoUC, posicaoUC, posicaoAula, opcao, erro, duracaoAula, falha;
    char designacaoAula[MAX_STRING];
    tipoAulas *pAula = NULL;
    pAula = vetorAula;

    int quantAulas = *quantAulasAgendadas+quantAulasDecorrer+quantAulasRealizadas;

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
            pAula = realloc(vetorAula, (quantAulas+1)*sizeof(tipoAulas));
            if(pAula == NULL)
            {
                printf("\n\nERRO: Impossivel agendar a aula!!");
            }
            else
            {
                vetorAula = pAula;

                lerString("\nDesignacao da aula: ", designacaoAula, MAX_STRING);
                posicaoAula = procuraAulaNome(vetorAula, quantAulas, designacaoAula);
                if(posicaoAula != -1)
                {
                    printf("\n\nERRO: A aula ja existe!!");
                }
                else
                {
                    strcpy(vetorAula[quantAulas].designacao, designacaoAula);
                    vetorAula[quantAulas].codigoUC = codigoUC;
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
                                vetorAula[quantAulas].tipoAula = 1;
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
                                vetorAula[quantAulas].tipoAula = 2;
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
                                vetorAula[quantAulas].tipoAula = 3;
                                vetorUC[posicaoUC].quantPrevistaPL -= 1;
                                duracaoAula = vetorUC[posicaoUC].duracaoPL;
                                erro=0;
                            }
                            break;
                        }
                    }
                    while(erro==1);

                    lerString("\nNome do Docente: ", vetorAula[quantAulas].nomeDocente, MAX_STRING);


                    do
                    {
                        vetorAula[quantAulas].data = lerData("\nData da aula");
                        if(vetorUC[posicaoUC].regime == 1)
                        {
                            vetorAula[quantAulas].horaInicio = lerHora("\nHora da aula", MIN_HORADIURNO, MAX_HORADIURNO);
                        }
                        else
                        {
                            vetorAula[quantAulas].horaInicio = lerHora("\nHora da aula", MIN_HORAPOSLABORAL, MAX_HORAPOSLABORAL);
                        }
                        vetorAula[quantAulas].horaFim = contarHoraFim(vetorAula[quantAulas].horaInicio, duracaoAula);
                        falha = validarDataHora(vetorAula, quantAulas, vetorUC, quantUCs, vetorAula[quantAulas].data, vetorAula[quantAulas].horaInicio, vetorAula[quantAulas].horaFim);
                    }
                    while(falha==1);

                    printf("\n\nAula agendada!!");

                    vetorAula[quantAulas].estadoAula = 1; //agendada
                    (*quantAulasAgendadas)++;
                    (quantAulas)++;
                }
            }
        }
    }
    return vetorAula;
}

int validarDataHora(tipoAulas vetorAula[], int quantAulas, tipoUCs vetorUC[], int quantUCs, tipoData data, tipoHora horaInicio, tipoHora horaFim)
{
    int horaMinutosInicio, minutosInicio, horaMinutosFim, minutosFim, horaMinutosInicioI, minutosInicioI, horaMinutosFimI, minutosFimI;
    int falha, i, pos;

    horaMinutosInicio = horaInicio.hora * 60;
    minutosInicio = horaInicio.minuto + horaMinutosInicio;

    horaMinutosFim = horaFim.hora * 60;
    minutosFim = horaFim.minuto + horaMinutosFim;

    for(pos=0; pos<quantUCs; pos++)
    {
        for(i=0; i<quantAulas; i++)                             //Melhorar!!!!****************************************************************************************************
        {
            if(vetorAula[i].codigoUC==vetorUC[pos].codigoUC)
            {
                if(data.dia==vetorAula[i].data.dia)
                {
                    if(data.mes==vetorAula[i].data.mes)
                    {
                        if(data.ano==vetorAula[i].data.ano)
                        {
                            horaMinutosInicioI = vetorAula[i].horaInicio.hora * 60;
                            minutosInicioI = vetorAula[i].horaInicio.minuto + horaMinutosInicioI;

                            horaMinutosFimI = vetorAula[i].horaFim.hora * 60;
                            minutosFimI = vetorAula[i].horaFim.minuto + horaMinutosFimI;

                            if((minutosInicio>=minutosInicioI && minutosInicio<=minutosFimI) || (minutosFim>=minutosInicioI && minutosFim<=minutosFimI)) //Corrigir esta verificacao
                            {
                                printf("\n\nERRO: A aula nao pode ser agendada!!");

                                falha=1;
                            }
                        }
                    }
                }
            }
        }
    }

    return falha;
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

int calcularQuantAulas(int quantAulasAgendadas, int quantAulasDecorrer, int quantAulasRealizadas)
{
    int quantAulas = quantAulasAgendadas+quantAulasDecorrer+quantAulasRealizadas;
    return quantAulas;
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
