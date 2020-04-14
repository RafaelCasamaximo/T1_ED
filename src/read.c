#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"
#include "list.h"

No* leGeo(char entryPath[], char geoPath[], No* inicio){

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
    char comando[3], corb[22], corp[22], buffer;
    char* texto = NULL;
    int numMax = 1000, id, buffersize = 0;
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
            inicio = addElem(inicio, id, 'c');
            inicio = addC(inicio, id, r, x, y, corb, corp);
        }
        else if(strcmp(comando, "r") == 0){
            fscanf(fGeo, "%d %f %f %f %f %s %s", &id, &w, &h, &x, &y, corb, corp);
            inicio = addElem(inicio, id, 'r');
        }
        else if(strcmp(comando, "t") == 0){
            fscanf(fGeo, "%d %f %f %s %s", &id, &x, &y, corb, corp);
            buffer = getc(fGeo);
            while(buffer != '\n' && buffer != EOF){
            buffer = getc(fGeo);
            buffersize++;
            }
            fseek(fGeo, -buffersize, SEEK_CUR);
            texto = (char*)malloc(sizeof(char) * buffersize);
            fscanf(fGeo, "%[^\n]s", texto);
            inicio = addElem(inicio, id, 't');
            inicio = addT(inicio, id, texto, x, y, corb, corp, buffersize);
        }
        i++;
    }

    inicio = imprimeLista(inicio);



    fclose(fGeo);
    printf("\n---Arquivo .geo fechado---");

    return inicio;
}