#include <stdio.h>

struct pair
{
    int x;
    int y;
};

struct pair three_pairs_sum(const struct pair pair_1, const struct pair pair_2,
const struct pair pair_3)
{
    struct pair result = { .x = pair_1.x + pair_2.x + pair_3.x, 
        .y =  pair_1.y + pair_2.y + pair_3.y};
    return result;
}

struct pair pairs_sum(const struct pair pairs[], size_t size)
{
    struct pair result = { .x = 0, .y = 0};
    for (size_t i = 0; i < size; i++)
    {
        result.x += pairs[i].x;
        result.y += pairs[i].y;
    }
    return result;
}

int main(void)
{
    struct pair p1 = { .x = 4, .y = 5};
    struct pair p2 = { .x = 5, .y = 6};
    struct pair p3 = { .x = 6, .y = 7};
    struct pair p4 = three_pairs_sum( p1, p2, p3);
    struct pair pairs[] = { p1, p2, p3, p4};
    struct pair p5 = pairs_sum(pairs, 4);
    printf("X = %d, Y = %d\n", p5.x, p5.y);
}
