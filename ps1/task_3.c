#include <superkarel.h>

void turn_right();
void go_to_end();
bool beepers_at_right();

int main(){
    turn_on("task_3.kw");
    set_step_delay(20);

    go_to_end();
    turn_right();
    turn_right();
    while (front_is_clear()) {
        if (right_is_blocked() && beepers_in_bag()) {
            put_beeper();
            step();
        } else step();
    }

    turn_left();
    step();
    turn_left();

    while (front_is_clear()) {
        go_to_end();
        turn_right();
        turn_right();
        while (front_is_clear()) {
            if (beepers_at_right() && beepers_in_bag()) {
                turn_right();
                turn_right();
                step();
                turn_right();
                put_beeper();
                step();
            } else {
                turn_right();
                turn_right();
                step();
                turn_right();
                step();
            }
        }

        turn_left();
        if (front_is_blocked()) break;
        step();
        turn_left();
    }

    turn_left();

    while (no_beepers_present()){
        if(front_is_clear()) step();
        else if (facing_west()) turn_right();
        else if (facing_east()) turn_left();
    }
    while (not_facing_north()) turn_left();
    while (front_is_clear()) step();
    turn_left();
    while (front_is_clear()) step();
    turn_left();
    turn_left();

    turn_off();

    return 0;
}
void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(20);
    turn_left();
}
void go_to_end(){
    while(front_is_clear()){
        if(beepers_present()) pick_beeper();
        step();
    }
    if(beepers_present()) pick_beeper();
}
bool beepers_at_right(){
    turn_right();
    step();
    if(beepers_present()) return true;
    else return false;
}