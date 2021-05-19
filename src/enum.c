#include "enum.h"
#include "colors.h"

int select_color(T_COLOR color) {
    return color;
}
T_COLOR get_side_color(T_SIDE side) {
    T_COLOR color;
    switch (side) {
        case FRONT:
            color = W;
            break;
        case BACK:
            color = Y;
            break;
        case UP:
            color = B;
            break;
        case DOWN:
            color = G;
            break;
        case RIGHT:
            color = R;
            break;
        case LEFT:
            color = O;
            break;
        default:
            color = LG;
    }
    return color;
}
int side_to_index(T_SIDE side, Face* rubiks[6]) {
    for (int i = 0; i < 6; ++i) {
        if (rubiks[i]->side == side) {
            return i;
        }
    }
    return -1;
}
