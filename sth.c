#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void utf8_to_cp1251(unsigned char **letter_prt);

int main(int argc, char *argv[]) {
    char* _0x = "";
    char* separator = "";
    int nflag = 0, count = 0;

    int optCount = 0;
    int opt;
    while ((opt = getopt(argc, argv, "s:n:")) != -1) {
        switch (opt) {
        case 's':
            _0x = "0x";
            separator = optarg;
            optCount += 2;
            break;
        case 'n':
            nflag = 1;
            unsigned char *letter = optarg;
            while (*letter++) {
                count = count * 10 + *(letter - 1) - '0';
            }
            optCount += 2;
            break;
        default:
            break;
        }
    }
    
    argv += optCount;

    int iter = 0;
    while (*++argv) {
        unsigned char *letter = *argv;

        while (*letter) {
            utf8_to_cp1251(&letter);
            printf("%s%02X", _0x, *letter);
            if (*(letter + 1)) {
                printf("%s", separator);
            }
            if (nflag && (++iter % count == 0)) {
                printf("\n");
            }
            ++letter;
        }
    }

    printf("\b");

    exit(0);
}

void utf8_to_cp1251(unsigned char **letter_prt) {
    if (**letter_prt == 0xD0) {
        if (*(++*letter_prt) == 0x81) {
            **letter_prt = 0xA8;
        } else {
            **letter_prt += 0x30;
        }
    } else if (**letter_prt == 0xD1) {
        if (*(++*letter_prt) == 0x91) {
            **letter_prt = 0xB8;
        } else {
            **letter_prt += 0x70;
        }
    }
}
