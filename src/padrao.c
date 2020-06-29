#include <stdio.h>
#include <stdlib.h>

void condicionaRetangulo(float* x, float* y, float* w, float* h){
    float xf = *x;
    float yf = *y;
    float wf = *w;
    float hf = *h;
    if(xf < (xf+wf)){
        if(yf > (yf+hf)){
            //2
            *x = xf;
            *y = yf + hf;
            *w = wf;
            *h = hf * (-1);
        }
    }
    else{
        if(yf < (yf+hf)){
            //3
            *x = xf + wf;
            *y = yf;
            *w = wf * (-1);
            *h = hf;
        }
        else{
            //4
            *x = xf + wf;
            *y = yf + hf;
            *w = wf * (-1);
            *h = hf * (-1);
        }
    }
}


float distanciaQuadrada(float x1, float  y1, float  x2, float  y2){
    return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}

float min(float a, float b){
    return ((a < b) ? a : b);
}

float max(float a, float b){
    return ((a > b) ? a : b);
}

float minV(float v[], int tamanho){
    float min = v[0];
    for(int i = 1; i < tamanho; i++){
        if(min > v[i]){
            min = v[i];
        }
    }
    return min;
}

float maxV(float v[], int tamanho){
    float max = v[0];
    for(int i = 1; i < tamanho; i++){
        if(max < v[i]){
            max = v[i];
        }
    }
    return max;
}

