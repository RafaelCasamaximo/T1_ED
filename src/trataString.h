#ifndef trataString_H_
#define trataString_H_

//Concatena dois paths fazendo a verificação de barras duplas, pontos duplos ou falta de caracteres;
//e[] - caminho especificado pelo -e;
//f[] - caminho especificado pelo -f;
//result - referência para a concatenação;
void concatenaCaminhos(char e[], char f[], char** result);

//retira o nome do arquivo que está sendo aberto e concatena com uma extensão;
//f[] - caminho especificado pelo -f;
//ext[] - extensão de um arquivo (Ex.: .txt, .svg, ...);
//result - referência para a concatenação;
void getNomeConcatExtension(char f[], char ext[], char** result);

//retira o nome do arquivo que está sendo aberto;
//f[] - caminho especificado pelo -f;
//result - referência para a concatenação;
void extraiNome(char f[], char** result);

//Faz o tratamento necessário para que o nome do arquivo SVG gerado a partir do query esteja correto;
//geo[] - nome do arquivo geo;
//qry[] - nome do arquivo qry;
//ext[] - extensão para ser concatenada ao final (Ex.: .txt, .svg, ...);
//result - referência para a concatenação;
void concatenaNomeGeoQry(char geo[], char qry[], char ext[], char** result);

#endif