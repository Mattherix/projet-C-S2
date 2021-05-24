#include <stdio.h>
#include "cube.c"
#include "move.c"


int main(void) {
    Face **rubiks = create_rubiks();

    printf("%d \n", rubiks[2]->side);
    init_rubiks(rubiks);

    display_rubiks(rubiks);
    printf("\n");

    display_rubiks(rubiks);

    printf("\n");
    scramble_rubiks(rubiks);

    display_rubiks(rubiks);
    printf("\n");

    free_rubiks(rubiks);

    return 0;
}