#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"
#include "cube.h"
#include "color.c"
#include "enum.c"
#include "move.h"

Face* create_face(T_SIDE side) {
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
                printf("%s %c%s",
                       get_color_code(rubiks[side[index]]->face[i][j]),
                       rubiks[side[index]]->face[i][j], NONE);
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
        blank_face(rubiks[side], side);
    }
}

bool check_if_solvable_cube(Face* rubiks[6]) {
    // We will just use a few check because it's easier
    // todo: Understand this link, it's complicated :(
    // https://math.stackexchange.com/questions/127577/how-to-tell-if-a-rubiks-cube-is-solvable

    // Check if there are any LG cell
    for (int side = FRONT; side <= LEFT ; ++side) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (rubiks[side]->face[i][j] == LG) {
                    return false;
                }
            }
        }
    }

    // Check the side color
    for (int side = FRONT; side <= LEFT ; ++side) {
        if (rubiks[side]->face[1][1] != get_side_color(side)) {
            return false;
        }
    }

    // Check if there is any adjacent cell witch have the same color
    // This check is precised in the suject, it's a none sens, it return false with a solved cube
    /*
    for (int side = FRONT; side <= LEFT ; ++side) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (rubiks[side]->face[i][j] == rubiks[side]->face[i + 1][j + 1] ||
                    rubiks[side]->face[j][i] == rubiks[side]->face[j + 1][i + 1]) {
                        return false;
                }
            }
        }
        if (rubiks[side]->face[0][2] == rubiks[side]->face[1][2] ||
            rubiks[side]->face[1][2] == rubiks[side]->face[2][2] ||
            rubiks[side]->face[2][0] == rubiks[side]->face[2][1] ||
            rubiks[side]->face[2][1] == rubiks[side]->face[2][2]) {
                return false;
        }
    }
    */
    return true;
}

void input_a_cell(Face* rubiks[6]) {
    printf("Select a side (FRONT, BACK, UP, DOWN, RIGHT, LEFT)\n");
    char side_str[6];
    T_SIDE side;
    bool failed = false;
    do {
        scanf("%s", side_str);
        if (!strcmp(side_str, "FRONT")) {
            side = FRONT;
            failed = false;
        } else if (!strcmp(side_str, "BACK")) {
            side = BACK;
            failed = false;
        } else if (!strcmp(side_str, "UP")) {
            side = UP;
            failed = false;
        } else if (!strcmp(side_str, "DOWN")) {
            side = DOWN;
            failed = false;
        } else if (!strcmp(side_str, "RIGHT")) {
            side = RIGHT;
            failed = false;
        } else if (!strcmp(side_str, "LEFT")) {
            side = LEFT;
            failed = false;
        } else {
            failed = true;
        }
    } while(failed);

    printf("Select a cell (0 then 0, 1 then 0, ..., 1 then 1)\n");
    int i;
    int j;
    do {
        scanf("%d %d", &i, &j);
    } while(i < 0 || i > 3 || j < 0 || j > 0);

    printf("Select a color (W, Y, B, G, R, O)\n");
    char color;
    do {
        scanf("%c", &color);
    } while(color != W &&
            color != Y &&
            color != B &&
            color != G &&
            color != R &&
            color != O &&
            color != LG);

    rubiks[side]->face[i][j] = color;
}
void fill_rubiks(Face* rubiks[6]) {
    int edit = 1;
    do {
        input_a_cell(rubiks);
        display_rubiks(rubiks);
        printf("Continuer (0, 1) ? :");
        scanf("%d", &edit);
    } while (edit || !check_if_solvable_cube(rubiks));
}

void scramble_rubiks(Face* rubiks[6]) {
    time_t t;
    srand((unsigned) time(&t));

    int n = rand() % 1000;
    for (int j = 0; j < n; ++j) {
        int choice = rand() % 24;
        switch (choice) {
            case 0:
                front_clockwise(rubiks, QUARTER);
                break;
            case 1:
                back_clockwise(rubiks, QUARTER);
                break;
            case 2:
                up_clockwise(rubiks, QUARTER);
                break;
            case 3:
                down_clockwise(rubiks, QUARTER);
                break;
            case 4:
                right_clockwise(rubiks, QUARTER);
                break;
            case 5:
                left_clockwise(rubiks, QUARTER);
                break;

            case 6:
                front_clockwise(rubiks, HALF);
                break;
            case 7:
                back_clockwise(rubiks, HALF);
                break;
            case 8:
                up_clockwise(rubiks, HALF);
                break;
            case 9:
                down_clockwise(rubiks, HALF);
                break;
            case 10:
                right_clockwise(rubiks, HALF);
                break;
            case 11:
                left_clockwise(rubiks, HALF);
                break;
            case 12:
                front_anticlockwise(rubiks, QUARTER);
                break;
            case 13:
                back_anticlockwise(rubiks, QUARTER);
                break;
            case 14:
                up_anticlockwise(rubiks, QUARTER);
                break;
            case 15:
                down_anticlockwise(rubiks, QUARTER);
                break;
            case 16:
                right_anticlockwise(rubiks, QUARTER);
                break;
            case 17:
                left_anticlockwise(rubiks, QUARTER);
                break;
            case 18:
                front_anticlockwise(rubiks, HALF);
                break;
            case 19:
                back_anticlockwise(rubiks, HALF);
                break;
            case 20:
                up_anticlockwise(rubiks, HALF);
                break;
            case 21:
                down_anticlockwise(rubiks, HALF);
                break;
            case 22:
                right_anticlockwise(rubiks, HALF);
                break;
            case 23:
                left_anticlockwise(rubiks, HALF);
                break;
        }
    }

}

void free_rubiks(Face* rubiks[6]) {
    for (int side = FRONT; side <= LEFT; ++side) {
        free(rubiks[side]);
    }
    // No need to free the list of pointer, already done, else we have a double free error
    rubiks = NULL;
}