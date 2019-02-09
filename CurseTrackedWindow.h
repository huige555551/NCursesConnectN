//
// Created by leich on 2019/2/2.
//

#ifndef NCURSESCONNECTN_CURSETRACKEDWINDOW_H
#define NCURSESCONNECTN_CURSETRACKEDWINDOW_H

#include <ncurses.h>

typedef struct CursorTrackedWindow_Struct{
    WINDOW* cursesWin;
    int cursorRow, cursorCol;
}CursorTrackedWindow;

CursorTrackedWindow newCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart);
void fillWindow(CursorTrackedWindow* win, char fillChar);

int getNumRows(CursorTrackedWindow* win);
int getNumCols(CursorTrackedWindow* win);

void moveAndAddCharacter(CursorTrackedWindow* win, int row, int col, char toAdd);
void addCharacter(CursorTrackedWindow* win, char toAdd);
void CursorTrackedWindowMove(CursorTrackedWindow* win, int row, int col);
#endif //NCURSESCONNECTN_CURSETRACKEDWINDOW_H
