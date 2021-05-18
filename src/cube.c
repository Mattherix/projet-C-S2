#include <stdlib.h>
#include "cube.h"
#include "main.h"
#include "colors.h"

Face* create_face(int side) {
    Face *face = malloc(sizeof(Face));
    face->side = side;

    for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
            face->face[j][k] = LG;
        }
    }
    return face;
}

Face** create_rubiks() {
    Face **rubiks = malloc(sizeof(Face) * 6);
    for (int i = FRONT; i <= LEFT; ++i) {
        rubiks[i] = create_face(i);
    }
    return rubiks;
}
