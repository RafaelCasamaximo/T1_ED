#ifndef list_H_
#define list_H_

typedef struct{
    float w, h, x, y;
    char corb[22], corp[22];
}Retangulo;

typedef struct{
    float r, x, y;
    char corb[22], corp[22];
}Circulo;

typedef struct{
    float x, y;
    char corb[22], corp[22];
    char* texto;
}Texto;

typedef union{
    Retangulo r;
    Circulo c;
    Texto t;
}Fig;

typedef struct no{
    char tipo;
    int id;
    Fig* fig;

    struct no* prox;
}No;

No* addElem(No* inicio, int id, char tipo);
No* imprimeLista(No* inicio);
No* buscaElem(No* inicio, int id);
No* addC(No* inicio, int id, float r, float x, float y, char corb[], char corp[]);
No* addR(No* inicio, int id, float w, float h, float x, float y, char corb[], char corp[]);
No* addT(No* inicio, int id, char texto[], float x, float y, char corb[], char corp[], int buffersize);
No* delLista(No* lista);
#endif