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

float min(float a, float b){
    return ((a < b) ? a : b);
}

float max(float a, float b){
    return ((a > b) ? a : b);
}

