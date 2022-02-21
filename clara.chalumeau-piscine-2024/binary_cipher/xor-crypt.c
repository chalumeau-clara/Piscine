#include <stddef.h>
void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    for (size_t i = 0; i < data_len; i++)
    {
        data[i] = data[i] ^ key[i % key_len];
    }
}
