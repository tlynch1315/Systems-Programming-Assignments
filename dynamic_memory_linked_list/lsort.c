/* lsort.c */

#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Globals */

char * PROGRAM_NAME = NULL;

/* Functions */

void usage(int status) {
    fprintf(stderr, "Usage: %s\n", PROGRAM_NAME);
    fprintf(stderr, "  -n   Numerical sort\n");
    fprintf(stderr, "  -q   Quick sort\n");
    exit(status);
}

void lsort(FILE *stream, bool numeric, bool quicksort) {
    char buffer[BUFSIZ];
    struct list * List = list_create();
    while(fgets(buffer,BUFSIZ,stream)){
        list_push_back(List, buffer);
    }
    if(numeric){
        if(quicksort)
            list_qsort(List, node_compare_number);
        else
            list_msort(List, node_compare_number);
    }
    else{
        if(quicksort)
            list_qsort(List, node_compare_string);
        else
            list_msort(List, node_compare_string);
    }
    for(struct node *it = List->head; it; it = it->next)
        printf("%s", it->string);
    list_delete(List);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    /* Parse command line arguments */
    int argind = 1;
    bool numeric = false;
    bool quicksort = false;
    
    PROGRAM_NAME = argv[0];
    while(argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-'){
        char *arg = argv[argind++];
        switch(arg[1]){
            case 'h':
                usage(0);
                break;
            case 'n':
                numeric = true;
                break;
            case 'q':
                quicksort = true;
                break;
            default:
                usage(1);
                break;
        }
    }

                

    /* Sort using list */
    lsort(stdin, numeric, quicksort);

    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
