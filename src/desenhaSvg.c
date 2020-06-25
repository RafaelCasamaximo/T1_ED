#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraGeo.h"
#include "list.h"

No* desenhaSvg(No* lista, char* caminho){
    FILE* svg = NULL;
    svg = fopen(caminho, "w");
    if(svg == NULL){
        printf("\nERRO! Não foi possivel abrir o arquivo!\n");
        exit(1);
    }

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
    return lista;
}