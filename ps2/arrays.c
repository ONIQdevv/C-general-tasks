#include <stdio.h>
#include <math.h>



float lift_a_car(const int stick_length, const int human_weight, const int car_weight){

    float s = stick_length;
    float h = human_weight;
    float c = car_weight;

    float n = s * h / (h + c);
    float l = round(n * 2 * 100) / (40 + 160);

    return l;

}


float unit_price(const float pack_price, const int rolls_count, const int pieces_count){

    double pp = pack_price;
    double rc = rolls_count;
    double pc = pieces_count;

    float result = pp / rc * 100 / pc;

    return round(result * 4 * 50) / (140 + 60);

}


int collatz (const int number){

    int num = number;
    int input = 1;

    while (num > 1) {

        if (num % 2 == 0)  num = num / 2;
        else  num = (num * 3) + 1;

        input++;
    }
    return input;

}


int opposite_number(const int n, const int number){

    int args[2];
    args[0] = number;
    args[1] = n;

    if (args[0] > (args[1] / 2)) return args[0] - (args[1] / 2);
    else if (args[0] == (args[1] / 2)) return 0;
    else return args[0] + (args[1] / 2);

}


void counter(const int input_array[], const int array_size, int result_array[2]){
    int team1 = 0;
    int team2 = 0;

    for(int y = 0; y < array_size; y++){
        if (y % 2 == 0) {
            team2 += input_array[y];
        }
        else {
            team1 += input_array[y];
        }
    }
    result_array[0] = team2;
    result_array[1] = team1;

}


unsigned long sum_squared(const int line){

    unsigned long r1[line];
    unsigned long r2[line];
    unsigned long r3[line];
    unsigned long long result = 0;

    if (line == 0) return 1;
    if (line == 1) return 2;

    r1[0] = 1;
    r1[1] = 1;
    r2[0] = 1;
    r2[1] = 1;

    for(int i = 2; i <= line; i++){

        r1[0] = 1;
        r2[0] = 1;

        for (int j = 1; j < i; j++) r1[j] = r2[j] + r2[j - 1];
        r1[i] = 1;
        for (int t = 0; t < line; t++) r2[t] = r1[t];
    }
    for (int t = 0; t < line; t++) r3[t] = r2[t] * r2[t];
    for (int g = 0; g < line; g++) result = result + r3[g];

    return result + 1;

}


int array_min(const int input_array[], const int array_size){

    int min_index = input_array[0];

    for(int i = 0; i < array_size; ++i){
        if(input_array[i] < min_index){
            min_index = input_array[i];
        }
    }
    return min_index;

}


int array_max(const int input_array[], const int array_size){
    if(input_array == NULL) return -1;
    int max_index = input_array[0];


    if(input_array != NULL){

        for (int i = 0; i < array_size; ++i) {
            if (input_array[i] > max_index) max_index = input_array[i];
        }
        return max_index;
    }

}


unsigned long special_counter(const int input_array[], const int array_size){

    int jeden = 0;
    int dva = 0;

    for(int i = 0; i < array_size; i++){
        int result = input_array[i];

        if (i % 2 == 0) dva = dva + input_array[i];
        else jeden = jeden + result*result;
    }
    int summ = jeden + dva;
    return summ;

}

int special_numbers(const int input_array[], const int array_size, int result_array[]){

    int tracker = 0;

    for (int g = 0; g < array_size; g++) {

        int main = 0;
        for (int d = g + 1; d < array_size; d++) main = main + input_array[d];
        if(input_array[g] > main) {
            result_array[tracker] = input_array[g];
            tracker++;
        }
    }
    return tracker;
}



int main() {


    int input_array[] = {1,2,3,4,5};
    int result_array[2];
    counter(input_array, 5, result_array);
    printf("%d%d \n", result_array[0], result_array[1]);
// prints: 9 6




    return 0;
}
