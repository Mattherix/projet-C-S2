//
// Created by matthieu on 14/05/2021.
//
// Function to represent the cube
//

#ifndef PROJECT_C_CUBE_H
#define PROJECT_C_CUBE_H

Face* create_rubiks();
void init_rubiks(Face rubiks[6]);
void display_rubiks(Face rubiks[6]);
void blank_rubiks(Face rubiks[6]);
void fill_rubiks(Face rubiks[6]);
void scramble_rubiks(Face rubiks[6]);
void free_rubiks(Face rubiks[6]);

#endif //PROJECT_C_CUBE_H
