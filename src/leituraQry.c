#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraQry.h"
#include "list.h"
#include "padrao.h"

No* pegaDadoQry(No* listaQry, No* lista, char* path){
    FILE* qry = NULL;
    qry = fopen(path, "r");
    if(qry == NULL){
        printf("ERRO! Não foi possivel abrir o arquivo! O QRY não será considerado!");
        exit(1);
    }

    int j = 0, k = 0, id = 0;
    float x, y;
    char cb[22], cp[22], comando[6];
    int resultado = 0;

    while(1){
        fscanf(qry, "%s", comando); //vai pra proxima linha automaticamente?
        if(feof(qry)){
            break;
        }
        if(strcmp(comando, "o?")){
            fscanf(qry, "%d %d", &j, &k);
            resultado = sobrepoe(lista, j, k);
        }
        if(strcmp(comando, "i?")){
            fscanf(qry, "%d %f %f", &j, &x, &y);
            resultado = contem(lista, j, x, y);
        }
        if(strcmp(comando, "pnt")){
            fscanf(qry, "%d %s %s", &j, cb, cp);
        }
        if(strcmp(comando, "pnt*")){
            fscanf(qry, "%d %d %s %s", &j, &k, cb, cp);
        }
        if(strcmp(comando, "delf")){
            fscanf(qry, "%d", &j);
        }
        if(strcmp(comando, "delf*")){
            fscanf(qry, "%d %d", &j, &k);
        }
        id++;
    }
    fclose(qry);
    return listaQry;
}

int sobrepoe(No* lista, int j, int k){
    No* auxJ = NULL;
    No* auxK = NULL;
    int resultado = 0;

    //Verificações
    auxJ = buscaElem(lista, j);
    if(auxJ == NULL){
        printf("\nNão é possivel aplicar o algoritmo de sobreposição.\nO Elemento com o ID J não foi encontrato e/ou não existe!\n");
        return 0;
    }
    auxK = buscaElem(lista, k);
    if(auxK == NULL){
        printf("\nNão é possivel aplicar o algoritmo de sobreposição.\nO Elemento com o ID K não foi encontrato e/ou não existe!\n");
        return 0;
    }
    //Verifica se nenhum dos dos elementos são circulos e/ou retangulos
    if((auxJ->tipo != 'c' && auxJ->tipo != 'r') || (auxK->tipo != 'c' && auxK->tipo != 'r')){
        printf("A verificação de sobreposição só é possível para círculos e retangulos!\n");
        return 0;
    }

    //retangulo e retangulo
    if(auxJ->tipo == 'r' && auxK->tipo == 'r'){
        //ret a
        float jx = auxJ->fig->r.x;
        float jy = auxJ->fig->r.y;
        float jw = auxJ->fig->r.w;
        float jh = auxJ->fig->r.h;

        float kx = auxK->fig->r.x;
        float ky = auxK->fig->r.y;
        float kw = auxK->fig->r.w;
        float kh = auxK->fig->r.h;

        //x,y
        if(jx <= kx && kx <= (jx+jw)){
            if(jy <= ky && ky <= (jy+jh)){
                return 1;
            }
        }
        //x+w, y
        if(jx <= kx+kw && kx+kw <= (jx+jw)){
            if(jy <= ky && ky <= (jy+jh)){
                return 1;
            }
        }
        //x, y+h
        if(jx <= kx && kx <= (jx+jw)){
            if(jy <= ky+kh && ky+kh <= (jy+jh)){
                return 1;
            }
        }
        if(jx <= kx+kw && kx+kw <= (jx+jw)){
            if(jy <= ky+kh && ky+kh <= (jy+jh)){
                return 1;
            }
        }
        return 0;
    }

    //circulo e circulo
    if(auxJ->tipo == 'c' && auxK->tipo == 'c'){
        if(distanciaQuadrada(auxJ->fig->c.x, auxJ->fig->c.y, auxK->fig->c.x, auxK->fig->c.y) <= ((auxJ->fig->c.r + auxK->fig->c.r) * (auxJ->fig->c.r + auxK->fig->c.r))){
            return 1;
        }
        return 0;
    }

    //retangulo e circulo
    if((auxJ->tipo == 'r' && auxK->tipo == 'c') || (auxJ->tipo == 'c' && auxK->tipo == 'r')){
        No* circulo = NULL;
        No* retangulo = NULL;
        if(auxJ->tipo == 'r'){
            circulo = auxJ;
            retangulo = auxK;
        }
        else{
            circulo = auxK;
            retangulo = auxJ;
        }
        float dX = circulo->fig->c.x - max(retangulo->fig->r.x, min(circulo->fig->c.x, retangulo->fig->r.x + retangulo->fig->r.w));
        float dY = circulo->fig->c.y - max(retangulo->fig->r.y, min(circulo->fig->c.y, retangulo->fig->r.y + retangulo->fig->r.h));
        if((dX * dX + dY * dY) <= (circulo->fig->c.r * circulo->fig->c.y)){
            return 1;
        } 
        return 0;
    }
    return 0;
}

int contem(No* lista, int j, float x, float y){
    No* auxJ = NULL;
    auxJ = buscaElem(lista, j);
    if(auxJ == NULL){
        printf("\nNão é possivel aplicar o algoritmo de intersecção.\nO Elemento com o ID J não foi encontrato e/ou não existe!\n");
        return 0;
    }
    if(auxJ->tipo == 'r'){
        float xr = auxJ->fig->r.x;
        float yr = auxJ->fig->r.y;
        float wr = auxJ->fig->r.w;
        float hr = auxJ->fig->r.h;
        if(((xr <= x) && (x <= (xr + wr))) && ((yr <= y) && (y <= (yr + hr)))){
            return 1;
        }
    }
    if(auxJ->tipo == 'c'){
        float dX = auxJ->fig->c.x - x;
        float dY = auxJ->fig->c.y - y;
        if(((dX * dX) + (dY * dY)) <= (auxJ->fig->c.r * auxJ->fig->c.r)){
            return 1;
        }
    }
    else{
        printf("O tipo de elemento é invalido na comparação!");
    }
    return 0;
}

float distanciaQuadrada(float x1, float  y1, float  x2, float  y2){
    return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}
