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

Test(insert_at_beginning, list_equal_NULL)
{
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    insert_at_beginning(&list, data);
}

Test(insert_at_beginning, simple_list)
{
    char **test = malloc(sizeof(char *) * 10);
    test[0] = my_strdup("1");
    test[1] = my_strdup("2");
    test[2] = my_strdup("3");
    test[3] = my_strdup("4");
    test[4] = my_strdup("5");
    test[5] = (char *)0x0;
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    for (int i = 0; test[i]; i++) {
        data = malloc(sizeof(data_t));
        *data = (data_t) {i, test[i]};
        insert_at_beginning(&list, data);
    }
}

Test(insert_at_end, list_equal_NULL)
{
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    insert_at_end(&list, data);
}

Test(insert_at_end, simple_list)
{
    char **test = malloc(sizeof(char *) * 10);
    test[0] = my_strdup("1");
    test[1] = my_strdup("2");
    test[2] = my_strdup("3");
    test[3] = my_strdup("4");
    test[4] = my_strdup("5");
    test[5] = (char *)0x0;
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    for (int i = 0; test[i]; i++) {
        data = malloc(sizeof(data_t));
        *data = (data_t) {i, test[i]};
        insert_at_end(&list, data);
    }
    print_list(list);
    print_reverse_list(list);
}

Test(print, list_equal_NULL)
{
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    print_list(list);
    print_reverse_list(list);
    delete_element(&list, data);
    delete_at_the_beginning(&list);
    delete_at_the_end(&list);
}

Test(insert_at_end, simple_list_3)
{
    char **test = malloc(sizeof(char *) * 10);
    test[0] = my_strdup("1");
    test[1] = my_strdup("2");
    test[2] = my_strdup("3");
    test[3] = my_strdup("4");
    test[4] = my_strdup("5");
    test[5] = (char *)0x0;
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    for (int i = 0; test[i]; i++) {
        data = malloc(sizeof(data_t));
        *data = (data_t) {i, test[i]};
        insert_at_end(&list, data);
    }
    print_list(list);
    print_reverse_list(list);
    delete_at_the_beginning(&list);
    delete_at_the_end(&list);
}

Test(delete, delete_one_element)
{
    char **test = malloc(sizeof(char *) * 10);
    test[0] = my_strdup("1");
    test[1] = (char *)0x0;
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    for (int i = 0; test[i]; i++) {
        data = malloc(sizeof(data_t));
        *data = (data_t) {i, test[i]};
        insert_at_beginning(&list, data);
    }
    delete_at_the_beginning(&list);
}

Test(delete, delete_one_element_2)
{
    char **test = malloc(sizeof(char *) * 10);
    test[0] = my_strdup("1");
    test[1] = (char *)0x0;
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    for (int i = 0; test[i]; i++) {
        data = malloc(sizeof(data_t));
        *data = (data_t) {i, test[i]};
        insert_at_beginning(&list, data);
    }
    data = malloc(sizeof(data_t));
    *data = (data_t) {0, test[0]};
    delete_element(&list, data);
}

Test(delete, delete_one_element_3)
{
    char **test = malloc(sizeof(char *) * 10);
    test[0] = my_strdup("1");
    test[1] = (char *)0x0;
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    for (int i = 0; test[i]; i++) {
        data = malloc(sizeof(data_t));
        *data = (data_t) {i, test[i]};
        insert_at_beginning(&list, data);
    }
    delete_at_the_end(&list);
}

Test(delete_element, any_deletion)
{
    char **test = malloc(sizeof(char *) * 10);
    test[0] = my_strdup("1");
    test[1] = my_strdup("2");
    test[2] = my_strdup("3");
    test[3] = my_strdup("4");
    test[4] = my_strdup("5");
    test[5] = (char *)0x0;
    doubly_linked_t *list = (doubly_linked_t *)0x0;
    data_t *data = (data_t *)0x0;
    for (int i = 0; test[i]; i++) {
        data = malloc(sizeof(data_t));
        *data = (data_t) {i, test[i]};
        insert_at_beginning(&list, data);
    }
    data = malloc(sizeof(data_t));
    *data = (data_t) {3, test[3]};
    delete_element(&list, data);
    data = malloc(sizeof(data_t));
    *data = (data_t) {1, test[1]};
    delete_element(&list, data);
}
