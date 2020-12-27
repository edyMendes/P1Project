#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#define MINANO 2000
#define MAXANO 2500

typedef struct{
    int dia, mes, ano;
} tipoData;


int lerInteiro(char mensagem[], int minimo, int maximo);
float lerFloat(char mensagem[], float minimo, float maximo);
void lerString(char mensagem[], char vetorCaracteres[], int maximoCaracteres);
void limpaBufferStdin(void);

tipoData lerData(char mensagem[]);
void escreverData (tipoData data);

#endif // FUNCOES_AUXILIARES_H_INCLUDED
