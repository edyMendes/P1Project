#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "gestao_UCs.h"
#include "gestao_Aulas.h"

char menuPrincipal(int quantUCs, int quantAulasAgendadas, int quantAulasRealizadas, int quantAulasGravadas);
char menuUCs(int quantUCs);
char menuAulas(int quantAulasAgendadas, int quantAulasRealizadas, int quantAulasGravadas);

int main()
{
    tipoUCs vetorUCs[MAX_UCS];
    int quantUCs=0;
    tipoAulas *vetorAulas;
    int quantAulasAgendadas=0, quantAulasRealizadas=0, quantAulasGravadas=0;

    vetorAulas = NULL;

    char opcao, opcaoUCs, opcaoAulas;

    do
    {
        opcao = menuPrincipal(quantUCs, quantAulasAgendadas, quantAulasRealizadas, quantAulasGravadas);

        switch(opcao)
        {
        case 'U':
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
        case 'A':
            do
            {
                opcaoAulas = menuAulas(quantAulasAgendadas, quantAulasRealizadas, quantAulasGravadas);

                switch(opcaoAulas)
                {
                case 'I':  // Inserir Aula
                    vetorAulas = acrescentarAula(vetorAulas, &quantAulasAgendadas, vetorUCs, quantUCs);
                    break;
                case 'A':  // alterar Aula
                    alterarAula(vetorAulas, &quantAulasAgendadas, vetorUCs, quantUCs);
                    break;
                case 'E':  // eliminar Aula
                    vetorAulas = eliminarAula(vetorAulas, &quantAulasAgendadas);
                    break;
                case 'M':   // Mostrar Aulas
                    mostrarDadosAulas(vetorAulas, quantAulasAgendadas);
                    break;
                case 'G':   // Gravar dados das Aulas (ficheiro)
                    escreverFicheiroTextoAulas(vetorAulas, quantAulasAgendadas);
                    escreverFicheiroBinarioAulas(vetorAulas, quantAulasAgendadas);
                    break;
                case 'L':   // Ler dados das Aulas (ficheiro)/Carregar ficheiro das Aulas
                    vetorAulas = lerFicheiroBinarioAulas(vetorAulas, &quantAulasAgendadas);
                    break;
                case 'V':    // Voltar para o menu principal
                    break;
                }
            }
            while (opcaoAulas != 'V');

            break;
        case 'F':
            break;
        }
    }
    while(opcao != 'F');

    free(vetorAulas);

    return 0;
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
        printf("\n(M)ostrar aulas ");
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
        printf("\n(F)im");
        printf("\n\t\tOPCAO -> ");

        scanf("%c", &opcao);
        limpaBufferStdin();

        opcao = toupper (opcao);

        if (strchr("UAF", opcao) == NULL)
        {
            printf("\n\nERRO: Opcao Invalida!!");
        }
    }
    while (strchr("UAF", opcao) == NULL);

    return opcao;
}
