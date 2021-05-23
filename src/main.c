#include <stdio.h>
#include "cube.c"
#include "move.c"


int main(void) {
    Face **rubiks = create_rubiks();

    printf("%d \n", rubiks[2]->side);
    init_rubiks(rubiks);

    rubiks[BACK]->face[0][0] = R;
    rubiks[LEFT]->face[0][0] = B;

    display_rubiks(rubiks);
    printf("\n");

    left_clockwise(rubiks, QUARTER);

    display_rubiks(rubiks);
    printf("\n");

    free_rubiks(rubiks);

    return 0;
}