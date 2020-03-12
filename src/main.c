#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    int i = 1;

    char* entryPath = NULL;
    char* geoPath = NULL;
    char* queryPath = NULL;
    char* outPath = NULL;

    //Lê os argumentos passados para o executável
    while(i < argc){
        //siguel [-e path] -f arq.geo [-q consulta.qry] -o dir
        printf("(%d) -> %s", i, argv[i]);

        //Vê se o usuário inseriu um parametro para especificar o local da entrada de arquivos
        if (strcmp("-e",argv[i])==0){
            i++;

            if (argv[i] == NULL){ //Encerra o programa se '-e' não for seguido do local do arquivo.
                printf("\n!Erro! Sem parametros em -e");
                printf("\n '-e' sem diretorio.");
                exit(1);
            }
            printf("\nO caminho existe. (%s)\n",argv[i]);
            entryPath = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(entryPath,argv[i]);
        }

        //Vê se o usuário inseriu um parametro para especificar o arquivo da geografia
        if (strcmp("-f",argv[i])==0){
            i++;

            if (argv[i] == NULL){ //Encerra o programa se '-f' não for seguido do local do arquivo.
                printf("\n!Erro! Sem parametros em -f");
                printf("\n'-f' sem arquivo");
                exit(1);
            }
            printf("\nO caminho existe. (%s)\n",argv[i]);
            geoPath = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(geoPath,argv[i]);
        }

        //Vê se o usuário inseriu um parametro para especificar o arquivo de consulta
        if (strcmp("-q",argv[i])==0){
            i++;

            if (argv[i] == NULL){ //Encerra o programa se '-q' não for seguido do local do arquivo.
                printf("\n!Erro! Sem parametros em -q");
                printf("\n'-q' sem arquivo");
                exit(1);
            }
            printf("\nO caminho existe. (%s)\n",argv[i]);
            queryPath = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(queryPath,argv[i]);
        }

        //Vê se o usuário inseriu um parametro para especificar o local dos arquivos de saída
        if (strcmp("-o",argv[i])==0){
            i++;

            if (argv[i] == NULL){ //Encerra o programa se '-o' não for seguido do diretorio.
                printf("\n!Erro! Sem parametros em -o");
                printf("\n'-o' sem diretorio");
                exit(1);
            }
            printf("\nO caminho existe. (%s)\n",argv[i]);
            outPath = (char *)malloc((strlen(argv[i])+1)*sizeof(char));
            strcpy(outPath,argv[i]);
        }
        i++;
    }

    return 0;
}