//gestão de funções relativas às Aulas

#ifndef GESTAO_AULAS_H_INCLUDED
#define GESTAO_AULAS_H_INCLUDED

#include "funcoes_auxiliares.h"
#include "gestao_UCs.h"


#define MAX_STRING 50

typedef struct
{
    char designacao[MAX_STRING];    //Designacao da aula(unica)(ex: ProgIPL1)
    int codigoUC;   //Codigo da UC
    int tipoAula;   //Tipo de aula(T, TP ou PL)
    char nomeDocente[MAX_STRING];   //Nome do docente que ira apresentar a aula
    tipoData data;  //data da aula
    tipoHora horaInicio;
    tipoHora horaFim;
    int estadoAula;    //agendada, a decorrer, realizada
    int gravacao;  //(S/N)
} tipoAulas;

int menuTipoAula(tipoUCs vetorUC[], int i);
int procuraAulaNome(tipoAulas vetorAula[], int quantAulas, char nome[]);
tipoHora contarHoraFim(tipoHora horaInicio, int duracaoAula);
int validarDataHora(tipoAulas vetorAula[], int quantAulas, tipoData data, tipoHora horaInicio, tipoHora horaFim);
tipoAulas *acrescentarAula(tipoAulas vetorAula[], int *quantAulas, tipoUCs vetorUC[], int quantUCs);

void escreverDadosAula (tipoAulas aula);
void mostrarDadosAulas(tipoAulas vetorAula[], int quantAulas);

tipoAulas *eliminarAula(tipoAulas vetorAula[], int *quantAulas);

int menuAlterarAula(tipoAulas vetorAula[], int i);
void alterarAula(tipoAulas vetorAula[], int *quantAulas, tipoUCs vetorUC[], int quantUCs);

void escreverFicheiroBinarioAulas(tipoAulas vetorAula[], int quantAulas);
void escreverFicheiroTextoAulas(tipoAulas vetorAula[], int quantAulas);

tipoAulas *lerFicheiroBinarioAulas(tipoAulas vetorAula[], int *quantAulas);

#endif // GESTAO_AULAS_H_INCLUDED
