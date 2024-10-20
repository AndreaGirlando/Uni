#include <stdio.h>
main() /* in C */
{
    int k, i, j;
    float y, s;
    do
    {
        scanf(“% d”, &k);
        if (k <= 0)
            printf(“Errore nell’immissione di k”);
    } while (k <= 0)
        y = 0;
    i = 1;
    while (i <= k)
    {
        s = 0;
        j = 1;
        while (j <= i)
        {
            s = s + 1 / (i + j);
            j = j + 1;
        }
        s = s * s;
        y = y + s;
        i = i + 1;
    }
    printf(“% d”, y)
}
