/* map.c: separate chaining hash table */

#include "map.h"
/**
 * Create map data structure.
 * @param   capacity        Number of buckets in the hash table.
 * @param   load_factor     Maximum load factor before resizing.
 * @return  Allocated Map structure.
 */
Map *	        map_create(size_t capacity, double load_factor) {
    Map * newMap = calloc(1, sizeof(Map));
    if(newMap == NULL) return NULL;     // check if allocation failed
    if(capacity == 0) newMap->capacity = DEFAULT_CAPACITY;
    else newMap->capacity = capacity;
    if(load_factor <= 0) newMap->load_factor = DEFAULT_LOAD_FACTOR;
    else newMap->load_factor = load_factor;
    newMap->size = 0;
    Entry * buckets = calloc(newMap->capacity, sizeof(Entry));
    newMap->buckets = buckets;
    return newMap;
}

/**
 * Delete map data structure.
 * @param   m               Map data structure.
 * @return  NULL.
 */
Map *	        map_delete(Map *m) {
    uint64_t counter = 0;
    while(counter+1 <= m->capacity){
        entry_delete(m->buckets[counter].next, true);
        counter++;
    }
    free(m->buckets);
    free(m);
    return NULL;
}

/**
 * Insert or update entry into map data structure.
 * @param   m               Map data structure.
 * @param   key             Entry's key.
 * @param   value           Entry's value.
 * @param   type            Entry's value's type.
 */
void            map_insert(Map *m, const char *key, const Value value, Type type) {

    bool newEntry = true;
    double loadChecker = m->size/(double)m->capacity;

    if(loadChecker > m->load_factor) map_resize(m, 2*(m->capacity));

    uint64_t bucket = fnv_hash(key, strlen(key));
    bucket = bucket % m->capacity;
    Entry * enter = m->buckets[bucket].next;
    while(enter != NULL){
        if(strcmp(enter->key, key) == 0){
            entry_update(enter, value, type);
            newEntry = false;
            break;
        }
        enter = enter->next;
    }
    if(newEntry){
        m->size++;
        m->buckets[bucket].next = entry_create(key, value, m->buckets[bucket].next, type);
    }
}


/**
 * Search map data structure by key.
 * @param   m               Map data structure.
 * @param   key             Key of the entry to search for.
 * @param   Pointer to the entry with the specified key (or NULL if not found).
 */
Entry *         map_search(Map *m, const char *key) {
    uint64_t bucket = fnv_hash(key, strlen(key));
    bucket = bucket % m->capacity;
    Entry * enter = m->buckets[bucket].next;
    while(enter != NULL){
        if(strcmp(enter->key, key) == 0) return enter;
        enter = enter->next;
    }
    return NULL;
}

/**
 * Remove entry from map data structure with specified key.
 * @param   m               Map data structure.
 * @param   key             Key of the entry to remove.
 * return   Whether or not the removal was successful.
 */
bool            map_remove(Map *m, const char *key) {
    Entry * result = map_search(m, key);
    if(result == NULL)return false;
    
    uint64_t bucket = fnv_hash(key, strlen(key));
    bucket = bucket % m->capacity;
    Entry * curr = m->buckets[bucket].next;
    Entry * prev = &m->buckets[bucket];
    while(curr != NULL){
        if(strcmp(curr->key, key) == 0){
            prev->next = curr->next;
            entry_delete(curr, false);
            m->size--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

/**
 * Dump all the entries in the map data structure.
 * @param   m               Map data structure.
 * @param   stream          File stream to write to.
 * @param   mode            Dump mode to use.
 */
void		map_dump(Map *m, FILE *stream, const DumpMode mode) {
    uint64_t counter = 0;
    Entry * help = NULL;
    while(counter+1 <= m->capacity){
        help = m->buckets[counter].next;
        while(help != NULL){
            entry_dump(help, stream, mode);
            help = help->next;
        }
        counter++;
    }
}

/**
 * Resize the map data structure.
 * @param   m               Map data structure.
 * @param   new_capacity    New capacity for the map data structure.
 */
void            map_resize(Map *m, size_t new_capacity) {
    Entry * newEntry = calloc(new_capacity, sizeof(Entry));
    uint64_t counter = 0;
    uint64_t bucket;
    Entry * help;
    Entry * next;
    while(counter+1 <= m->capacity){
        help = m->buckets[counter].next;
        while(help != NULL){
            bucket = fnv_hash(help->key, strlen(help->key));
            bucket = bucket % new_capacity;
            next = help->next;
            help->next = newEntry[bucket].next;
            newEntry[bucket].next = help;
            help = next;
        }
        counter++;
    }
    free(m->buckets);
    m->buckets = newEntry;
    m->capacity = new_capacity;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
