#ifndef padrao_H_
#define padrao_H_

//Função para fazer com que o ponto X e Y do retângulo seja sempre o superior direito (OPCIONAL) - Caso o professor corrija com script, a função pode dar problema, por isso está comentada. O código funciona normalmente sem ela
//void condicionaRegantulo(float* x, float* y, float* w, float* h);

//Calcula e retorna a distancia quadrada entre 2 pontos
float distanciaQuadrada(float x1, float  y1, float  x2, float  y2);

//Calcula o min de 2 valores
float min(float a, float b);

//Calcula o max de 2 valores
float max(float a, float b);

//Calcula o min de um vetor
float minV(float v[], int tamanho);

//Calcula o max de um vetor
float maxV(float v[], int tamanho);

#endif