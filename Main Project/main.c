#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "gestao_UCs.h"

char menuUCs(void);

int main()
{
    tipoUCs vetorUCS[MAX_UCS];
    int quantUCs=0;
    char opcao;



    do
    {
        opcao = menuUCs();

        switch (opcao)
        {
        case 'A':  // acrescentar UC

            break;
        case 'M':   // Mostrar UCs

            break;
        case 'L':   // Ler dados das UCs

            break;
        case 'F':    // Terminar o programa
            break;
        }

    }
    while (opcao != 'F');

    return 0;
}

char menuUCs(void)
{
    char opcao;

    do
    {
        printf("\n\n********************* MENU PRINCIPAL ********************\n");
        printf("(A)crescentar UCs");
        printf("(M)ostrar UCs ");
        printf("(L)er UCs");
        printf("(F)im");
        printf("\t\tOPCAO -> ");

        scanf("%c", &opcao);
        limpaBufferStdin();

        opcao = toupper (opcao);

        if (strchr("AMLF", opcao) == NULL)
        {
            printf("\n\nERRO: Opcao Invalida\n\n");
        }
    }
    while (strchr("AMLF", opcao) == NULL);

    return opcao;
}
