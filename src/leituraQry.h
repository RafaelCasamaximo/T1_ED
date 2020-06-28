#ifndef leituraQry_H_
#define leituraQry_H_

#include "list.h"

No* pegaDadoQry(No* listaQry, No* lista, char* path);
int sobrepoe(No* lista, int j, int k);
int contem(No* lista, int id, float x, float y);
float distanciaQuadrada(float x1, float  y1, float  x2, float  y2);
int paint(No* lista, int j, char cb[], char cp[]);

#endif