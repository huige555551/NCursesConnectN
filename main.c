#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "board.h"
#include "move.h"
#include "win.h"
#include "CurseTrackedWindow.h"


//int main(int argc, char* argv[]) {
int main(int argc, char* argv[]) {

        //int numOfRows = atoi(argv[1]) + 2;
        //int numOfCols = atoi(argv[2]);
        //int pieceToWin = atoi(argv[3]);
        //FILE* file = fopen(argv[4]), "w");
        int numOfRows = 4 + 2;
        int numOfCols = 4;
        int numToWin = 3;
        FILE* file = fopen(outputFile, "w");
        initscr();
        noecho();
        cbreak();



        CursorTrackedWindow boardWindow = newCursorTrackedWindow(numOfRows, numOfCols, 0, 0);
        fillWindow(&boardWindow, '*');
        keypad(boardWindow.cursesWin, true);

        wrefresh(boardWindow.cursesWin);




        //make a board

        Board board = makeBoard(numOfRows, numOfCols, numToWin, '*');
        TurnType playerTurn = Player1;
        // pick a starting player
        while(!isGameOver(board)){

            //show them the state of the game
            //printBoard(board);
            //get a move from the user
            Move move = getValidMove(&board, playerTurn, &boardWindow);
            //place their move on the board
            placeMove(move, &board, &boardWindow);
            //change turn
            //playerTurn = (playerTurn + 1) % 2;
            playerTurn = playerTurn == Player1 ? Player2 : Player1;
        }

        delwin(boardWindow.cursesWin);
        endwin();
        //print the winning board
        printBoard(board, playerTurn, &boardWindow);

        //declare who wins or a tie
        declareWinner(board, playerTurn);
        //clean up
        cleanUpBoard(&board);

        return 0;

    }