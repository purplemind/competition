#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_CUBES 500
#define MAX_COLORS 100

int main() {
    int n, i, max_cubes, rb_tower, max_cubes_idx;

    struct type_cube {
        int front, back, left, right, top, bottom;
    };
    struct type_cube cubes[MAX_CUBES];

    int color_up[MAX_COLORS], copy_color[MAX_COLORS];

    char string[MAX_COLORS][1000];
    char copy_string[MAX_COLORS][10000];

    n = 0;
    rb_tower = 0;
    do {
        /*init color array:*/
        for (i=0; i<MAX_COLORS; i++) {
            color_up[i] = 0;
            strcpy(string[i], "");
        }
        scanf("%d", &n);
        max_cubes = 0;
        max_cubes_idx = 0;
        for (i=0; i<n; i++) {
            /*front, back, left, right, top and bottom i-th cube face color*/
            scanf("%d", &cubes[i].front);
            scanf("%d", &cubes[i].back);
            scanf("%d", &cubes[i].left);
            scanf("%d", &cubes[i].right);
            scanf("%d", &cubes[i].top);
            scanf("%d", &cubes[i].bottom);
            /*set copy colors ( up cube face colors state before i-th cube)*/
            copy_color[cubes[i].front] = color_up[cubes[i].front];
            copy_color[cubes[i].back] = color_up[cubes[i].back];
            copy_color[cubes[i].left] = color_up[cubes[i].left];
            copy_color[cubes[i].right] = color_up[cubes[i].right];
            copy_color[cubes[i].top] = color_up[cubes[i].top];
            copy_color[cubes[i].bottom] = color_up[cubes[i].bottom];
            strcpy(copy_string[cubes[i].front], string[cubes[i].front]);
            strcpy(copy_string[cubes[i].back], string[cubes[i].back]);
            strcpy(copy_string[cubes[i].left], string[cubes[i].left]);
            strcpy(copy_string[cubes[i].right], string[cubes[i].right]);
            strcpy(copy_string[cubes[i].top], string[cubes[i].top]);
            strcpy(copy_string[cubes[i].bottom], string[cubes[i].bottom]);
            /*front*/
            if ( copy_color[cubes[i].front] < color_up[cubes[i].back] + 1 ) {
                copy_color[cubes[i].front] = color_up[cubes[i].back] + 1;
                sprintf(string[cubes[i].front], "%s %d %s\n", copy_string[cubes[i].back], i+1, "front");
            }
            /*back*/
            if ( copy_color[cubes[i].back] < color_up[cubes[i].front] + 1 ) {
                copy_color[cubes[i].back] = color_up[cubes[i].front] + 1;
                sprintf(string[cubes[i].back], "%s %d %s\n", copy_string[cubes[i].front], i+1, "back");
            }
            /*left*/
            if ( copy_color[cubes[i].left] < color_up[cubes[i].right] + 1 ) {
                copy_color[cubes[i].left] = color_up[cubes[i].right] + 1;
                sprintf(string[cubes[i].left], "%s %d %s\n", copy_string[cubes[i].right], i+1, "left");
            }
            /*right*/
            if ( copy_color[cubes[i].right] < color_up[cubes[i].left] + 1 ) {
                copy_color[cubes[i].right] = color_up[cubes[i].left] + 1;
                sprintf(string[cubes[i].right], "%s %d %s\n", copy_string[cubes[i].left], i+1, "right");
            }
            /*top*/
            if ( copy_color[cubes[i].top] < color_up[cubes[i].bottom] + 1 ) {
                copy_color[cubes[i].top] = color_up[cubes[i].bottom] + 1;
                sprintf(string[cubes[i].top], "%s %d %s\n", copy_string[cubes[i].bottom], i+1, "top");
            }
            /*bottom*/
            if ( copy_color[cubes[i].bottom] < color_up[cubes[i].top] + 1 ) {
                copy_color[cubes[i].bottom] = color_up[cubes[i].top] + 1;
                sprintf(string[cubes[i].bottom], "%s %d %s\n", copy_string[cubes[i].top], i+1, "top");
            }

            /*restore*/
            color_up[cubes[i].front] = copy_color[cubes[i].front];
            color_up[cubes[i].back] = copy_color[cubes[i].back];
            color_up[cubes[i].left] = copy_color[cubes[i].left];
            color_up[cubes[i].right] = copy_color[cubes[i].right];
            color_up[cubes[i].top] = copy_color[cubes[i].top];
            color_up[cubes[i].bottom] = copy_color[cubes[i].bottom];
        }
        if ( n > 0 ) {
            rb_tower++;
            printf("Case #%d\n", rb_tower);
            for (i=0; i<MAX_COLORS; i++)
                if ( max_cubes < color_up[i] ) {
                    max_cubes = color_up[i];
                    max_cubes_idx = i;
                }
            printf("%d\n", max_cubes);
            printf("%s", string[max_cubes_idx]);
        }
    } while ( n > 0 );
    return 0;
}
