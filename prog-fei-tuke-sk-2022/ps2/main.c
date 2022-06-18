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
#include "k.h"
#include "ui.h"
#include "hof.h"

int main() {

    struct game game = {
            .score=8667,
            .board={
                    {' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' '}
            }};

    add_random_tile(&game);
    add_random_tile(&game);

    struct player list[10];
    int size = load(list);

    for (int i = 0; i < size; ++i) {
        int u = 0;
        while (list[i].name[u] != 0) u++;

        for (int j = 0; j < u; ++j) {
            printf("%c", list[i].name[j]);
        }
        printf(" - %d\n", list[i].score);
    }

    printf("list size: %d\n", size);

    printf("is won: %d\n", is_game_won(game));
// stdout: 1
    printf("is move possible: %d\n", is_move_possible(game));

    printf("save to draft2.txt: %d\n", save(list, size));

    // update(*game, 0, 1);
    // render(game);
// stdout: 1

    //    float player1 = 1200, player2 = 1000;
    //
    //    int K = 30;
    //    bool check = true;
    //    rating(player1, player2, K, check);

    // case 1: the list is empty

    //    struct player list[10];
    //    int size = 0;
    //    struct player player = {
    //            .name = "John",
    //            .score = 100
    //    };
    //
    //    bool result = add_player(list, &size, player);


    initscr();
    noecho();

    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, FALSE);
    start_color();

    init_pair(0, COLOR_BLUE, COLOR_BLUE);
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_RED);
    init_pair(4, COLOR_RED, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_WHITE);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);

    int input = 0;

    while(true) {

        render(game);
        input = (int) getch();

        if(input == KEY_RIGHT) {
            if (update(&game, 0, 1)) add_random_tile(&game);;
        }
        else if(input == KEY_LEFT) {
            if (update(&game, 0, -1)) add_random_tile(&game);;
        }
        else if(input == KEY_DOWN) {
            if (update(&game, 1, 0)) add_random_tile(&game);;
        }
        else if(input == KEY_UP) {
            if (update(&game, -1, 0)) add_random_tile(&game);;
        }

        if (!is_move_possible(game)) break;
    }
    endwin();

    printf("save to draft2.txt: %d\n", save(list, size));


    return 0;
}