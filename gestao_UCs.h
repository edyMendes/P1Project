//gestão de funções relativas às UCs

#ifndef GESTAO_UCS_H_INCLUDED
#define GESTAO_UCS_H_INCLUDED

#include "funcoes_auxiliares.h"

#define MAX_STRING 50
#define MAX_UCS 40

#define MIN_CODUC 1
#define MAX_CODUC 99

#define OBRIGATORIO 1
#define OPCIONAL 2

#define MIN_SEMESTRE 1
#define MAX_SEMESTRE 6

#define DIURNO 1
#define POSLABORAL 2

#define MIN_QUANTPREVISTA 0
#define MAX_QUANTPREVISTA 60

#define MIN_DURACAOAULA 60
#define MAX_DURACAOAULA 180

typedef struct
{
    int codigoUC; // 1 a 9999
    char designacao[MAX_STRING]; // Designacao da UC
    int tipoUC; // 1-obrigatorio ou 2-opcional
    int semestre; // 1 a 6
    int regime; // 1-diurno ou 2-pos-laboral
    int quantPrevistaT; // quantidade prevista de aulas T
    int duracaoT; // Duracao da aula T em minutos
    int quantPrevistaTP; // quantidade prevista de aulas TP
    int duracaoTP; // Duracao da aula TP em minutos
    int quantPrevistaPL; // quantidade prevista de aulas PL
    int duracaoPL; // Duracao da aula PL em minutos
} tipoUCs;

tipoUCs lerDadosUc(tipoUCs vetorUC[], int *quantUCs);
int procuraUCCodigo (tipoUCs vetorUCs[], int quantUCs, int codigoUC);
void acrescentarUC (tipoUCs vetorUC[], int *quantUCs);
void escreverDadosUC (tipoUCs uc);
void mostrarDadosUCs (tipoUCs vetorUC[], int quantUCs);
//void eliminarUC(tipoUCs vetorUC[], int *quantUCs);
int menuAlterarUCs(tipoUCs vetorUC[], int i);
char menuAlterarDuracao(void);
void alterarUc(tipoUCs vetorUC[], int quantUCs);

void gravarFicheiroBinarioUCs(tipoUCs vetorUC[], int quantUCs);
void lerFicheiroBinarioUCs(tipoUCs vetorUc[], int *quantUcs);

#endif // GESTAO_UCS_H_INCLUDED
