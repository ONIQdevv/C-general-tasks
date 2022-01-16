#include <superkarel.h>

void go_center();
void go_center_r();
void turn_right();

int main(){
        turn_on("task_2.kw");

        set_step_delay(70);
        go_center();
        pick_beeper();
        turn_left();
        turn_left();
        go_center_r();
        turn_off();

        return 0;
}

void turn_right(){
        turn_left();
        set_step_delay(30);
        turn_left();
        turn_left();
}
void go_center(){
        while(no_beepers_present()){

                if(front_is_blocked()) turn_left();

                else while(front_is_clear()) step();
        }
}
void go_center_r() {
    while (not_facing_west() || right_is_clear()) {

        if (front_is_blocked()) turn_right();

        else while (front_is_clear())step();
    }
}

