/*TEST ZAPOCET
 *
 *
 *

int prog(){
    char p[] = "Programovanie";
    for(int i = 0; i <= 3; i++) printf("%c", p[i]); // Output: Prog
    return 0;
}


int f1(int x[], int y, int z){
    int i;
    for (i = 0; i < y; i++) {
        if (x[i] == z)
            return i;
    }
    return (-1);
}

int main(){
    int a[10] = { 2, 8, 4, 1, 3, 7 };
    printf("%d", f1(a, 6, 7)); // Output: 5
}

 *
 *
 *
 */



#include <stdio.h>
#include <string.h>


int bash(const char string[]){ //aka strlen from <string.h>
    int a = 0;
    while(string[a]!='\0'){
        a++;
    }
    return a;
}

int is_white(const char c){
    if(c ==' ' || c == '\t' || c == '\n') return  1;
    else return  0;

}

void change_whites(char string[]){
    for (int i = 0; i < bash(string); i++) {
        if(string[i] ==' ' || string[i] == '\n') string[i] = '.';
    }
}

int guess_eval(const int guess, const int my_number){
    if(my_number == guess) return 1;
    else if(my_number < guess) return 0;
    else if(my_number > guess) return 2;
}

int leap_year(const int year){
    if(year > 4443 || year < 1) return -1;
    else{
        if((year %4 == 0 && year %100 != 0) || (year %4 == 0 && year %400 == 0) || (year %4 == 0 && year < 400)) return 1;
        else return 0;
    }
}

int count_positives(const int size, const int array[]) {
    int counter = 0;
    if(array == NULL)  return -1;
    else {
        for (int i = 0; i < size; i++) {
            if (array[i] > 0) counter++;
        }
        return counter;
    }
}

int count_whites(const char string[]){
    int counter = 0;
    if(string == NULL)  return -1;
    else {
        for (int i = 0; i < bash(string); i++) {
            if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') counter++;
        }
        return counter;
    }
}

int direction_correction(const int degree){
    if(degree < 0) return -1;
    if(degree %360 == 0) return 0;
    if(degree %180 == 0) return 180;
    if(degree %270 == 0) return 270;
    if(degree %90 == 0) return 90;
    else return -1;
}

int all_positives(const int size, const int array[]) {
    int counter = 0;
    if(array == NULL)  return -1;
    else {
        for (int i = 0; i < size; i++) {
            if (array[i] > 0) counter++;
        }
        if(counter == size) return 1;
        else return 0;
    }
}

int last_positive(const int size, const int array[]){
    if(array == NULL)  return -1;
    else {
        for (int i = size-1; i >= 0; i--) {
            if (array[i] > 0) return array[i];
        }
        return -1;
    }
}

int binary_num(const int num){
    if(num == 0 || num == 1) return 1;
    if(num < -1000 || num > 1000) return -1;
    else return 0;
}

void swap_sign(const int size, int array[]){
    if(array != NULL) {
        for (int i = 0; i < size; i++) {
            array[i] = array[i] * -1;
        }
    }
}

int div_by_3(const int num){
    if( num %3 == 0) return 1;
    else return 0;
}

int same_case(const char a, const char b){
    if (( a < 123 && a > 96 && b < 123 && b > 96) || ( a < 91 && a > 64 && b < 91 && b > 64)) return 1;
    if((a <= 64 || b <= 64) || (a >= 91 && a <= 96) || (b >= 91 && b <= 96) || (a >= 123 || b >= 123)) return -1;
    else return 0;
}

int max_2d(const int size, int array[][size]){
    if(array == NULL) return -1;
    else {
        int max_num = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(array[i][j] > max_num) max_num = array[i][j];
            }
        }
        return max_num;
    }
}

int vowels_count_2d(const int rows, const int cols, char string[][cols]){
    int counter = 0;
    char arr[] = "aqeyuioAQEYUIO";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < bash(string[i]); j++) {
            if(strchr(arr, string[i][j]) != NULL){
                counter++;
            }
        }
    }
    return counter;
}

int is_in_array_2d(const int num, const int size, int array[][size]) {
    if(array == NULL) return -1;
    else {
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (array[i][j] == num) return 1;
            }
        }
        return 0;
    }
}

int largest_line(const int size, int array[][size]){

    int counter = 0;
    int summ [size];

    if (array == NULL) return -1;

    for (int i = 0; i < sizeof(array[0]) / sizeof(array[0][0]); i++) {
        for (int j = 0; j < size; j++) {
            summ[i] = summ[i] + array[i][j];
        }
    }

    counter = summ[0];
    int result = 0;

    for (int j = 0; j < size; ++j) {
        if (counter < summ[j]) {
            counter = summ[j];
        }
    }

    for (int i = 0; i < size; ++i) {
        if (summ[i] == counter) {
            result = i;
            break;
        }
    }

    return result;
}

/*void swap_case_2d ( const int rows, const int cols, char string[][cols]){
    if(string != NULL) {
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < cols; j++) {
               if(string[i][j] > 96 && string[i][j] < 123) string[i][j] -= 32;
               if(string[i][j] > 64 && string[i][j] < 91) string[i][j] += 32;
            }
        }
    }
}*/

void swap_case_2d(const int rows, const int cols, char strings[][cols]) {
    if (strings != NULL) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int height = -1;
                char alph_lowc[] = "abcdefghijklmnopqrstuvwxyz";
                char alph_upperc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                for (int k = 0; k < 26; k++) {
                    if (alph_lowc[k] == strings[i][j]) {
                        height = 0;
                        break;
                    }
                    if (alph_upperc[k] == strings[i][j]) {
                        height = 1;
                        break;
                    }
                }
                if (height == 0) {
                    strings[i][j] = strings[i][j] - 32;
                } else if (height == 1) {
                    strings[i][j] = strings[i][j] + 32;
                }
            }
        }
    }
}

int largest_col(const int size, int array[][size]) {
    if (array == NULL) return -1;
    int counter = 0;
    int summ[size];
    for (int i = 0; i < sizeof(array[0])/sizeof(array[0][0]); ++i) {
        for (int j = 0; j < size; j++) {
            summ[i] = summ[i] + array[j][i];
        }
    }

    counter = summ[0];
    int result = 0;
    for (int j = 0; j < size; j++) {
        if (counter < summ[j]) {
            counter = summ[j];
        }
    }

    for (int i = 0; i < size; ++i) {
        if (summ[i] == counter) {
            result = i;
            break;
        }
    }
    return result;
}



int main(){ // There you can find some prints
    /*
     *
     *

    printf("%d%d\n", is_white('#'), is_white(' '));

    char str[]= "Hello world!";
    change_whites(str);
    printf("%s\n", str);

    printf("%d %d %d\n", guess_eval(34,22), guess_eval(22,34), guess_eval(34,34) );

    printf("%d%d%d%d\n", leap_year(4000), leap_year(3000), leap_year(3004), leap_year(-20));

    const int array1[] = {1,-38,0,3,-1,0};
    printf("%d\n", count_positives(6, NULL));

    const char string[] = "Hello, how,are u ?";
    printf("%d\n", count_whites(string));

    printf("%d%d%d\n", direction_correction(-90), direction_correction(540), direction_correction(180));

    const int array1[] = {1,38,10,3,1,110};
    printf("%d\n", all_positives(6, array1));

    const int array1[] = {1, 0, 1};
    const int array2[] = {-1,0,-6,-2};
    printf("%d\n", last_positive(4, array1));

    printf("%d\n", binary_num(1));

    const int array1[] = {-1,0,-6,-2};
    swap_sign(4, array1);
    for (int i = 0; i < 4; i++) printf("%d\n", array1[i]);
    printf("\n");

    printf("%d\n", div_by_3(-3));

    printf("%d\n", same_case('a','f'));

    int array[2][2] = {{1,2},{0,-3}};
    printf("%d\n", max_2d(2, array));

    int array[2][2] = {{1,0},{0,-3}};
    printf("%d%d\n", is_in_array_2d(2, 2, array), is_in_array_2d(-3, 2, array));

    char strings [3][50] = {"helloWORLD", "aHOJ", "Ahoj"};
    printf("%d\n", vowels_count_2d(3, 50, strings));

    int array[2][2] = {{1,0},{0,-3}};
    printf("%d\n", largest_line(2, array));

    int array[2][2] = {{1,0},{0,-3}};
    printf("%d\n", largest_line(2, array));

     *
     *
     */
    return 0;
}