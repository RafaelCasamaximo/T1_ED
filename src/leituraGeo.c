#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraGeo.h"
#include "list.h"

No* pegaDadosGeo(No* lista, char* dirEntrada){

    printf("\nO caminho passado para pegaDadosGeo é: %s", dirEntrada);
    FILE* arqGeo = fopen(dirEntrada, "r");
    if(arqGeo == NULL){
        printf("\n ***Não foi possivel abrir o arquivo. Certifique-se de passar as flags corretas para o programa***\n");
        exit(1);
    }
    printf("\n***Arquivo Geo foi aberto***\n");

    int numMax = 1000;
    char comando[3];
    int i = 0, id, bufferSize = 0;
	float x, y, w, h, r;
	char cb[20], cp[20], buffer;
    char* txt = NULL;

    while(i <= numMax){
        fscanf(arqGeo, "%s", comando);

        if(feof(arqGeo)){
            break;
        }
        else if(strcmp("nx", comando) == 0){
            fscanf(arqGeo, "%d", &numMax);
            printf("Valor máximo de figuras alterado para %d", numMax);
        }
        else if(strcmp("c", comando) == 0){
            //c i r x y corb corp 
            fscanf(arqGeo, "%d %f %f %f %s %s", &id, &r, &x, &y, cb, cp);
            lista = addElem(lista, id, 'c');
            addC(lista, id, r, x, y, cb, cp);
        }
        else if(strcmp("r", comando) == 0){
            fscanf(arqGeo, "%d %f %f %f %f %s %s", &id, &w, &h, &x, &y, cb, cp);
            lista = addElem(lista, id, 'r');
            condicionaRetangulo(&x, &y, &w, &h);
            addR(lista, id, w, h, x, y, cb, cp);
        }
        else if(strcmp("t", comando) == 0){
            //t i x y cb cp txt
            fscanf(arqGeo, "%d %f %f %s %s", &id, &x, &y, cb, cp);
            buffer = getc(arqGeo);
            while(!feof(arqGeo) && buffer != '\n'){ 
                buffer = getc(arqGeo);
                bufferSize++;
            }
            bufferSize++;
            fseek(arqGeo, -bufferSize, SEEK_CUR);
            buffer = getc(arqGeo);
            txt = (char *)malloc(sizeof(char) * (bufferSize + 1));
            if(txt == NULL){
                printf("ERRO! Não foi possivel alocar memória!");
                exit(1);
            }
            fscanf(arqGeo, "%[^\n]s", txt);
            lista = addElem(lista, id, 't');
            lista = addT(lista, id, txt, x, y, cb, cp, bufferSize);
            bufferSize = 0;
            free(txt);
        }
        i++;
    }

    fclose(arqGeo);
    printf("\n***Arquivo Geo foi fechado***\n***A leitura foi concluida***\n");
    lista = imprimeLista(lista);
    return lista;
}