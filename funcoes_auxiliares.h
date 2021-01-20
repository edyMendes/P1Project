#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#define MINANO 2000
#define MAXANO 2500

#define MIN_HORA 8
#define MAX_HORA 24
#define MIN_MINUTO 0
#define MAX_MINUTO 59

typedef struct
{
    int dia, mes, ano;
} tipoData;

typedef struct
{
    int hora, minuto;
} tipoHora;

int lerInteiro(char mensagem[], int minimo, int maximo);
float lerFloat(char mensagem[], float minimo, float maximo);
void lerString(char mensagem[], char vetorCaracteres[], int maximoCaracteres);
void limpaBufferStdin(void);

tipoData lerData(char mensagem[]);
void escreverData (tipoData data);

tipoHora lerHora(char mensagem[]);
void escreverHora (tipoHora hora);

void alterarStringMaiusculas(char stringName[]);

#endif // FUNCOES_AUXILIARES_H_INCLUDED
