//
// Created by leich on 2019/1/31.
//
#include <stdio.h>
#include "move.h"
#include "board.h"
#include "input_validation.h"
#include "CurseTrackedWindow.h"

Move getValidMove(struct Board_Struct* board, TurnType playerTurn, CursorTrackedWindow* win) {
    Move move;

    while (true) {

        char input = wgetch(win->cursesWin);
        if (input == 'a' || input == 'j'|| input == (KEY_LEFT & A_CHARTEXT)) {
            if (win->cursorCol > 0) {
                win->cursorCol -= 1;
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol + 1, ' ');
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol, "XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
            } else if (win->cursorCol == 0) {
                win->cursorCol = board->numCols - 1;
                mvwaddch(win->cursesWin, win->cursorRow, 0, ' ');
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol, "XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
            }
        } else if (input == 's' || input == 'k'|| input == (KEY_RIGHT & A_CHARTEXT)) {
            if (win->cursorCol < board->numCols - 1) {
                win->cursorCol += 1;
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol - 1, ' ');
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol, "XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
            }else if (win->cursorCol == board->numCols - 1) {
                win->cursorCol = 0;
                mvwaddch(win->cursesWin, win->cursorRow, board->numCols - 1, ' ');
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol, "XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, 0);
            }

        } else if (input == ' ' || input == '\n') {
            if (board->theBoard[board->numRows - 2][win->cursorCol] == board->blankChar){
                win->cursorRow = board->numRows - 2;
                move.row = win->cursorRow;
                move.col = win->cursorCol;
                move.marker = "XO"[playerTurn];
                if (playerTurn == 0){
                    mvwaddch(win->cursesWin, 0, win->cursorCol, 'O');
                } else if (playerTurn == 1){
                    mvwaddch(win->cursesWin, 0, win->cursorCol, 'X');
                }
                return move;
            }else {
                int i;
                for (i = board->numRows - 2; i > 0; i--) {
                    if (board->theBoard[win->cursorRow + i][win->cursorCol] == board->blankChar) {
                        win->cursorRow = win->cursorRow + i ;
                        move.row = win->cursorRow;
                        move.col = win->cursorCol;
                        move.marker = "XO"[playerTurn];
                        if (playerTurn == 0){
                            mvwaddch(win->cursesWin, 0, win->cursorCol, 'O');
                        } else if (playerTurn == 1){
                            mvwaddch(win->cursesWin, 0, win->cursorCol, 'X');
                        }
                        return move;
                    }

                }
            }

        }
        wrefresh(win->cursesWin);
    }

}

bool isValidMove(Move move, struct Board_Struct* board, int numArgsRead, int numArgsNeeded) {
    return isValidFormat(numArgsRead, numArgsNeeded) &&
           isInRange(move.row, 0, board->numRows - 1) &&
           isInRange(move.col, 0, board->numCols - 1) &&
           board->theBoard[move.row][move.col] == board->blankChar;
}

const char* PlayerToString(TurnType player) {
    static const char p1[] = "Player1";
    static const char p2[] = "Player2";
    if (player == Player1) {
        return p1;
    } else {
        return p2;
    }
}