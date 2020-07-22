#ifndef logTxt_H_
#define logTxt_H_

//Imprime (append) informações do i? no txt
//Lista - lista na qual os elementos serão lidos e escritos no log;
//path - caminho para abrir o arquivo de log
//J, x, y, interno - necessário para o i?
void logInside(No* lista, char* path, int j, float x, float y, int interno);

//Imprime (append) informações do o? no txt
//Lista - lista na qual os elementos serão lidos e escritos no log;
//path - caminho para abrir o arquivo de log
//J, k, interno - necessário para o o?
void logOverlay(No* lista, char* path, int j, int k, int interno);

//Imprime (append) informações do pnt e pnt* no txt
//Lista - lista na qual os elementos serão lidos e escritos no log;
//path - caminho para abrir o arquivo de log
//J - necessário para o pnt e pnt*
void logPaint(No* lista, char* path, int j);

//Imprime (append) informações do delf e delf* no txt
//Lista - lista na qual os elementos serão lidos e escritos no log;
//path - caminho para abrir o arquivo de log
//J - necessário para o delf e o delf*
void logDelf(No* lista, char* path, int j);

#endif