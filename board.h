//
// Created by leich on 2019/1/31.
//

#ifndef NCURSESCONNECTN_BOARD_H
#define NCURSESCONNECTN_BOARD_H
#include "move.h"



typedef struct Board_Struct{
    char** theBoard;
    int numRows;
    int numCols;
    int numToWin;
    char blankChar;
}Board;



Board makeBoard(int numRows, int numCols, int numToWin, char blankChar);
void printBoard(Board board, TurnType playerTurn, CursorTrackedWindow* win);
void cleanUpBoard(Board* board);

void placeMove(Move move, Board* board, CursorTrackedWindow* win);
#endif //NCURSESCONNECTN_BOARD_H
