#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"
size_t hash(const char *key)
{
    size_t i = 0;
    size_t hash = 0;

    for (i = 0; key[i] != '\0'; ++i)
        hash += key[i];
    hash += i;

    return hash;
}

struct hash_map *hash_map_init(size_t size)
{
    struct pair_list *pair = malloc(sizeof(struct pair_list));
    struct hash_map *hashm = malloc (sizeof(struct hash_map));
    pair->key = NULL;
    pair->value = NULL;
    pair->next = NULL;
    hashm->size = size;
    hashm->data = &pair;
    return hashm;
}

void hash_map_free(struct hash_map *hash_map)
{
     while (hash_map->data != NULL)
    {
        temp = hash_map->data->next;
        free(hash_map->data);
        hash_map = temp;
    }
}



