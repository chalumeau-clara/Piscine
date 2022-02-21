#include <stdlib.h>
#include <stdio.h>
#include "freq_analysis.c"

int main( int argc, char *argv[])
{
    if (argc<1)
        return 1;
    freq_analysis(argv[1], argv[2]);
    return 0;
}
