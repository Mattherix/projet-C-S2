#include <stdio.h>
#include "cube.c"


int main(void) {
    Face **rubiks = create_rubiks();

    printf("%d \n", rubiks[2]->side);
    init_rubiks(rubiks);

    display_rubiks(rubiks);

    fill_rubiks(rubiks);

    display_rubiks(rubiks);

    free_rubiks(rubiks);

    return 0;
}