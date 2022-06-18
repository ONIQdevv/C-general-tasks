/** AUTHORED BY VOLODYMYR BOLGARIN ^_^
 *
 * TWITTER: @bolgarin_v
 * MY GITHUB IS: @ONIQdevv
 * STUDENT AT Technická univerzita v Košiciach -> FEI
 *
 * **/

///INCLUDES
#include <stdio.h>
//#include <stdbool.h>


int main () {

    int rows = 0;
    scanf("%d", &rows);
    int cols = 0;
    scanf("%d", &cols);
//    int res = 0;



    int trees[rows][cols];
    int nums[cols];
    int index[rows][cols];


    for (int i = 0; i < rows; ++i) for (int j = 0; j < cols; ++j) scanf("%d", &trees[i][j]); // trees[][] --> get values from 'scanf'
    for (int i = 0; i < rows; ++i) for (int j = 0; j < cols; ++j) nums[j] = trees[i][j]; // tree_data[] --> get values from trees[][]
    for (int i = 0; i < rows; ++i) for (int j = 0; j < cols; ++j) index[i][j] = 6;

    for (int i = 0; i < rows; ++i) {

        int used = 1;
        int curr_num = 0;
        int uValues[used];
        index[i][0] = 0;
//        int mas1[used];

        for (int j = 0; j < cols; ++j) {

            curr_num = nums[i];
            uValues[used] = curr_num;

            if (curr_num > nums[j]) {
                
                curr_num = nums[j];
                used++;
                index[i][used] = 0; // Left side <--
                uValues[used] = curr_num;

            }
            
        }

        int j = 0;
        while (used != cols) {

            for (int y = 0; y < used; ++y) if (nums[j] != uValues[y]) j++;

            if (curr_num < uValues[j]) {

                index[i][used] = 1;
                curr_num = nums[j];
                used++;
                uValues[used] = curr_num;

            }
            if (j < cols) j++;
            else break;

        }



        for (int p = 0; p < cols; ++p) printf("%d\t", index[i][p]);

    }

//    int res = rows - counter;
//    printf("%d\n", res);
    return 0;
}







































//    for (int i = 0; i < 1; ++i) {
//        for (int j = 0; j < size; ++j) {
//
//            int left = nums[i][0];
//
//            for (int k = 1; k < size - 1; ++k) {
//                if (nums[i][k] < left) {
//
//                   used_nums[i][k] = nums[i][k];
//                   left = nums[i][k];
//
//                }
//
//            }
//            for (int k = 0; k < size; ++k) {
//                if (used_nums[i][j] == nums[i][k]) {
//                    sides[i][k] = 1; // Left side <--
//                }
//            }
//            printf("%d\t\n", sides[i][j]);
//
//        }
//    }



//
//    for (int i = 0; i < amount_of_trees; ++i) {
//
//        for (int j = 0; j < tree_data; ++j) bin_tree[j] = trees[i][j];
//
//        for (int j = 0; j < tree_data; ++j) {
//            bin_tree[0] = 110; // 110 -> Left side
//
//            for (int k = 0; k < tree_data; ++k) {
//                for (int n = 1; n < tree_data - 1; ++n) {
//
//                    /// sizeID[][] INIT
//
//                    if (bin_tree[n] < bin_tree[k]){
//                        sidesID[i][n] = 110; // 110 -> Left side
//                    }
//                    else if (bin_tree[n] > bin_tree[k]) {
//                        sidesID[i][n] = 111; // 111 -> Right side
//                    }
//
//                }
//            }
//
//            printf("%d\n\t", sidesID[i][j]);
//        }
//
//
//    }
//
//    for (int i = 0; i < amount_of_trees; ++i) {
//        for (int j = 0; j < tree_data; ++j) {
//            printf("%d\n\t", sidesID[i][j]);
//        }
//    }
//
//
//    for (int i = 0; i < amount_of_trees; ++i) {
//        for (int j = 0; j < tree_data; ++j) {
//            trees[i][j] = sidesID[i][j];
//        }
//    }


//int counter;
//for (int t = 1; t < cols; ++t) {
//
//for (counter = 0; bin_tree[counter] < bin_tree [j]; ++counter) {
//if (bin_tree[counter] != bin_tree[t] && bin_tree[counter] == 998){
//while (bin_tree[t] < bin_tree[0]) {
//counter++;
//}
//}
//}
//while (bin_tree[t] < bin_tree[0]) {
//counter++;
//}
//bin_tree[counter] = 999;