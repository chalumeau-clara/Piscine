#include "hash_map.h"

#include <stdbool.h>
#include <stdlib.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *has = (struct hash_map *)malloc(sizeof(struct hash_map));
    if (has == NULL)
        return NULL;
    has->size = size;
    has->data = (struct pair_list **)malloc(sizeof(struct pair_list *) * size);
    for (size_t i = 0; i < size; i++)
        has->data[i] = NULL;
    return has;
}
bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (hash_map == NULL || hash_map->size == 0)
        return false;
    // get pos
    size_t pos = hash(key) % hash_map->size;

    // get pair list
    struct pair_list *list = hash_map->data[pos];

    // create new node
    struct pair_list *temp = list;
    while (temp)
    {
        if (temp->key == key)
        {
            temp->value = value;
            *updated = true;
            return true;
        }
        temp = temp->next;
    }
    struct pair_list *new =
        (struct pair_list *)malloc(sizeof(struct pair_list));
    if (new == NULL)
        return false;
    new->key = key;
    new->value = value;
    new->next = list;
    hash_map->data[pos] = new;
    *updated = false;
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map == NULL)
        return;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *temp = hash_map->data[i];
        while (temp)
        {
            struct pair_list *tmp = temp;
            temp = temp->next;
            free(tmp);
        }
    }
    free(hash_map->data);
    free(hash_map);
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL || hash_map->size == 0)
        return NULL;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *temp = hash_map->data[i];
        while (temp)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
    }
    return NULL;
}

struct pair_list *list_remove(struct pair_list *l, const char *e, bool *value)
{
    if (l == NULL)
    {
        *value = false;
        return NULL;
    }
    struct pair_list *temp = l;
    if (l && l->key == e)
    {
        l = l->next;
        free(temp);
        *value = true;
        return l;
    }
    if (l->next == NULL && l->key != e)
    {
        *value = false;
        return l;
    }
    while (temp->next && temp->next->key != e)
        temp = temp->next;
    if (temp->next && temp->next->key != e)
    {
        *value = false;
        return l;
    }
    struct pair_list *temp2 = temp->next;
    if (temp->next)
        temp->next = temp->next->next;
    free(temp2);
    *value = true;
    return l;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL || hash_map->size == 0)
        return false;
    // get pos
    size_t pos = hash(key) % hash_map->size;
    // get pair list
    struct pair_list *list = hash_map->data[pos];
    bool value = false;
    hash_map->data[pos] = list_remove(list, key, &value);
    return value;
}
