/** AUTHORED BY VOLODYMYR BOLGARIN ^_^
 *
 * TWITTER: @bolgarin_v
 * MY GITHUB IS: @ONIQdevv
 * STUDENT AT Technická univerzita v Košiciach -> FEI
 *
 * **/

///INCLUDES
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "hof.h"

/*bool add_player(struct player list[], int* size, const struct player player) {
    for (int i = 0; i < strlen(list->name); ++i) {

        if ((list->name[i] % 2 == 0) && (list->name[i] > list->name[i + 1])) {

            char let = list->name[i - 1];
            list->name[i - 1] = list->name[i];
            list->name[i] = let;

        }
        if ((list->name[i] % 2 == 1) && (list->name[i] > list->name[i + 1])) {

            char let = list->name[i - 1];
            list->name[i - 1] = list->name[i];
            list->name[i] = let;

        }

    }
    return true;
}*/

void bubble_sort(struct player list[], int size, const struct player player, int temp) {
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // for (int i = 0; i < size; ++i) list[i].score = player.score;
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    /*** Bubble Sort (^_^) ***/
    //^^^^^^^^^^^^^^^^^^^^^^^^^

    for (int t = 0 ; t < size - 1; ++t) {
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
        for (int j = 0 ; j < size - t - 1 ; ++j) {
            if (list[j].score < list[j + 1].score) {
//          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ^
                int let = list[j + 1].score;
                list[j + 1].score = list[j].score;
                list[j].score = let;

            }

        }

    }

    if(temp == 1) {}
}

int load(struct player list[]) {

    struct player empty = {
            .score = 0,
            .name = ""
    };

    FILE *f = fopen(HOF_FILE, "r");
    if (f == NULL) return -1;
    char alpha[999];
    for (int i = 0; i < 999; ++i) alpha[i] = 0;
        int x = 0;
        while (true) {
            alpha[x] = (char) fgetc(f);

            if (feof(f)) break;
            x++;
        }

    // printf("%s\n", alpha);

    int lsize = 0;
    int xsize = 0;
    while (alpha[xsize] != 0) {
        if (alpha[xsize] == '\n') {
            lsize++;
        }
        xsize++;
    }

    // printf("%d %d\n", xsize, lsize);

    if (lsize > 10) lsize = 10;
    int d = 0;

    for (int i = 0; i < lsize; ++i) {
        int c = 0;
        int k = 0;
        for (int j = 0; j < 30; ++j) {
            list[i].name[i] = 0;
        }
        while (alpha[d] != ' ') {
            list[i].name[c] = alpha[d];
            c++;
            d++;
        }

        d++;

        char sc[6];
        for (int j = 0; j < 6; ++j) {
            sc[j] = 0;
        }

        while (alpha[d] != '\n') {
            sc[k] = alpha[d];
            k++;
            d++;
        }
        d++;

        list[i].score = atoi(sc);
    }

    fclose(f);

    bubble_sort(list, lsize, empty, 0);

    return lsize;
}
//bool add_player(struct player list[], int* size, const struct player player) {
//    if(*size < 10) {
//
//        int counter = 0;
//
//        for (int i = 0; i < 30; ++i) {
//
//            list[*size - 1].name[i] = 0;
//            while(list[*size - 1].name[i] != 0) counter++;
//
//        }
//
//        for (int i = 0; i < counter; ++i) list[*size - 1].name[i] = player.name[i];
//
//        bubble_sort(list, *size, player, 1);
//
//    } else {
//        if(player.score > list[9].score) {
//
//            list[9].score = player.score;
//            int counter = 0;
//
//            for (int i = 0; i < 30; ++i) {
//
//                list[9].name[i] = 0;
//                while(list[9].name[i] != 0) counter++;
//
//            }
//
//            for (int i = 0; i < counter; ++i) list[9].name[i] = player.name[i];
//
//        }
//    }
//
//    return false;
//}









bool save(const struct player list[], const int size) {
    FILE* hof_file = fopen(HOF_FILE, "r+");

    if (hof_file != NULL) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (list[i].name[j] != 0) {
                    fputc(list[i].name[j], hof_file);
                }
            }

            fputc(' ', hof_file);
            char number[6];
            for (int j = 0; j < 6; ++j) {
                number[j] = 0;
            }

            sprintf(number, "%d", list[i].score);

            for (int j = 0; j < 6; ++j) {
                if (number[j] != 0) {
                    fputc(number[j], hof_file);
                }
            }
            fputc('\n', hof_file);
        }
        fclose(hof_file);
        return true;
    }
    return false;
}




















//    char str[10][30], name[30];
//
//    FILE *f;
//    if((f = fopen ("score.txt", "r")) == NULL) return "EOF";
//    /** READING WORDS... **/
//    int counter = 0;
//
//    while (feof(f) == 0 || counter > 10) {
//
//        fscanf (f, "%s", name);
//        strcpy(str[counter], name);
//        counter++;
//
//    }
//    fclose(f);
//
//// for(i = 0; i < counter; ++i) printf("%s\n", str[i]);
//
//    putchar('\n');
//
//    /*** Bubble Sort (^_^) ***/
//
//    for(int i = 1; i < counter; ++i) {
//        for(int j = 0; j < counter - i; ++j) {
//            if(strcmp(str[j], str[j + 1]) > 0) {
//
//                strcpy(name, str[j]);
//                strcpy(str[j], str[j + 1]);
//                strcpy(str[j + 1], name);
//
//            }
//        }
//    }
//
//    // for(i = 0; i < counter; i++) printf("%s\n", str[i]);

