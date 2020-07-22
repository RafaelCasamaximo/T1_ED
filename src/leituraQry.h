#ifndef leituraQry_H_
#define leituraQry_H_

#include "list.h"

//Responsável pela leitura do arquivo .qry;
//listaQry - lista de figuras gerados pelo qry. Cada retanbulo tracejado, ponto ou linha é adicionado aqui;
//lista - lista na qual será salvo os elementos lidos do arquivo .geo;
//path - caminho do arquivo .qry;
//pathLog - caminho onde será gerado o arquivo geo-qry.txt;
No* pegaDadoQry(No* listaQry, No** lista, char* path, char* pathLog);

//Responsável por calcular se dois elementos se sobrepoem (o?) 1 - SIM, 0 - NAO, -1 - Não é possivel realizar comparação;
//lista - lista na qual será salvo os elementos lidos do arquivo .geo;
//J e K - elementos necessários no o?;
int sobrepoe(No* lista, int j, int k);

//Responsável por calcular se dois elementos se interceptam (i?) 1 - SIM, 0 - NAO, -1 - Não é possivel realizar comparação;
//lista - lista na qual será salvo os elementos lidos do arquivo .geo;
//id - elemento necessário para o i?;
int contem(No* lista, int id, float x, float y);

//Troca a cor de um elemento 1 - SIM, 0 - NAO;
//lista - lista na qual será salvo os elementos lidos do arquivo .geo;
//j, cb, cp - Elementos necessários para o pnt;
int paint(No* lista, int j, char cb[], char cp[]);

//Troca a cor de N elementos entre J e K 1 - SIM, 0 - NAO;
//lista - lista na qual será salvo os elementos lidos do arquivo .geo;
//j, k, cb, cp - Elementos necessários para o pnt*;
//path - caminho onde o log será criado. É utilizado dentro da função para chamar a função logPaint;
int paintN(No* lista, int j, int k, char cb[], char cp[], char* path);

//Deleta todos os elementos entre J e K caso existam;
//lista - lista na qual será salvo os elementos lidos do arquivo .geo;
//j, k - Elementos necessários para o delf*;
//path - caminho onde o log será criado. É utilizado dentro da função para chamar a função logDelf;
void dElemN(No** lista, int j, int k, char* path);

//Pega coordanadas necessárias para desenhar o retangulo do o?;
//lista - lista na qual será salvo os elementos lidos do arquivo .geo;
//j, k, *x, *y, *w, *h - Elementos necessários para identificar o tamanho do retangulo que será desenhado pelo o?;
void pegaCoordanadas(No* lista, int j, int k, float* x, float* y, float* w, float* h);

//Pega o centro de massa de cada figura para o i?;
//lista - lista na qual será salvo os elementos lidos do arquivo .geo;
//j, *x, *y - elementos necessários para descobrir o centro de massa da figura;
void pegaCentro(No* lista, int j, float* x, float* y);

#endif
