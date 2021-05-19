#include "color.h"

char* get_color_code(T_COLOR color) {
    char* color_code;
    switch (color) {
        case W:
            color_code = WHITE;
            break;
        case Y:
            color_code = YELLOW;
            break;
        case B:
            color_code = BLUE;
            break;
        case G:
            color_code = GREEN;
            break;
        case R:
            color_code = RED;
            break;
        case O:
            color_code = ORANGE;
            break;
        default:
            color_code = NONE;
    }
    return color_code;
}