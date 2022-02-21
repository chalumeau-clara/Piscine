#include <stdio.h>

void grade(char g)
{
    switch (g)
    {
    case 'A':
        puts("Excellent\n");
        break;
    case 'B':
        puts("Good\n");
        break;
    case 'C':
        puts("Not so bad\n");
        break;
    case 'D':
        puts("Could be worse\n");
        break;
    case 'E':
        puts("Maybe next time\n");
        break;
    case 'F':
        puts("No comment\n");
        break;
    default:
        puts("Call a wild ACU\n");
        break;
    }
}
