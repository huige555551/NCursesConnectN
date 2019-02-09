//
// Created by leich on 2019/1/31.
//

#ifndef NCURSESCONNECTN_MOVE_H
#define NCURSESCONNECTN_MOVE_H
#include <stdbool.h>
#include <stdbool.h>
#include "CurseTrackedWindow.h"
//#include "board.h"

typedef enum{Player1 = 0, Player2 = 1}TurnType;

typedef struct Move_Struct{
    int row, col;
    char marker;
}Move;

struct Board_Struct;


Move getValidMove(struct Board_Struct* board, TurnType playerTurn, CursorTrackedWindow* win);
bool isValidMove(Move move,  struct Board_Struct* board, int numArgsRead, int numArgsNeeded);
const char* PlayerToString(TurnType player);
#endif //NCURSESCONNECTN_MOVE_H
