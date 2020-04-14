#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"

void leGeo(char entryPath[], char geoPath[]){

    //Abrindo o arquivo e concatenando, caso necessário
    FILE* fGeo = NULL;
    if(entryPath == NULL){
        printf("\nO arquivo .geo está nesse mesmo diretorio");
        printf("\nO arquivo é: %s", geoPath);
        fGeo = fopen(geoPath, "r");
    }
    else{
        printf("\nO caminho esta sendo processado");
        strcat(entryPath, "/");
        strcat(entryPath, geoPath);
        printf("\nO caminho é: %s\n", entryPath);
        fGeo = fopen(entryPath, "r");
    }
    if(!fGeo){
        printf("\n---Não foi possivel abrir o arquivo---");
        printf("\n---O programa será encerrado---");
        exit(1);
    }
    printf("\nArquivo aberto com sucesso");

    //Lendo comandos
    //nx, c, r, t;
    char comando[3], corb[22], corp[22];
    char* texto = NULL;
    int numMax = 1000, id;
    float r, x, y, w, h;
    
    int i = 0;
    while(i < numMax){
        fscanf(fGeo, "%s", comando);

        if(feof(fGeo)){
            break;
        }
        else if(strcmp(comando, "nx") == 0){
            fscanf(fGeo, "%d", &numMax);
        }
        else if(strcmp(comando, "c") == 0){
            fscanf(fGeo, "%d %f %f %f %s %s", &id, &r, &x, &y, corb, corp);
        }
        else if(strcmp(comando, "r") == 0){
            fscanf(fGeo, "%d %f %f %f %f %s %s", &id, &w, &h, &x, &y, corb, corp);
        }
        else if(strcmp(comando, "t") == 0){
            //mais tarde com alocação dinamica
        }
        i++;
    }

    fclose(fGeo);
    printf("\n---Arquivo .geo fechado---");
}