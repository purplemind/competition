#include <stdio.h>

#define MAX_n 5000 //max #diff. coins
#define MAX_change 50000

//unlimited amount of each of coins

int main()
{
    int change, n, i, min, j;
    int coin[MAX_n];
    int c[MAX_change];

    scanf("%d", &change);
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &coin[i]);
    }

    for (i=0; i<=change; i++) c[i] = 0;

    for (j=0; j<=change; j++) {
        min = 50001;
        for (i=0; i<n; i++) {
            if ( j == coin[i] && (c[0] == 0 || c[0] == 50001) ) min = 1;
            if ( j > coin[i] && (c[j-coin[i]] + 1) < min ) min = c[j-coin[i]] + 1;
        }
        c[j] =  min;
    }
    for (i=0; i<=change; i++) printf("c[%d] = %d\n", i, c[i]);
    printf("Min #coins to get change is %d\n", c[change]);
    return 0;
}
