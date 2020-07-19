#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void logInside(No* lista, char* path, int j, float x, float y, int interno){
    FILE* log = fopen(path, "a");
    if(log == NULL){
        printf("Não foi possivel adicionar mais ao arquivo!");
        return;
    }
    No* aux = buscaElem(lista, j);
    if(aux == NULL){
        fclose(log);
        return;
    }
    fprintf(log, "\ni? %d %f %f\n%d: ", j, x, y, j);
    if(aux->tipo == 'c'){
        fprintf(log, "círculo ");
    }
    if(aux->tipo == 'r'){
        fprintf(log, "retângulo ");
    }
    if(interno == 0){
        fprintf(log, "NÃO INTERNO\n");
    }
    if(interno == 1){
        fprintf(log, "INTERNO\n");
    }
    fclose(log);
}

void logOverlay(No* lista, char* path, int j, int k, int interno){
    FILE* log = fopen(path, "a");
    if(log == NULL){
        printf("Não foi possivel adicionar mais ao arquivo!");
        return;
    }
    No* auxJ = buscaElem(lista, j);
    if(auxJ == NULL){
        fclose(log);
        return;
    }
    No* auxK = buscaElem(lista, k);
    if(auxK == NULL){
        fclose(log);
        return;
    }
    if((auxK->tipo != 'c' && auxK->tipo != 'r') || (auxJ->tipo != 'c' && auxJ->tipo != 'r')){
        fclose(log);
        return;
    }
    fprintf(log, "\no? %d %d", j, k);
    if(auxJ->tipo == 'c'){
        fprintf(log, "\n%d: círculo ", j);
    }
    if(auxJ->tipo == 'r'){
        fprintf(log, "\n%d: retângulo ", j);
    }
    if(auxK->tipo == 'c'){
        fprintf(log, "%d: círculo", k);
    }
    if(auxK->tipo == 'r'){
        fprintf(log, "%d: retângulo", k);
    }
    if(interno == 0){
        fprintf(log, " NÃO SOBREPOE\n");
    }
    if(interno == 1){
        fprintf(log, " SOBREPOE\n");
    }
    fclose(log);
}

void logPaint(No* lista, char* path, int j){
    FILE* log = fopen(path, "a");
    if(log == NULL){
        printf("Não foi possivel adicionar mais ao arquivo!");
        return;
    }
    No* aux = buscaElem(lista, j);
    if(aux == NULL){
        fclose(log);
        return;
    }
    fprintf(log, "\npnt %d ", j);
    if(aux->tipo == 'c'){
        fprintf(log, " %s %s\n", aux->fig->c.corb, aux->fig->c.corp);
        fprintf(log, "%d: %f %f\n", j, aux->fig->c.x, aux->fig->c.y);
    }
    if(aux->tipo == 'r'){
        fprintf(log, " %s %s\n", aux->fig->r.corb, aux->fig->r.corp);
        fprintf(log, "%d: %f %f\n", j, aux->fig->r.x, aux->fig->r.y);
    }
    if(aux->tipo == 't'){
        fprintf(log, " %s %s\n", aux->fig->t.corb, aux->fig->t.corp);
        fprintf(log, "%d: %f %f\n", j, aux->fig->t.x, aux->fig->t.y);
    }
    fclose(log);
}

void logDelf(No* lista, char* path, int j){
    FILE* log = fopen(path, "a");
    if(log == NULL){
        printf("Não foi possivel adicionar mais ao arquivo!");
        return;
    }
    No* aux = buscaElem(lista, j);
    if(aux == NULL){
        fclose(log);
        return;
    }
    fprintf(log, "\ndelf %d\n", j);
    if(aux->tipo == 'r'){
        fprintf(log, "x: %f y: %f w: %f h: %f corb: %s corp: %s\n", aux->fig->r.x, aux->fig->r.y, aux->fig->r.w, aux->fig->r.h, aux->fig->r.corb, aux->fig->r.corp);
    }
    if(aux->tipo == 'c'){
        fprintf(log, "x: %f y: %f r: %f corb: %s corp: %s\n", aux->fig->c.x, aux->fig->c.y, aux->fig->c.r, aux->fig->c.corb, aux->fig->c.corp);
    }
    if(aux->tipo == 't'){
        fprintf(log, "x: %f y: %f corb: %s corp: %s texto: %s\n", aux->fig->t.x, aux->fig->t.y, aux->fig->t.corb, aux->fig->t.corp, aux->fig->t.texto);
    }
    fclose(log);
}