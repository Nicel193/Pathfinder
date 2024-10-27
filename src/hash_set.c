#include "../inc/pathfinder.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 1024
#define LOAD_FACTOR 0.75


size_t hash_function(const char *str, size_t capacity) {
    size_t hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % capacity;
}

void hash_set_init(hash_set *set) {
    set->capacity = INITIAL_CAPACITY;
    set->size = 0;
    set->entries = calloc(set->capacity, sizeof(hash_set_entry));
}

bool hash_set_contains(hash_set *set, const char *key) {
    size_t index = hash_function(key, set->capacity);
    size_t original_index = index;
    while (set->entries[index].is_occupied) {
        if (strcmp(set->entries[index].key, key) == 0) {
            return true;
        }
        index = (index + 1) % set->capacity;
        if (index == original_index) break;
    }
    return false;
}

void hash_set_resize(hash_set *set) {
    size_t new_capacity = set->capacity * 2;
    hash_set_entry *new_entries = calloc(new_capacity, sizeof(hash_set_entry));

    for (size_t i = 0; i < set->capacity; i++) {
        if (set->entries[i].is_occupied) {
            size_t index = hash_function(set->entries[i].key, new_capacity);
            while (new_entries[index].is_occupied) {
                index = (index + 1) % new_capacity;
            }
            new_entries[index].key = set->entries[i].key;
            new_entries[index].is_occupied = true;
        }
    }
    free(set->entries);
    set->entries = new_entries;
    set->capacity = new_capacity;
}

void hash_set_add(hash_set *set, const char *key) {
    if ((float)set->size / set->capacity > LOAD_FACTOR) {
        hash_set_resize(set);
    }
    size_t index = hash_function(key, set->capacity);
    while (set->entries[index].is_occupied) {
        if (strcmp(set->entries[index].key, key) == 0) {
            return;
        }
        index = (index + 1) % set->capacity;
    }

    set->entries[index].key = malloc(strlen(key) + 1);
    strcpy(set->entries[index].key, key);
    set->entries[index].is_occupied = true;
    set->size++;
}

void hash_set_delete(hash_set *set) {
    for (size_t i = 0; i < set->capacity; i++) {
        if (set->entries[i].is_occupied) {
            free(set->entries[i].key);
        }
    }
    free(set->entries);
    set->entries = NULL;
    set->capacity = 0;
    set->size = 0;
}
