#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *d;
    float *f;
    void *v;

    int x = 2918;
    float y = 2918;
    d = &x;
    v = &x;
    f = &x;
    v = &y;

    printf("%u\n", v);
    v++;
    printf("%u\n", v);
    return 0;
}
