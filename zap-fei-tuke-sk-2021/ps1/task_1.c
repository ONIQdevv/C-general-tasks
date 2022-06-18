#include <superkarel.h>

void turn_right();

int main() {

    turn_on("task_1.kw");
    set_step_delay(50);

    put_beeper();

    if(front_is_blocked()){
        turn_left();
        step();
    } else {
        step();
    }

    while (no_beepers_present()) {

        if (right_is_clear()) turn_right();
        else if (left_is_clear() && front_is_blocked()) turn_left();
        else if (front_is_blocked()) {
            turn_left();
            turn_left();
        }

        step();
    }

    turn_right();
    pick_beeper();

    while (no_beepers_present()) {
        if (left_is_clear()) turn_left();
        else if (right_is_clear() && front_is_blocked()) turn_right();
        else if (front_is_blocked()) {
            turn_right();
            turn_right();
        }

        step();
    }

    pick_beeper();
    while(!facing_west()) {
        turn_left();
    }

    turn_off();
    return 0;

}
void turn_right() {

    turn_left();
    turn_left();
    set_step_delay(30);
    turn_left();

}

