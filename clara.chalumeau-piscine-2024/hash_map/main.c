#include "hash_map.c"
#include "dump.c"
#include "hash.c"
#include <stdio.h>
int main(void)
{
    struct hash_map *h = hash_map_init(6);
    bool updated = NULL;
    hash_map_insert(h, "TOKYO", "japon", &updated);
    hash_map_insert(h, "PARIS", "FRANCE", &updated);
    hash_map_dump(h);
    hash_map_insert(h, "ROME", "Italie", &updated);
    hash_map_dump(h);
    printf("Bool %s\n", updated ? "true": "false");
    printf("\n");
    updated = NULL;
    hash_map_insert(h, "MADRID", "Espagne", &updated);
    hash_map_insert(h, "LONDRES", "RU", &updated);
    hash_map_insert(h, "BERLIN", "Allemagne", &updated);
    hash_map_insert(h, "NEWYORK", "Etat unis", &updated);
    hash_map_insert(h, "SEOUL", "Korea", &updated);
    hash_map_insert(h, "BUSAN", "Korea", &updated);
    hash_map_insert(h, "JEJU", "Korea", &updated);
    hash_map_insert(h, "PARIS", "France", &updated);
    hash_map_insert(h, "LYON", "France", &updated);
    hash_map_insert(h, "ELANCOURT", "France", &updated);
    hash_map_dump(h);
    printf("\n");
    hash_map_remove(h, "ELANCOURT");
    printf("Bool %s\n", updated ? "true": "false");
    printf("Get: %s\n", hash_map_get(h, "ELANCOURT"));
    printf("Get: %s\n", hash_map_get(h, "BUSAN"));
    hash_map_remove(h, "SKI");
    hash_map_remove(h, "Hello");
    hash_map_remove(h, "Hel");
    hash_map_free(h);
    return 0;
}

