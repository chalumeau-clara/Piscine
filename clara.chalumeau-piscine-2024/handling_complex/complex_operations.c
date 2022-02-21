#include "complex_operations.h"
struct complex neg_complex(struct complex a)
{
    struct complex c = { .real = -a.real, .img = -a.img };
    return c;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex c = { .real = a.real + b.real, .img = a.img + b.img };
    return c;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex c = { .real = a.real - b.real, .img = a.img - b.img };
    return c;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    float real = a.real * b.real - a.img * b.img;
    float img = a.real * b.img + a.img * b.real;
    struct complex c = { .real = real, .img = img };
    return c;
}

struct complex div_complex(struct complex a, struct complex b)
{
    float div = b.real * b.real + b.img * b.img;
    float real = (a.real * b.real + a.img * b.img) / div;
    float img = (a.img * b.real - a.real * b.img) / div;
    struct complex c = { .real = real, .img = img };
    return c;
}
