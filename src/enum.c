#include "enum.h"
#include "color.h"

int select_color(T_COLOR color) {
    return color;
}
T_COLOR get_side_color(T_SIDE side) {
    T_COLOR color;
    switch (side) {
        case FRONT:
            color = G;
            break;
        case BACK:
            color = B;
            break;
        case UP:
            color = W;
            break;
        case DOWN:
            color = Y;
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
