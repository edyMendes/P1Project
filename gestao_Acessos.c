//gestão de funções relativas aos alunos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestao_Acessos.h"
#include "funcoes_auxiliares.h"

/*void mostrarDadosAlunos(tipoAluno vetorAluno[], int quantAlunos)
{
    int i;

    if (quantAlunos == 0)
    {
        printf("\n\nERRO: Nao existem alunos inscritos!!\n\n");
    }
    else
    {
        printf("\n\n**************** * DADOS DOS ALUNOS  ****************\n");
        for (i=0; i < quantAlunos; i++)
        {
            escreverDadosAluno(vetorAluno[i]);
        }
    }
}

void escreverDadosAluno(tipoAluno aluno)
{
    printf("\n\n**************** * ALUNO %d  ****************", aluno.numero);
    printf("\nNome: %s", aluno.nome);
    printf("\nTipo de acesso a aula: ", aluno.acessoAula);
}


tipoAluno *acrescentarAluno(tipoAluno vetorAluno[], int *quantAlunos)
{
    tipoAluno *pAluno, dados;
    int posicao;

    pAluno = vetorAluno;

    lerDadosAluno(&dados);
    posicao = procuraAlunoNumero(vetorAluno, *quantAlunos, dados.numero);
    if(posicao!=-1)
    {
        printf("\n\nERRO: O aluno já existe!!");
    }
    else
    {
        vetorAluno=realloc(vetorAluno, (*quantAlunos+1)*sizeof(tipoAluno));
        if(vetorAluno==NULL)
        {
            printf("\n\nERRO: Impossivel acrescentar o aluno!!");
            vetorAluno = pAluno;
        }
        else
        {
            vetorAluno[*quantAlunos]=dados;
            (*quantAlunos)++;
        }
    }
    return vetorAluno;
}

void lerDadosAcesso(tipoAcesso *pAcesso)
{
    lerString("\nDesignação da aula: ",pAcesso->designacaoAula, MAX_STRING);
    pAcesso->numeroAluno=lerInteiro("\nNumero de Estudante: ", MIN_NUMALUNO, MAX_NUMALUNO);
    pAcesso->acessoAula = -1;

}*/
