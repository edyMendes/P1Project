#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include ""

int main()
{
    printf("Hello world!\n");
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
