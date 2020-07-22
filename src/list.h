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

//Adiciona um elemento com uma figura nula;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id e tipo são necessários para criar um elemento na lista;
No* addElem(No* inicio, int id, char tipo);

//Imprime a lista inteira detalhadamente;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
No* imprimeLista(No* inicio);

//Busca um elemento na lista e retorna-o caso encontre;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id - necessário para achar o elemento de determinado id e retornar;
No* buscaElem(No* inicio, int id);

//Adiciona uma figura Circulo em um elemento já existente;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id - necessário para adicionar a figura no elemento correspondente;
//r, x, y, corb, corp - necessários para adicionar uma figura Circulo;
No* addC(No* inicio, int id, float r, float x, float y, char corb[], char corp[]);

//Adiciona uma figura Retângulo em um elemento já existente;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id - necessário para adicionar a figura no elemento correspondente;
//w, h, x, y, corb, corp - necessários para adicionar uma figura Retângulo;
No* addR(No* inicio, int id, float w, float h, float x, float y, char corb[], char corp[]);

//Adiciona uma figura Texto em um elemento já existente;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id - necessário para adicionar a figura no elemento correspondente;
//x, y, texto, corb, corp - necessários para adicionar uma figura Texto;
No* addT(No* inicio, int id, char texto[], float x, float y, char corb[], char corp[], int buffersize);

//Adiciona uma figura Linha em um elemento já existente;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id - necessário para adicionar a figura no elemento correspondente;
//x1, y1, x2, y2, interno - necessários para adicionar uma figura Linha;
No* addL(No* inicio, int id, float x1, float y1, float x2, float y2, int interno);

//Adiciona uma figura Ponto em um elemento já existente;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id - necessário para adicionar a figura no elemento correspondente;
//x1, y1, interno - necessários para adicionar uma figura Ponto;
No* addP(No* inicio, int id, float x, float y, int interno);

//Adiciona uma figura Retângulo Tracejado em um elemento já existente;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id - necessário para adicionar a figura no elemento correspondente;
//w, h, x, y, sobrepoe - necessários para adicionar uma figura Retângulo Tracejado;
No* addRT(No* inicio, int id, float x, float y, float w, float h, int sobrepoe);

//Deleta a lista inteira e retorna NULL;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
No* delLista(No* inicio);

//Deleta um unico elemento da lista;
//Inicio - começo da lista que é sempre retornado no final da função para não perder a referência;
//id - elemento de referência para ser deletado;
No* delElem(No* lista, int id);

#endif