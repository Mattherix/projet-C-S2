#include <stdio.h>

typedef enum {FRONT, BACK, UP, DOWN, RIGHT, LEFT} T_SIDE;
typedef enum {R='R', B='B', G='G', W='W', Y='Y', O='O'} T_COLOR;

typedef struct Face{
    T_SIDE side;
    T_COLOR face[3][3];
} Face;

int main() {
    return 0;
}