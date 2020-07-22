#ifndef desenhaSvg_H_
#define desenhaSvg_H_

#include "list.h"

//Desenha o SVG apenas do arquivo .geo;
//Lista - lista na qual os elementos serão lidos e desenhados;
//caminho - caminho para criar o arquivo;
No* desenhaSvg(No* lista, char* caminho);

//Desenha o SVG do arquivo .geo e do .qry;
//lista - lista de figuras;
//listaQry - lista de figuras gerados pelo qry. Cada retanbulo tracejado, ponto ou linha é adicionado aqui;
//caminho - caminho para criar o arquivo geo-qry.svg;
No* desenhaSvgQry(No* lista, No* listaQry, char* caminho);

#endif