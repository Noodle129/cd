#include <stdio.h>
#include "d.h"

int main(int argc, char* argv[]) {
    int descm_RLE = 0; // Se estiver a 1, apenas realiza a descompressão RLE.
    int descm_SF = 0;  // Se estiver a 1, apenas realiza a descompressão SF.
    char* file_name = argv[1];

    if (argc == 1) {
        printf("Tem que especificar pelo menos o nome do ficheiro de input.\n");
        return 0;
    }

    if (argc == 2) {
        moduloD(file_name,descm_RLE,descm_SF);
        return 0;
    }

    if (argc > 2) {
        int i = 2;
        while (i < argc) {
            if (argv[i][1] == 'd') {
                i++;
                if (argv[i][0] == 'r') descm_RLE = 1;
                else if (argv[i][0] == 's') descm_SF = 1;
                i++;
            }
            i++;
        }
    }

    moduloD(file_name,descm_RLE,descm_SF);

}