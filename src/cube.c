#include <stdlib.h>
#include "cube.h"
#include "main.h"
#include "colors.h"

Face* create_face(int side) {
    Face *face = malloc(sizeof(Face));
    face->side = side;

    blank_face(face);
    return face;
}
void blank_face(Face *face) {
    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            face->face[j][k] = LG;
        }
    }
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