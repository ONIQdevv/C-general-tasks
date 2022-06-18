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
//#include <ctype.h>
#include "item.h"

struct item* create_item(char* name, char* description, unsigned int properties) {

    if (name == NULL || description == NULL) return NULL;

    struct item* item = malloc(sizeof (struct item));
    item->properties = 0;

////    item->name = malloc(sizeof (char )* strlen(name));
////    memcpy(item->name, name, strnlen(name));
////    item->description = malloc(sizeof (char )* strlen(description));
////    memcpy(item->description, description, strnlen(description));

    int nLength = 0;
    while (name[nLength] != '\0') nLength++;
    int dLength = 0;
    while (description[dLength] != '\0') dLength++;

    item->name = malloc(sizeof (char ) * (long unsigned int) nLength);
    memcpy(item->name, name, (size_t) nLength);

    item->description = malloc(sizeof (char ) * (long unsigned int) dLength);
    memcpy(item->description, description, (size_t) dLength);

    return item;
}

struct item* destroy_item(struct item* item) {
    if (item != NULL) {
        free(item->description);
        free(item->name);
    }
    free(item);
    return NULL;

}
