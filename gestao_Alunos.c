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

void lerDadosAluno(tipoAluno *pAluno)
{
    pAluno->numero=lerInteiro("\nNumero de Estudante: ", MIN_NUMALUNO, MAX_NUMALUNO);
    lerString("\nNome do Aluno: ",pAluno->nome, MAX_STRING);
    pAluno->acessoAula = -1;

}
