#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

int main() {
    srand(time(NULL));
    char ww[43];
    get_word(ww);
    hangman(ww);
    return 0;
}
