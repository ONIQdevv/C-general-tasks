#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void encode_char (const char character, bool bits[8]){
    bool arr[8];
    int c = (int) character;
    for (int i = 0; i < 8; i++) {
        arr[i] = c % 2 == 0 ? false : true;
        c /= 2;
    }
    int elPos = 7;
    for (int i = 0; i < 8; i++) {
        bits[i] = arr[elPos];
        elPos--;
    }
}

char decode_byte(const bool bits[8]){
    int k = 128, res = 0;
    for (int i = 0; i < 8; i++) {
        res = bits[i] == false ? res : res + k;
        k /= 2;
    }
    return (char) res;
}

void encode_string(const char string[], bool bytes[strlen(string) + 1][8]){
    bool cBite[8];
    for (int x = 0; x < strlen(string) + 1; x++) {
        encode_char(string[x], cBite);
        for (int y = 0; y < 8; y++) bytes[x][y] = cBite[y];
    }
}
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    bool cBite[8];

    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < 8; y++) cBite[y] = bytes[x][y];
        string[x] = decode_byte(cBite);

    }
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset * 8][cols], const int rows, bool bytes[rows][8]){
    int mSize = rows + ( cols - (rows % cols));
    bool myMatrix[8][mSize];
    for (int x = 0; x < 8; x++) for (int y = 0; y < mSize; y++) myMatrix[x][y] = 0;
    for (int x = 0; x < 8; x++) for (int y = 0; y < mSize; y++) myMatrix[x][y] = bytes[y][x];
    int k_x = 0, k_y = 0;
    for (int x = 0; x < offset; x++){
        for (int y = 0; y < cols; y++) for (int z = 0; z < 8; z++) blocks[z + k_y][y] = myMatrix[z][y + k_x];
        k_x += cols;
        k_y += 8;
    }
}

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset * 8][cols], const int rows, bool bytes[rows][8]) {
    int mSize = rows + ( cols - (rows % cols));
    bool myMatrix[8][mSize];
    for (int x = 0; x < 8; x++) for (int y = 0; y < mSize; y++) myMatrix[x][y] = 0;
    int k_x = 0, k_y = 0;
    for (int x = 0; x < offset; x++) {
        for (int y = 0; y < cols; y++) for (int z = 0; z < 8; z++) myMatrix[z][y + k_x] = blocks[z + k_y][y];
        k_x += cols;
        k_y += 8;
    }
    for (int x = 0; x < rows; x++) for (int y = 0; y < 8; y++) bytes[x][y] = myMatrix[y][x];
}

int main() {
    /*
    bool bits1[8];
    encode_char('A', bits1);
    for(int i = 0; i < 8; i++){
        printf("%d", bits1[i]);
    }
    printf("\n");
// prints: 01000001

    char* text = "Hello, how are you?";
    const int len = strlen(text);
    bool bytes1[len+1][8];
    encode_string(text, bytes1);
    for(int j = 0; j <= len; j++){
        printf("%c: ", text[j]);
        for(int i = 0; i < 8; i++){
            printf("%d", bytes1[j][i]);
        }
        printf("\n");
    }
// prints:
// H: 01001000
// e: 01100101
// l: 01101100
// l: 01101100
// o: 01101111
// ,: 00101100
//  : 00100000
// h: 01101000
// o: 01101111
// w: 01110111
//  : 00100000
// a: 01100001
// r: 01110010
// e: 01100101
//  : 00100000
// y: 01111001
// o: 01101111
// u: 01110101
// ?: 00111111
// : 00000000

    bool bytes2[7][8] = {
            {0,1,0,0,1,0,0,0},
            {0,1,1,0,0,1,0,1},
            {0,1,1,0,1,1,0,0},
            {0,1,1,0,1,1,0,0},
            {0,1,1,0,1,1,1,1},
            {0,0,1,0,0,0,0,1},
            {0,0,0,0,0,0,0,0}
    };
    char string[7];
    decode_bytes(7, bytes2, string);
    printf("%s\n", string);
// prints: Hello!

    int length = 4+1, cols = 3, offset = 2;
    bool bytes1[4+1][8] = {
            {0,1,0,0,0,0,0,1},
            {0,1,1,0,1,0,0,0},
            {0,1,1,0,1,1,1,1},
            {0,1,1,0,1,0,1,0},
            {0,0,0,0,0,0,0,0}
    };
    bool blocks1[offset*8][cols];
    bytes_to_blocks(cols, offset, blocks1, length, bytes1);
    for(int j = 0; j < offset*8; j++){
        for(int i = 0; i < cols; i++){
            printf("%d ", (blocks1[j][i] == true) ? 1 : 0);
        }
        printf("\n");
        if(j % 8 == 7){
            printf("\n");
        }
    }
// prints:
// 0 0 0
// 1 1 1
// 0 1 1
// 0 0 0
// 0 1 1
// 0 0 1
// 0 0 1
// 1 0 1
//
// 0 0 0
// 1 0 0
// 1 0 0
// 0 0 0
// 1 0 0
// 0 0 0
// 1 0 0
// 0 0 0

    bool blocks2[2*8][3] = {
            {0,0,0},
            {1,1,1},
            {0,1,1},
            {0,0,0},
            {0,1,1},
            {0,0,1},
            {0,0,1},
            {1,0,1},
            {0,0,0},
            {1,0,0},
            {1,0,0},
            {0,0,0},
            {1,0,0},
            {0,0,0},
            {1,0,0},
            {0,0,0}
    };
    bool bytes2[length][8];
    blocks_to_bytes(3, 2, blocks2, length, bytes2);
    for(int j = 0; j < length; j++){
        for(int i = 0; i < 8; i++){
            printf("%d", bytes2[j][i]);
        }
        printf("\n");
    }
// prints:
// 01000001
// 01101000
// 01101111
// 01101010
// 00000000
    */
    return 0;
}



/**
 * Second realization *
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void encode_char(const char character, bool bits[8]){
	int k = character*2;
	for(int i =  7; i > -1; i--) bits[i] = ((k = k / 2) % 2);
}
char decode_byte(const bool bits[8]){
	int k = 1;
	int c = bits[7];
	for(int i = 6; i > -1 ; i--) c = c + (bits[i] ? k=k*2 : 0*(k=k*2));
	return (char)c;
}
void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
	bzero(bytes,sizeof(bool)*8*(strlen(string)+1));
	for(int i = 0;string[i]; i++) encode_char(string[i],bytes[i]);
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
	bzero(string,rows*sizeof(char));
	for(int i = 0; i < rows; i++) string[i] = decode_byte(bytes[i]);
}
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
	bzero(blocks,offset*8*cols*sizeof(bool));
	for(int j = 0; j < 8; j++) for(int i = 0; i < rows; i++) blocks[j+8*(i/cols)][i%cols] = bytes[i][j];

}
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
	bzero(bytes,rows*8*sizeof(bool));
	for(int j = 0; j < 8; j++) for(int i = 0; i < rows; i++) bytes[i][j] = blocks[j+8*(i/cols)][i%cols];
}
 *
 **/