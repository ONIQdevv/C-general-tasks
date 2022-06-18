/** AUTHORED BY VOLODYMYR BOLGARIN ^_^
 *
 * TWITTER: @bolgarin_v
 * MY GITHUB IS: @ONIQdevv
 * STUDENT AT Technická univerzita v Košiciach -> FEI
 *
 * **/

///INCLUDES
#include <stdio.h>
#include "item.h"
#include "container.h"
#include "backpack.h"

int main() {

    add_item_to_backpack(NULL, NULL);
    create_backpack(0);
    create_item("", "", 0);
    delete_item_from_backpack(NULL, NULL);
    destroy_backpack(NULL);
//    destroy_containers(NULL);
    destroy_item(NULL);

    printf("OK!");
}