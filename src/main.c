#include <stdio.h>
#include "colors.h"

typedef enum {FRONT, BACK, UP, DOWN, RIGHT, LEFT} T_SIDE;
typedef enum {R='R', B='B', G='G', W='W', Y='Y', O='O', LG='#'} T_COLOR;
typedef enum {HALF=1, QUARTER=2} R_TYPE;

typedef struct Face{
    T_SIDE side;
    T_COLOR face[3][3];
} Face;

int main() {
    Face rubiks;
    rubiks.side = FRONT;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            rubiks.face[i][j] = R;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%s %c %s", orange, rubiks.face[i][j], none);
        }
        printf("\n");
    }


    return 0;
}