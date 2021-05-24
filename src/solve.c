#include "solve.h"
#include "move.c"

// Brouillon
bool case1(Face* rubiks[6]) {
    if (rubiks[UP]->face[0][1] == W &&
        rubiks[UP]->face[1][0] == W &&
        rubiks[UP]->face[2][1] == W &&
        rubiks[FRONT]->face[0][1] == W &&
        rubiks[RIGHT]->face[0][1] == R &&
        rubiks[FRONT]->face[1][2] == G) {
        return true;
    }
    // Faire de même pour les 3 autres cas
}

void white_cross(Face* rubiks[6]) {
    if (case1(rubiks)) {
        front_clockwise(rubiks, QUARTER);
        up_anticlockwise(rubiks, QUARTER);
        right_clockwise(rubiks, QUARTER);
        up_clockwise(rubiks, QUARTER);
    } else if (case2) {
        front_anticlockwise(rubiks, QUARTER);
        right_anticlockwise(rubiks, QUARTER);
        down_anticlockwise(rubiks, QUARTER);
        right_clockwise(rubiks, QUARTER);
        front_clockwise(rubiks, HALF);
    } else if (case3) {
        right_anticlockwise(rubiks, QUARTER);
        down_anticlockwise(rubiks, QUARTER);
        right_clockwise(rubiks, QUARTER);
        front_clockwise(rubiks, HALF);
    } else if (case4) {
        front_clockwise(rubiks, QUARTER);
        right_clockwise(rubiks, QUARTER);
    } else {
        right_anticlockwise(rubiks, QUARTER);
        front_anticlockwise(rubiks, QUARTER);
        up_clockwise(rubiks, QUARTER);
    }
}
void full_white_face(Face* rubiks[6]);
void second_crown(Face* rubiks[6]);
void last_face(Face* rubiks[6]);