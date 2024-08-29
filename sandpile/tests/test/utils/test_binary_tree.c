/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** desc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../../include/utils.h"
#include "../../../include/struct.h"
#include "../../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../../include/tree/tree.h"

Test(join_tree, tree_undefine)
{
    tree_t *creat_new_tree = (tree_t *)0x0;
    print_tree_postfix(creat_new_tree);
    print_tree_postfix_2(creat_new_tree);
    print_tree_prefix(creat_new_tree);
    print_tree_prefix_2(creat_new_tree);
    depth_first_search(creat_new_tree, NULL);
    depth_first_search_2(creat_new_tree, 0);
    breadth_first_search(creat_new_tree, NULL, NULL);
    breadth_first_search_2(creat_new_tree, 0, NULL);
}

Test(join_tree, simple_tree)
{
    join_tree(NULL, new_tree("2"), "0");
    join_tree(new_tree("1"), NULL, "0");
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    tree_t *creat_new_tree = join_tree(join_tree(join_tree(new_tree("7"), new_tree("8"), "3"), join_tree(new_tree("9"), new_tree("10"), "4"), "1"), join_tree(join_tree(new_tree("11"), new_tree("12"), "5"), join_tree(new_tree("13"), new_tree("14"), "6"), "2"), "0");
    print_tree_postfix(creat_new_tree);
    print_tree_prefix(creat_new_tree);
    count_tree_nodes(creat_new_tree);
    clean_tree(creat_new_tree);
}

Test(join_tree, simple_tree_2)
{
    char *test[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", (char *)0x0};
    for (int x = 0; test[x]; x++) {
        int output = 0;
        mini_printf("\n\n-%s-\n\n", test[x]);
        doubly_linked_t *list = (doubly_linked_t *)0x0;
        tree_t *tree = join_tree(join_tree(join_tree(new_tree("7"), new_tree("8"), "3"), join_tree(new_tree("9"), new_tree("10"), "4"), "1"), join_tree(join_tree(new_tree("11"), new_tree("12"), "5"), join_tree(new_tree("13"), new_tree("14"), "6"), "2"), "0");
        data_t *da = malloc(sizeof(data_t));
        *da = (data_t) {0, "0"};
        insert_at_end(&list, da);
        print_tree_prefix(tree);
        my_putstr("<-------------------------------->\n");
        output = depth_first_search(tree, test[x]);
        mini_printf("depth_first_search: %d\n", output);
        my_putstr("<-------------------------------->\n");
        output = breadth_first_search(tree, test[x], list);
        mini_printf("breadth_first_search: %d\n", output);
        my_putstr("<-------------------------------->\n");
        clean_tree(tree);
    }
}

Test(assemly_tree_2, simple_tree)
{
    for (int x = 0; x <= 30; x++) {
        tree_t *tree = (tree_t *)0x0;
        doubly_linked_t *list = (doubly_linked_t *)0x0;
        data_t *data = (data_t *)0x0;
        int y = x;
        int *test = malloc(sizeof(int) * 9);

        test[0] = 13;
        test[1] = 13;
        test[2] = 17;
        test[3] = 19;
        test[4] = 10;
        test[5] = 20;
        test[6] = 7;
        test[7] = 18;
        test[8] = 4;
        data = malloc(sizeof(data_t));
        *data = (data_t) {13, (char *)0x0, tree};
        insert_at_end(&list, data);

        for (int x = 0; x <= 8; x++)
            tree = assemly_tree_2(tree, test[x]);
        free(test);
        print_tree_prefix_2(tree);
        print_tree_postfix_2(tree);
        mini_printf("depth_first_search_2 -> %s : (%d)\n", depth_first_search_2(tree, y) == 0 ? "yes" : "no", y);
        mini_printf("breadth_first_search_2 -> %s : (%d)\n", breadth_first_search_2(tree, y, list) == 0 ? "yes" : "no", y);
        clean_tree(tree);
    }
}

Test(assemly_tree_2, simple_tree_2)
{
    tree_t *tree = (tree_t *)0x0;
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    int y = 10;
    int *test = malloc(sizeof(int) * 9);

    test[0] = 0;
    test[1] = 0;
    test[2] = 0;
    test[3] = 0;
    test[4] = 0;
    test[5] = 0;
    test[6] = 0;
    test[7] = 0;
    test[8] = 0;
    data = malloc(sizeof(data_t));
    *data = (data_t) {13, (char *)0x0, tree};
    insert_at_end(&list, data);

    for (int x = 0; x <= 8; x++)
        tree = assemly_tree_2(tree, test[x]);
    free(test);
    print_tree_prefix_2(tree);
    print_tree_postfix_2(tree);
    mini_printf("depth_first_search_2 -> %s : (%d)\n", depth_first_search_2(tree, y) == 0 ? "yes" : "no", y);
    mini_printf("breadth_first_search_2 -> %s : (%d)\n", breadth_first_search_2(tree, y, list) == 0 ? "yes" : "no", y);
    clean_tree(tree);
}