#include "vigenere.h"

#include <stddef.h>
size_t my_strlen(const char *s)
{
    if (!s)
        return 0;

    size_t len = 0;
    while (*s != '\0')
    {
        s++;
        len += 1;
    }
    return len;
}

void cipher(const char *key, const char *msg, char *res)
{
    if (key != NULL && msg != NULL)
    {
        int key_size = my_strlen(key);
        int key_index = 0;

        int msg_size = my_strlen(msg);
        char mg, ky;
        int i;

        for (i = 0; i < msg_size; i++)
        {
            mg = msg[i];
            ky = key[key_index];
            if (msg[i] >= 'a' && msg[i] <= 'z')
                mg = msg[i] - 32;
    
            if (key[key_index] >= 'a' && key[key_index] <= 'z')
                ky = key[key_index] - 32;
            
            if (mg >= 'A' && mg <= 'Z')
            {
                while (ky < 'A' || ky > 'Z')
                {
                    key_index = (key_index + 1) % key_size;
                    if (key[key_index] >= 'a' && key[key_index] <= 'z')
                        ky = 'a' - 'A' + key[key_index];
                }
            
                res[i] = (mg + ky) % 26 + 'A';
                key_index = (key_index + 1) % key_size;
            }
            else
                res[i] = msg[i];
        }
    res[i] = '\0';
    }
}


void decipher(const char *key, const char *msg, char *res)
{

        int key_size = my_strlen(key);
        int msg_size = my_strlen(msg);
        int k = 0;
        int i;
        for (i = 0; i < msg_size; i++)
        {

            if (msg[i] >= 'A' && msg[i] <= 'Z')
            {
                char j = msg[i] - key[k];
                while (j < 0)
                    j += 26;
                res[i] = j % 26 + 'A';
                k = (k + 1) % key_size;
            }
            else
                res[i] = msg[i];
        }
        res[i] = '\0';
}
