#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "gestao_UCs.h"
#include "gestao_Aulas.h"
#include "gestao_Alunos.h"

char menuPrincipal(int quantUCs, int quantAulasAgendadas, int quantAulasRealizadas, int quantAulasGravadas);
char menuUCs(int quantUCs);
char menuAulas(int quantAulasAgendadas, int quantAulasRealizadas, int quantAulasGravadas);
char menuAlunos(int quantAlunos);

int main()
{
    tipoUCs vetorUCs[MAX_UCS];
    int quantUCs=0;
    tipoAulas *vetorAulas;
    int quantAulasAgendadas=0, quantAulasDecorrer=0, quantAulasRealizadas=0, quantAulasGravadas=0, quantAulas=0;
    tipoAluno vetorAlunos[MAX_ALUNOS];
    int quantAlunos=0;

    vetorAulas = NULL;

    char opcao, opcaoUCs, opcaoAulas, opcaoAlunos;

    do
    {
        opcao = menuPrincipal(quantUCs, quantAulasAgendadas, quantAulasRealizadas, quantAulasGravadas);

        switch(opcao)
        {
        case 'U':   //Submenu das UCS********************************************************************************************
            do
            {
                opcaoUCs = menuUCs(quantUCs);

                switch(opcaoUCs)
                {
                case 'I':  // Inserir UC
                    acrescentarUC(vetorUCs, &quantUCs);
                    break;
                case 'A':  // alterar UC
                    alterarUc(vetorUCs, quantUCs);
                    break;
                case 'E':  // eliminar UC
                    //eliminarUC(vetorUCs, &quantUCs);
                    break;
                case 'M':   // Mostrar UCs
                    mostrarDadosUCs(vetorUCs, quantUCs);
                    break;
                case 'G':   // Gravar dados das UCs (ficheiro)
                    gravarFicheiroBinarioUCs(vetorUCs, quantUCs);
                    break;
                case 'L':   // Ler dados das UCs (ficheiro)/Carregar ficheiro das UCs
                    lerFicheiroBinarioUCs(vetorUCs, &quantUCs);
                    break;
                case 'V':    // Terminar o programa
                    break;
                }

            }
            while (opcaoUCs != 'V');

            break;
        case 'A':   //Submenu das aulas********************************************************************************************
            do
            {
                opcaoAulas = menuAulas(quantAulasAgendadas, quantAulasRealizadas, quantAulasGravadas);

                switch(opcaoAulas)
                {
                case 'I':  // Inserir Aula
                    vetorAulas = acrescentarAulaAgendada(vetorAulas, &quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas, vetorUCs, quantUCs);
                    break;
                case 'A':  // alterar Aula
                    alterarAula(vetorAulas, &quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas, vetorUCs, quantUCs); //acertar codigo da funcao
                    break;
                case 'E':  // eliminar Aula
                    vetorAulas = eliminarAula(vetorAulas, &quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas);
                    break;
                case 'C':   //Comecar uma aula
                    acrescentarAulaDecorrer(vetorAulas, &quantAulasAgendadas, &quantAulasDecorrer, quantAulasRealizadas);
                    break;
                case 'F':   //Finalizar uma aula
                    acrescentarAulaRealizada(vetorAulas, quantAulasAgendadas, &quantAulasDecorrer, &quantAulasRealizadas, &quantAulasGravadas);
                    break;
                case 'M':   // Mostrar Aulas
                    mostrarDadosAulas(vetorAulas, quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas);
                    break;
                case 'G':   // Gravar dados das Aulas (ficheiro)
                    escreverFicheiroTextoAulas(vetorAulas, quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas);
                    escreverFicheiroBinarioAulas(vetorAulas, quantAulasAgendadas, quantAulasDecorrer, quantAulasRealizadas);
                    break;
                case 'L':   // Ler dados das Aulas (ficheiro)/Carregar ficheiro das Aulas
                    vetorAulas = lerFicheiroBinarioAulas(vetorAulas, &quantAulas, &quantAulasAgendadas, &quantAulasDecorrer, &quantAulasRealizadas);
                    break;
                case 'V':    // Voltar para o menu principal
                    break;
                }
            }
            while (opcaoAulas != 'V');

            break;
        case 'E':   //Submenu dos alunos********************************************************************************************

            do
            {
                opcaoAlunos = menuAlunos(quantAlunos);

                switch(opcaoAlunos)
                {
                case 'I':  // Inserir aluno
                    acrescentarAluno(vetorAlunos, &quantAlunos);
                    break;
                case 'A':  // alterar aluno

                    break;
                case 'E':  // eliminar aluno

                    break;
                case 'M':   // Mostrar aluno
                    mostrarDadosAlunos(vetorAlunos, quantAlunos);
                    break;
                case 'G':   // Gravar dados dos alunos (ficheiro)

                    break;
                case 'L':   // Ler dados dos alunos (ficheiro)/Carregar ficheiro dos alunos

                    break;
                case 'V':    // Voltar para o menu principal
                    break;
                }
            }
            while (opcaoAulas != 'V');
            break;

        case 'L':   //Ler os dados de todos os ficheiros
            lerFicheiroBinarioUCs(vetorUCs, &quantUCs);
            vetorAulas = lerFicheiroBinarioAulas(vetorAulas, &quantAulas, &quantAulasAgendadas, &quantAulasDecorrer, &quantAulasRealizadas);
            break;
        case 'F':
            break;
        }
    }
    while(opcao != 'F');

    free(vetorAulas);

    return 0;
}


char menuAlunos(int quantAlunos)
{
    char opcao;

    do
    {
        printf("\n\n******** /* MENU ALUNOS */ ********\n");
        printf("Alunos Inscritos: %d\n", quantAlunos);
        printf("\n(I)nserir Aluno");
        printf("\n(A)lterar Aluno");
        printf("\n(E)liminar Aluno");
        printf("\n(M)ostrar Aluno ");
        printf("\n(G)ravar dados para o ficheiro");
        printf("\n(L)er dados do Ficheiro");
        printf("\n(V)oltar ao Menu Principal");
        printf("\n\t\tOPCAO -> ");

        scanf("%c", &opcao);
        limpaBufferStdin();

        opcao = toupper (opcao);

        if (strchr("IAEMGLV", opcao) == NULL)
        {
            printf("\n\nERRO: Opcao Invalida!!");
        }
    }
    while (strchr("IAEMGLV", opcao) == NULL);

    return opcao;
}


char menuAulas(int quantAulasAgendadas, int quantAulasRealizadas, int quantAulasGravadas)
{
    char opcao;

    do
    {
        printf("\n\n******** /* MENU AULAS ONLINE */ ********\n");
        printf("Aulas Agendadas: %d\n", quantAulasAgendadas);
        printf("Aulas Realizadas: %d\n", quantAulasRealizadas);
        printf("Aulas Gravadas: %d\n", quantAulasGravadas);
        printf("\n(I)nserir aulas online");
        printf("\n(A)lterar aula online");
        printf("\n(E)liminar aula online");
        printf("\n(C)omecar uma aula");
        printf("\n(F)inalizar uma aula");
        printf("\n(M)ostrar aulas ");
        printf("\n(G)ravar dados para o ficheiro");
        printf("\n(L)er dados do Ficheiro");
        printf("\n(V)oltar ao Menu Principal");
        printf("\n\t\tOPCAO -> ");

        scanf("%c", &opcao);
        limpaBufferStdin();

        opcao = toupper (opcao);

        if (strchr("IAECFMGLV", opcao) == NULL)
        {
            printf("\n\nERRO: Opcao Invalida!!");
        }
    }
    while (strchr("IAECFMGLV", opcao) == NULL);

    return opcao;
}

char menuUCs(int quantUCs)
{
    char opcao;

    do
    {
        printf("\n\n******** /* MENU UCS */ ********\n");
        printf("UCs Inseridas: %d\n", quantUCs);
        printf("\n(I)nserir UC");
        printf("\n(A)lterar UC");
        printf("\n(E)liminar UC");
        printf("\n(M)ostrar UCs ");
        printf("\n(G)ravar dados para o ficheiro");
        printf("\n(L)er dados do Ficheiro");
        printf("\n(V)oltar ao Menu Principal");
        printf("\n\t\tOPCAO -> ");

        scanf("%c", &opcao);
        limpaBufferStdin();

        opcao = toupper (opcao);

        if (strchr("IAEMGLV", opcao) == NULL)
        {
            printf("\n\nERRO: Opcao Invalida!!");
        }
    }
    while (strchr("IAEMGLV", opcao) == NULL);

    return opcao;
}

char menuPrincipal(int quantUCs, int quantAulasAgendadas, int quantAulasRealizadas, int quantAulasGravadas)
{
    char opcao;

    do
    {
        printf("\n\n******** /* MENU PRINCIPAL */ ********\n");
        printf("\nQuantidade de UCs: %d\n", quantUCs);
        printf("\nQuantidade de aulas agendadas: %d", quantAulasAgendadas);
        printf("\nQuantidade de aulas realizadas: %d", quantAulasRealizadas);
        printf("\nQuantidade de aulas gravadas: %d", quantAulasGravadas);
        printf("\n\n(U)Cs");
        printf("\n(A)ulas");
        printf("\n(E)studantes");
        printf("\n\n(L)er dados dos ficheiros");
        printf("\n\n(F)im");
        printf("\n\t\tOPCAO -> ");

        scanf("%c", &opcao);
        limpaBufferStdin();

        opcao = toupper (opcao);

        if (strchr("UAELF", opcao) == NULL)
        {
            printf("\n\nERRO: Opcao Invalida!!");
        }
    }
    while (strchr("UAELF", opcao) == NULL);

    return opcao;
}
