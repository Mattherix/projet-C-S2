#ifndef PROJECT_C_CUBE_H
#define PROJECT_C_CUBE_H

#include <stdbool.h>

Face* create_face(T_SIDE side);
void blank_face(Face *face, T_SIDE side);
Face** create_rubiks(void);
void init_rubiks(Face* rubiks[6]);
void display_array_face(Face* rubiks[6], T_SIDE side[], int lenght, bool space);
void display_rubiks(Face* rubiks[6]);
void blank_rubiks(Face* rubiks[6]);
void fill_rubiks(Face* rubiks[6]);
void scramble_rubiks(Face* rubiks[6]);
void free_rubiks(Face* rubiks[6]);

#endif //PROJECT_C_CUBE_H
