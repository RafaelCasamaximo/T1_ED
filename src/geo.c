#include "geo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criaSVG(char outPath[]){
    strcat(outPath, "/output.svg");
    FILE* fileSVG = NULL;
    fileSVG = fopen(outPath, "w");

    if(fileSVG == NULL){
        printf("!Erro! Nao foi possivel criar o arquivo.");
        exit(1);
    }
    
    fprintf(fileSVG, "<svg>");
    fclose(fileSVG);
}


void finalizaSVG(char outPath[]){
    FILE* fileSVG = NULL;
    fileSVG = fopen(outPath, "a");

    if(fileSVG == NULL){
        printf("!Erro! Nao foi possivel adicionar ao arquivo.");
        exit(1);
    }

    fprintf(fileSVG, "</svg>");
    fclose(fileSVG);
}