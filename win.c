//
// Created by leich on 2019/1/31.
//
#include <stdio.h>
#include "win.h"

bool isGameOver(Board board) {
    return win(board) || tie(board);
}

bool win(Board board) {
    return horzWin(board) || vertWin(board) || diagWin(board);
}

bool horzWin(Board board) {
    int numInARow;
    for (int row = 1; row < board.numRows - 1; row++){
        for (int col = 0; col <= board.numCols - board.numToWin + 1 ; col++){
            if (board.theBoard[row][col] != board.blankChar){
                numInARow = 1;
                for (int i = 1; i < board.numToWin; i++){
                    if ((board.theBoard[row][col + i] == board.theBoard[row][col])&&(board.theBoard[row][col] != board.blankChar)){
                        numInARow += 1;
                    }
                    if (numInARow == board.numToWin){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool vertWin(Board board) {
    int numInACol;
    for (int col = 0; col < board.numCols; col++) {
        for (int row = board.numRows - 2; row >= board.numRows - board.numToWin; row--) {
            numInACol = 0;
            if (board.theBoard[row][col] != board.blankChar) {
                for (int i = board.numToWin; i >= 0; i--) {
                    if (board.theBoard[row - i][col] == board.theBoard[row][col]) {
                        numInACol += 1;
                        if (numInACol == board.numToWin) {
                            return true;
                        }
                    }

                }
            }
        }
    }
    return false;
}

bool diagWin(Board board) {
    return leftDiagWin(board) || rightDiagWin(board);
}

/**
 * Check for a left diagonal win. This looks like
 * X
 *   X
 *     X
 * @param board
 * @return
 */
bool leftDiagWin(Board board) {
    int numInACol;
    for (int col = board.numCols; col >= board.numCols - board.numToWin + 1; col--) {
        for (int row = board.numRows - 2; row >= board.numRows - board.numToWin; row--) {
            numInACol = 0;
            if (board.theBoard[row][col] != board.blankChar) {
                for (int i = board.numToWin; i >= 0; i--) {
                    if (board.theBoard[row - i][col - i] == board.theBoard[row][col]) {
                        numInACol += 1;
                        if (numInACol == board.numToWin) {
                            return true;
                        }
                    }

                }
            }
        }
    }
    return false;
}

/**
 * Check for a right diagonal win
 * One that looks like
 *      X
 *    X
 *  X
 * @param board
 * @return
 */
bool rightDiagWin(Board board) {
    int numInACol;
    for (int col = 0; col <= board.numCols - board.numToWin + 1; col++) {
        for (int row = board.numRows - 2; row >= board.numRows - board.numToWin; row--) {
            numInACol = 0;
            if (board.theBoard[row][col] != board.blankChar) {
                for (int i = board.numToWin; i >= 0; i--) {
                    if (board.theBoard[row - i][col + i] == board.theBoard[row][col]) {
                        numInACol += 1;
                        if (numInACol == board.numToWin) {
                            return true;
                        }
                    }

                }
            }
        }
    }
    return false;
}

bool tie(Board board) {

    if(win(board)){
        return false;
    }

    for (int row = 1; row <  board.numRows - 1; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if(board.theBoard[row][col] == board.blankChar){
                return false;
            }
        }
    }
    return true;
}

void declareWinner(Board board, TurnType playerTurn) {
    if(win(board)){
        //if someone one it would actually be the loser's turn
        //so account for this here
        int winner = playerTurn == Player1 ? Player2 : Player1;
        winner++;

        printf("Player %d won!\n", winner);

    }else{
        printf("Tie game.\n");
    }
}