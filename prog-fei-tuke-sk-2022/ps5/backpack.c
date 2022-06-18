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
#include "backpack.h"
#include "container.h"
#include "item.h"

struct backpack* create_backpack(const int capacity) {

    struct backpack* backpack = malloc(sizeof (struct backpack));
    backpack->size = 0;
    backpack->capacity = capacity;
    backpack->items = NULL;

    return backpack;
}

struct backpack* destroy_backpack(struct backpack* backpack) {
    free(backpack);
    return NULL;
}

bool add_item_to_backpack(struct backpack* backpack, struct item* item) {
    if(backpack == NULL || item == NULL) return false;
    if(backpack->size < backpack->capacity) {
        if(backpack->items != NULL) {
            struct container *temp = backpack->items;
            while (temp->next != NULL) temp = temp->next;
            backpack->size++;
            create_container(temp, ITEM, item);
            return true;
        } else {
            create_container(NULL, ITEM, item);
            return true;
        }
    }
    else return false;
}

void delete_item_from_backpack(struct backpack* backpack, struct item* item) {
    if(backpack != NULL && item != NULL) {

//        char * name = item->name;
//        struct container* items = backpack->items;
//        struct container* temp = items;
//
//        while (temp->next != NULL) {
//            if(strcmp(temp->item->name, name) == 0) break;
//            temp = temp->next;
//        }

        remove_container(backpack->items, item);
    }
}





