//
// Created by leich on 2019/1/31.
//
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include "board.h"
#include "CurseTrackedWindow.h"

Board makeBoard(int numRows, int numCols, int numToWin, char blankChar) {
    Board board;

    board.theBoard = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; ++i) {
        board.theBoard[i] = (char*)malloc(numCols * sizeof(char));
        for (int j = 0; j < numCols; ++j) {
            if (i == 0 && j == 0){
                board.theBoard[i][j] = ' ';
            } else if (i == 0){
                board.theBoard[i][j] = ' ';
            } else {
                board.theBoard[i][j] = blankChar;
            }
        }
    }

    board.numRows = numRows;
    board.numCols = numCols;
    board.blankChar = blankChar;
    board.numToWin = numToWin;
    return board;
}

void printBoard(Board board, TurnType playerTurn, CursorTrackedWindow* win) {
    //print column header
//    printf("  "); //make things line up
//    for (int i = 0; i < board.numCols; ++i) {
//        printf("  ");
//    }
//    printf("\n");

    for (int row = 0; row < board.numRows - 1; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if ((row == 0) && (col == win->cursorCol)){
                if (playerTurn == 1){
                    printf("%c", "XO"[0]);
                } else {
                    printf("%c", "XO"[1]);
                }

            }
            printf("%c", board.theBoard[row][col]);

        }
        printf("\n");
    }
}

void cleanUpBoard(Board* board) {

    for (int row = 0; row < board->numRows; ++row) {
        free(board->theBoard[row]);
    }
    free(board->theBoard);
    board->theBoard = NULL;
    board->numRows = 0;
    board->numCols = 0;
}

void placeMove(Move move, Board* board, CursorTrackedWindow* win) {
    board->theBoard[move.row][move.col] = move.marker;
    addCharacter(win, move.marker);
    CursorTrackedWindowMove(win, win->cursorRow, win->cursorCol);
    wrefresh(win->cursesWin);
}