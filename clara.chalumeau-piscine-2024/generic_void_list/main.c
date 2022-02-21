#include <stddef.h>
#include <stdio.h>

#include "list.c"
int main(void)
{
    struct list *l = NULL;
    // int e = 34;
    char *es = "34";
    char *ess = "34";
    char *esss = "42";
    char *e = "42";
    char *ea = "42";
    char *eb = "42";
    char *ec = "42";
    char *ed = "42";
    char *ee = "42";
    char *ef = "42";
    // l = list_prepend(l, &e, sizeof(&e));
    l = list_prepend(l, es, 2);
    l = list_prepend(l, ess, 2);
    l = list_prepend(l, esss, 2);
    l = list_prepend(l, e, 2);
    l = list_prepend(l, ea, 2);
    l = list_prepend(l, eb, 2);
    l = list_prepend(l, ec, 2);
    l = list_prepend(l, ed, 2);
    l = list_prepend(l, ee, 2);
    l = list_prepend(l, ef, 2);
    printf("%ld\n", list_length(l));
    for (size_t i = 0; i < list_length(l); i++)
    {
        unsigned char *d = l->data;
        printf("%s,", d);
    }
    list_destroy(l);
}
