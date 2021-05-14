#include <stdio.h>
#include "colors.h"
#include "enum.c"



int main() {
    T_COLOR c = R;
    printf("%d", select_color(c));

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