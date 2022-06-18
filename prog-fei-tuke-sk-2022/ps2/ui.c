/** AUTHORED BY VOLODYMYR BOLGARIN ^_^
 *
 * TWITTER: @bolgarin_v
 * MY GITHUB IS: @ONIQdevv
 * STUDENT AT Technická univerzita v Košiciach -> FEI
 *
 * **/

///INCLUDES
#include <stdio.h>
#include <curses.h>
#include <string.h>

#include "k.h"

//void render(const struct game game){
//    printf("score: %d\n", game.score);
//
//    for(int row = 0; row < SIZE; row++){
//        printf("+---+---+---+---+\n|");
//        for(int col = 0; col < SIZE; col++){
//            printf(" %c |", game.board[row][col]);
//        }
//        printf("\n");
//    }
//    printf("+---+---+---+---+\n");
//
//}

void render(const struct game game) {
    clear();
    char text[20];
    sprintf(text, "Score: %d", game.score);
    attrset(COLOR_PAIR(0));
    mvprintw(1, (COLS - (int)strlen(text)) / 2, text);
    int x_entry = (COLS - 25) / 2;
    int y_entry = 3;
    attrset(COLOR_PAIR(6));

    for(int x_pos = y_entry; x_pos < y_entry + 17; x_pos++) for(int y_pos = x_entry; y_pos < x_entry + 25; y_pos++) mvprintw(x_pos, y_pos, " ");



    for(int i = 0; i < SIZE; i++) for(int j = 0; j < SIZE; j++) {

            if (game.board[i][j] == ' ') attrset(COLOR_PAIR(0));
            else if (game.board[i][j] < 'C') attrset(COLOR_PAIR(1));
            else if (game.board[i][j] < 'E') attrset(COLOR_PAIR(2));
            else if (game.board[i][j] < 'G') attrset(COLOR_PAIR(3));
            else if (game.board[i][j] < 'J') attrset(COLOR_PAIR(4));
            else attrset(COLOR_PAIR(5));

            mvprintw(y_entry + (i * SIZE) + 1, x_entry + (j * 6) + 1, "     ");
            mvprintw(y_entry + (i * SIZE) + 2, x_entry + (j * 6) + 1, "  %c  ", game.board[i][j]);
            mvprintw(y_entry + (i * SIZE) + 3, x_entry + (j * 6) + 1, "     ");

    }
    refresh();

}
