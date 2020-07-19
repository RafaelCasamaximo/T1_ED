#ifndef leituraQry_H_
#define leituraQry_H_

#include "list.h"

//Responsável pela leitura do arquivo .qry
No* pegaDadoQry(No* listaQry, No** lista, char* path, char* pathLog);

//Responsável por calcular se dois elementos se sobrepoem (o?) 1 - SIM, 0 - NAO, -1 - Não é possivel realizar comparação
int sobrepoe(No* lista, int j, int k);

//Responsável por calcular se dois elementos se interceptam (i?) 1 - SIM, 0 - NAO, -1 - Não é possivel realizar comparação
int contem(No* lista, int id, float x, float y);

//Troca a cor de um elemento 1 - SIM, 0 - NAO
int paint(No* lista, int j, char cb[], char cp[]);

//Troca a cor de N elementos entre J e K 1 - SIM, 0 - NAO
int paintN(No* lista, int j, int k, char cb[], char cp[], char* path);

//Deleta todos os elementos entre J e K caso existam
void dElemN(No** lista, int j, int k, char* path);

//Pega coordanadas necessárias para desenhar o retangulo do o?
void pegaCoordanadas(No* lista, int j, int k, float* x,float* y,float* w,float* h);

//Pega o centro de massa de cada figura para o i?
void pegaCentro(No* lista, int j, float* x, float* y);

#endif
