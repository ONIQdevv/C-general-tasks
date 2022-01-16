#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ballsortpuzzle.h"

void generator(const int rows, const int columns, char field[rows][columns]) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; ++j) {
            field[i][j] = 'G';
        }
    }

    int c1 = (rand() % columns);
    int c2 = (rand() % columns);
    while (c1 == c2) {
        c2 = (rand() % columns);
    }

    for (int i = 0; i < rows; i++) {
        field[i][c1] = ' ';
        field[i][c2] = ' ';
    }

    for (int i = 0; i < rows; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '^';
    }

    for (int i = 0; i < rows && columns > 3; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '@';
    }

    for (int i = 0; i < rows && columns > 4; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '+';
    }

    for (int i = 0; i < rows && columns > 5; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '*';
    }

    for (int i = 0; i < rows && columns > 6; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '$';
    }

    for (int i = 0; i < rows && columns > 7; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '&';
    }

    for (int i = 0; i < rows && columns > 8; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '#';
    }

    for (int i = 0; i < rows && columns > 9; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '.';
    }

    for (int i = 0; i < rows && columns > 10; i++) {
        int pos1 = (rand() % columns);
        int pos2 = (rand() % rows);
        while (field[pos2][pos1] != 'G'){
            pos1 = (rand() % columns);
            pos2 = (rand() % rows);
        }
        field[pos2][pos1] = '!';
    }

}

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y) {

    int p = x - 1;
    int q = y - 1;
    int y_pos1 = 0;
    int y_pos2 = 0;

    for (int i = 0; i < rows; ++i) {
        if(field[i][p] != 32) break;
        y_pos1++;
    }
    for (int j = 0; j < rows; ++j) {
        if(field[j][q] != 32) break;
        y_pos2++;
    }

    if (y_pos2 == rows - 1 && (field[y_pos2][q] == 0 || field[y_pos2][q] == 8)) y_pos2++;

    if(p >=0 && p < columns && q >= 0 && q < columns && q != p){
        if(y_pos2 == 0) printf("Hey! You can't do this move, please try again\n");
        else{
            if(y_pos2 == rows){
                field[y_pos2 - 1][q] = field[y_pos1][p];
                field[y_pos1][p] = 32;
                if(field[y_pos2 - 1][q] == 0 || field[y_pos2 - 1][q] == 8) field[y_pos2 - 1][q] = 32;
            }
            else{
                if(field[y_pos1][p] == field[y_pos2][q]){
                    field[y_pos2 - 1][q] = field[y_pos1][p];
                    field[y_pos1][p] = 32;
                    if(field[y_pos2 - 1][q] == 0 || field[y_pos2 - 1][q] == 8) field[y_pos2 - 1][q] = 32;
                }
                else{
                    printf("Hey! You can't do this move, please try again\n");
                }
            }
        }
    } else printf("Hey! You can't do this move, please try again\n");
}
bool check(const int rows, const int columns, char field[rows][columns]){
    int r_counter = 0;
    int s_counter = 0;
    for (int i = 0; i < columns; ++i) {
        char res = field[0][i];
        r_counter = 0;
        for (int j = 0; j < rows; ++j) {
            if(res == field[j][i]) {
                r_counter++;
            }
        }
        if(r_counter == rows) s_counter++;
    }
    return s_counter == columns ? true : false;
}
void game_field(const int rows, const int columns, char field[rows][columns]){


    //
    // Created by Teslasoft (Dmytro Ostapenko) on 11/11/2021.
    //

#ifndef COLORS_COLORS_H
#define COLORS_COLORS_H

#endif //COLORS_COLORS_H

    const char RED[8] = "\033[0;31m\0";
    const char YELLOW[8] = "\033[0;33m\0";
    const char GREEN[8] = "\033[0;32m\0";
    const char BLUE[8] = "\033[0;34m\0";
    const char MAGENTA[8] = "\033[0;35m\0";
    const char CYAN[8] = "\033[0;36m\0";
    const char WHITE[8] = "\033[0;37m\0";

    const char BOLD_GREEN[8] = "\033[1;32m\0";
    const char BOLD_BLUE[8] = "\033[1;34m\0";

    const char RESET[5] = "\033[0m\0";


    for (int i = 0; i < rows; i++) {
        printf("|");
        for (int j = 0; j < columns; j++) {
            if(field[i][j] == '@') printf(" %s0%s |", RED, RESET);
            else if(field[i][j] == '^') printf(" %s0%s |", GREEN, RESET);
            else if(field[i][j] == '+') printf(" %s0%s |", CYAN, RESET);
            else if(field[i][j] == '*') printf(" %s0%s |", YELLOW, RESET);
            else if(field[i][j] == '$') printf(" %s0%s |", MAGENTA, RESET);
            else if(field[i][j] == '.') printf(" %s0%s |", BLUE, RESET);
            else if(field[i][j] == '!') printf(" %s0%s |", WHITE, RESET);
            else if(field[i][j] == '&') printf(" %s0%s |", BOLD_BLUE, RESET);
            else if(field[i][j] == '#') printf(" %s0%s |", BOLD_GREEN, RESET);
            else printf(" %c |", field[i][j]);
        }

        printf("\n");
    }
    for (int l = 0; l < columns; l++) {
        printf("----");
    }
    printf("-");
    printf("\n");
    printf("  1");
    for (int l = 2; l < columns + 1; l++) {
        printf("   %d", l);
    }
    printf("\n");
    printf("\n");
}
void ball_sort_puzzle(){
    int rows = 4;
    int columns = 6;
    char field [rows][columns];
    generator(rows, columns, field);
    while (true){
        int y;
        int x;
        game_field(rows, columns, field);
        if(check(rows, columns, field)){
            break;
        }
        printf("Enter what: ");
        scanf("%d" , &x);
        getchar();
        printf("Enter where: ");
        scanf("%d" , &y);
        getchar();
        down_possible(rows, columns, field, x, y);
    }
    printf("YOU WON\n");

}
