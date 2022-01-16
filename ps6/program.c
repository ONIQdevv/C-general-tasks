/////// ALL FUNCTIONS
/*
void start() – Inicializuje hru a nastavuje knižnicu ncurses;
void exit() – Tento funkcia ukončuje hru;
void field() – Kreslí Gamebar;
void clear_ground() – Funkcia vymaže obrazovku a vyplní ho medzerami;
void charakter_body(int y, int x, int is_damaged) – Nakreslí charaktera;
int y – Vertikálna súradnica (const);
int x – Horizontálne súradnice;
int is_damaged – Parameter je zodpovedný za kreslenie animácie, keď ju zasiahne v tašky;
void draw_rock(int x, int y), ---------||
void health_point(int x, int y),-------||
void invisible(int x, int y), ---------VV
void bucks(int x, int y) – Kreslí značky;
int y – Vertikálna súradnica kameňa;
int x – к Horizontálne súradnice;
void line_del(int l) – Vymaže konkrétny riadok jeho vyplnením medzerami. Keď kameň spadol dole;
void rock_del(int x, int y), ----------||
void minus_hp(int x, int y), -------------||
void remove_bucks(int x, int y), ---------VV
void no_invis(int x, int y) – Funkcie je opačné do draw_arrow(), health_points(), invisible(), bucks();

////////////////ELSE

int main(int argc, char* argv[]) – Hlavná funkcia programu;

*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <stdbool.h>
#include <time.h>
#include "colors.h"

// Initialize game ticks (1 tick = 10ms)
struct timespec ticks = {
        .tv_sec = 0,                    // nr of secs
        .tv_nsec = 0.01 * 1000000000L  // nr of nanosecs
};

// Setup ncurses
void start() {
    initscr();
    cbreak(); // Disable bufferization
    noecho(); // Comment for debug output

    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
}

// Restore terminal settings
void exits() {
    endwin();
}

// Draw interface
void fields () {
    mvprintw(0, 0, "+");

    for (int i = 1; i < COLS - 1; i++) mvprintw(0, i, "-");

    mvprintw(0, COLS - 1, "+");
    mvprintw(LINES - 1, 0, "+");

    for (int i = 1; i < COLS - 1; i++) mvprintw(LINES - 1, i, "-");
    for (int i = 1; i < COLS - 1; i++) mvprintw(4, i, "-");

    mvprintw(LINES - 1, COLS - 1, "+");
    mvprintw(1, 24, "|");
    mvprintw(2, 24, "|");
    mvprintw(3, 24, "|");

    for (int i = 1; i < LINES - 1; i++) mvprintw(i, 0, "|");
    for (int i = 1; i < LINES - 1; i++) mvprintw(i, COLS - 1, "|");
}
void clear_ground() {
    for (int i = 0; i < LINES; i++) for (int j = 0; j < COLS; j++) mvprintw(i, j, " ");
}

// Animations
void character_body(int y, int x, int is_damaged, int is_boosted) {
    if (is_damaged == 0 || (is_damaged > 10 && is_damaged < 20) || (is_damaged > 30 && is_damaged < 40) || is_damaged > 50) { // Default behavior
        if (is_boosted > 0) { //default
            move(y - 1, x);
            attron(COLOR_PAIR(2));
            printw("_");
            move(y - 1, x + 1);
            attron(COLOR_PAIR(2));
            printw("_");
            move(y - 1, x - 1);
            attron(COLOR_PAIR(2));
            printw("_");
            move(y - 1, x - 2);
            attron(COLOR_PAIR(2));
            printw("\\");
            move(y - 1, x + 2);
            attron(COLOR_PAIR(2));
            printw("/");
            refresh();
        } else { // boost
            move(y - 1, x);
            attron(COLOR_PAIR(2));
            printw("_");
            move(y - 1, x + 1);
            attron(COLOR_PAIR(2));
            printw("_");
            move(y - 1, x - 1);
            attron(COLOR_PAIR(2));
            printw("_");
            move(y - 1, x - 2);
            attron(COLOR_PAIR(2));
            printw("\\");
            move(y - 1, x + 2);
            attron(COLOR_PAIR(2));
            printw("/");
            refresh();
        }
    } else { // Player damaged, blink animation
        move(y - 1, x);
        attron(COLOR_PAIR(2));
        printw("_");
        move(y - 1, x + 1);
        attron(COLOR_PAIR(2));
        printw("_");
        move(y - 1, x - 1);
        attron(COLOR_PAIR(2));
        printw("_");
        move(y - 1, x - 2);
        attron(COLOR_PAIR(2));
        printw("\\");
        move(y - 1, x + 2);
        attron(COLOR_PAIR(2));
        printw("/");
        refresh();
    }
}

void rock(int x, int y) {
    move(y, x);
    attron(COLOR_PAIR(1));
    printw("0");
    move(y - 1, x);
    printw(" ");
    attroff(COLOR_PAIR(1));
    refresh();
}

// It is required to fix a bug with disposed objects
void line_del(int l) {
    for (int i = 1; i < COLS - 1; ++i) mvprintw(l, i, " ");
}

void rock_del(int x, int y) {
    move(y, x);
    attron(COLOR_PAIR(1));
    printw(" ");
    move(y + 1, x);
    printw(" ");
    move(y + 2, x);
    printw(" ");
    attroff(COLOR_PAIR(1));
    refresh();
}

void health_points(int x, int y) {
    attron(COLOR_PAIR(3));
    mvprintw(y, x, "+");
    mvprintw(y - 1, x, " ");
    attroff(COLOR_PAIR(3));
}

void minus_hp(int x, int y) {
    mvprintw(y, x, " ");
    mvprintw(y - 1, x, " ");
}

void invisible(int x, int y) {
    attron(COLOR_PAIR(4));
    mvprintw(y, x, "?");
    mvprintw(y - 1, x, " ");
    attroff(COLOR_PAIR(4));
}

void no_invis(int x, int y) {
    mvprintw(y, x, " ");
    mvprintw(y - 1, x, " ");
}

void bucks(int x, int y) {
    attron(COLOR_PAIR(2));
    mvprintw(y, x, "$");
    mvprintw(y - 1, x, " ");
    attroff(COLOR_PAIR(2));
}

void remove_bucks(int x, int y) {
    mvprintw(y, x, " ");
    mvprintw(y - 1, x, " ");
}

int rocks_counting(int max_rrockss, int rock[max_rrockss][2]) {
    int rock_counter = 0;
    for (int i = 0; i < max_rrockss; ++i) {
        if (rock[i][0] != 0 && rock[i][1] != 0) rock_counter++;
    }
    return rock_counter;
}

int bucks_counting(int max_bucks, int bucks[max_bucks][2]) {
    int bucks_counting = 0;
    for (int i = 0; i < max_bucks; ++i) {
        if (bucks[i][0] != 0 && bucks[i][1] != 0) bucks_counting++;
    }
    return bucks_counting;
}

void game_field(int max_rrockss, int tick_speed, int rock_speed, int new_best, int diff_speed, int max_bbuckss, int player_speed) {
    int input; // Keyboard handler

    int rocks_number = 0; // Current number of rrockss on the screen
    int bucks_number = 0; // Current number of bbuckss on the screen
    int second = 0; // It is counter that counts ticks between changing difficulty
    int boost_seconds = 0; // It is counter that counts ticks between spawning boosts
    int boost_timer = 0; // Timer to count 10 seconds of boost
    int boost_chance = 0; // Boost spawn chance
    int new_rock = 0; // It is counter that counts ticks between spawning rrockss and coins
    int object_moves = 0; // It is counter that counts ticks between moving all objects
    int s_rock_speed = rock_speed; // Save current rrockss speed for the next game
    int x = COLS / 2; // Start position of the player (horizontal)
    int y = LINES - 6; // Start position of the player (vertical)
    int rrockss[max_rrockss][2]; // Info about rocks
    int bbuckss[max_bbuckss][2]; // Info about bucks
    int health_point[2] = {0, 0}; // Info about all hp
    int boosts[2] = {0, 0}; // Info about boosts

    // Initialize rrockss
    for (int i = 0; i < max_rrockss; ++i) for (int j = 0; j < 2; ++j) rrockss[i][j] = 0;
    // Initialize bbuckss
    for (int i = 0; i < max_bbuckss; ++i) for (int j = 0; j < 2; ++j) bbuckss[i][j] = 0;

    int shoots = 0;
    int score = 0; // Coins collected
    int is_damaged = 0; // Needs to draw damage animation

    // If game will over it will be changed to true
    bool game_over = false;

    // Prepare screen, draw character
    clear_ground();
    refresh();
    fields();
    character_body(y, x, 0, 0);

    // General game loop

    while (!game_over) {

        // Fix a bug

        line_del(LINES - 5);
        line_del(LINES - 4);
        line_del(LINES - 3);

        // Wait 1 game tick
        nanosleep(&ticks, NULL);

        // Get info about rrockss and bbuckss count
        rocks_number = rocks_counting(max_rrockss, rrockss);
        bucks_number = rocks_counting(max_bbuckss, bbuckss);

        // Draw boosts indicator
        attron(COLOR_PAIR(5));
        mvprintw(2, 26, "Boost: [                    ] (Arrows resistance)");
        attroff(COLOR_PAIR(5));
        refresh();

        if (boost_seconds == 10) {
            attron(COLOR_PAIR(3));
            mvprintw(2, 34, "####################");
            attroff(COLOR_PAIR(3));
            refresh();
        } else if (boost_seconds == 9) {
            attron(COLOR_PAIR(3));
            mvprintw(2, 34, "##################  ");
            attroff(COLOR_PAIR(3));
            refresh();
        } else if (boost_seconds == 8) {
            attron(COLOR_PAIR(3));
            mvprintw(2, 34, "################    ");
            attroff(COLOR_PAIR(3));
            refresh();
        } else if (boost_seconds == 7) {
            attron(COLOR_PAIR(3));
            mvprintw(2, 34, "##############      ");
            attroff(COLOR_PAIR(3));
            refresh();
        } else if (boost_seconds == 6) {
            attron(COLOR_PAIR(3));
            mvprintw(2, 34, "############        ");
            attroff(COLOR_PAIR(3));
            refresh();
        } else if (boost_seconds == 5) {
            attron(COLOR_PAIR(3));
            mvprintw(2, 34, "##########          ");
            attroff(COLOR_PAIR(3));
            refresh();
        } else if (boost_seconds == 4) {
            attron(COLOR_PAIR(2));
            mvprintw(2, 34, "########            ");
            attroff(COLOR_PAIR(2));
            refresh();
        } else if (boost_seconds == 3) {
            attron(COLOR_PAIR(2));
            mvprintw(2, 34, "######              ");
            attroff(COLOR_PAIR(2));
            refresh();
        } else if (boost_seconds == 2) {
            attron(COLOR_PAIR(1));
            mvprintw(2, 34, "####                ");
            attroff(COLOR_PAIR(1));
            refresh();
        } else if (boost_seconds == 1) {
            attron(COLOR_PAIR(1));
            mvprintw(2, 34, "##                  ");
            attroff(COLOR_PAIR(1));
            refresh();
        } else if (boost_seconds == 0) {
            attron(COLOR_PAIR(1));
            mvprintw(2, 34, "                    ");
            attroff(COLOR_PAIR(1));
            refresh();
        }

        // Work with boosts
        if (boost_timer >= 100) {
            if (boost_seconds > 0) boost_seconds--;
            boost_timer = 0;
        }

        // Draw and move objects
        if (new_rock == tick_speed) {
            if (rocks_number < max_rrockss) {
                int rand_x = rand() % (COLS - 8) + 4;
                rock(rand_x, 5);

                int get_empty_rock = 0;
                for (int i = 0; i < max_rrockss; ++i) {
                    if (rrockss[i][0] == 0 && rrockss[i][1] == 0) break;
                    get_empty_rock++;
                }
                rrockss[get_empty_rock][0] = rand_x;
                rrockss[get_empty_rock][1] = 5;
            }

            if (bucks_number < max_bbuckss) {
                int rand_x = rand() % (COLS - 8) + 4;
                bucks(rand_x, 5);

                int get_empty_bucks = 0;
                for (int i = 0; i < max_bbuckss; ++i) {
                    if (bbuckss[i][0] == 0 && bbuckss[i][1] == 0) break;
                    get_empty_bucks++;
                }
                bbuckss[get_empty_bucks][0] = rand_x;
                bbuckss[get_empty_bucks][1] = 5;
            }
            new_rock = 0;
        }

        if (health_point[0] == 0) {
            int rand_x = rand() % (COLS - 8) + 4;
            health_point[0] = rand_x;
            health_point[1] = 5;
            health_points(health_point[0], health_point[1]);
        }

        if (boost_chance >= 1200) {
            if (boosts[0] == 0) {
                int rand_x = rand() % (COLS - 8) + 4;
                boosts[0] = rand_x;
                boosts[1] = 5;
                invisible(boosts[0], boosts[1]);
            }
            boost_chance = 0;
        }

        // Animate character
        if (is_damaged >= 1 && is_damaged <= 50) {
            if (is_damaged == 50) {
                is_damaged = 0;
            } else {
                is_damaged++;
            }
        }

        // Objects behavior
        if (rock_speed == object_moves) {
            for (int i = 0; i < max_rrockss; ++i) {
                if (rrockss[i][1] != 0 && rrockss[i][0] != 0 && rrockss[i][1] <= LINES - 4) {
                    rrockss[i][1] = rrockss[i][1] + 1;
                    rock(rrockss[i][0], rrockss[i][1]);
                }

                // Detect collisions
                if ((rrockss[i][0] == x && rrockss[i][1] == y) || (rrockss[i][0] == x - 1 && rrockss[i][1] == y) || (rrockss[i][0] == x - 2 && rrockss[i][1] == y) || (rrockss[i][0] == x - 3 && rrockss[i][1] == y) || (rrockss[i][0] == x + 1 && rrockss[i][1] == y) || (rrockss[i][0] == x + 2 && rrockss[i][1] == y) || (rrockss[i][0] == x + 3 && rrockss[i][1] == y)) {
                    rock_del(rrockss[i][0], rrockss[i][1]);
                    rrockss[i][0] = 0;
                    rrockss[i][1] = 0;
                    if (boost_seconds <= 0) {
                        is_damaged = 1;
                        line_del(LINES - 6);
                        line_del(LINES - 7);
                        character_body(y, x, is_damaged, boost_seconds);
                        shoots++;
                        boost_seconds = 0;
                    }
                }

                if (rrockss[i][1] > LINES - 4) {
                    rock_del(rrockss[i][0], rrockss[i][1]);
                    rrockss[i][0] = 0;
                    rrockss[i][1] = 0;
                }
            }

            for (int i = 0; i < max_bbuckss; ++i) {
                // Move object
                if (bbuckss[i][1] != 0 && bbuckss[i][0] != 0 && bbuckss[i][1] <= LINES - 4) {
                    bbuckss[i][1] = bbuckss[i][1] + 1;
                    bucks(bbuckss[i][0], bbuckss[i][1]);
                }

                // Detect collisions
                if ((bbuckss[i][0] == x && bbuckss[i][1] == y) || (bbuckss[i][0] == x - 1 && bbuckss[i][1] == y) || (bbuckss[i][0] == x - 2 && bbuckss[i][1] == y) || (bbuckss[i][0] == x - 3 && bbuckss[i][1] == y) || (bbuckss[i][0] == x + 1 && bbuckss[i][1] == y) || (bbuckss[i][0] == x + 2 && bbuckss[i][1] == y) || (bbuckss[i][0] == x + 3 && bbuckss[i][1] == y)) {
                    remove_bucks(bbuckss[i][0], bbuckss[i][1]);
                    bbuckss[i][0] = 0;
                    bbuckss[i][1] = 0;
                    score++;
                }

                // Dispose object
                if (bbuckss[i][1] > LINES - 4) {
                    remove_bucks(bbuckss[i][0], bbuckss[i][1]);
                    bbuckss[i][0] = 0;
                    bbuckss[i][1] = 0;
                }
            }

            // Move object
            if (health_point[1] != 0 && health_point[0] != 0 && health_point[1] <= LINES - 4) {
                health_point[1] = health_point[1] + 1;
                health_points(health_point[0], health_point[1]);
            }

            // Detect collisions
            if ((health_point[0] == x && health_point[1] == y) || (health_point[0] == x - 1 && health_point[1] == y) || (health_point[0] == x - 2 && health_point[1] == y) || (health_point[0] == x - 3 && health_point[1] == y) || (health_point[0] == x + 1 && health_point[1] == y) || (health_point[0] == x + 2 && health_point[1] == y) || (health_point[0] == x + 3 && health_point[1] == y)) {
                minus_hp(health_point[0], health_point[1]);
                health_point[0] = 0;
                health_point[1] = 0;
                if (shoots > -2) {
                    shoots--;
                }
            }

            // Dispose object
            if (health_point[1] > LINES - 4) {
                minus_hp(health_point[0], health_point[1]);
                health_point[0] = 0;
                health_point[1] = 0;
            }

            // Move object
            if (boosts[1] != 0 && boosts[0] != 0 && boosts[1] <= LINES - 4) {
                boosts[1] = boosts[1] + 1;
                invisible(boosts[0], boosts[1]);
            }

            // Detect collisions
            if ((boosts[0] == x && boosts[1] == y) || (boosts[0] == x - 1 && boosts[1] == y) || (boosts[0] == x - 2 && boosts[1] == y) || (boosts[0] == x - 3 && boosts[1] == y) || (boosts[0] == x + 1 && boosts[1] == y) || (boosts[0] == x + 2 && boosts[1] == y) || (boosts[0] == x + 3 && boosts[1] == y)) {
                no_invis(boosts[0], boosts[1]);
                boosts[0] = 0;
                boosts[1] = 0;
                boost_seconds = 10;
            }

            // Dispose object
            if (boosts[1] > LINES - 4) {
                no_invis(boosts[0], boosts[1]);
                boosts[0] = 0;
                boosts[1] = 0;
            }

            object_moves = 0;
            if (second >= diff_speed * 100 && rock_speed > 1 && tick_speed > 2) {
                second = 0;
                rock_speed--;
            }
        }

        // Drawing INFO
        mvprintw(1, 2, "Health:");
        mvprintw(2, 2, "Score:");
        attron(COLOR_PAIR(4));
        mvprintw(2, 9, "%d", score);
        attroff(COLOR_PAIR(4));
        mvprintw(3, 2, "Highest score:");
        attron(COLOR_PAIR(4));
        mvprintw(3, 17, "%d", new_best);
        attroff(COLOR_PAIR(4));
        refresh();

        // Draw health indicator
        if (shoots == -2) {
            attron(COLOR_PAIR(5));
            mvprintw(1, 10, "# # # # #");
            attroff(COLOR_PAIR(5));
            refresh();
        } else if (shoots == -1) {
            attron(COLOR_PAIR(4));
            mvprintw(1, 10, "# # # #  ");
            attroff(COLOR_PAIR(4));
            refresh();
        } else if (shoots == 0) {
            attron(COLOR_PAIR(3));
            mvprintw(1, 10, "# # #    ");
            attroff(COLOR_PAIR(3));
            refresh();
        } else if (shoots == 1) {
            attron(COLOR_PAIR(2));
            mvprintw(1, 10, "# #      ");
            attroff(COLOR_PAIR(2));
            refresh();
        } else if (shoots == 2) {
            attron(COLOR_PAIR(1));
            mvprintw(1, 10, "#        ");
            attroff(COLOR_PAIR(1));
            refresh();
        } else if (shoots == 3) {
            // Complete the game and stop game cycle
            attron(COLOR_PAIR(1));
            mvprintw(1, 10, "         ");
            attroff(COLOR_PAIR(1));
            game_over = true;
            clear_ground();
            mvprintw(2, 2, "Score:");
            attron(COLOR_PAIR(4));
            mvprintw(2, 9, "%d", score);
            attroff(COLOR_PAIR(4));
            mvprintw(3, 2, "Highest score:");
            attron(COLOR_PAIR(4));
            mvprintw(3, 17, "%d", new_best);
            attroff(COLOR_PAIR(4));
            refresh();
            break;
        }

        fields();
        input = getch(); // Handle input
        move(y, x);
        if (input == KEY_RIGHT) { // Move right
            fields();
            if (x + player_speed < COLS - 7) x += player_speed;
        } else if (input == KEY_LEFT) { // Move left
            fields();
            if (x - player_speed > 6) x -= player_speed;
        }

        // Fix bugs and draw character
        line_del(LINES - 6);
        line_del(LINES - 7);
        character_body(y, x, is_damaged, boost_seconds);

        // All counters count ticks
        new_rock++;
        object_moves++;
        second++;
        boost_timer++;
        boost_chance++;
    }

    // Show Game Over screen
    if (game_over) {
        fields();
        mvprintw(LINES / 2 - 1, COLS / 2 - 5, "Game over!");
        mvprintw(LINES / 2, COLS / 2 - 7, "Your score: %d", score);
        if (new_best < score) mvprintw(LINES / 2 + 1, COLS / 2 - 9, "Highest score: %d", score);
        else mvprintw(LINES / 2 + 1, COLS / 2 - 9, "Highest score: %d", new_best);
        mvprintw(LINES / 2 + 2, COLS / 2 - 20, "Press 'r' to play again and 'q' to exit");
        refresh();

        // If player do a best write his score to file "score.txt"
        if (new_best < score) {
            FILE *fp2 = fopen("best_score.txt", "w+");
            if(fp2 != NULL) {
                fprintf(fp2, "%d", score);
                fflush(fp2);
            }
            fclose(fp2);
            new_best = score;
        }

        // q&r func
        char next;
        bool replay = false;

        while (true) {
            next = getch();
            if (next == 'r') {
                replay = true;
                break;
            } else if (next == 'q') {
                break;
            }

            nanosleep(&ticks, NULL); // Unload computer resources
        }

        // Restart if "r"
        if (replay) {
            game_field(max_rrockss, tick_speed, s_rock_speed, new_best, diff_speed, max_bbuckss, player_speed);
            clear_ground();
            refresh();
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 7) {
        printf("Usage: ./program <Max arrows count> <Max beepers count> <Arrows speed (delay between arrow moves in ms)> <Array spawn delay in ms> <Speed of changing game difficulty in seconds> <Player's speed>\n");
        return 1;
    }

    srand(time(NULL));

    int new_best = 0;

    FILE *fp = fopen("score.txt", "r");

    char score_contents[15];

    // Get highest score from file "score.txt"
    if(fp != NULL){
        fscanf(fp, "%s", score_contents);

        new_best = atoi(score_contents);
        refresh();
        fclose(fp);
    }

    // Convert arguments to game params
    int max_rrockss = strtol(argv[1], NULL, 10);
    int max_bbuckss = strtol(argv[2], NULL, 10);
    int tick_speed = strtol(argv[4], NULL, 10) / 10;
    int rock_speed = strtol(argv[3], NULL, 10) / 10;
    int diff_speed = strtol(argv[5], NULL, 10);
    int speed = strtol(argv[6], NULL, 10);


    if (diff_speed <= 0) {
        printf("%sDifficulty changing speed must be greater than 0!%s\n", RED, RESET);
        return 1;
    }
    if (speed <= 0) {
        printf("%sPlayer's speed must be greater than 0!%s\n", RED, RESET);
        return 1;
    }
    start();
    game_field(max_rrockss, tick_speed, rock_speed, new_best, diff_speed, max_bbuckss, speed);
    exits();
    return 0;
}
