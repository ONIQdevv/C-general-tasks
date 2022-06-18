/** AUTHORED BY VOLODYMYR BOLGARIN ^_^
 *
 * TWITTER: @bolgarin_v
 * MY GITHUB IS: @ONIQdevv
 * STUDENT AT Technická univerzita v Košiciach -> FEI
 *
 * **/

///INCLUDES
#include "k.h"
#include <math.h>
#include <stdlib.h>

/*
            if(game.board[i][j] == game.board[i][0]) return false;
            if(game.board[i][j] == game.board[i][1]) return false;
            if(game.board[i][j] == game.board[i][2]) return false;
            if(game.board[i][j] == game.board[i][3]) return false;
            if(game.board[i][j] == game.board[0][j]) return false;
            if(game.board[i][j] == game.board[1][j]) return false;
            if(game.board[i][j] == game.board[2][j]) return false;
            if(game.board[i][j] == game.board[3][j]) return false;
            */

void add_random_tile(struct game *game) {
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    } else {
        game->board[row][col] = 'B';
    }
}

bool is_game_won(const struct game game) {

    int rows = SIZE;
    int cols = SIZE;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            if(game.board[i][j] == 'K') return true;

        }

    }
    return false;
}

bool is_move_possible(const struct game game) {

    int rows = SIZE;
    int cols = SIZE;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            if (game.board[i][j] == 32) return true;
            if (j <= cols - 1) if(game.board[i][j] == game.board[i + 1][j]) return true;
            if (j <= rows - 1) if(game.board[i][j] == game.board[i][j + 1]) return true;

        }

    }

    return false;

}


bool update(struct game *game, int dy, int dx) {

    if((dy == 1 && dx == 1) || (dy == -1 && dx == -1) || (dy == -1 && dx == 1) || (dy == 1 && dx == -1) || (dy == dx)) return false;

    if(dx == 1) {

        for (int i = 0; i < SIZE; ++i) {

            if(game->board[i][0] == game->board[i][3] && game->board[i][0] != 32 && game->board[i][1] == 32 && game->board[i][2] == 32) {

                game->board[i][3]++;
                game->board[i][0] = 32;

                if(game->board[i][3] == 66) game->score += (int)pow(2,2);
                if(game->board[i][3] == 67) game->score += (int)pow(2,3);
                if(game->board[i][3] == 68) game->score += (int)pow(2,4);
                if(game->board[i][3] == 69) game->score += (int)pow(2,5);
                if(game->board[i][3] == 70) game->score += (int)pow(2,6);
                if(game->board[i][3] == 71) game->score += (int)pow(2,7);
                if(game->board[i][3] == 72) game->score += (int)pow(2,8);
                if(game->board[i][3] == 73) game->score += (int)pow(2,9);
                if(game->board[i][3] == 74) game->score += (int)pow(2,10);
                if(game->board[i][3] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][1] == game->board[i][3] && game->board[i][0] != game->board[i][1] && game->board[i][1] != 32 && game->board[i][2] == 32) {

                game->board[i][3]++;
                game->board[i][1] = 32;

                if(game->board[i][3] == 66) game->score += (int)pow(2,2);
                if(game->board[i][3] == 67) game->score += (int)pow(2,3);
                if(game->board[i][3] == 68) game->score += (int)pow(2,4);
                if(game->board[i][3] == 69) game->score += (int)pow(2,5);
                if(game->board[i][3] == 70) game->score += (int)pow(2,6);
                if(game->board[i][3] == 71) game->score += (int)pow(2,7);
                if(game->board[i][3] == 72) game->score += (int)pow(2,8);
                if(game->board[i][3] == 73) game->score += (int)pow(2,9);
                if(game->board[i][3] == 74) game->score += (int)pow(2,10);
                if(game->board[i][3] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][0] == game->board[i][2] && game->board[i][0] != game->board[i][3] && game->board[i][1] == 32 && game->board[i][0] != 32) {

                game->board[i][2]++;
                game->board[i][0] = 32;

                if(game->board[i][2] == 66) game->score += (int)pow(2,2);
                if(game->board[i][2] == 67) game->score += (int)pow(2,3);
                if(game->board[i][2] == 68) game->score += (int)pow(2,4);
                if(game->board[i][2] == 69) game->score += (int)pow(2,5);
                if(game->board[i][2] == 70) game->score += (int)pow(2,6);
                if(game->board[i][2] == 71) game->score += (int)pow(2,7);
                if(game->board[i][2] == 72) game->score += (int)pow(2,8);
                if(game->board[i][2] == 73) game->score += (int)pow(2,9);
                if(game->board[i][2] == 74) game->score += (int)pow(2,10);
                if(game->board[i][2] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][0] == game->board[i][1] && game->board[i][2] == game->board[i][3] && game->board[i][0] != 32 && game->board[i][2] != 32) {

                game->board[i][1]++;
                game->board[i][3]++;
                game->board[i][0] = 32;
                game->board[i][2] = 32;

                if(game->board[i][1] == 66) game->score += (int)pow(2,2);
                if(game->board[i][1] == 67) game->score += (int)pow(2,3);
                if(game->board[i][1] == 68) game->score += (int)pow(2,4);
                if(game->board[i][1] == 69) game->score += (int)pow(2,5);
                if(game->board[i][1] == 70) game->score += (int)pow(2,6);
                if(game->board[i][1] == 71) game->score += (int)pow(2,7);
                if(game->board[i][1] == 72) game->score += (int)pow(2,8);
                if(game->board[i][1] == 73) game->score += (int)pow(2,9);
                if(game->board[i][1] == 74) game->score += (int)pow(2,10);
                if(game->board[i][1] == 74) game->score += (int)pow(2,11);

                if(game->board[i][3] == 66) game->score += (int)pow(2,2);
                if(game->board[i][3] == 67) game->score += (int)pow(2,3);
                if(game->board[i][3] == 68) game->score += (int)pow(2,4);
                if(game->board[i][3] == 69) game->score += (int)pow(2,5);
                if(game->board[i][3] == 70) game->score += (int)pow(2,6);
                if(game->board[i][3] == 71) game->score += (int)pow(2,7);
                if(game->board[i][3] == 72) game->score += (int)pow(2,8);
                if(game->board[i][3] == 73) game->score += (int)pow(2,9);
                if(game->board[i][3] == 74) game->score += (int)pow(2,10);
                if(game->board[i][3] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][2] == game->board[i][3] && game->board[i][2] != 32) {

                game->board[i][3]++;
                game->board[i][2] = 32;

                if(game->board[i][3] == 66) game->score += (int) pow(2,2);
                if(game->board[i][3] == 67) game->score += (int) pow(2,3);
                if(game->board[i][3] == 68) game->score += (int) pow(2,4);
                if(game->board[i][3] == 69) game->score += (int) pow(2,5);
                if(game->board[i][3] == 70) game->score += (int) pow(2,6);
                if(game->board[i][3] == 71) game->score += (int) pow(2,7);
                if(game->board[i][3] == 72) game->score += (int) pow(2,8);
                if(game->board[i][3] == 73) game->score += (int) pow(2,9);
                if(game->board[i][3] == 74) game->score += (int) pow(2,10);
                if(game->board[i][3] == 74) game->score += (int) pow(2,11);

            }
            else if(game->board[i][1] == game->board[i][2] && game->board[i][2] != 32) {

                game->board[i][2]++;
                game->board[i][1] = 32;

                if(game->board[i][2] == 66) game->score += (int)pow(2,2);
                if(game->board[i][2] == 67) game->score += (int)pow(2,3);
                if(game->board[i][2] == 68) game->score += (int)pow(2,4);
                if(game->board[i][2] == 69) game->score += (int)pow(2,5);
                if(game->board[i][2] == 70) game->score += (int)pow(2,6);
                if(game->board[i][2] == 71) game->score += (int)pow(2,7);
                if(game->board[i][2] == 72) game->score += (int)pow(2,8);
                if(game->board[i][2] == 73) game->score += (int)pow(2,9);
                if(game->board[i][2] == 74) game->score += (int)pow(2,10);
                if(game->board[i][2] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][0] == game->board[i][1] && game->board[i][0] != 32) {

                game->board[i][1]++;
                game->board[i][0] = 32;

                if(game->board[i][1] == 66) game->score += (int)pow(2,2);
                if(game->board[i][1] == 67) game->score += (int)pow(2,3);
                if(game->board[i][1] == 68) game->score += (int)pow(2,4);
                if(game->board[i][1] == 69) game->score += (int)pow(2,5);
                if(game->board[i][1] == 70) game->score += (int)pow(2,6);
                if(game->board[i][1] == 71) game->score += (int)pow(2,7);
                if(game->board[i][1] == 72) game->score += (int)pow(2,8);
                if(game->board[i][1] == 73) game->score += (int)pow(2,9);
                if(game->board[i][1] == 74) game->score += (int)pow(2,10);
                if(game->board[i][1] == 74) game->score += (int)pow(2,11);

            }

            /*
            int counter = 1;
            char arr[SIZE][SIZE];
//            for (int x = 0; x < SIZE; ++x) {
//                for (int y = 0; y < SIZE; ++y) {
//                    arr[x][y] = game->board[x][y];
//                }
//            }

            for (int t = SIZE - 1; t >= 0; t--) {
                if(t + counter >= SIZE){
                    game->board[t + counter - SIZE] = arr[t];
                }
                else{
                    game->board[t + counter] = arr[t];
                }
            }

            for (int k = SIZE - 1; k <= 0; --k) {
                if(game->board[i][k] == 32){
                    for (int j = 0; j < SIZE - counter; ++j) {
                        game->board[i][j] = game->board[i][j + 1];
                    }
                    counter++;
                }
            }

            for (int j = 0; j < SIZE; ++j) {
                if(game->board[i][j] != 32) {
                    for (int k = SIZE - 1; k <= 0; --k) {
                        if(game->board[i][k] == 32) game->board[i][j] = game->board[i][3];
                    }

                    game->board[i][j] = 32;
                }
            }
             */
            for (int j = 0; j < SIZE ; ++j) {
                for (int k = 0; k < SIZE; ++k) {
                    if(game->board[i][3] == 32 && game->board[i][2] != 32){
                        game->board[i][3] = game->board[i][2];
                        game->board[i][2] = 32;
                    }
                    else if(game->board[i][2] == 32 && game->board[i][1] != 32) {
                        game->board[i][2] = game->board[i][1];
                        game->board[i][1] = 32;
                    }
                    else if(game->board[i][1] == 32 && game->board[i][0] != 32) {
                        game->board[i][1] = game->board[i][0];
                        game->board[i][0] = 32;
                    }

                }

            }

        }
        return true;

    }


    if(dx == -1) {

        for (int i = 0; i < SIZE; ++i) {

            if (game->board[i][3] == game->board[i][0] && game->board[i][3] != 32 && game->board[i][2] == 32 && game->board[i][1] == 32) {

                game->board[i][0]++;
                game->board[i][3] = 32;

                if(game->board[i][0] == 66) game->score += (int)pow(2,2);
                if(game->board[i][0] == 67) game->score += (int)pow(2,3);
                if(game->board[i][0] == 68) game->score += (int)pow(2,4);
                if(game->board[i][0] == 69) game->score += (int)pow(2,5);
                if(game->board[i][0] == 70) game->score += (int)pow(2,6);
                if(game->board[i][0] == 71) game->score += (int)pow(2,7);
                if(game->board[i][0] == 72) game->score += (int)pow(2,8);
                if(game->board[i][0] == 73) game->score += (int)pow(2,9);
                if(game->board[i][0] == 74) game->score += (int)pow(2,10);
                if(game->board[i][0] == 74) game->score += (int)pow(2,11);
            }
            else if(game->board[i][2] == game->board[i][0] && game->board[i][2] != 32 && game->board[i][1] == 32 && game->board[i][3] != game->board[i][2]) {

                game->board[i][0]++;
                game->board[i][2] = 32;

                if(game->board[i][0] == 66) game->score += (int)pow(2,2);
                if(game->board[i][0] == 67) game->score += (int)pow(2,3);
                if(game->board[i][0] == 68) game->score += (int)pow(2,4);
                if(game->board[i][0] == 69) game->score += (int)pow(2,5);
                if(game->board[i][0] == 70) game->score += (int)pow(2,6);
                if(game->board[i][0] == 71) game->score += (int)pow(2,7);
                if(game->board[i][0] == 72) game->score += (int)pow(2,8);
                if(game->board[i][0] == 73) game->score += (int)pow(2,9);
                if(game->board[i][0] == 74) game->score += (int)pow(2,10);
                if(game->board[i][0] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][3] == game->board[i][1] && game->board[i][3] != game->board[i][0] && game->board[i][2] == 32 && game->board[i][3] != 32) {

                game->board[i][1]++;
                game->board[i][3] = 32;

                if(game->board[i][1] == 66) game->score += (int)pow(2,2);
                if(game->board[i][1] == 67) game->score += (int)pow(2,3);
                if(game->board[i][1] == 68) game->score += (int)pow(2,4);
                if(game->board[i][1] == 69) game->score += (int)pow(2,5);
                if(game->board[i][1] == 70) game->score += (int)pow(2,6);
                if(game->board[i][1] == 71) game->score += (int)pow(2,7);
                if(game->board[i][1] == 72) game->score += (int)pow(2,8);
                if(game->board[i][1] == 73) game->score += (int)pow(2,9);
                if(game->board[i][1] == 74) game->score += (int)pow(2,10);
                if(game->board[i][1] == 74) game->score += (int)pow(2,11);

            }
            else if((game->board[i][3] == game->board[i][2]) && (game->board[i][1] == game->board[i][0]) && game->board[i][3] != 32 && game->board[i][1] != 32) {

                game->board[i][0]++;
                game->board[i][2]++;
                game->board[i][3] = 32;
                game->board[i][1] = 32;

                if(game->board[i][0] == 66) game->score += (int)pow(2,2);
                if(game->board[i][0] == 67) game->score += (int)pow(2,3);
                if(game->board[i][0] == 68) game->score += (int)pow(2,4);
                if(game->board[i][0] == 69) game->score += (int)pow(2,5);
                if(game->board[i][0] == 70) game->score += (int)pow(2,6);
                if(game->board[i][0] == 71) game->score += (int)pow(2,7);
                if(game->board[i][0] == 72) game->score += (int)pow(2,8);
                if(game->board[i][0] == 73) game->score += (int)pow(2,9);
                if(game->board[i][0] == 74) game->score += (int)pow(2,10);
                if(game->board[i][0] == 74) game->score += (int)pow(2,11);

                if(game->board[i][2] == 66) game->score += (int)pow(2,2);
                if(game->board[i][2] == 67) game->score += (int)pow(2,3);
                if(game->board[i][2] == 68) game->score += (int)pow(2,4);
                if(game->board[i][2] == 69) game->score += (int)pow(2,5);
                if(game->board[i][2] == 70) game->score += (int)pow(2,6);
                if(game->board[i][2] == 71) game->score += (int)pow(2,7);
                if(game->board[i][2] == 72) game->score += (int)pow(2,8);
                if(game->board[i][2] == 73) game->score += (int)pow(2,9);
                if(game->board[i][2] == 74) game->score += (int)pow(2,10);
                if(game->board[i][2] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][1] == game->board[i][0] && game->board[i][1] != 32) {

                game->board[i][0]++;
                game->board[i][1] = 32;

                if(game->board[i][0] == 66) game->score += (int)pow(2,2);
                if(game->board[i][0] == 67) game->score += (int)pow(2,3);
                if(game->board[i][0] == 68) game->score += (int)pow(2,4);
                if(game->board[i][0] == 69) game->score += (int)pow(2,5);
                if(game->board[i][0] == 70) game->score += (int)pow(2,6);
                if(game->board[i][0] == 71) game->score += (int)pow(2,7);
                if(game->board[i][0] == 72) game->score += (int)pow(2,8);
                if(game->board[i][0] == 73) game->score += (int)pow(2,9);
                if(game->board[i][0] == 74) game->score += (int)pow(2,10);
                if(game->board[i][0] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][2] == game->board[i][1] && game->board[i][1] != 32) {

                game->board[i][1]++;
                game->board[i][2] = 32;

                if(game->board[i][1] == 66) game->score += (int)pow(2,2);
                if(game->board[i][1] == 67) game->score += (int)pow(2,3);
                if(game->board[i][1] == 68) game->score += (int)pow(2,4);
                if(game->board[i][1] == 69) game->score += (int)pow(2,5);
                if(game->board[i][1] == 70) game->score += (int)pow(2,6);
                if(game->board[i][1] == 71) game->score += (int)pow(2,7);
                if(game->board[i][1] == 72) game->score += (int)pow(2,8);
                if(game->board[i][1] == 73) game->score += (int)pow(2,9);
                if(game->board[i][1] == 74) game->score += (int)pow(2,10);
                if(game->board[i][1] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[i][3] == game->board[i][2] && game->board[i][3] != 32) {

                game->board[i][2]++;
                game->board[i][3] = 32;

                if(game->board[i][2] == 66) game->score += (int)pow(2,2);
                if(game->board[i][2] == 67) game->score += (int)pow(2,3);
                if(game->board[i][2] == 68) game->score += (int)pow(2,4);
                if(game->board[i][2] == 69) game->score += (int)pow(2,5);
                if(game->board[i][2] == 70) game->score += (int)pow(2,6);
                if(game->board[i][2] == 71) game->score += (int)pow(2,7);
                if(game->board[i][2] == 72) game->score += (int)pow(2,8);
                if(game->board[i][2] == 73) game->score += (int)pow(2,9);
                if(game->board[i][2] == 74) game->score += (int)pow(2,10);
                if(game->board[i][2] == 74) game->score += (int)pow(2,11);

            }

            for (int j = 0; j < SIZE ; ++j) {
                for (int k = 0; k < SIZE; ++k) {
                    if(game->board[i][0] == 32 && game->board[i][1] != 32){
                        game->board[i][0] = game->board[i][1];
                        game->board[i][1] = 32;
                    }
                    else if(game->board[i][1] == 32 && game->board[i][2] != 32) {
                        game->board[i][1] = game->board[i][2];
                        game->board[i][2] = 32;
                    }
                    else if(game->board[i][2] == 32 && game->board[i][3] != 32) {
                        game->board[i][2] = game->board[i][3];
                        game->board[i][3] = 32;
                    }

                }

            }

        }
        return true;

    }


    if(dy == -1) {

        for (int i = 0; i < SIZE; ++i) {

            if (game->board[3][i] == game->board[0][i] && game->board[3][i] != 32 && game->board[2][i] == 32 && game->board[1][i] == 32) {

                game->board[0][i]++;
                game->board[3][i] = 32;

                if(game->board[0][i] == 66) game->score += (int)pow(2,2);
                if(game->board[0][i] == 67) game->score += (int)pow(2,3);
                if(game->board[0][i] == 68) game->score += (int)pow(2,4);
                if(game->board[0][i] == 69) game->score += (int)pow(2,5);
                if(game->board[0][i] == 70) game->score += (int)pow(2,6);
                if(game->board[0][i] == 71) game->score += (int)pow(2,7);
                if(game->board[0][i] == 72) game->score += (int)pow(2,8);
                if(game->board[0][i] == 73) game->score += (int)pow(2,9);
                if(game->board[0][i] == 74) game->score += (int)pow(2,10);
                if(game->board[0][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[2][i] == game->board[0][i] && game->board[2][i] != 32 && game->board[1][i] == 32 && game->board[3][i] != game->board[2][i]) {

                game->board[0][i]++;
                game->board[2][i] = 32;

                if(game->board[0][i] == 66) game->score += (int)pow(2,2);
                if(game->board[0][i] == 67) game->score += (int)pow(2,3);
                if(game->board[0][i] == 68) game->score += (int)pow(2,4);
                if(game->board[0][i] == 69) game->score += (int)pow(2,5);
                if(game->board[0][i] == 70) game->score += (int)pow(2,6);
                if(game->board[0][i] == 71) game->score += (int)pow(2,7);
                if(game->board[0][i] == 72) game->score += (int)pow(2,8);
                if(game->board[0][i] == 73) game->score += (int)pow(2,9);
                if(game->board[0][i] == 74) game->score += (int)pow(2,10);
                if(game->board[0][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[3][i] == game->board[1][i] && game->board[3][i] != game->board[0][i] && game->board[2][i] == 32 && game->board[3][i] != 32) {

                game->board[1][i]++;
                game->board[3][i] = 32;

                if(game->board[1][i] == 66) game->score += (int)pow(2,2);
                if(game->board[1][i] == 67) game->score += (int)pow(2,3);
                if(game->board[1][i] == 68) game->score += (int)pow(2,4);
                if(game->board[1][i] == 69) game->score += (int)pow(2,5);
                if(game->board[1][i] == 70) game->score += (int)pow(2,6);
                if(game->board[1][i] == 71) game->score += (int)pow(2,7);
                if(game->board[1][i] == 72) game->score += (int)pow(2,8);
                if(game->board[1][i] == 73) game->score += (int)pow(2,9);
                if(game->board[1][i] == 74) game->score += (int)pow(2,10);
                if(game->board[1][i] == 74) game->score += (int)pow(2,11);

            }
            else if((game->board[3][i] == game->board[2][i]) && (game->board[1][i] == game->board[0][i]) && game->board[3][i] != 32) {

                game->board[2][i]++;
                game->board[0][i]++;
                game->board[3][i] = 32;
                game->board[1][i] = 32;

                if(game->board[0][i] == 66) game->score += (int)pow(2,2);
                if(game->board[0][i] == 67) game->score += (int)pow(2,3);
                if(game->board[0][i] == 68) game->score += (int)pow(2,4);
                if(game->board[0][i] == 69) game->score += (int)pow(2,5);
                if(game->board[0][i] == 70) game->score += (int)pow(2,6);
                if(game->board[0][i] == 71) game->score += (int)pow(2,7);
                if(game->board[0][i] == 72) game->score += (int)pow(2,8);
                if(game->board[0][i] == 73) game->score += (int)pow(2,9);
                if(game->board[0][i] == 74) game->score += (int)pow(2,10);
                if(game->board[0][i] == 74) game->score += (int)pow(2,11);

                if(game->board[2][i] == 66) game->score += (int)pow(2,2);
                if(game->board[2][i] == 67) game->score += (int)pow(2,3);
                if(game->board[2][i] == 68) game->score += (int)pow(2,4);
                if(game->board[2][i] == 69) game->score += (int)pow(2,5);
                if(game->board[2][i] == 70) game->score += (int)pow(2,6);
                if(game->board[2][i] == 71) game->score += (int)pow(2,7);
                if(game->board[2][i] == 72) game->score += (int)pow(2,8);
                if(game->board[2][i] == 73) game->score += (int)pow(2,9);
                if(game->board[2][i] == 74) game->score += (int)pow(2,10);
                if(game->board[2][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[1][i] == game->board[0][i] && game->board[1][i] != 32) {

                game->board[0][i]++;
                game->board[1][i] = 32;

                if(game->board[0][i] == 66) game->score += (int)pow(2,2);
                if(game->board[0][i] == 67) game->score += (int)pow(2,3);
                if(game->board[0][i] == 68) game->score += (int)pow(2,4);
                if(game->board[0][i] == 69) game->score += (int)pow(2,5);
                if(game->board[0][i] == 70) game->score += (int)pow(2,6);
                if(game->board[0][i] == 71) game->score += (int)pow(2,7);
                if(game->board[0][i] == 72) game->score += (int)pow(2,8);
                if(game->board[0][i] == 73) game->score += (int)pow(2,9);
                if(game->board[0][i] == 74) game->score += (int)pow(2,10);
                if(game->board[0][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[2][i] == game->board[1][i] && game->board[1][i] != 32) {

                game->board[1][i]++;
                game->board[2][i] = 32;

                if(game->board[1][i] == 66) game->score += (int)pow(2,2);
                if(game->board[1][i] == 67) game->score += (int)pow(2,3);
                if(game->board[1][i] == 68) game->score += (int)pow(2,4);
                if(game->board[1][i] == 69) game->score += (int)pow(2,5);
                if(game->board[1][i] == 70) game->score += (int)pow(2,6);
                if(game->board[1][i] == 71) game->score += (int)pow(2,7);
                if(game->board[1][i] == 72) game->score += (int)pow(2,8);
                if(game->board[1][i] == 73) game->score += (int)pow(2,9);
                if(game->board[1][i] == 74) game->score += (int)pow(2,10);
                if(game->board[1][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[3][i] == game->board[2][i] && game->board[3][i] != 32) {

                game->board[2][i]++;
                game->board[3][i] = 32;

                if(game->board[2][i] == 66) game->score += (int)pow(2,2);
                if(game->board[2][i] == 67) game->score += (int)pow(2,3);
                if(game->board[2][i] == 68) game->score += (int)pow(2,4);
                if(game->board[2][i] == 69) game->score += (int)pow(2,5);
                if(game->board[2][i] == 70) game->score += (int)pow(2,6);
                if(game->board[2][i] == 71) game->score += (int)pow(2,7);
                if(game->board[2][i] == 72) game->score += (int)pow(2,8);
                if(game->board[2][i] == 73) game->score += (int)pow(2,9);
                if(game->board[2][i] == 74) game->score += (int)pow(2,10);
                if(game->board[2][i] == 74) game->score += (int)pow(2,11);

            }

            for (int j = 0; j < SIZE ; ++j) {
                for (int k = 0; k < SIZE; ++k) {
                    if(game->board[0][i] == 32 && game->board[1][i] != 32){
                        game->board[0][i] = game->board[1][i];
                        game->board[1][i] = 32;
                    }
                    else if(game->board[1][i] == 32 && game->board[2][i] != 32) {
                        game->board[1][i] = game->board[2][i];
                        game->board[2][i] = 32;
                    }
                    else if(game->board[2][i] == 32 && game->board[3][i] != 32) {
                        game->board[2][i] = game->board[3][i];
                        game->board[3][i] = 32;
                    }

                }

            }

        }
        return true;

    }


    if(dy == 1) {

        for (int i = 0; i < SIZE; ++i) {

            if (game->board[0][i] == game->board[3][i] && game->board[0][i] != 32 && game->board[1][i] == 32 && game->board[2][i] == 32) {

                game->board[3][i]++;
                game->board[0][i] = 32;

                if(game->board[3][i] == 66) game->score += (int)pow(2,2);
                if(game->board[3][i] == 67) game->score += (int)pow(2,3);
                if(game->board[3][i] == 68) game->score += (int)pow(2,4);
                if(game->board[3][i] == 69) game->score += (int)pow(2,5);
                if(game->board[3][i] == 70) game->score += (int)pow(2,6);
                if(game->board[3][i] == 71) game->score += (int)pow(2,7);
                if(game->board[3][i] == 72) game->score += (int)pow(2,8);
                if(game->board[3][i] == 73) game->score += (int)pow(2,9);
                if(game->board[3][i] == 74) game->score += (int)pow(2,10);
                if(game->board[3][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[1][i] == game->board[3][i] && game->board[1][i] != 32 && game->board[2][i] == 32 && game->board[0][i] != game->board[1][i]) {

                game->board[3][i]++;
                game->board[1][i] = 32;

                if(game->board[3][i] == 66) game->score += (int)pow(2,2);
                if(game->board[3][i] == 67) game->score += (int)pow(2,3);
                if(game->board[3][i] == 68) game->score += (int)pow(2,4);
                if(game->board[3][i] == 69) game->score += (int)pow(2,5);
                if(game->board[3][i] == 70) game->score += (int)pow(2,6);
                if(game->board[3][i] == 71) game->score += (int)pow(2,7);
                if(game->board[3][i] == 72) game->score += (int)pow(2,8);
                if(game->board[3][i] == 73) game->score += (int)pow(2,9);
                if(game->board[3][i] == 74) game->score += (int)pow(2,10);
                if(game->board[3][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[0][i] == game->board[2][i] && game->board[0][i] != game->board[3][i] && game->board[1][i] == 32 && game->board[2][i] != 32) {

                game->board[2][i]++;
                game->board[0][i] = 32;

                if(game->board[2][i] == 66) game->score += (int)pow(2,2);
                if(game->board[2][i] == 67) game->score += (int)pow(2,3);
                if(game->board[2][i] == 68) game->score += (int)pow(2,4);
                if(game->board[2][i] == 69) game->score += (int)pow(2,5);
                if(game->board[2][i] == 70) game->score += (int)pow(2,6);
                if(game->board[2][i] == 71) game->score += (int)pow(2,7);
                if(game->board[2][i] == 72) game->score += (int)pow(2,8);
                if(game->board[2][i] == 73) game->score += (int)pow(2,9);
                if(game->board[2][i] == 74) game->score += (int)pow(2,10);
                if(game->board[2][i] == 74) game->score += (int)pow(2,11);

            }
            else if ((game->board[0][i] == game->board[1][i]) && (game->board[2][i] == game->board[3][i]) && game->board[0][i] != 32) {

                game->board[1][i]++;
                game->board[3][i]++;
                game->board[0][i] = 32;
                game->board[2][i] = 32;

                if(game->board[3][i] == 66) game->score += (int)pow(2,2);
                if(game->board[3][i] == 67) game->score += (int)pow(2,3);
                if(game->board[3][i] == 68) game->score += (int)pow(2,4);
                if(game->board[3][i] == 69) game->score += (int)pow(2,5);
                if(game->board[3][i] == 70) game->score += (int)pow(2,6);
                if(game->board[3][i] == 71) game->score += (int)pow(2,7);
                if(game->board[3][i] == 72) game->score += (int)pow(2,8);
                if(game->board[3][i] == 73) game->score += (int)pow(2,9);
                if(game->board[3][i] == 74) game->score += (int)pow(2,10);
                if(game->board[3][i] == 74) game->score += (int)pow(2,11);

                if(game->board[1][i] == 66) game->score += (int)pow(2,2);
                if(game->board[1][i] == 67) game->score += (int)pow(2,3);
                if(game->board[1][i] == 68) game->score += (int)pow(2,4);
                if(game->board[1][i] == 69) game->score += (int)pow(2,5);
                if(game->board[1][i] == 70) game->score += (int)pow(2,6);
                if(game->board[1][i] == 71) game->score += (int)pow(2,7);
                if(game->board[1][i] == 72) game->score += (int)pow(2,8);
                if(game->board[1][i] == 73) game->score += (int)pow(2,9);
                if(game->board[1][i] == 74) game->score += (int)pow(2,10);
                if(game->board[1][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[2][i] == game->board[3][i] && game->board[2][i] != 32) {

                game->board[3][i]++;
                game->board[2][i] = 32;

                if(game->board[3][i] == 66) game->score += (int)pow(2,2);
                if(game->board[3][i] == 67) game->score += (int)pow(2,3);
                if(game->board[3][i] == 68) game->score += (int)pow(2,4);
                if(game->board[3][i] == 69) game->score += (int)pow(2,5);
                if(game->board[3][i] == 70) game->score += (int)pow(2,6);
                if(game->board[3][i] == 71) game->score += (int)pow(2,7);
                if(game->board[3][i] == 72) game->score += (int)pow(2,8);
                if(game->board[3][i] == 73) game->score += (int)pow(2,9);
                if(game->board[3][i] == 74) game->score += (int)pow(2,10);
                if(game->board[3][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[1][i] == game->board[2][i] && game->board[2][i] != 32) {

                game->board[2][i]++;
                game->board[1][i] = 32;

                if(game->board[2][i] == 66) game->score += (int)pow(2,2);
                if(game->board[2][i] == 67) game->score += (int)pow(2,3);
                if(game->board[2][i] == 68) game->score += (int)pow(2,4);
                if(game->board[2][i] == 69) game->score += (int)pow(2,5);
                if(game->board[2][i] == 70) game->score += (int)pow(2,6);
                if(game->board[2][i] == 71) game->score += (int)pow(2,7);
                if(game->board[2][i] == 72) game->score += (int)pow(2,8);
                if(game->board[2][i] == 73) game->score += (int)pow(2,9);
                if(game->board[2][i] == 74) game->score += (int)pow(2,10);
                if(game->board[2][i] == 74) game->score += (int)pow(2,11);

            }
            else if(game->board[0][i] == game->board[1][i] && game->board[0][i] != 32) {

                game->board[1][i]++;
                game->board[0][i] = 32;

                if(game->board[1][i] == 66) game->score += (int)pow(2,2);
                if(game->board[1][i] == 67) game->score += (int)pow(2,3);
                if(game->board[1][i] == 68) game->score += (int)pow(2,4);
                if(game->board[1][i] == 69) game->score += (int)pow(2,5);
                if(game->board[1][i] == 70) game->score += (int)pow(2,6);
                if(game->board[1][i] == 71) game->score += (int)pow(2,7);
                if(game->board[1][i] == 72) game->score += (int)pow(2,8);
                if(game->board[1][i] == 73) game->score += (int)pow(2,9);
                if(game->board[1][i] == 74) game->score += (int)pow(2,10);
                if(game->board[1][i] == 74) game->score += (int)pow(2,11);

            }

            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < SIZE; ++k) {
                    if (game->board[3][i] == 32 && game->board[2][i] != 32) {
                        game->board[3][i] = game->board[2][i];
                        game->board[2][i] = 32;
                    } else if (game->board[2][i] == 32 && game->board[1][i] != 32) {
                        game->board[2][i] = game->board[1][i];
                        game->board[1][i] = 32;
                    } else if (game->board[1][i] == 32 && game->board[0][i] != 32) {
                        game->board[1][i] = game->board[0][i];
                        game->board[0][i] = 32;
                    }

                }

            }

        }
        return true;

    }

    return false;

}