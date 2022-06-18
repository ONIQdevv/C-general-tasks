#include <superkarel.h>

void turn_right();
int speed();
void beeper_found();

int main() {
    turn_on("task_6.kw");
    set_step_delay(speed());
    
    while (no_beepers_present() && front_is_clear()) {
        step();
    }

    if (beepers_present()) {
        beeper_found();
    }

    turn_off();
    return 0;
}

void turn_right() {
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(speed());
    turn_left();
}

int speed () {
    return 250;
}

void beeper_found() {
    pick_beeper();
    if (beepers_present()) {
        pick_beeper();
        if (beepers_present()) {
            pick_beeper();
            if (beepers_present()) {
                pick_beeper();
                if (beepers_present()) {
                    pick_beeper();
                    // 5 beepers
                } else {
                    // 4 beepers
                    while (!facing_east()) {
                        turn_left();
                    }

                    while (no_beepers_present() && front_is_clear()) {
                        step();
                    }
                    beeper_found();
                }
            } else {
                // 3 beepers
                while (!facing_south()) {
                    turn_left();
                }

                while (no_beepers_present() && front_is_clear()) {
                    step();
                }
                beeper_found();

            }
        } else {
            // 2 beepers
            while (!facing_west()) {
                turn_left();
            }
         
            while (no_beepers_present() && front_is_clear()) {
                step();
            }
            beeper_found();

        }
    } else {
        // 1 beeper
        while (!facing_north()) {
            turn_left();
        }

        while (no_beepers_present() && front_is_clear()) {
            step();
        }
        beeper_found();

    }
}
