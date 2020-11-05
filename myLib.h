#ifndef _myLib
#define _mylib


struct gen_chunk {
    int tamanho;
    char tipo[4];
}__attribute__ ((packed));

struct IHDR_chunk {
    int width;
    int height;
    char bit_depth;
    char colour_type;
    char compressionMethod;
    char filterMethod;
    char interfaceMethod;
}__attribute__ ((packed));


int ler_chunk(char *arquivo,struct gen_chunk* tmp);

#endif