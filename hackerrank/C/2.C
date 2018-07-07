#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

int main(int agrc, char *argv[])
{
    int a, b;
    float c, d;
    scanf("%d%d%f%f", &a, &b, &c, &d);
    printf("%d %d\n%0.1f %0.1f", a+b, a-b, c+d, c-d);
    return 0;
}
