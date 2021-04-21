#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double sum = 0;
    double a;
    double b;
    int x;
    int i;

    (void)scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        (void)scanf("%d", &x);

        a = pow((double)-1, (double)(i));
        b = pow((double)x, (double)2);

        sum += (a * b);
    }

    printf("%lf", sum);

    return 0;
}