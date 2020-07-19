#ifndef desenhaSvg_H_
#define desenhaSvg_H_

#include "list.h"

//Desenha o SVG apenas do arquivo .geo
No* desenhaSvg(No* lista, char* caminho);

//Desenha o SVG do arquivo .geo e do .qry
No* desenhaSvgQry(No* lista, No* listaQry, char* caminho);

#endif