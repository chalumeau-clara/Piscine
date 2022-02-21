#include <stdio.h>
#include "lookup_table.c"

int main(void)
{
    unsigned char lut[256];
    for (int i = 0; i < 256; i++)
        lut[i] = 255 - i;

    unsigned char mat[4][4] = {{ 0, 1, 2, 3},
                  { 121, 122, 123, 124},
                  {125, 126, 127, 128},
                  {252, 253, 254, 255}};
    apply_lut(mat, lut);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
