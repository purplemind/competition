#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long i, j, poc;
    long start, end;
    int cases;
    char arr[100000];

    scanf("%d", &cases);
    while ( cases > 0 ) {
    scanf("%ld %ld", &start, &end);
    for (i=0; i<=(end-start); i++) arr[i] = 1;
    if ( start == 1 ) arr[0] = 0;
    for (i=2; i<=(long)sqrt(end); i++) {
        if ( start < 2*i ) poc = 2;
        else poc = start/i;
        for (j=poc; j<=(long)end/i; j++)
            if ( i*j >= start ) arr[i*j-start] = 0;
    }
    for (i=0; i<=(end-start); i++)
        if ( arr[i] == 1 ) printf("%ld\n", i+start);
    printf("\n");
    cases--;
    }
    return 0;
}
