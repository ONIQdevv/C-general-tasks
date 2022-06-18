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
#include "container.h"

struct container* create_container(struct container* first, enum container_type type, void* entry) {
    if (entry == NULL) return NULL;
    if (first == NULL) {
        struct container* container = malloc(sizeof (struct container));
        container->type = type;

        if (type == ROOM) container->room = entry;
        else if (type == COMMAND)container->command = entry;
        else if (type == ITEM) container->item = entry;
        else if (type == TEXT) container->text = entry;

        container->next = NULL;
        return container;
    } else {
        if (first->type == type) {

            struct container* container = malloc(sizeof (struct container));
            container->type = type;

            if (type == ROOM) container->room = entry;
            else if (type == COMMAND)container->command = entry;
            else if (type == ITEM) container->item = entry;
            else if (type == TEXT) container->text = entry;

            container->next = NULL;

            first->next = container;
            return container;

        } else return NULL;
    }

}

//struct container* destroy_containers(struct container* first) {
//    if (first == NULL) return NULL;
//    else {
//        struct container* temp = first;
//        struct container* temp2 = first;
//        free(first);
//
//        while (temp->next != NULL) {
//            temp = temp2;
//            temp2 = temp->next;
//
//            if (temp2->type == ITEM) destroy_item(temp2->item);
//            if (temp2->type == ROOM) destroy_room(temp2->room);
//            if (temp2->type == COMMAND) destroy_command(temp2->command);
//            if (temp2->type == TEXT) free(temp2->text);
//
//            free(temp2);
//        }
//
//        if (temp->type == ITEM) destroy_item(temp->item);
//        if (temp->type == ROOM) destroy_room(temp->room);
//        if (temp->type == COMMAND) destroy_command(temp->command);
//        if (temp->type == TEXT) free(temp->text);
//
//        free(temp);
//
//        }
//    }
//
//    return NULL;
//}

struct container* remove_container(struct container *first, void *entry) {
    if (first == NULL || entry == NULL) return NULL;
    int type = first->type;
    if (type == ROOM) {
        struct room* r = entry;

        char * name = r->name;
        struct container* temp = first;

        if(strcmp(first->room->name, name) == 0) {
            struct container* temp2 = first->next;
            free(first);
            return temp2;
        }

        bool is_found = false;

        while (temp->next != NULL) {
            if(strcmp(temp->room->name, name) == 0) {
                is_found = true;
                break;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            if(strcmp(temp->next->room->name, name) == 0) {
                is_found = true;
            }
        }

        if(strcmp(temp->room->name, name) == 0) {
            is_found = true;
        }

        return is_found ? temp->next : NULL;
    } else if (type == COMMAND) {
        struct command* cmd = entry;
        char * name = cmd->name;
        struct container* temp = first;

        if(strcmp(first->command->name, name) == 0) {
            struct container* temp2 = first->next;
            free(first);
            return temp2;
        }

        bool is_found = false;

        while (temp->next != NULL) {
            if(strcmp(temp->command->name, name) == 0) {
                is_found = true;
                break;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            if(strcmp(temp->next->command->name, name) == 0) {
                is_found = true;
            }
        }

        if(strcmp(temp->command->name, name) == 0) {
            is_found = true;
        }

        return is_found ? temp->next : NULL;
    } else if (type == ITEM) {
        struct item* i = entry;
        char * name = i->name;
        struct container* temp = first;

        if(strcmp(first->item->name, name) == 0) {
            struct container* temp2 = first->next;
            free(first);
            return temp2;
        }

        bool is_found = false;

        while (temp->next != NULL) {
            if(strcmp(temp->item->name, name) == 0) {
                is_found = true;
                break;
            }
            temp = temp->next;
        }

        if (temp->next != NULL) {
            if(strcmp(temp->next->item->name, name) == 0) {
                is_found = true;
            }
        }

        if(strcmp(temp->item->name, name) == 0) {
            is_found = true;
        }

        return is_found ? temp->next : NULL;
    } else if (type == TEXT) {
        char * name = entry;
        struct container* temp = first;

        if(strcmp(first->text, name) == 0) {
            struct container* temp2 = first->next;
            free(first);
            return temp2;
        }

        bool is_found = false;

        while (temp->next != NULL) {
            if(strcmp(temp->text, name) == 0) {
                is_found = true;
                break;
            }
            temp = temp->next;
        }

        if (temp->next != NULL)
            if(strcmp(temp->next->text, name) == 0)
                is_found = true;

        if(strcmp(temp->text, name) == 0)
            is_found = true;

        return is_found ? temp->next : NULL;
    } else return NULL;



//        char * name = item->name;
//        struct container* items = backpack->items;
//        struct container* temp = items;
//
//        while (temp->next != NULL) {
//            if(strcmp(temp->item->name, name) == 0) break;
//            temp = temp->next;
//        }
}
