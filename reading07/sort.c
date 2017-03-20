/* sort.c */

#include <stdio.h>
#include <stdlib.h>

//* Constants */

#define MAX_NUMBERS (1<<10)

//* Functions */

size_t read_numbers(FILE *stream, int numbers[], size_t n) {
    size_t i = 0;

    while (i < n && scanf("%d", &numbers[i]) != EOF) {
        i++;
    }

    return i;
}

void sort_numbers(int numbers[], size_t n) {
    int key;
    int j;
    for (size_t i = 1; i < n; i++) {
        key = numbers[i];
        j = i-1;
        while (j >= 0 && numbers[j] > key){
            numbers[j+1] = numbers[j];
            j = j-1;
        }
        numbers[j+1] = key;
    }
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int numbers[MAX_NUMBERS];
    size_t nsize;

    nsize = read_numbers(stdin, numbers, MAX_NUMBERS);
    if(nsize != 0){ 
        sort_numbers(numbers, nsize);
        for(int i = 0; i < nsize-1; i++){
            printf("%d ", numbers[i]);
        }
        printf("%d", numbers[nsize-1]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
