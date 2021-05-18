#include <stdio.h>
#include "colors.h"
#include "enum.c"
#include "cube.c"


int main() {
    T_COLOR c = R;
    // printf("%d\n", select_color(c));

    // printf("%ld", sizeof(Face) * 6);
    Face **rubiks = create_rubiks();

    printf("%d", rubiks[2]->side);
    init_rubiks(rubiks);

    for (int side = FRONT; side < LEFT; ++side) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                printf("%s %c %s", orange, rubiks[side]->face[i][j], none);
            }
            printf("\n");
        }
    }

    return 0;
}