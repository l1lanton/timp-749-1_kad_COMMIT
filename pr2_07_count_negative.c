#include <stdio.h>

int main()
{
    int n;

    int count = 0;
    int x;
    int i;

    (void)scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        (void)scanf("%d", &x);
        if (x < 0) {
            ++count;
        }
    }

    printf("%d", count);
    return 0;
}

