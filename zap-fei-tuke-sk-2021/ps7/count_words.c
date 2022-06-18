#include <stdio.h>

int bash(char arr[]) {
    int counter = 0;
    while(arr[counter] != '\0' ) counter++;
    return counter;
}
void toLower (char arr[]) {

    for (int i = 0; i < bash(arr); i++) if (arr[i] >= 65 && arr[i] <= 90) arr[i] += 32;

}

int sCompare(char str1[], const char str2[]){

    int counter = 0;

    for (int i = 0; i < bash(str1); i++) if(str1[i] == str2[i]) counter++;
    return counter == bash(str1) ? 1 : 0;

}



int main(int argc, char* argv[]) {

    if (argc == 2){

        FILE *jeden = fopen(argv[1], "r");

        char arr[2048];
        char lm = fgetc(jeden);
        int data = 0;

        for (int i = 0; i < 2048; i++) arr[i] = '\0';
        while(lm != EOF) {
            arr[data] = lm;
            lm = fgetc(jeden);
            data++;
        }
        toLower(arr);

        int counter = 0;
        char arrays[6];
        char arrays2[7];

        for (int i = 0; i < bash(arr) - 6; i++) {

            for (int j = 0; j < 6; j++) arrays[j] = arr[i + j];
            for (int j = 0; j < 6; j++) arrays2[j] = arrays[j];
            arrays2 [6]='\0';
            if(sCompare(arrays2, "ananas") == 1) counter++;

        }

        FILE *dva = fopen(argv[1], "w+");

        int result = counter / 10;
        counter = counter % 10;

        if (result != 0) fputc(result + 48, dva);
        fputc(counter + 48, dva);



        /*
    char arr[] = "qwerty";
    printf("%d \n", bash(arr));

    char arr[] = "QWERTY";
    toLower(arr);
    printf("%s \n", arr);
     */


    } //else printf(stderr, "ERROR\n");

    return 0;

}
