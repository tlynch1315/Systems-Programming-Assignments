/* node.c */

#include "node.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Create node. 
 *
 * This allocates and configures a node that the user must later deallocate.
 * @param   string      String value.
 * @param   next        Reference to next node.
 * @return  Allocated node structure.
 */
struct node *	node_create(char *string, struct node *next) {
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode){
        char *strcpy = strdup(string);
        newNode->string = strcpy;
        newNode->number = atoi(string);
        newNode->next = next;
    }
    else{
        return NULL;
    }
    return newNode;
}

/**
 * Delete node.
 *
 * This deallocates the given node (recursively if specified).
 * @param   n           Node to deallocate.
 * @param   recursive   Whether or not to deallocate recursively.
 * @return  NULL pointer.
 */
struct node *   node_delete(struct node *n, bool recursive) {
    struct node * help;
    if(!recursive){
        free(n->string);
        free(n);
    }
    else{
        while(n != NULL){
            help = n->next;
            free(n->string);
            free(n);
            n = help;
        }
    }
    return NULL;
}

/**
 * Dump node to stream.
 * 
 * This dumps out the node structure (Node{string, number, next}) to the stream.
 * @param   n       Node structure.
 * @param   stream  File stream.
 **/
void            node_dump(struct node *n, FILE *stream) {
//fprintf(stream, "");
    fprintf(stream, "Node{%s, %i, %p}\n", n->string, n->number, n->next);
}

/**
 * Compare node structures by number
 *
 * This compares two node structures by their number values.
 * @param   a       First node structure.
 * @param   b       Second node structure.
 * @return  < 0 if a < b, 0 if a == 0, > 0 if a > b
 */
int		node_compare_number(const void *a, const void *b) {
    struct node *ptrA = *((struct node **)a);
    struct node *ptrB = *((struct node **)b);
    if(ptrA->number < ptrB->number)
        return -1;
    else if(ptrA->number > ptrB->number)
        return 1;
    else
        return 0;
}

/**
 * Compare node structures by string
 *
 * This compares two node structures by their string values.
 * @param   a       First node structure.
 * @param   b       Second node structure.
 * @return  < 0 if a < b, 0 if a == 0, > 0 if a > b
 */
int		node_compare_string(const void *a, const void *b) {
    struct node **ptrA = (struct node **)a;
    struct node **ptrB = (struct node **)b;
    char *a1 = (*ptrA)->string;
    char *b1 = (*ptrB)->string;
    int ret;
    ret = strcmp(a1,b1);
    return ret;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
