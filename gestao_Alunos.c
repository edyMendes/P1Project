//gestão de funções relativas aos alunos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestao_Alunos.h"
#include "funcoes_auxiliares.h"

void mostrarDadosAlunos(tipoAluno vetorAluno[], int quantAlunos)
{
    int i;

    if (quantAlunos == 0)
    {
        printf("\n\nERRO: Nao existem alunos inscritos!!\n\n");
    }
    else
    {
        printf("\n\n**************** /* DADOS DOS ALUNOS */ ****************\n");
        for (i=0; i < quantAlunos; i++)
        {
            escreverDadosAluno(vetorAluno[i]);
        }
    }
}

void escreverDadosAluno(tipoAluno aluno)
{
    printf("\n\n**************** /* ALUNO %d */ ****************", aluno.numero);
    printf("\nNome: %s", aluno.nome);
}


void acrescentarAluno(tipoAluno vetorAluno[], int *quantAlunos)
{
    int posicao;

    if(*quantAlunos==MAX_ALUNOS)
    {
        printf("\n\nERRO: Impossivel inscrever o aluno!!");
        printf("\n  O limite dos alunos foi atingido!!\n\n");
    }
    else
    {
        vetorAluno[*quantAlunos]=lerDadosAluno();
        posicao=procuraAlunoNumero(vetorAluno, *quantAlunos, vetorAluno[*quantAlunos].numero);

        if(posicao!=-1)
        {
            printf("\n\nERRO: Ja existe um aluno com o numero indicado!!");
        }
        else
        {
            (*quantAlunos)++;
        }
    }
}

int procuraAlunoNumero(tipoAluno vetorAluno[], int quantAlunos, int numero)
{
    int i, posicao;

    posicao = -1;

    for(i=0; i<quantAlunos; i++)
    {
        if(vetorAluno[i].numero==numero)
        {
            posicao=i;
            i=quantAlunos;
        }
    }
    return posicao;
}

tipoAluno lerDadosAluno()
{
    tipoAluno aluno;
    printf("\n**************** /* NOVO ALUNO */ ****************\n");

    aluno.numero=lerInteiro("\nNumero de Estudante: ", MIN_NUMALUNO, MAX_NUMALUNO);
    lerString("\nNome do Aluno: ",aluno.nome, MAX_STRING);

    return aluno;
}
