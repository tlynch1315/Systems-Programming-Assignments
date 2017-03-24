/* translate.c: string translator */

#include "stringutils.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */
char *PROGRAM_NAME = NULL;
enum {
    STRIP = 1<<1,
    REVERSE = 1<<2,
    REVERSEWORDS = 1<<3,
    LOWERCASE = 1<<4,
    UPPERCASE = 1<<5
};

/* Functions */
void usage(int status) {
    fprintf(stderr, "Usage: %s SOURCE TARGET\n\n", PROGRAM_NAME);
    fprintf(stderr, "Post Translation filters:\n\n");
    fprintf(stderr, "   -s     Strip whitespace\n");
    fprintf(stderr, "   -r     Reverse line\n");
    fprintf(stderr, "   -w     Reverse words in line\n");
    fprintf(stderr, "   -l     Convert to lowercase\n");
    fprintf(stderr, "   -u     Convert to uppercase\n");
    exit(status);
}

void translate_stream(FILE *stream, char *source, char *target, int mode){
/* TODO */
    char buffer[BUFSIZ];
    while (fgets(buffer,BUFSIZ,stream)){
        char * buff = buffer;
        string_chomp(buff);
        string_translate(buff, source, target);
        if (mode & STRIP) {
            string_strip(buff);
        }
        if (mode & REVERSE) {
            string_reverse(buff);
        }
        if(mode & REVERSEWORDS){
            string_reverse_words(buff);
        }
        if(mode & LOWERCASE){
            string_lowercase(buff);
        }
        if(mode & UPPERCASE){
            string_uppercase(buff);
        }
    }
    fputs(buffer, stdout);
    printf("\n");
}


/* Main Execution */

int main(int argc, char *argv[]) {
    int argind = 1;
    int mode = 0;
    char *source = "";
    char *target = "";

    /* Parse command line arguments */
    PROGRAM_NAME = argv[0];
    while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
        char *arg = argv[argind++];
        switch (arg[1]) {
            case 'h':
                usage(0);
                break;
            case 's':
                mode |= STRIP;
                break;
            case 'r':
                mode |= REVERSE;
                break;
            case 'w':
                mode |= REVERSEWORDS;
                break;
            case 'l':
                mode |= LOWERCASE;
                break;
            case 'u':
                mode |= UPPERCASE;
                break;
            default:
                usage(1);
                break;
        }
    }
    if ((argc - argind)>=2){
        source = argv[argind++];
    }
    if ((argc - argind)>=1){
        target = argv[argind++];
    }                                                                   
    /* Translate Stream */
    translate_stream(stdin,source ,target , mode);

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
