#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraGeo.h"
#include "list.h"

No* pegaDadosGeo(No* lista, char* dirEntrada){

    printf("\n-----%d", lista);

    lista = imprimeLista(lista);

    printf("\nO caminho passado para pegaDadosGeo é: %s", dirEntrada);
    FILE* arqGeo = fopen(dirEntrada, "r");
    if(arqGeo == NULL){
        printf("\n ***Não foi possivel abrir o arquivo. Certifique-se de passar as flags corretas para o programa***\n");
        exit(1);
    }
    printf("\n***Arquivo Geo foi aberto***\n");

    int numMax = 1000;
    char comando[3];
    int i = 0;
    int id;
	float x, y, w, h, r;
	char cb[20], cp[20];

    while(i <= numMax){
        printf("\n-----%d", lista);
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
            fscanf(arqGeo, "%d %f %f %f %f %s %s", &id, &x, &y, &w, &h, cb, cp);
            lista = addElem(lista, id, 'r');
            addR(lista, id, w, h, x, y, cb, cp);
        }
        else if(strcmp("t", comando) == 0){
            //fscanf(arqGeo, "", );
        }
        i++;
    }

    fclose(arqGeo);
    free(dirEntrada);
    printf("\n***Arquivo Geo foi fechado***\n");
    lista = imprimeLista(lista);
}
