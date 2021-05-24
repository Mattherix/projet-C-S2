//
// Created by matthieu on 14/05/2021.
//
// Function used to move the cube
//

#ifndef PROJECT_C_MOVE_H
#define PROJECT_C_MOVE_H

void rotate_face(Face* rubiks[6], T_SIDE side, R_TYPE type);

void front_clockwise(Face* rubiks[6], R_TYPE type);
void back_clockwise(Face* rubiks[6], R_TYPE type);
void up_clockwise(Face* rubiks[6], R_TYPE type);
void down_clockwise(Face* rubiks[6], R_TYPE type);
void right_clockwise(Face* rubiks[6], R_TYPE type);
void left_clockwise(Face* rubiks[6], R_TYPE type);

void front_anticlockwise(Face* rubiks[6], R_TYPE type);
void back_anticlockwise(Face* rubiks[6], R_TYPE type);
void up_anticlockwise(Face* rubiks[6], R_TYPE type);
void down_anticlockwise(Face* rubiks[6], R_TYPE type);
void right_anticlockwise(Face* rubiks[6], R_TYPE type);
void left_anticlockwise(Face* rubiks[6], R_TYPE type);

// Les autres movements sont inutile pour l'algo de résolution

#endif //PROJECT_C_MOVE_H
