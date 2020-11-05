#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "myLib.h"

int ler_chunk(char *arquivo,struct gen_chunk* tmp){
    FILE* arq_in = fopen(arquivo, "rb");
    struct IHDR_chunk* aux;
    fseek(arq_in, 8,SEEK_CUR);
    while(!feof(arq_in)){
        tmp = malloc(sizeof(struct gen_chunk));
        fread(tmp,sizeof(struct gen_chunk),1,arq_in);
        printf("--> Tamanho:\t%d\n",ntohl(tmp -> tamanho));
        printf("--> Tipo:\t%0.4s\n",tmp -> tipo);
        if(tmp -> tipo[0] == 'I' && tmp -> tipo[3] == 'R'){
            aux = malloc(sizeof(struct IHDR_chunk));
            fread(aux,sizeof(struct IHDR_chunk),1,arq_in);
            printf("\t-->Largura:\t%d\n",ntohl(aux -> width));
            printf("\t-->Altura:\t%d\n",ntohl(aux -> height));
            fseek(arq_in, 4,SEEK_CUR);
        }
        else if(tmp -> tipo[0] == 'I' && tmp -> tipo[3] == 'D'){
            fseek(arq_in,0,SEEK_END);
        }
        else{
            fseek(arq_in,ntohl(tmp -> tamanho) + 4,SEEK_CUR);
        }
        free(aux);
        free(tmp);

    }
    fclose(arq_in);
    
}

