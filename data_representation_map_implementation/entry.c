/* entry.c: map entry */

#include "map.h"
#include<string.h>
/**
 * Create entry structure.
 * @param   key             Entry's key.
 * @param   value           Entry's value.
 * @param   next            Reference to next entry.
 * @param   type            Entry's value's type.
 * @return  Allocate Entry structure.
 */
Entry *		entry_create(const char *key, const Value value, Entry *next, Type type) {

    Entry * e = calloc(1, sizeof(Entry));
    if(e){
        e->key = strdup(key);
        if(type == STRING) e->value.string = strdup(value.string);
        else e->value.number = value.number;
        e->next = next;
        e->type = type;
    }
    else{
        return NULL;
    }
    return e;
}

/**
 * Delete entry structure.
 * @param   e               Entry structure.
 * @param   recursive       Whether or not to delete remainder of entries.
 * return   NULL.
 */
Entry *		entry_delete(Entry *e, bool recursive) {
    struct Entry  * help;
    if(!recursive){
        if(e->type == STRING) free(e->value.string);
        free(e->key);
        free(e);
    }
    else{
        while(e != NULL){
            help = e->next;
            if(e->type == STRING) free(e->value.string);
            free(e->key);
            free(e);
            e = help;
        }
    }
    return NULL;
}

/**
 * Update entry's value.
 * @param   e               Entry structure.
 * @param   value           New value for entry.
 * @param   type            New value's type.
 */
void            entry_update(Entry *e, const Value value, Type type) {
    if(e->type  == STRING) free(e->value.string);
    if(type == STRING) e->value.string = strdup(value.string);
    else e->value.number = value.number;
    e->type = type;
}

/**
 * Dump entry.
 * @param   e               Entry structure.
 * @param   stream          File stream to write to.
 * @param   mode            Dump mode to use.
 */
void            entry_dump(Entry *e, FILE *stream, const DumpMode mode) {
    if(mode == KEY){
        fprintf(stream, "%s\n", e->key);
    }
    else if(mode == KEY_VALUE){
        if(e->type == STRING){
            fprintf(stream, "%s\t%s\n",e->key, e->value.string);
        }
        else{
            fprintf(stream, "%s\t%ld\n",e->key, e->value.number);
        }
    }
    else if(mode == VALUE){
        if(e->type == STRING){
            fprintf(stream, "%s\n", e->value.string);
        }
        else{
            fprintf(stream, "%ld\n", e->value.number);
        }
    }
    else if(mode == VALUE_KEY){
        if(e->type == STRING){
            fprintf(stream, "%s\t%s\n", e->value.string, e->key);
        }
        else{
            fprintf(stream, "%ld\t%s\n", e->value.number, e->key);
        }
    }
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
