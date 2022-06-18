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
//#include "colors.h"

struct bmp_header* read_bmp_header(FILE* stream) {
    if (stream == NULL) return NULL;
    else {
        fseek(stream, 0, SEEK_END);
        int fLength = ftell(stream);
        rewind(stream);
        if (fLength < 54) return NULL;

        struct bmp_header* img_header = malloc(sizeof (struct bmp_header));
        fread(img_header, sizeof (struct bmp_header), 1, stream);
        if (img_header == NULL) return NULL;
        if (img_header->type != 0x4D42) {
            free(img_header);
            return NULL;
        }
        return img_header;
    }
}

void free_bmp_image(struct bmp_image* image) {

    if (image != NULL) {

        if (image->data != NULL) free(image->data);
        if (image->header != NULL) free(image->header);
        free(image);

    }

}

struct pixel* read_data(FILE* stream, const struct bmp_header* header) {

    if (stream == NULL) return NULL;
    if (header == NULL) return NULL;

    fseek(stream, 0, SEEK_END);
    int fLength = ftell(stream);
    rewind(stream);
    if (fLength < 54) return NULL;

    struct pixel* pixels = malloc(sizeof(struct pixel) * header->height * header->width);

    char* pixel_buf = malloc(fLength);
    fread(pixel_buf, sizeof (char), fLength, stream);

    int padding = (4 - (header->width * sizeof(struct pixel)) % 4) % 4;

    int pos = 54;
    int pos2 = 0;

    for (int i = 0; i < header->height; ++i) {
        for (int j = 0; j < header->width; ++j) {
            pixels[pos2].blue = pixel_buf[pos];
            pos++;
            pixels[pos2].green = pixel_buf[pos];
            pos++;
            pixels[pos2].red = pixel_buf[pos];
            pos++;
            pos2++;
        }
        pos += padding;
    }

//    pos = 0;
//
//    for (int i = 0; i < header->height; ++i) {
//        for (int j = 0; j < header->width; ++j) {
//
//            int blue = pixels[pos].blue;
//            int green = pixels[pos].green;
//            int red = pixels[pos].red;
//
//            if(red != 0 && green == 0&& blue == 0) {
//                printf("%s█%s", RED, RESET);
//            } else if (red == 0 && green != 0&& blue == 0) {
//                printf("%s█%s", GREEN, RESET);
//            } else if (red == 0 && green == 0 && blue != 0) {
//                printf("%s█%s", BLUE, RESET);
//            } else if(red != 0 && green == 0&& blue != 0) {
//                printf("%s█%s", MAGENTA, RESET);
//            } else if (red == 0 && green != 0&& blue != 0) {
//                printf("%s█%s", CYAN, RESET);
//            } else if (red != 0 && green != 0 && blue == 0) {
//                printf("%s█%s", YELLOW, RESET);
//            } else if (red > 200 && green > 200 && blue > 200) {
//                printf("%s█%s", WHITE, RESET);
//            } else {
//                printf(" ");
//            }
//
//            pos++;
//        }
//
//        printf("\n");
//
//    }
    free(pixel_buf);
    return pixels;
}

struct bmp_image* read_bmp(FILE* stream) {

    if (stream == NULL) {
        fprintf(stderr, "Error: This is not a BMP file.\n");
        return NULL;
    }

    struct bmp_header* pointer;
    pointer = read_bmp_header(stream);
    if (pointer == NULL) {
        fprintf(stderr, "Error: This is not a BMP file.\n");
        return NULL;
    }
    struct pixel* let = read_data(stream, pointer);
    if (let == NULL) {
        fprintf(stderr, "Error: This is not a BMP file.\n");
        return NULL;
    }

    struct bmp_image* temp = malloc(sizeof(struct bmp_image));
    temp->header = pointer;
    temp->data = let;

//    int pos = 0;
//
//    for (int i = 0; i < pointer->height; ++i) {
//        for (int j = 0; j < pointer->width; ++j) {
//
//            int blue = let[pos].blue;
//            int green = let[pos].green;
//            int red = let[pos].red;
//
//            if(red != 0 && green == 0&& blue == 0) {
//                printf("%s█%s", RED, RESET);
//            } else if (red == 0 && green != 0&& blue == 0) {
//                printf("%s█%s", GREEN, RESET);
//            } else if (red == 0 && green == 0 && blue != 0) {
//                printf("%s█%s", BLUE, RESET);
//            } else if(red != 0 && green == 0&& blue != 0) {
//                printf("%s█%s", MAGENTA, RESET);
//            } else if (red == 0 && green != 0&& blue != 0) {
//                printf("%s█%s", CYAN, RESET);
//            } else if (red != 0 && green != 0 && blue == 0) {
//                printf("%s█%s", YELLOW, RESET);
//            } else if (red > 200 && green > 200 && blue > 200) {
//                printf("%s█%s", WHITE, RESET);
//            } else {
//                printf(" ");
//            }
//
//            pos++;
//        }
//
//        printf("\n");
//
//    }

    return temp;
}

//bool write_bmp (FILE* stream, const struct bmp_image* image) {
//
//}