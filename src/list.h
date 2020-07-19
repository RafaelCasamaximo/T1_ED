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

typedef struct{
    float x1, y1, x2, y2;
    int interno;
}Linha;

typedef struct{
    float x, y;
    int interno;
}Ponto;

typedef struct{
    float w, h, x, y;
    int sobrepoe;
}RetanguloTracejado;

typedef union{
    Retangulo r;
    Circulo c;
    Texto t;
    Linha l;
    Ponto p;
    RetanguloTracejado rt;
}Fig;

typedef struct no{
    char tipo;
    int id;
    Fig* fig;

    struct no* prox;
}No;

//Adiciona um elemento com uma figura nula
No* addElem(No* inicio, int id, char tipo);

//Imprime a lista inteira detalhadamente
No* imprimeLista(No* inicio);

//Busca um elemento na lista e retorna-o caso encontre
No* buscaElem(No* inicio, int id);

//Adiciona uma figura Circulo em um elemento já existente
No* addC(No* inicio, int id, float r, float x, float y, char corb[], char corp[]);

//Adiciona uma figura Retângulo em um elemento já existente
No* addR(No* inicio, int id, float w, float h, float x, float y, char corb[], char corp[]);

//Adiciona uma figura Texto em um elemento já existente
No* addT(No* inicio, int id, char texto[], float x, float y, char corb[], char corp[], int buffersize);

//Adiciona uma figura Linha em um elemento já existente
No* addL(No* inicio, int id, float x1, float y1, float x2, float y2, int interno);

//Adiciona uma figura Ponto em um elemento já existente
No* addP(No* inicio, int id, float x, float y, int interno);

//Adiciona uma figura Retângulo Tracejado em um elemento já existente
No* addRT(No* inicio, int id, float x, float y, float w, float h, int sobrepoe);

//Deleta a lista inteira e retorna NULL
No* delLista(No* inicio);

//Deleta um unico elemento da lista
No* delElem(No* lista, int id);

#endif