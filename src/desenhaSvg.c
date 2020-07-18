#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraGeo.h"
#include "list.h"

No* desenhaSvg(No* lista, char* caminho){
    FILE* svg = NULL;
    svg = fopen(caminho, "w");
    if(svg == NULL){
        printf("\nERRO! Não foi possivel abrir o arquivo!  (SVG)\n");
        exit(1);
    }
    printf("\n---DESENHANDO O SVG COM OS ELEMENTOS LIDOS---\n");
    No* aux = lista;
    fprintf(svg, "<svg>\n");
    while(aux != NULL){
        if(aux->fig != NULL){
            if(aux->tipo == 'c'){
                fprintf(svg, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" stroke=\"%s\" fill=\"%s\"/>", aux->fig->c.x, aux->fig->c.y, aux->fig->c.r, aux->fig->c.corb, aux->fig->c.corp);
            }
            else if(aux->tipo == 'r'){
                fprintf(svg, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"fill:%s;stroke:%s\"/>", aux->fig->r.x, aux->fig->r.y, aux->fig->r.w, aux->fig->r.h, aux->fig->r.corb, aux->fig->r.corp);
            }
            else if(aux->tipo == 't'){
                fprintf(svg, "\n\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"0.5\">%s</text>", aux->fig->t.x, aux->fig->t.y, aux->fig->t.corp, aux->fig->t.corb, aux->fig->t.texto);
            }
        }
        aux = aux->prox;
    }
    fprintf(svg, "\n<svg>\n");
    fclose(svg);
    printf("\n---SVG DESENHADO COM SUCESSO---\n");
    return lista;
}

No* desenhaSvgQry(No* lista, No* listaQry, char* caminho){
    FILE* svgQry = NULL;
    svgQry = fopen(caminho, "w");
    if(svgQry == NULL){
        printf("Não foi possivel abrir o arquivo! (SVG-QRY)");
        exit(1);
    }
        printf("\n---DESENHANDO O SVG COM OS ELEMENTOS LIDOS---\n");
    No* aux = lista;
    fprintf(svgQry, "<svg>\n");
    while(aux != NULL){
        if(aux->fig != NULL){
            if(aux->tipo == 'c'){
                fprintf(svgQry, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" stroke=\"%s\" fill=\"%s\"/>", aux->fig->c.x, aux->fig->c.y, aux->fig->c.r, aux->fig->c.corb, aux->fig->c.corp);
            }
            else if(aux->tipo == 'r'){
                fprintf(svgQry, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"fill:%s;stroke:%s\"/>", aux->fig->r.x, aux->fig->r.y, aux->fig->r.w, aux->fig->r.h, aux->fig->r.corb, aux->fig->r.corp);
            }
            else if(aux->tipo == 't'){
                fprintf(svgQry, "\n\t<text x=\"%f\" y=\"%f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"0.5\">%s</text>", aux->fig->t.x, aux->fig->t.y, aux->fig->t.corp, aux->fig->t.corb, aux->fig->t.texto);
            }
        }
        aux = aux->prox;
    }
    No* auxQry = listaQry;
    while(auxQry != NULL){
        
        if(auxQry->tipo == 'l'){
            if(auxQry->fig->l.interno == 1){
                fprintf(svgQry, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:blue; stroke-width:2\"/>", auxQry->fig->l.x1 , auxQry->fig->l.y1 , auxQry->fig->l.x2 , auxQry->fig->l.y2);
            }
            else{
                fprintf(svgQry, "\n\t<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" style=\"stroke:magenta; stroke-width:2\"/>", auxQry->fig->l.x1 , auxQry->fig->l.y1 , auxQry->fig->l.x2 , auxQry->fig->l.y2);
            }
        }
        if(auxQry->tipo == 'p'){
            if(auxQry->fig->p.interno == 1){
                fprintf(svgQry, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"3\" fill=\"blue\"/>", auxQry->fig->p.x, auxQry->fig->p.y);
            }
            else{
                fprintf(svgQry, "\n\t<circle cx=\"%f\" cy=\"%f\" r=\"3\" fill=\"magenta\"/>", auxQry->fig->p.x, auxQry->fig->p.y);
            }
        }
        
        if(auxQry->tipo == 'd'){
            if(auxQry->fig->rt.sobrepoe == 1){
                fprintf(svgQry, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill-opacity=\"0.0\" style=\"stroke-width:4px;stroke:black;\"/>", auxQry->fig->r.x, auxQry->fig->r.y, auxQry->fig->r.w, auxQry->fig->r.h);
            }
            else{
                fprintf(svgQry, "\n\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill-opacity=\"0.0\" style=\"stroke-width:4px;stroke:black;stroke-dasharray: 20 20;\"/>", auxQry->fig->r.x, auxQry->fig->r.y, auxQry->fig->r.w, auxQry->fig->r.h);
            }
        }
        auxQry = auxQry->prox;
    }
    fprintf(svgQry, "\n<svg>\n");
    fclose(svgQry);
    return listaQry;
}