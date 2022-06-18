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
#include "transformations.h"

int main (void) {
    FILE* stream;
    stream = fopen("kliatba.noci.bmp", "rb");

//    struct bmp_header* img_header;
//
//    img_header = read_bmp_header(stream);
//
//    if (img_header != NULL) {
//        printf("Type: %d\n", img_header->type);
//        printf("Width: %d\n", img_header->width);
//        printf("Height: %d\n", img_header->height);
//    }

    struct bmp_image* illustration;
    illustration = read_bmp(stream);

    if (illustration == NULL || stream == NULL)
        return 0;

    struct bmp_image* hflip;
    hflip = flip_horizontally(illustration);

    struct bmp_image* vflip;
    vflip = flip_vertically(illustration);

    struct bmp_image* rrotate;
    rrotate = rotate_right(illustration);

    struct bmp_image* lrotate;
    lrotate = rotate_left(illustration);

    struct bmp_image* extractt;
    extractt = extract(illustration, "rgb");

    struct bmp_image* img_crop;
    img_crop = crop(illustration, 5, 5, 101, 135);

////    printf("Image size: %d, width: %d, height: %d\n", lrotate->header->image_size, lrotate->header->width, lrotate->header->height);

    free_bmp_image(hflip);
    free_bmp_image(vflip);
    free_bmp_image(rrotate);
    free_bmp_image(lrotate);
    free_bmp_image(extractt);
    free_bmp_image(img_crop);
    free_bmp_image(illustration);

    fclose(stream);

    return 0;
}
