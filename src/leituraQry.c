#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraQry.h"
#include "list.h"

No* pegaDadoQry(No* lista, char* path){
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
            // resultado = sobrepoe(j, k);
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

    return lista;
}