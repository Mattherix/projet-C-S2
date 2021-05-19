//
// Created by matthieu on 05/05/2021.
//

#ifndef PROJET_C_MAIN_H
#define PROJET_C_MAIN_H

#include "color.h"

typedef enum {FRONT, BACK, UP, DOWN, RIGHT, LEFT} T_SIDE;
typedef enum {HALF=1, QUARTER=2} R_TYPE;

typedef struct Face{
    T_SIDE side;
    T_COLOR face[3][3];
} Face;


#endif //PROJET_C_MAIN_H
