//
// Created by matthieu on 14/05/2021.
//
#include "enum.h"
#include "colors.h"

int select_color(T_COLOR color) {
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
