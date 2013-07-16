#include <stdio.h>

#define MAX_n 5000
#define MAX_capacity 100

int max(int a, int b) {
    if ( a >= b ) return a;
    return b;
}

int main()
{
    int n, i, capacity, c;
    struct predmet{
        int weight;
        int value;
    };
    struct predmet item[MAX_n];
    int v[MAX_capacity][MAX_n];

    scanf("%d", &capacity);
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        printf("item[%d].weight = ", i);
        scanf("%d", &item[i].weight);
        printf("item[%d].value = ", i);
        scanf("%d", &item[i].value);
        v[0][i] = 0;
    }
    for(c=0; c<=capacity; c++) {
        for (i=0; i<n; i++) {
            if ( item[i].weight <= c) {
                v[c][i] = max( v[c][i-1], v[c-item[i].weight][i-1] + item[i].value );
            }
            else v[c][i] = v[c-1][i];
        }
    }
    printf("Max value for knapsack of capacity %d is %d", capacity, v[capacity][n-1]);
    return 0;
}
