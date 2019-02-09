//
// Created by leich on 2019/1/31.
//

#ifndef NCURSESCONNECTN_INPUT_VALIDATION_H
#define NCURSESCONNECTN_INPUT_VALIDATION_H
#include <stdbool.h>
bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isInRange(int value, int lowerBound, int uppderBound);
#endif //NCURSESCONNECTN_INPUT_VALIDATION_H
