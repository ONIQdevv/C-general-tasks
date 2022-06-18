#include <superkarel.h>

void turn_right();
int speed();

int main() {
    turn_on("task_5.kw");
    set_step_delay(speed());
    
    while (!facing_west()) {
        turn_left();
    }

    while (front_is_clear()) {
        step();        
    }

    turn_left();

    while (front_is_clear()) {
        step();
    }

    turn_left();

    while (no_beepers_present()) {
        put_beeper();
        while (front_is_clear()) {
            step();
            if (no_beepers_present()) {
                put_beeper();
            }
        }

        turn_left();
        
        if (front_is_clear()) {
            step();
        }
    }

    turn_left();
    step();
    turn_right();
    step();
    if (front_is_blocked()) {
        turn_left();
        turn_left();
        step();
        turn_right();
        step();
        if (front_is_blocked()) {
            turn_left();
            turn_left();
            step();
            while (!facing_north()) {
                turn_left();
            }
            while (beepers_present()) {
                pick_beeper();
            }
            turn_off();
        } else {
            step();
            step();
            if (front_is_blocked()) {
                turn_left();
                turn_left();
                step();
                step();
                turn_left();
                turn_left();
                while (beepers_present()) {
                    pick_beeper();
                }
                turn_off(); // Turn off
            }
        }
    }

    while (!facing_south()) {
        turn_left();
    }
    while (front_is_clear()) {
        step();
    }
    while (!facing_west()) {
        turn_left();
    }
    while (front_is_clear()) {
        step();
    }
    while (!facing_east()) {
        turn_left();
    }
    step();
    turn_left();
    step();
    turn_right();
    put_beeper();
    step();
    //put_beeper();
    //step();
    while (true) {
        while (no_beepers_present()) {
            step();
        }
        if (front_is_clear()) {
            pick_beeper();
        }
        turn_left();
        turn_left();
        step();
        turn_right();
        step();
        
        if (beepers_present() /*&& facing_north()*/) {
            //set_step_delay(400);
            if (front_is_clear()) {
                pick_beeper();
                
            }
            turn_left();
            turn_left();
            step();
            turn_right();
            //set_step_delay(400);
            if (beepers_present()) {
                while (beepers_present()) {
                    pick_beeper();
                }

                step();
                while (beepers_present()) {
                    pick_beeper();
                }
                turn_left();
                turn_left();
                step();
                step();
                while(beepers_present()) {
                    pick_beeper();
                }
                turn_left();
                turn_left();
                step();
                turn_left();
                step();
                while (beepers_present()) {
                    pick_beeper();
                }

                turn_left();
                turn_left();
                step();
                step();
                while (beepers_present()) {
                    pick_beeper();
                }
                turn_left();
                turn_left();
                step();
                while (!facing_north()) {
                    turn_left();
                }
                while (beepers_present()) {
                    pick_beeper();
                }
                turn_off();
            }
            put_beeper();
            step();
            //turn_off();
            while (no_beepers_present()) {
                step();
            }
            turn_left();
            turn_left();
            step();
            //turn_off(); // Breakpoint
            if (beepers_present()) {
                turn_left();
                turn_left();
                pick_beeper();
                step();
                if (beepers_present()) {
                    pick_beeper();
                }
                step();
                if (beepers_present()) {
                    pick_beeper();
                }

                turn_left();
                turn_left();
                step();
                while (!facing_north()) {
                    turn_left();
                }
                while (beepers_present()) {
                    pick_beeper();
                }
                turn_off();
            }
            put_beeper();
            turn_left();
            turn_left();
            step();
            //if (front_is_clear()) {
                pick_beeper();
                step();
            //}
            //turn_off();
            if (front_is_clear()) {
                pick_beeper();
                turn_left();
                turn_left();
            } else {
                turn_left();
                turn_left();
                step();
            }
            while (no_beepers_present()) {
                step();
            }
            step();
            while (no_beepers_present()) {
                step();
            }
            turn_left();
            turn_left();
            //if (front_is_clear()) {
                pick_beeper();
            //}
            step();
            if (beepers_present()) {
                while (!facing_north()) {
                    turn_left();
                }
                while (beepers_present()) {
                    pick_beeper();
                }
                turn_off();
            }
            put_beeper();
            step();
            //set_step_delay(400);
            while (true) {
                while (no_beepers_present()) {
                    step();
                }
                turn_left();
                turn_left();
                step();
                if (beepers_present()) {
                    pick_beeper();
                    turn_left();
                    turn_left();
                    step();
                    pick_beeper();
                    turn_left();
                    turn_left();
                    step();
                    //turn_off();
                    if (facing_north()) {
                        turn_left();
                        turn_left();
                        step();
                    } else if (facing_south()) {
                        step();
                    }
                    while (!facing_north()) {
                        turn_left();
                    }
                    while (beepers_present()) {
                        pick_beeper();
                    }
                    turn_off();
                }
                turn_left();
                turn_left();
                step();
                turn_left();
                turn_left();
                pick_beeper();
                step();
                //if (beepers_present()) {
                //    turn_off();
                //}
                
                put_beeper();

                step();
            }
            while (beepers_present()) {
                pick_beeper();
            }
            turn_off();
        } else {
            put_beeper();
            step();
        }
    }
    while (beepers_present()) {
        pick_beeper();
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
    return 10;
}
