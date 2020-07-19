#ifndef trataString_H_
#define trataString_H_

//Concatena dois paths fazendo a verificação de barras duplas, pontos duplos ou falta de caracteres
void concatenaCaminhos(char e[], char f[], char** result);

//retira o nome do arquivo que está sendo aberto e concatena com uma extensão
void getNomeConcatExtension(char f[], char ext[], char** result);

//retira o nome do arquivo que está sendo aberto
void extraiNome(char f[], char** result);

//Faz o tratamento necessário para que o nome do arquivo SVG gerado a partir do query esteja correto
void concatenaNomeGeoQry(char geo[], char qry[], char ext[], char** result);

#endif