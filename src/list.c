#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

No* addElem(No* inicio, int id, char tipo){
    if(!inicio){
        inicio = (No*)malloc(sizeof(No));
        inicio->id = id;
        inicio->tipo = tipo;
        inicio->fig = NULL;
        inicio->prox = NULL;
        printf("\nElemento adicionado como sucesso (ID: %d TIPO: %c)", inicio->id, inicio->tipo);
        return inicio;
    }
    No* aux = inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = (No*)malloc(sizeof(No));
    aux = aux->prox;
    aux->fig = NULL;
    aux->id = id;
    aux->tipo = tipo;
    aux->prox = NULL;
    printf("\nElemento adicionado como sucesso (ID: %d TIPO: %c)", aux->id, aux->tipo);
    return inicio;
}

No* imprimeLista(No* inicio){
    No* aux = inicio;
    printf("\n---IMPRIMINDO LISTA---\nInicio->");
    while(aux != NULL){
        printf(" (Id:%d Tipo:%c)->", aux->id, aux->tipo);
        aux = aux->prox;
    }
    printf(" (null)\n---FIM DA LISTA---\n");
    return inicio;
}

No* buscaElem(No* inicio, int id){
    No *aux = inicio;
    while(aux != NULL){
        if(id == aux->id){
            printf("\n\nRetornando elemento de ID: %d", id);
            return aux;
        }
        aux = aux->prox;
    }
    printf("\nNão foi possivel encontrar o elemento de ID: %d. Retornando NULL\n\n", id);
    return NULL;
}

No* addC(No* inicio, int id, float r, float x, float y, char corb[], char corp[]){
    No* aux = buscaElem(inicio, id);
    if(aux == NULL){
        return inicio;
    }
    aux->fig = (Fig*)malloc(sizeof(Fig));
    if(aux->fig == NULL){
        printf("Não foi possivel alocar memória para a figura. Encerrando programa");
        exit(1);
    }
    aux->fig->c.r = r;
    aux->fig->c.x = x;
    aux->fig->c.y = y;
    strcpy(aux->fig->c.corb, corb);
    strcpy(aux->fig->c.corp, corp);
    printf("\nForma Tipo: \'c\' adicionada com sucesso.\nr: %f x: %f y: %f\ncorb: %s corp: %s",aux->fig->c.r, aux->fig->c.x, aux->fig->c.y, aux->fig->c.corb, aux->fig->c.corp);
    return inicio;
}

No* addR(No* inicio, int id, float w, float h, float x, float y, char corb[], char corp[]){
    No* aux = buscaElem(inicio, id);
    aux->fig = (Fig*)malloc(sizeof(Fig));
    if(aux->fig == NULL){
        printf("Não foi possivel alocar memória para a figura. Encerrando programa");
        exit(1);
    }
    aux->fig->r.w = w;
    aux->fig->r.w = h;
    aux->fig->r.x = x;
    aux->fig->r.y = y;
    strcpy(aux->fig->r.corb, corb);
    strcpy(aux->fig->r.corp, corp);
    printf("\nForma Tipo: \'r\' adicionada com sucesso.\nw: %f h: %f x: %f y: %f\ncorb: %s corp: %s",aux->fig->r.w, aux->fig->r.h, aux->fig->r.x, aux->fig->r.y, aux->fig->r.corb, aux->fig->r.corp);
    return inicio;
}

No* addT(No* inicio, int id, char texto[], float x, float y, char corb[], char corp[], int buffersize){
    No* aux = buscaElem(inicio, id);
    aux->fig = (Fig*)malloc(sizeof(Fig));
    if(aux->fig == NULL){
        printf("Não foi possivel alocar memória para a figura. Encerrando programa");
        exit(1);
    }

    aux->fig->t.x = x;
    aux->fig->t.y = y;
    aux->fig->t.texto = (char*)malloc(sizeof(char) * buffersize);
    if(aux->fig->t.texto == NULL){
        printf("Erro inesperado! Memoria insuficiente para salvar caracteres do texto.");
        exit(1);
    }
    strcpy(aux->fig->t.texto, texto);
    strcpy(aux->fig->t.corb, corb);
    strcpy(aux->fig->t.corp, corp);
    printf("\nForma Tipo: \'t\' adicionada com sucesso.\nt: \'%s\' x: %f y: %f\ncorb: %s corp: %s", aux->fig->t.texto, aux->fig->t.x, aux->fig->t.y, aux->fig->r.corb, aux->fig->r.corp);
    return inicio;
}