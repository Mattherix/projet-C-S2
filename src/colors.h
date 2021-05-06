//
// Created by mattherix on 06/05/2021.
//
// Don't wanna use the conio file yet,
// it look to complicated just for the text color,
// not all the function are implemented (ie void c_textattr(int newattr)
// and I'm not sure about the licence.
//
// Please read this if your on linux:
//  https://ramprasadk.wordpress.com/2010/06/09/c-programming-linux-color-text-output/
// Please take also a look the ANSI color and this stackoverflow question for orange
// https://stackoverflow.com/questions/32573654/is-there-a-way-to-create-an-orange-color-from-ansi-escape-characters
//
// https://www.man7.org/linux/man-pages/man5/terminal-colors.d.5.html
// todo: Add windows and mac support.

#ifndef PROJECT_C_COLOR_H
#define PROJECT_C_COLOR_H

#ifdef __unix__
    #define red    "\033[31m"
    #define blue   "\033[34m"
    #define green  "\033[32m"
    #define white  "\033[37m"
    #define yellow "\033[33m"
    #define orange "\033[35m" // todo: Find a way to use orange, here it's purple

    #define none   "\033[0m"
#endif


#endif //PROJECT_C_COLOR_H

