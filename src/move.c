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

void rotate_other_face(Face* rubiks[6], T_SIDE side) {
    T_SIDE side_to_move[4];
    switch (side) {
        case BACK:
            for (int i = 0; i < 3; ++i) {rotate_other_face(rubiks, FRONT);}
            return;
        case RIGHT:
            for (int i = 0; i < 3; ++i) {rotate_other_face(rubiks, LEFT);}
            return;
        case UP:
            for (int i = 0; i < 3; ++i) {rotate_other_face(rubiks, DOWN);}
            return;
        case FRONT:
            side_to_move[0] = UP;
            side_to_move[1] = RIGHT;
            side_to_move[2] = DOWN;
            side_to_move[3] = LEFT;
            break;
        case LEFT:
            side_to_move[0] = UP;
            side_to_move[1] = FRONT;
            side_to_move[2] = DOWN;
            side_to_move[3] = BACK;
            break;
        case DOWN:
            side_to_move[0] = FRONT;
            side_to_move[1] = RIGHT;
            side_to_move[2] = BACK;
            side_to_move[3] = LEFT;
            break;
        default:
            side_to_move[0] = UP;
            side_to_move[1] = RIGHT;
            side_to_move[2] = DOWN;
            side_to_move[3] = LEFT;
    }

    // We copy the value of the 3 cell on the first side
    T_COLOR first_side_value[3];
    for (int i = 0; i < 3; ++i) {
        first_side_value[i] = rubiks[side_to_move[0]]->face[0][i];
    }

    // We rotate the other face
    for (int i = 0; i < 3; ++i) {
        rubiks[side_to_move[0]]->face[0][i] = rubiks[side_to_move[1]]->face[i][2];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[side_to_move[1]]->face[2-i][2] = rubiks[side_to_move[2]]->face[2][i];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[side_to_move[2]]->face[2][i] = rubiks[side_to_move[3]]->face[i][0];
    }
    for (int i = 0; i < 3; ++i) {
        rubiks[side_to_move[3]]->face[i][0] = first_side_value[2-i];
    }
}

void rotate_face(Face* rubiks[6], T_SIDE side, R_TYPE type) {
    // Check the R_TYPE
    if (type == HALF) {
        rotate_face(rubiks, side, QUARTER);
    }

    rotate_center_face(rubiks, side);
    rotate_other_face(rubiks, side);
}
