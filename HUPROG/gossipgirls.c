#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    long int x, y;
} point;

#define dist(p1, p2) (abs(p1.x - p2.x) + abs(p1.y - p2.y))

#define max(x, y) (((x) > (y)) ? (x) : (y))

int main()
{
    long int i, j, n, x, maxDist = 0;
    scanf("%lu", &n);

    point posXposY, posXnegY, negXposY, negXnegY, newp;

    newp.x = 310; newp.y = 440;

    posXposY = posXnegY = negXposY = negXnegY = newp;

    char ad[200];

    for (i = 1; i <= n; i++)
    {
        newp.x = newp.y = 0;

        scanf("%s", ad);
        for (j = 0; j < strlen(ad); j++)
            newp.x += ad[j];

        scanf("%s", ad);    // aslinda soyad
        for (j = 0; j < strlen(ad); j++)
            newp.y += ad[j];

        maxDist = max(maxDist, dist(newp, posXposY));
        maxDist = max(maxDist, dist(newp, posXnegY));
        maxDist = max(maxDist, dist(newp, negXposY));
        maxDist = max(maxDist, dist(newp, negXnegY));

        printf("%lu\n", maxDist);

        if (newp.x + newp.y > posXposY.x + posXposY.y)
            posXposY = newp;


        if (newp.x - newp.y > posXnegY.x - posXnegY.y)
            posXnegY = newp;

        if (-newp.x + newp.y > -negXposY.x + negXposY.y)
            negXposY = newp;

        if (-newp.x - newp.y > -negXnegY.x - negXnegY.y)
            negXnegY = newp;
/*
        printf("++ %ld %ld\n", posXposY.x, posXposY.y);
        printf("+- %ld %ld\n", posXnegY.x, posXnegY.y);
        printf("-+ %ld %ld\n", negXposY.x, negXposY.y);
        printf("-- %ld %ld\n", negXnegY.x, negXnegY.y);
*/
    }

    return 0;
}
