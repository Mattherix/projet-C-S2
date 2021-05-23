#include "main.h"
#include "move.h"
#include "cube.h"

void rotate_center_face(Face* rubiks[6], T_SIDE side) {
    // Rotate the center face
    Face *face = create_face(side);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            face->face[i][j] = rubiks[side]->face[2-j][i];
        }
    }
    free(rubiks[side]);
    rubiks[side] = face;
}

void back_clockwise(Face* rubiks[6], R_TYPE type) {
    // Check the R_TYPE
    if (type == HALF) {
        back_clockwise(rubiks, QUARTER);
    }

    rotate_center_face(rubiks, BACK);

    // We copy the value of the 3 cell on the first side
    T_COLOR up_side_value[3];
    for (int i = 0; i < 3; ++i) {
        up_side_value[i] = rubiks[UP]->face[0][i];
    }

    // We rotate the other face
    for (int i = 0; i < 3; ++i) {
        rubiks[UP]->face[0][i] = rubiks[RIGHT]->face[i][2];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[RIGHT]->face[2-i][2] = rubiks[DOWN]->face[2][i];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[DOWN]->face[2][i] = rubiks[LEFT]->face[i][0];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[LEFT]->face[i][0] = up_side_value[2-i];
    }
}

