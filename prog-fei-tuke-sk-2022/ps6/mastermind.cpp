#include <Arduino.h>
#include <avr/wdt.h>
#include <Wire.h>
#include <stdlib.h>
#include <string.h>
#include "lcd_wrapper.h"
#include "mastermind.h"

void render_leds_when_win() {
    
}

/**
 * Generate secret code
 * 
 * Generates secret code, which consists from digits only as a string. 
 * No two digits in the code combination can be same! Only if the repeat
 * parameter is set to true.
 * The length of generated code is set by the parameter length. If the given
 * parameter is less than 1, function will generate no code and returns NULL.
 * @param repeat if set to true, numbers in the generated code can repeat
 * @param length the length of the code
 * @return Pointer to the random generated code as string of given length. If length param is less than 1, return NULL.
 */
char* generate_code(bool repeat, int length) {

    if(length < 1) return NULL;
    char* key = malloc(sizeof(char) * length);

    for (int i = 0; i < length; ++i) {
        
        int offset = 48;

        if(repeat == 1) {
            for (int i = 0; i < length; i++) {
                randomSeed(analogRead(A2)); ///RANDOM INIT
                key[i] = (char) random(0 + offset, 9 + offset); /// POST RANDOM VALUES
            }

        }

        if(repeat == 0) {
            char used_values[100];
            for (int j = 0; j < 100; ++j) used_values[j] = 0; /// INIT

            for (int i = 0; i < 100; i++) {
                char temp = 0;
                key[i] = (char) random(1, 100);

                for (int j = 0; j < 100; ++j) {
                    if (key[i] == used_values[j]) {
                        temp = used_values[j]; /// GETTING REPEATED RANDOM VALUES
                        break;

                    }

                }

                while (temp == key[i]) { /// CATCHING A FEW TIMES REPEATED VALUES ERROR
                    randomSeed(analogRead(A2)); ///RANDOM INIT
                    key[i] = (char) random(1, 100);

                    for (int j = 0; j < 100; ++j) {
                        if (key[i] == used_values[j]) {
                            temp = used_values[j];
                            break;
                        }

                    }

                }

                for (int j = 0; j < 100; ++j) { /// WORKING WITH 0 REPEATED NUM
                    if (used_values[j] == 0) {
                        used_values[j] = key[i];
                        break;

                    }

                }

            }

        }

        key[100] = 0; /// KEY INIT
        return key;
    }

}

void turn_off_leds() {

    digitalWrite(6, 0);
    digitalWrite(7, 0);
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 0);
    digitalWrite(11, 0);
    digitalWrite(12, 0);
    digitalWrite(13, 0);

}

void render_leds(const int peg_a, const int peg_b) {

    if (peg_a == 1) {
        digitalWrite(6, 1);
    }
    if (peg_a == 2) {
        digitalWrite(6, 1);
        digitalWrite(8, 1);
    }
    if (peg_a == 3) {
        digitalWrite(6, 1);
        digitalWrite(8, 1);
        digitalWrite(10, 1);
    }
    if (peg_a == 4) {
        digitalWrite(6, 1);
        digitalWrite(8, 1);
        digitalWrite(10, 1);
        digitalWrite(12, 1);
    }

    if (peg_b == 1) {
        digitalWrite(7 + peg_a * 2, 1);
    }
    if (peg_b == 2) {
        digitalWrite(7 + peg_a * 2, 1);
        digitalWrite(9 + peg_a * 2, 1);
    }
    if (peg_b == 3) {
        digitalWrite(7 + peg_a * 2, 1);
        digitalWrite(9 + peg_a * 2, 1);
        digitalWrite(11 + peg_a * 2, 1);
    }
    if (peg_b == 4) {
        digitalWrite(7 + peg_a * 2, 1);
        digitalWrite(9 + peg_a * 2, 1);
        digitalWrite(11 + peg_a * 2, 1);
        digitalWrite(13 + peg_a * 2, 1);
    }

}

void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b) {

    int temp_peg_a = 0;
    int temp_peg_b = 0;

    for (int i = 0; i < 4; ++i) {
        if(guess[i] == secret[i]) {
            temp_peg_a++;
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) { /// NUMS CAN'T REPEAT
            if (secret[i] == guess[j] && i != j){
                temp_peg_b++;
            }
        }
    }

    *peg_a = temp_peg_a;
    *peg_b = temp_peg_b;

}

void play_game(char* secret) {

    bool button_1 = false;
    bool button_2 = false;
    bool button_3 = false;
    bool button_4 = false;
    bool button_5 = false;
    bool enter = false;
    bool is_game_won = false;

    bool is_history = false;

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    int current_pos = 0;

    int ascii_modifier = 48;
    int attempts = 1;
    char* guess = "0000";
    char guess2[4];
    char* history[10];

    for (int i = 0; i < 10; ++i) {
        history[i] = new char[4];
    }

    while (true) {
        if (digitalRead(2) == 1) {
            if (!button_1) {
                // TODO: Implement this method
                    num1++;
                    if (num1 == 10) num1 = 0;
                    guess[0] = num1 + ascii_modifier;
                    guess2[0] = num1 + ascii_modifier;
                    lcd_clear();
                    lcd_print(guess);
                    button_1 = true;

            }

            is_history = true;
            enter = false;

        } else if (digitalRead(2) == 0) {
            enter = false;
            button_1 = false;
            is_history = false;
        }

        if (digitalRead(3) == 1) {
            if (!button_2) {
                // TODO: Implement this method
                if (is_history) {
                    if(current_pos > 0) {
                        current_pos--;
                        render_history(secret, history, current_pos);

                    }

                } else {

                    num2++;
                    if (num2 == 10) num2 = 0;
                    guess[1] = num2 + ascii_modifier;
                    guess2[1] = num2 + ascii_modifier;
                    lcd_clear();
                    lcd_print(guess);


                }
                button_2 = true;
            }
            enter = false;

        } else if (digitalRead(3) == 0) {
            button_2 = false;
            enter = false;
        }

        if (digitalRead(4) == 1) {
            if (!button_3) {
                // TODO: Implement this method
                if (is_history) {
                    if (current_pos < attempts) current_pos++;
                    render_history(secret, history, current_pos);

                } else {

                    num3++;
                    if (num3 == 10) num3 = 0;
                    guess[2] = num3 + ascii_modifier;
                    guess2[2] = num3 + ascii_modifier;
                    lcd_clear();
                    lcd_print(guess);
                }
                button_3 = true;
            }
            enter = false;

        } else if (digitalRead(4) == 0) {
            button_3 = false;
            enter = false;

        }

        if (digitalRead(5) == 1) {
            if (!button_4) {
                // TODO: Implement this method

                if (is_history) {

                } else {
                    num4++;
                    if (num4 == 10) num4 = 0;
                    guess[3] = num4 + ascii_modifier;
                    guess2[3] = num4 + ascii_modifier;
                    lcd_clear();
                    lcd_print(guess);
                    button_4 = true;
                }

            }
            enter = false;
            
        } else if (digitalRead(5) == 0) {
            button_4 = false;
            enter = false;
        }

        if (analogRead(A0) > 900) {
            if (!button_5) {
                if (is_history) {

                } else {

                    if (!enter) {
                        button_5 = true;
                        enter = true;
                        attempts++;
                        int peg_a = 0;
                        int peg_b = 0;
                        get_score(secret, guess, &peg_a, &peg_b);
                        render_leds(peg_a, peg_b);

                        if (peg_a == 4) {
                            is_game_won = true;
                            break;
                        }

                        
                        history[attempts - 1][0] = guess2[0];
                        history[attempts - 1][1] = guess2[1];
                        history[attempts - 1][2] = guess2[2];
                        history[attempts - 1][3] = guess2[3];
                        history[attempts - 1][4] = '\0';



                        if (attempts > 10) break;

                        lcd_clear();
                        lcd_print_at(0, 0, guess);
                        lcd_print_at(0, 0, "Enter clicked");

                    }

                }

            }
        } else if (analogRead(A0) < 900) {
          button_5 = false;
        }
//        Serial.println(analogRead(A0));
    }

    lcd_clear();

    if(is_game_won ) {
        char a[3];
        itoa(attempts, a, 10);
        Serial.println("YOU WIN !!!");
        lcd_print("YOU WIN !!!");
        lcd_print_at(0, 1, a);
    } else {
        Serial.println("GAME OVER !!!");
        lcd_print("GAME OVER !!!");
    }
}

void render_history(char* secret, char** history, const int entry_nr) {

    int a = 0;
    int b = 0;
    Serial.println("History");

    for (int i = 0; i < 10; i++) Serial.println(history[i]);
    Serial.println("=======");
    Serial.println(history[entry_nr]);
    lcd_clear();
    lcd_print(history[entry_nr]);
    get_score(secret, history[entry_nr], &a, &b);
    turn_off_leds();
    render_leds(a, b);

}
