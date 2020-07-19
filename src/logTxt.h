#ifndef logTxt_H_
#define logTxt_H_

//Imprime (append) informações do i? no txt
void logInside(No* lista, char* path, int j, float x, float y, int interno);

//Imprime (append) informações do o? no txt
void logOverlay(No* lista, char* path, int j, int k, int interno);

//Imprime (append) informações do pnt e pnt* no txt
void logPaint(No* lista, char* path, int j);

//Imprime (append) informações do delf e delf* no txt
void logDelf(No* lista, char* path, int j);

#endif