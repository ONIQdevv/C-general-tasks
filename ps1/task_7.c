#include <superkarel.h>

void turn_right();
void l_step();
void l_step_reverse();
void b_step();
void l_wall_move();
void do_put();
void r_check();
void r_complete();





1 || 2 логическое ИЛИ
1true2true = true;
1true2false = true;
1false2false = false;

1 && 2 - логическое И
1true2true = true;
1true2false = false;
1false2false = false;










int main() {
    turn_on("task_7.kw");

        set_step_delay(30);
        while(left_is_blocked()) {
                step();
        }
        l_step();
        put_beeper();
        step();

        while( front_is_clear() || right_is_clear()) {

                r_complete();

        }

    turn_off();

    return 0;
}



void turn_right() {
    turn_left();
    turn_left();
    turn_left();
}
void l_step(){
            turn_left();
            step();

}
void l_step_reverse(){
            step();
            turn_left();
}
void b_step(){
            turn_left();
            turn_left();
            step();
}
void l_wall_move(){
            while(left_is_blocked()) {
                if (front_is_clear()){
                        step();
		} else {
                        turn_right();
                }
            }
}
void do_put(){
	    l_step();
            put_beeper();
}
void r_check(){
    if(right_is_clear()) {
            turn_right();
        }

    else if(left_is_clear() && front_is_blocked()) {
            turn_left();
        }

    else if(front_is_blocked()) {
            turn_left();
            turn_left();
        }
}
void r_complete() {
    while(no_beepers_present()) {
        r_check();
	if(front_is_clear()) {
        	step();
        }
    }
    if(beepers_present() && facing_north()) {
            b_step();
            l_step();
            while(left_is_blocked()) {
                step();
            }
            do_put();
            b_step();
            turn_left();
            if(front_is_clear()) {
            step();

	if(front_is_clear()) {
            while(left_is_blocked()) {
                step();
            }
            do_put();
            step();
            }
            }
    } else
        if(facing_south() && beepers_present()) {
                pick_beeper();
                l_step_reverse();
                if(front_is_clear()) {
                step();
while(left_is_blocked() && front_is_clear()) {
                    step();
                }
                if(front_is_clear()) {
                do_put();
                if(front_is_clear()) {
                    step();
                } else {
                    b_step();
                    turn_left();
                }
                }
                }
        }

}
