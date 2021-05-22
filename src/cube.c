#include <stdlib.h>
#include <stdbool.h>
#include "main.h"
#include "cube.h"
#include "color.c"
#include "enum.c"

Face* create_face(int side) {
    Face *face = malloc(sizeof(Face));
    face->side = side;

    blank_face(face, side);
    return face;
}
void blank_face(Face *face, T_SIDE side) {
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            face->face[j][k] = LG;
        }
    }
    face->face[1][1] = get_side_color(side);
}
Face** create_rubiks() {
    Face **rubiks = malloc(sizeof(Face) * 6);
    for (int side = FRONT; side <= LEFT; ++side) {
        rubiks[side] = create_face(side);
    }
    return rubiks;
}

void init_rubiks(Face* rubiks[6]) {
    for (int side = FRONT; side <= LEFT; ++side) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                rubiks[side]->face[i][j] = get_side_color(side);
            }
        }
    }
}

void display_array_face(Face* rubiks[6], T_SIDE side[], int lenght, bool space) {
    for (int i = 0; i < 3; ++i) {
        if (space) {
            printf("      ");
        }
        for (int index = 0; index < lenght; ++index) {
            for (int j = 0; j < 3; ++j) {
                printf("%s %c%s", get_color_code(rubiks[side[index]]->face[j][i]), rubiks[side[index]]->face[i][j], NONE);
            }
        }
        printf("\n");
    }
}

void display_rubiks(Face* rubiks[6]) {
    T_SIDE ligne1[] = {UP};
    T_SIDE ligne2[] = {LEFT, FRONT, RIGHT, BACK};
    T_SIDE ligne3[] = {DOWN};

    display_array_face(rubiks, ligne1, 1, true);
    display_array_face(rubiks, ligne2, 4, false);
    display_array_face(rubiks, ligne3, 1, true);
}

void blank_rubiks(Face* rubiks[6]) {
    for (int side = FRONT; side <= LEFT; ++side) {
        blank_face(rubiks[side]);
    }
}

void free_rubiks(Face* rubiks[6]) {
    for (int side = FRONT; side <= LEFT; ++side) {
        free(rubiks[side]);
    }
    // No need to free the list of pointer, already done, else we have a double free error
    rubiks = NULL;
}