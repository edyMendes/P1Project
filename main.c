#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include ""

int main()
{
<<<<<<< Updated upstream
    printf("Hello world!\n");
=======
    tipoUCs vetorUCS[MAX_UCS];
    int quantUCs=0;
    tipoAulas *vetorAulas;
    int quantAulasAgendadas=0, quantAulasRealizadas=0, quantAulasGravadas=0;

    vetorAulas = NULL;

    char opcao, opcaoUcs, opcaoAulas;

    do
    {
        opcao = menuPrincipal(quantUCs, quantAulasAgendadas, quantAulasRealizadas, quantAulasGravadas);

        switch(opcao)
        {
        case 'U':
            do
            {
                opcaoUcs = menuUCs(quantUCs);

                switch(opcaoUcs)
                {
                case 'I':  // Inserir UC
                    acrescentarUC(vetorUCS, &quantUCs);
                    break;
                case 'A':  // alterar UC
                    alterarUc(vetorUCS, quantUCs);
                    break;
                case 'E':  // eliminar UC
                    //eliminarUC(vetorUCS, &quantUCs);
                    break;
                case 'M':   // Mostrar UCs
                    mostrarDadosUCs(vetorUCS, quantUCs);
                    break;
                case 'G':   // Gravar dados das UCs (ficheiro)
                    gravarFicheiroBinarioUCs(vetorUCS, quantUCs);
                    break;
                case 'L':   // Ler dados das UCs (ficheiro)/Carregar ficheiro das UCs
                    lerFicheiroBinarioUCs(vetorUCS, &quantUCs);
                    break;
                case 'F':    // Terminar o programa
                    break;
                }

            }
            while (opcaoUcs != 'F');

            break;
        case 'A':
            do
            {
                opcaoAulas = menuAulas();

                switch(opcaoAulas)
                {
                case 'I':  // Agendar aula
                    lerDadosAula(vetorAulas);
                    break;
                case 'A':  // alterar UC
                    break;
                case 'E':  // eliminar UC
                    break;
                case 'M':   // Mostrar UCs
                    break;
                case 'G':   // Gravar dados das UCs (ficheiro)
                    break;
                case 'L':   // Ler dados das UCs (ficheiro)/Carregar ficheiro das UCs
                    break;
                case 'F':    // Terminar o programa
                    break;
                }
            }
            while (opcaoAulas != 'F');

            break;
        case 'F':
            break;
        }
    }
    while(opcao != 'F');

    free(vetorAulas);

>>>>>>> Stashed changes
    return 0;
}

char menuPrincipal()
{
    char opcao;

    do
    {
        printf("\n\n********************* MENU PRINCIPAL ********************\n");
        printf("UCs Inseridas: %d\n");
        printf("\t\tOPCAO -> ");

        scanf("%c", &opcao);
        limpaBufferStdin();

        opcao = toupper (opcao);

        if (strchr("", opcao) == NULL)
        {
            printf("\n\nERRO: Opcao Invalida\n\n");
        }
    }
    while (strchr("", opcao) == NULL);

    return opcao;
}
