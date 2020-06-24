#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trataString.h"

char *concatenaCaminhos(char e[], char f[])
{

    printf("E -> %s", e);
    printf("\nE -> %s\n", f);

    //Tamanho base definido
    int tamanhoE = strlen(e);
    int tamanhoF = strlen(f);
    int tamanhoResultado = tamanhoE + tamanhoF + 1;
    char *concat = NULL;
    //Condicionais
    //-e = * e -f = *
    if (e[tamanhoE - 1] != '/' && (f[0] != '/' && f[0] != '.'))
    {
        tamanhoResultado += 1;
        concat = (char *)malloc(sizeof(char) * tamanhoResultado);
        strcat(concat, e);
        strcat(concat, "/");
        strcat(concat, f);
        strcat(concat, "\0");
    }
    else if (e[tamanhoE - 1] == '/' && (f[0] != '/' && f[0] != '.'))
    {
        concat = (char *)malloc(sizeof(char) * tamanhoResultado);
        strcat(concat, e);
        strcat(concat, f);
        strcat(concat, "\0");
    }
    else if (e[tamanhoE - 1] == '/' && f[0] == '/')
    {
        tamanhoResultado -= 1;
        concat = (char *)malloc(sizeof(char) * tamanhoResultado);
        concat = strtok(e, "/");
        strcat(concat, f);
        strcat(concat, "\0");
    }
    else if (e[tamanhoE - 1] == '/' && f[0] == '.')
    {
        tamanhoResultado -= 2;
        concat = (char *)malloc(sizeof(char) * tamanhoResultado);
        concat = strtok(e, "/");
        f = &f[1];
        strcat(concat, f);
        strcat(concat, "\0");
    }
    printf("Caminho concatenado para abrir o .GEO: \"%s\"", concat);
    return concat;
}

char *getNomeConcatExtension(char f[], char ext[])
{
    int tamanhoString = 0;
    char *concat = NULL;
    if (f[0] == '.')
    {
        f = &f[1];
    }
    f = strtok(f, ".");
    if (f[0] == '/')
    {
        f = strrchr(f, '/');
        f = &f[1];
    }

    tamanhoString += strlen(f) + strlen(ext);
    concat = (char *)malloc(sizeof(char) * tamanhoString);
    strcpy(concat, f);
    strcat(concat, ext);
    return concat;
}
