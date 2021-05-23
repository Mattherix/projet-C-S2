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

void front_clockwise(Face* rubiks[6], R_TYPE type) {
    // Check the R_TYPE
    if (type == HALF) {
        back_clockwise(rubiks, QUARTER);
    }

    rotate_center_face(rubiks, FRONT);

    // We copy the value of the 3 cell on the first side
    T_COLOR up_side_value[3];
    for (int i = 0; i < 3; ++i) {
        up_side_value[i] = rubiks[UP]->face[0][i];
    }

    // We rotate the other face
    for (int i = 0; i < 3; ++i) {
        rubiks[UP]->face[2][i] = rubiks[RIGHT]->face[i][0];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[RIGHT]->face[2-i][0] = rubiks[DOWN]->face[0][i];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[DOWN]->face[0][i] = rubiks[LEFT]->face[i][2];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[LEFT]->face[i][2] = up_side_value[2-i];
    }
}

void back_clockwise(Face* rubiks[6], R_TYPE type) {
    // Check the R_TYPE
    if (type == HALF) {
        back_clockwise(rubiks, QUARTER);
    }

    rotate_center_face(rubiks, BACK);

    for (int j = 0; j < 3; ++j) {
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
}

void up_clockwise(Face* rubiks[6], R_TYPE type) {
    // Check the R_TYPE
    if (type == HALF) {
        back_clockwise(rubiks, QUARTER);
    }

    rotate_center_face(rubiks, UP);

    // We copy the value of the 3 cell on the first side
    T_COLOR front_side_value[3];
    for (int i = 0; i < 3; ++i) {
        front_side_value[i] = rubiks[FRONT]->face[0][i];
    }

    // We rotate the other face
    for (int i = 0; i < 3; ++i) {
        rubiks[FRONT]->face[0][i] = rubiks[RIGHT]->face[0][i];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[RIGHT]->face[0][i] = rubiks[BACK]->face[0][i];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[BACK]->face[0][i] = rubiks[LEFT]->face[0][i];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[LEFT]->face[0][i] = front_side_value[i];
    }
}
void down_clockwise(Face* rubiks[6], R_TYPE type) {
    // Check the R_TYPE
    if (type == HALF) {
        back_clockwise(rubiks, QUARTER);
    }

    rotate_center_face(rubiks, DOWN);

    for (int j = 0; j < 3; ++j) {
        // We copy the value of the 3 cell on the first side
        T_COLOR front_side_value[3];
        for (int i = 0; i < 3; ++i) {
            front_side_value[i] = rubiks[FRONT]->face[2][i];
        }

        // We rotate the other face
        for (int i = 0; i < 3; ++i) {
            rubiks[FRONT]->face[2][i] = rubiks[RIGHT]->face[2][i];
        }
        for (int i = 0; i < 3; ++i) {
            rubiks[RIGHT]->face[2][i] = rubiks[BACK]->face[2][i];
        }
        for (int i = 0; i < 3; ++i) {
            rubiks[BACK]->face[2][i] = rubiks[LEFT]->face[2][i];
        }
        for (int i = 0; i < 3; ++i) {
            rubiks[LEFT]->face[2][i] = front_side_value[i];
        }
    }
}
void right_clockwise(Face* rubiks[6], R_TYPE type) {
    // Check the R_TYPE
    if (type == HALF) {
        back_clockwise(rubiks, QUARTER);
    }

    rotate_center_face(rubiks, RIGHT);

    for (int j = 0; j < 3; ++j) {
        // We copy the value of the 3 cell on the first side
        T_COLOR front_side_value[3];
        for (int i = 0; i < 3; ++i) {
            front_side_value[i] = rubiks[FRONT]->face[i][2];
        }

        // We rotate the other face
        for (int i = 0; i < 3; ++i) {
            rubiks[FRONT]->face[i][2] = rubiks[UP]->face[i][2];
        }
        for (int i = 0; i < 3; ++i) {
            rubiks[UP]->face[i][2] = rubiks[BACK]->face[i][0];
        }
        for (int i = 0; i < 3; ++i) {
            rubiks[BACK]->face[i][0] = rubiks[DOWN]->face[i][2];
        }
        for (int i = 0; i < 3; ++i) {
            rubiks[DOWN]->face[i][2] = front_side_value[i];
        }
    }
}
void left_clockwise(Face* rubiks[6], R_TYPE type) {
    // Check the R_TYPE
    if (type == HALF) {
        back_clockwise(rubiks, QUARTER);
    }

    rotate_center_face(rubiks, LEFT);

    // We copy the value of the 3 cell on the first side
    T_COLOR front_side_value[3];
    for (int i = 0; i < 3; ++i) {
        front_side_value[i] = rubiks[FRONT]->face[i][2];
    }

    // We rotate the other face
    for (int i = 0; i < 3; ++i) {
        rubiks[FRONT]->face[i][0] = rubiks[UP]->face[i][0];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[UP]->face[i][0] = rubiks[BACK]->face[i][2];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[BACK]->face[i][2] = rubiks[DOWN]->face[i][0];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[DOWN]->face[i][0] = front_side_value[i];
    }
}