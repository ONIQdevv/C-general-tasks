#include<stdio.h>


int main(int argc, char* argv[]){

    if(argc != 3) return 1;
    FILE *jeden = fopen(argv[1], "r");

    if(jeden == NULL) return 1;
    FILE *dva = fopen(argv[2], "w");

    char input;
    int start = 1;

    do {
        input = fgetc(jeden);
        if(input == 'S'){
            input = fgetc(jeden);
            if(input == 'T'){
                input = fgetc(jeden);
                if(input == 'A'){
                    input = fgetc(jeden);
                    if(input == 'R'){
                        input = fgetc(jeden);
                        if(input == 'T'){
                            input = fgetc(jeden);
                            if(input == ' ') break;
                        }
                    }
                }
            }
        }
        if(input == EOF) return 0;
    } while(1);                          

    int field = 0;

    while(input != EOF) {
        input = fgetc(jeden);
        if(input == 'S'){
            input = fgetc(jeden);
            if(input == 'T'){
                input = fgetc(jeden);
                if(input == 'O'){
                    input = fgetc(jeden);

                    if(input == 'P') break;
                    else {
                        if(field == 1){
                            fputc('S', dva);
                            fputc('T', dva);
                            fputc('O', dva);
                        }
                    }

                }

                else {
                    if(field == 1){
                        fputc('S', dva);
                        fputc('T', dva);
                    }
                }

            }

            else {
                if(field == 1){
                    fputc('S', dva);
                }
            }

        }

        if(field == 1 && input != ' ') fputc(input, dva);
        else if(field == 0 && input == ' ' && start == 0) fputc(input, dva);

        if(start == 1 && field == 1) start = 0;
        if(input == ' ') field = (field == 0) ? 1 : 0;
    }

    fclose(jeden);
    fclose(dva);

    return 0;
}