/* duplicates.c */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NITEMS = 1<<10;
const int TRIALS = 100;

bool contains(int *a, int n, int k) {
    /* TODO: Search through array to see if there is an element that matches key */
    for (int i = 0; i < n; i++){
        puts("entered contains");
        if(a[i] == k){
            return true;
        }
    }
    return false;
}

bool duplicates(int n) {
    int *randoms = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    	randoms[i] = rand() % 1000;

    for (int i = 0; i < n; i++) {
        /* TODO: Use contains to search array for duplicate */ 
    	if (contains(randoms, n, i)) {
    	    free(randoms);
            return true;
        }
    }

    free(randoms);
    return false;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    for (int i = 0; i < TRIALS; i++)
    	if (duplicates(NITEMS))
	    puts("Duplicates detected!");

    return 0;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
