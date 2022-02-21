#include "append_file.c"

int main(void)
{
    append_file("test.", "BDE");
    append_file("test.", "BDA");
    append_file("test.", "BDY");
    return 0;
}
