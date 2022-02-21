#include <stdio.h>

#include "hash_map.h"

void hash_map_dump(struct hash_map *hash_map)
{
    for (size_t i = 0; i < hash_map->size; i++)
    {
        struct pair_list *temp = hash_map->data[i];
        if (temp)
        {
            while (temp->next)
            {
                printf("%s: %s, ", temp->key, temp->value);
                temp = temp->next;
            }
            if (temp)
                printf("%s: %s\n", temp->key, temp->value);
        }
    }
}
