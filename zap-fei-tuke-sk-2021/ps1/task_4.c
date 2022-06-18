#include <superkarel.h>

void turn_right();
int speed();

int main() {
    turn_on("task_4.kw");
    set_step_delay(speed());
    while (!facing_east()) {
        turn_left();
    }
    while (front_is_clear()) {
        turn_left();
        while (front_is_clear()) {
            if (beepers_present()) {
                break;
            } else {
                step();
            }
        }
        if (beepers_present()) {
            while (!facing_north()) {
                turn_left();
            }
            while (front_is_clear()) {
                step();
            }
            turn_left();
            turn_left();
            while (front_is_clear()) {
                if (beepers_present()) {
                    step();
                } else {
                    put_beeper();
                }
            }
            if (no_beepers_present()) {
                put_beeper();
            }
        }
        
        while (!facing_south()) {
            turn_left();
        }
        while (front_is_clear()) {
            step();
        }
        while (!facing_east()) {
            turn_left();
        }
        if (front_is_clear()) {
            step();
        }
    }

    while (!facing_north()) {
        turn_left();
    }

    while (front_is_clear()) {
        if (beepers_present()) {
            break;
        } else {
            step();
        }
    }

    if (beepers_present()) {
        while (front_is_clear()) {
            step();
        }

        turn_left();
        turn_left();

        while (front_is_clear()) {
            if (no_beepers_present()) {
                put_beeper();
            }
            step();
        }
        if (no_beepers_present()) {
            put_beeper();
        }
    }

    while (!facing_south()) {
        turn_left();
    }

    while (front_is_clear()) {
        step();
    }

    while (!facing_east()) {
        turn_left();
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
    return 50;
}
