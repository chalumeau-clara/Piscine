#include <stddef.h>
int nbbit(int x)
{
    int nb = 0;
    while(x > 0)
    {
        nb++;
        x >>= 1;
    }

return nb;
}

unsigned char rol(unsigned char value, unsigned char roll)
{
    return (value << roll) |(value >> ((nbbit(value)) - roll));
}

void my_rol_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    for (size_t i = 0; i < data_len; i++)
    {
        data[i] = rol(data[i], key[i % key_len]);
    }
}
