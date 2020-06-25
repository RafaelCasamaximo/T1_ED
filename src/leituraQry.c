#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraQry.h"
#include "list.h"

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
    }
    fclose(qry);
    return listaQry;
}

int sobrepoe(No* lista, int j, int k){
    No* auxJ = NULL;
    No* auxK = NULL;

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

    return 0;
}

int contem(No* lista, int j, float x, float y){
    No* auxJ = NULL;
    auxJ = buscaElem(lista, j);
    if(auxJ == NULL){
        printf("\nNão é possivel aplicar o algoritmo de intersecção.\nO Elemento com o ID J não foi encontrato e/ou não existe!\n");
    }
    if(auxJ->tipo == 'r'){
        float xr = auxJ->fig->r.x;
        float yr = auxJ->fig->r.y;
        float wr = auxJ->fig->r.w;
        float hr = auxJ->fig->r.h;
        return (((xr <= x) && (x <= (xr + wr))) && ((yr <= y) && (y <= (yr + hr))));
    }
    if(auxJ->tipo == 'c'){
        float dX = auxJ->fig->c.x - x;
        float dY = auxJ->fig->c.y - y;
        return (((dX * dX) + (dY * dY)) <= (auxJ->fig->c.r * auxJ->fig->c.r));
    }
    else{
        printf("O tipo de elemento é invalido na comparação!");
    }
    return 0;
}