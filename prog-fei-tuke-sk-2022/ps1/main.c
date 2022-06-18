/** AUTHORED BY VOLODYMYR BOLGARIN ^_^
 *
 * TWITTER: @bolgarin_v
 * MY GITHUB IS: @ONIQdevv
 * STUDENT AT Technická univerzita v Košiciach -> FEI
 *
 * **/

///INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main() {
    /*
    char* abc = removeSpaces("hEllO World!", 12);
    printf("%s\n", mass);
    free(abc);

    return 0;
     */
    char* reversed = reverse("nULL");
    printf("%s\n", reversed);
    free(reversed);

    char* encrypted;

// basic test with long text
    encrypted = vigenere_encrypt("CoMPuTeR", "Hello world!");
    printf("%s\n", encrypted);
// "JSXAI PSINR!"
    return 0;
// "!DLROW OLLEH"
}