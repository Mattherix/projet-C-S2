//
// Created by matthieu on 06/05/2021.
//
// Function for the enum type 3.1
//

#ifndef PROJECT_C_ENUM_H
#define PROJECT_C_ENUM_H

#include "main.h"

int select_color(T_COLOR color);
T_COLOR get_side_color(T_SIDE side);
int side_to_index(T_SIDE side, Face* rubiks[6]);

#endif //PROJECT_C_ENUM_H
