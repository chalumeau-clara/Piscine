#include <assert.h>
#include "bsearch.c"

int main(void)
{
    int a[] =
    {
        0, 1, 4, 5, 9, 10, 18, 22, 42, 51, 69
    };
    assert(binary_search(a, a + 11, 6) == a + 4);
    assert(binary_search(a, a + 11, 0) == a);
    assert(binary_search(a, a + 11, -1) == a);
    assert(binary_search(a, a + 11, 99) == a + 11);
    assert(binary_search(a, a + 11, 68) == a + 10);
    assert(binary_search(a, a, 5) == a);
}
