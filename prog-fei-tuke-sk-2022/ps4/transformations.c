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
#include <string.h>
#include "transformations.h"
//#include "colors.h"

struct bmp_image* flip_horizontally(const struct bmp_image* image) {

    if (image == NULL) return NULL;
    if (image->header == NULL) return NULL;
    if (image->data == NULL) return NULL;

    struct pixel arr[image->header->height][image->header->width];
    struct pixel farr[image->header->height][image->header->width];

    int pos = 0;
    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            arr[i][j] = image->data[pos];
            pos++;
        }
    }

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            farr[i][j] = arr[i][image->header->width - j - 1];
        }
    }

    pos = 0;

    struct pixel* temp = malloc(sizeof (struct pixel) * image->header->height * image->header->width);

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            temp[pos] = farr[i][j];
            pos++;
        }
    }

    struct bmp_header* rq = malloc(sizeof (struct bmp_header));
    memcpy(rq, image->header, sizeof (struct bmp_header));

    struct bmp_image* illustration = malloc(sizeof (struct bmp_image));
    illustration->header = rq;
    illustration->data = temp;

//    pos = 0;
//    for (int i = 0; i < image->header->height; ++i) {
//        for (int j = 0; j < image->header->width; ++j) {
//
//            int blue = temp[pos].blue;
//            int green = temp[pos].green;
//            int red = temp[pos].red;
//
//            if(red != 0 && green == 0&& blue == 0) {
//               printf("%s█%s", RED, RESET);
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

    return illustration;

}





struct bmp_image* rotate_left(const struct bmp_image* image) {

    if (image == NULL) return NULL;
    if (image->header == NULL) return NULL;
    if (image->data == NULL) return NULL;

    struct pixel arr[image->header->height][image->header->width];
    struct pixel arrt[image->header->width][image->header->height];
    struct pixel farr[image->header->width][image->header->height];

    int pos = 0;
    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            arr[i][j] = image->data[pos];
            pos++;
        }
    }

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            arrt[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            farr[j][i] = arrt[j][image->header->height - i - 1];
        }
    }

    pos = 0;

    struct pixel* temp = malloc(sizeof (struct pixel) * image->header->height * image->header->width);

    for (int i = 0; i < image->header->width; ++i) {
        for (int j = 0; j < image->header->height; ++j) {
            temp[pos] = farr[i][j];
            pos++;
        }
    }

    struct bmp_header* rq = malloc(sizeof (struct bmp_header));
    memcpy(rq, image->header, sizeof (struct bmp_header));

    struct bmp_image* illustration = malloc(sizeof (struct bmp_image));
    illustration->header = rq;
    illustration->data = temp;
    int padding = (4 - (illustration->header->height * sizeof(struct pixel)) % 4) % 4;

    illustration->header->image_size = image->header->height * image->header->width * 3 + image->header->width * padding;
    illustration->header->height = image->header->width;
    illustration->header->width = image->header->height;
    illustration->header->size = illustration->header->image_size + sizeof (struct bmp_header);


//    pos = 0;
//    for (int i = 0; i < image->header->width; ++i) {
//        for (int j = 0; j < image->header->height; ++j) {
//
//            int blue = temp[pos].blue;
//            int green = temp[pos].green;
//            int red = temp[pos].red;
//
//            if(red != 0 && green == 0&& blue == 0) {
//               printf("%s█%s", RED, RESET);
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

    return illustration;
}




struct bmp_image* flip_vertically(const struct bmp_image* image) {

    if (image == NULL) return NULL;
    if (image->header == NULL) return NULL;
    if (image->data == NULL) return NULL;

    struct pixel arr[image->header->height][image->header->width];
    struct pixel farr[image->header->height][image->header->width];

    int pos = 0;
    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            arr[i][j] = image->data[pos];
            pos++;
        }
    }

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            farr[i][j] = arr[image->header->height - i - 1][j];
        }
    }

    pos = 0;

    struct pixel* temp = malloc(sizeof (struct pixel) * image->header->height * image->header->width);

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            temp[pos] = farr[i][j];
            pos++;
        }
    }

    struct bmp_header* rq = malloc(sizeof (struct bmp_header));
    memcpy(rq, image->header, sizeof (struct bmp_header));

    struct bmp_image* illustration = malloc(sizeof (struct bmp_image));
    illustration->header = rq;
    illustration->data = temp;

//    pos = 0;
//    for (int i = 0; i < image->header->height; ++i) {
//        for (int j = 0; j < image->header->width; ++j) {
//
//            int blue = temp[pos].blue;
//            int green = temp[pos].green;
//            int red = temp[pos].red;
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

    return illustration;
}

struct bmp_image* rotate_right(const struct bmp_image* image) {

    if (image == NULL) return NULL;
    if (image->header == NULL) return NULL;
    if (image->data == NULL) return NULL;

    struct pixel arr[image->header->height][image->header->width];
    struct pixel arrt[image->header->width][image->header->height];
    struct pixel farr[image->header->width][image->header->height];

    int pos = 0;
    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            arr[i][j] = image->data[pos];
            pos++;
        }
    }

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            arrt[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            farr[j][i] = arrt[image->header->width - j - 1][i];
        }
    }

    pos = 0;

    struct pixel* temp = malloc(sizeof (struct pixel) * image->header->height * image->header->width);

    for (int i = 0; i < image->header->width; ++i) {
        for (int j = 0; j < image->header->height; ++j) {
            temp[pos] = farr[i][j];
            pos++;
        }
    }

    struct bmp_header* rq = malloc(sizeof (struct bmp_header));
    memcpy(rq, image->header, sizeof (struct bmp_header));

    struct bmp_image* illustration = malloc(sizeof (struct bmp_image));
    illustration->header = rq;
    illustration->data = temp;
    int padding = (4 - (illustration->header->height * sizeof(struct pixel)) % 4) % 4;

    illustration->header->image_size = image->header->height * image->header->width * 3 + image->header->width * padding;
    illustration->header->height = image->header->width;
    illustration->header->width = image->header->height;
    illustration->header->size = illustration->header->image_size + sizeof (struct bmp_header);


//    pos = 0;
//    for (int i = 0; i < image->header->width; ++i) {
//        for (int j = 0; j < image->header->height; ++j) {
//
//            int blue = temp[pos].blue;
//            int green = temp[pos].green;
//            int red = temp[pos].red;
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

    return illustration;
}

struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep) {

    if (image == NULL) return NULL;
    if (image->header == NULL) return NULL;
    if (image->data == NULL) return NULL;
    if (colors_to_keep == NULL) return NULL;

    bool keep_blue = false;
    bool keep_green = false;
    bool keep_red = false;

    for (int i = 0; i < strlen(colors_to_keep); ++i)
        if (colors_to_keep[i] != 'r' && colors_to_keep[i] != 'g' && colors_to_keep[i] != 'b') return NULL;

    if (strlen(colors_to_keep) == 1) {
        if (colors_to_keep[0] == 'r') keep_red = true;
        if (colors_to_keep[0] == 'g') keep_green = true;
        if (colors_to_keep[0] == 'b') keep_blue = true;
    }

    if (strlen(colors_to_keep) == 2) {
        if (colors_to_keep[0] == 'r') keep_red = true;
        if (colors_to_keep[0] == 'g') keep_green = true;
        if (colors_to_keep[0] == 'b') keep_blue = true;
        if (colors_to_keep[1] == 'r') keep_red = true;
        if (colors_to_keep[1] == 'g') keep_green = true;
        if (colors_to_keep[1] == 'b') keep_blue = true;
    }

    if (strlen(colors_to_keep) == 3) {
        if (colors_to_keep[0] == 'r') keep_red = true;
        if (colors_to_keep[0] == 'g') keep_green = true;
        if (colors_to_keep[0] == 'b') keep_blue = true;
        if (colors_to_keep[1] == 'r') keep_red = true;
        if (colors_to_keep[1] == 'g') keep_green = true;
        if (colors_to_keep[1] == 'b') keep_blue = true;
        if (colors_to_keep[2] == 'r') keep_red = true;
        if (colors_to_keep[2] == 'g') keep_green = true;
        if (colors_to_keep[2] == 'b') keep_blue = true;
    }

    struct pixel arr[image->header->height][image->header->width];
    struct pixel farr[image->header->height][image->header->width];

    int pos = 0;
    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            arr[i][j] = image->data[pos];
            pos++;
        }
    }

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {

            if (keep_blue) farr[i][j].blue = arr[i][j].blue;
            else farr[i][j].blue = 0;

            if (keep_green) farr[i][j].green = arr[i][j].green;
            else farr[i][j].green = 0;

            if (keep_red) farr[i][j].red = arr[i][j].red;
            else farr[i][j].red = 0;

        }
    }

    pos = 0;

    struct pixel* temp = malloc(sizeof (struct pixel) * image->header->height * image->header->width);

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            temp[pos] = farr[i][j];
            pos++;
        }
    }

    struct bmp_header* rq = malloc(sizeof (struct bmp_header));
    memcpy(rq, image->header, sizeof (struct bmp_header));

    struct bmp_image* illustration = malloc(sizeof (struct bmp_image));
    illustration->header = rq;
    illustration->data = temp;

//    pos = 0;
//    for (int i = 0; i < image->header->height; ++i) {
//        for (int j = 0; j < image->header->width; ++j) {
//
//            int blue = temp[pos].blue;
//            int green = temp[pos].green;
//            int red = temp[pos].red;
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

    return illustration;
}



struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width) {

    if (image == NULL) return NULL;
    if (image->header == NULL) return NULL;
    if (height <= 0) return NULL;
    if (width <= 0) return NULL;
    if (start_x < 0) return NULL;
    if (start_y < 0) return NULL;
    if (start_x + width > image->header->width) return NULL;
    if (start_y + height > image->header->height) return NULL;

    struct bmp_image* illustration;
    illustration = flip_vertically(image);

    struct pixel arr[image->header->height][image->header->width];
    struct pixel arr2[height][width];

    for (int i = 0; i < image->header->height; ++i) {
        for (int j = 0; j < image->header->width; ++j) {
            arr[i][j] = illustration->data[i * image->header->width + j];
        }
    }

    int x = start_x, y = start_y;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            arr2[i][j] = arr[y + i][x + j];
        }
    }

    struct pixel* temp = malloc(width * height * sizeof (struct pixel));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            temp[i * width + j] = arr2[i][j];
        }
    }

    struct bmp_header* res = malloc(sizeof (struct bmp_header));
    memcpy(res, image->header, sizeof (struct bmp_header));

    struct bmp_image* let = malloc(sizeof (struct bmp_image));
    let->header = res;
    let->data = temp;
    let->header->width = width;
    let->header->height = height;

    int padding = (4 -(width * sizeof(struct pixel)) % 4) % 4;
    let->header->image_size = height * padding + height * width * sizeof(struct pixel);
    let->header->size = let->header->image_size + sizeof (struct bmp_header);

    struct bmp_image* fin;
    fin = flip_vertically(let);

    free_bmp_image(let);
    free_bmp_image(illustration);


//    int pos = 0;
//    for (int i = 0; i < height; ++i) {
//        for (int j = 0; j < width; ++j) {
//
//            int blue = fin->data[pos].blue;
//            int green = fin->data[pos].green;
//            int red = fin->data[pos].red;
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

    return fin;

//    illustration->header = malloc(sizeof(struct bmp_header));
//    *illustration->header = *image->header;
//
//    /** IMAGE PARAMS INIT **/
//    illustration->header->height = height; // Image param 1
//    illustration->header->width = width; // Image param 2
//    /** End INIT **/
//
//    int padding = (4 -(width * sizeof(struct pixel)) % 4) % 4;
//    uint32_t w_before = width;
//
//    struct bmp_image* illustration = malloc(sizeof(struct bmp_image));
//    illustration->header = malloc(sizeof(struct bmp_header));
//
//    illustration->header->image_size = height * padding + height * width * sizeof(struct pixel);
//    illustration->header->size = illustration->header->image_size + 54;
//    illustration->data = calloc(height * width, sizeof(struct pixel));
//    struct bmp_image *fv_Bimg = flip_vertically(image);
//
//    for (int i = 0; i < width; i++) for (int j = 0; j < height; j++) illustration->data[(j * width) + i] = fv_Bimg->data[(start_y + j) * w_before + start_x + i];
//    struct bmp_image *fv_Aimg = flip_vertically(illustration);
//
//    free_bmp_image(fv_Bimg);
//    free_bmp_image(illustration);
//    return fv_Aimg;
}