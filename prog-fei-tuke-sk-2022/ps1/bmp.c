/** AUTHORED BY VOLODYMYR BOLGARIN ^_^
 *
 * TWITTER: @bolgarin_v
 * MY GITHUB IS: @ONIQdevv
 * STUDENT AT Technická univerzita v Košiciach -> FEI
 *
 * **/

///INCLUDES
#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

////// DECRYPT
char* reverse(const char* text) {

    if(text == NULL) return NULL;
    if(text[0] == 0) return NULL;

    int length = 0;
    while (text[length] != 0){
        length++;
    }

    char textArr[length];

    for (int i = 0; i < length; ++i) {
        textArr[i] = toupper(text[length - i - 1]);
    }

    char* result = calloc(length, sizeof(char*));

    for (int i = 0; i < length; ++i) {
        result[i] = textArr[i];
    }

    return result;
}

char* vigenere_encrypt(const char* key, const char* text) {

    int text_length = 0;
    int key_length = 0;
    int position = 0;
    char keyArr[500];
    char textArr[500];
    char output[500];

    for (int i = 0; i < 500; ++i) textArr[i] = 0;
    for (int i = 0; i < 500; ++i) keyArr[i] = 0;
    for (int i = 0; i < 500; ++i) output[i] = 0;

    while (text[text_length] != 0) {
        text_length++;
    }
    while (key[key_length] != 0) {
        key_length++;
    }
    for (int i = 0; i < text_length; ++i) textArr[i] = toupper(text[i]);


    int mLength = 0;

    for (int i = 0; i < text_length; ++i) if (textArr[i] > 65 && textArr[i] < 91) mLength++;
    for (int i = 0; i < text_length; ++i) {
        if (position == key_length) position = 0;

        keyArr[i] = toupper(key[position]);
        position++;
        printf("%c", keyArr[i]);
    }

    printf("\n");

    char field[26][26];
    char entry = 65;

    int mod = 0;

    for (int i = 0; i < 26; ++i) {
        entry = mod + 65;
        for (int j = 0; j < 26; ++j) {
            if (entry == 91) {
                entry = 65;

            }
            field[i][j] = entry;
            entry++;
            //printf("%c ", field[i][j]);

        }
        mod++;
        //printf("\n");
    }

    int x = 0;
    int y = 0;
    int a = 0;

    for (int i = 0; i < text_length; ++i) {
        if(textArr[i] >= 65 && textArr[i] <= 90) {

            for (int j = 0; j < 26; ++j) {
                if(textArr[i] == field[j][0]){
                    x = j;
                    break;
                }

            }

            for (int j = 0; j < 26; ++j) {
                if(keyArr[i-a] == field[0][j]){
                    y = j;
                    break;
                }

            }
            //printf("%c", field[x][y]);
            output[i] = field[x][y];

        } else {
            output[i] = textArr[i];
            a++;

        }

    }

    char* result = calloc(text_length, sizeof(char*));

    for (int i = 0; i < text_length; ++i) result[i] = output[i];

    return result;
}


