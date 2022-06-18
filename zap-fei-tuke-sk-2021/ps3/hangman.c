#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/stat.h>

#include "hangman.h"


/**
 * * TUKE FUNCTION !!!
 * @param secret
 * @return
 *
int get_word(char secret[]){

    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    } while(1);

    fclose(fp);

    return 0;
}
 *
 * TUKE FUNCTION !!!
**/

int is_word_guessed(const char secret[], const char letters_guessed[]){
    int counter = 0;
    for (int i = 0; i < strlen(secret); i++) {
        for (int j = 0; j < strlen(letters_guessed); j++) {
            if(secret[i] == letters_guessed[j]){
                counter++;
                break;
            }
        }
    }
    if(strlen(secret) == counter) return 1;
    else return 0;
}


void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    bool p;
    for (int i = 0; i < strlen(secret); i++) {
        p = false;
        for (int j = 0; j < strlen(letters_guessed); j++) {
            if(secret[i] == letters_guessed[j]){
                p = true;
            }
        }

        if (p) {
            guessed_word[i] = secret[i];
        } else {
            guessed_word[i] = '_';
        }
    }

    guessed_word[strlen(secret)] = '\0';
}

void get_available_letters(const char letters_guessed[], char available_letters[]) {
    char alpha[33] = "abcdefghijklmnopqrstuvwxyz\0";
    char arrz[67];
    int cm = 28;
    bool jopa;
    for (int hui = 0; hui < (cm - 2); hui++) {
        jopa = false;
        for (int kurva = 0; kurva < strlen(letters_guessed); kurva++) {
            if (alpha[hui] == letters_guessed[kurva]) {
                jopa = true;
                break;
            }
        }

        if (jopa) {
            arrz[hui] = alpha[hui];
            // break;
        } else {
            arrz[hui] = '#';
            // break;
        }
        // printf("%c", arrz[hui]);
    }

    arrz[26] = '\0';

    // printf("\n");

    int gct = 0;

    for (int g = 0; g < (cm - 2); g++) {
        if (arrz[g] == '#') {
            available_letters[gct] = alpha[g];
            gct++;
        }
    }

    available_letters[gct] = '\0';
}


void hangman(const char secret[]){
    char uletters[34];
    char current_letters[39];
    char avl[52];
    uletters[0] = '\0';
    char gw[99];
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %ld letters long.\n", strlen(secret));
    printf("-------------\n");

    int attempts = 8;
    bool is_win = false;

    while (attempts > 0){
        if (is_word_guessed(secret, uletters) == 1) {
            is_win = true;
            break;
        }
        else {
            printf("You have %d guesses left.\n", attempts);
            get_available_letters(uletters, avl);
            printf("Available letters: %s\n", avl);
            printf("Please guess a letter: ");
            scanf("%s", current_letters);
            getchar();
            if (strlen(current_letters) == 1) {
                char cur_l = tolower(current_letters[0]);
                bool proof_data = false;
                for (int i = 0; i < strlen(uletters); i++) {
                    if (uletters[i] == cur_l) {
                        proof_data = true;
                        break;
                    }
                }
                if (proof_data) {
                    get_guessed_word(secret, uletters, gw);
                    char ty[33];
                    for (int i = 0; i < strlen(secret); i++) {
                        ty[i] = gw[i];
                    }

                    ty[strlen(gw)] = '\0';

                    // break;

                    int counter = 0;
                    for (int i = 0; i < strlen(secret) * 2; i += 2) {
                        gw[i] = ' ';
                        gw[i + 1] = ty[counter];
                        counter++;
                    }

                    // break;

                    gw[strlen(secret) * 2] = '\0';
                    printf("Oops! You've already guessed that letter:%s\n", gw);
                    printf("-------------\n");
                } else {
                    char abc[] = "abcdefghijklmnopqrstuvwxyz\0";
                    bool inv = false;
                    for (int i = 0; i < 26; i++) {
                        if (cur_l == abc[i]) {
                            inv = true;
                            break;
                        }
                    }
                    if (!inv) {
                        get_guessed_word(secret, uletters, gw);
                        char ty[33];
                        for (int i = 0; i < strlen(secret); i++) {
                            ty[i] = gw[i];
                        }

                        ty[strlen(gw)] = '\0';

                        // break;

                        int counter = 0;
                        for (int i = 0; i < strlen(secret) * 2; i += 2) {
                            gw[i] = ' ';
                            gw[i + 1] = ty[counter];
                            counter++;
                        }

                        // break;

                        gw[strlen(secret) * 2] = '\0';
                        printf("Oops! '%c' is not a valid letter:%s\n", cur_l, gw);
                        printf("-------------\n");
                    } else {
                        uletters[strlen(uletters)] = cur_l;
                        uletters[strlen(uletters) + 1] = '\0';
                        // break;
                        bool is_ins_secret = false;

                        get_guessed_word(secret, uletters, gw);

                        /**
                         * TODO: Spaces between each letter ("h_ll_" to " h _ l l _")
                         **/

                        // Your code here
                        char ty[33];
                        for (int i = 0; i < strlen(secret); i++) {
                            ty[i] = gw[i];
                        }

                        ty[strlen(gw)] = '\0';

                        // break;

                        int counter = 0;
                        for (int i = 0; i < strlen(secret) * 2; i += 2) {
                            gw[i] = ' ';
                            gw[i + 1] = ty[counter];
                            counter++;
                        }

                        // break;

                        gw[strlen(secret) * 2] = '\0';


                        /**
                         * EOF
                         */

                        for (int i = 0; i < strlen(secret); ++i) {
                            if (secret[i] == cur_l) {
                                is_ins_secret = true;
                                break;
                            }
                        }

                        if (is_ins_secret) {
                            printf("Good guess:%s\n", gw);
                            printf("-------------\n");
                        } else {
                            printf("Oops! That letter is not in my word:%s\n", gw);
                            printf("-------------\n");
                            attempts--;
                        }
                    }
                }
            } else {
                int bb = 0;
                for (int bbb = 0; bbb < strlen(secret); bbb++) {
                    if (current_letters[bbb] == secret[bbb]) {
                        bb++;
                    }
                }

                if (bb == strlen(secret)) {
                    is_win = true;
                    break;
                } else {
                    break;
                }
            }
        }
    }

    if (is_win) {
        printf("Congratulations, you won!\n");
    } else {
        if (attempts == 0) {
            // run out of guesses
            printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
        } else {
            // Single guess failed
            printf("Sorry, bad guess. The word was %s.\n", secret);
        }
    }
}