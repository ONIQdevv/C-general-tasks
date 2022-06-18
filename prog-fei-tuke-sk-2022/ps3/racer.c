/** AUTHORED BY VOLODYMYR BOLGARIN ^_^
 *
 * TWITTER: @bolgarin_v
 * MY GITHUB IS: @ONIQdevv
 * STUDENT AT Technická univerzita v Košiciach -> FEI
 *
 * **/

///INCLUDES
#include <stdio.h>


int main () {

    int size = 0, time = 0;
    scanf("%d %d", &size, &time);
    int values[size][2];
    for (int i = 0; i < size; ++i) for (int j = 0; j < 2; ++j) scanf("%d", &values[i][j]); // INIT

    double c = 2000;
    double summary = 0;

    for (int i = 0; i < 4000; ++i) {

        summary = 0;
        int temp = 0;

        for (int j = 0; j < size; ++j) {

            summary += (double) values[j][0] / ( values [j][1] + c );

            if (values[j][1] + c == 0) {
                temp = 1;
                break;
            }

        }

        if (temp == 1 || summary == time) break;
//        printf("%0.9f   %0.9f\n", c, summary);
        c-=1;

    }

    if (summary == time) {
        printf("%0.9f\n", c);
        return 0;
    }

    double mod = 0.1;

    for (int i = 0; i < 7; ++i) {
        for (int k = 0; k < 50; ++k) {
            summary = 0;

            for (int j = 0; j <= size - 1; ++j) summary += (double) values[j][0] / ( values [j][1] + c );

            if (summary < time) break;

//            printf("%0.9f\n", c);
            c += mod;
        }

        if (summary < time) c -= mod;
        mod /= 10;
    }

    printf("%0.9f\n", c);
    return 0;
}
