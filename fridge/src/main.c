/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to count number of word in a function
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../include/utils.h"
#include "../include/struct.h"
#include "../include/robot.h"
#include "../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../include/tree/tree.h"


typedef struct fridge {
    char *ingredients[9];
    int quantity[8];
} fridge_t;

void free_data(fridge_t *data_fridge)
{
    int x = 0;

    while (data_fridge->ingredients[x]) {
        free_f(data_fridge->ingredients[x]);
        x++;
    }
    free_f(data_fridge);
    return;
}

void disp_fridge(fridge_t *data_fridge)
{
    int i = 0;

    while (i < 8) {
        mini_printf("%s = %d\n", data_fridge->ingredients[i],
        data_fridge->quantity[i]);
        i++;
    }
    return;
}

int verif_ingredients(char *ingredient)
{
    int x = 0;
    char *ingredients[8] = {"tomato", "dough", "onion", "pasta", "olive",
    "pepper", "ham", "cheese"};

    while (x < 8) {
        if (!my_strcmp(ingredients[x], ingredient))
            return x;
        x++;
    }
    return -1;
}

int make_pizza(fridge_t *data_fridge)
{
    char *ingredients[8] = {"tomato", "dough", "onion", "pasta", "olive",
    "pepper", "ham", "cheese"};
    int quantity[8] = {5, 1, 3, 0, 8, 8, 4, 3};
    int x = 0;

    while (x < 8) {
        if (data_fridge->quantity[x] < quantity[x]) {
            mini_printf("'make pizza': not enough %s\n",
            data_fridge->ingredients[x]);
            return -1;
        }
        data_fridge->quantity[x] -= quantity[x];
        x++;
    }
    return 0;
}

int make_pasta(fridge_t *data_fridge)
{
    char *ingredients[8] = {"tomato", "dough", "onion", "pasta", "olive",
    "pepper", "ham", "cheese"};
    int quantity[8] = {5, 0, 0, 2, 6, 0, 4, 3};
    int x = 0;

    while (x < 8) {
        if (data_fridge->quantity[x] < quantity[x]) {
            mini_printf("'make pasta': not enough %s\n",
            data_fridge->ingredients[x]);
            return -1;
        }
        data_fridge->quantity[x] -= quantity[x];
        x++;
    }
    return 0;
}

fridge_t *init_data(fridge_t *data_fridge)
{
    int fd = open(".save", O_RDWR | O_CREAT | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    *data_fridge = (fridge_t) {{my_strdup("tomato"), my_strdup("dough"),
    my_strdup("onion"), my_strdup("pasta"), my_strdup("olive"),
    my_strdup("pepper"), my_strdup("ham"), my_strdup("cheese"),
    (char *)0x0}, {50, 50, 50, 50, 50, 50, 50, 50}};
    for (int i = 0; i < 8; i++)
        dprintf(fd, "%s = %d\n", data_fridge->ingredients[i],
        data_fridge->quantity[i]);
    close(fd);
    return data_fridge;
}

fridge_t *retrieve_data_2(char **tab_content, fridge_t *data_fridge)
{
    char **line = (char **)0x0;
    int x = 0;

    while(tab_content[x]) {
        line = split(tab_content[x], " \t=");
        if (tab_len(line) == 1 || tab_len(line) > 2 ||
        verif_ingredients(*line) == -1 || is_integer(line[1])) {
            data_fridge->ingredients[x] = (char *)0x0;
            free_2d_array(tab_content);
            free_2d_array(line);
            free_data(data_fridge);
            exit(84);
        }
        data_fridge->ingredients[x] = my_strdup(*line);
        data_fridge->quantity[x] = my_getnbr(line[1]);
        free_2d_array(line);
        x++;
    }
    data_fridge->ingredients[x] = (char *)0x0;
    return data_fridge;
}

char **retrieve_data_1(int fd, fridge_t *data_fridge)
{
    char *content = (char *)0x0;
    char **tab_content = (char **)0x0;

    content = read_map(fd, ".save");
    if (content == (char *)0x0 || *content == '\0') {
        *data_fridge->ingredients = (char *)0x0;
        free_f(content);
        free_data(data_fridge);
        exit(84);
    }
    tab_content = split(content, "\n");
    if (tab_len(tab_content) != 8) {
        free_f(data_fridge);
        free_f(content);
        free_2d_array(tab_content);
        exit(84);
    }
    free_f(content);
    return tab_content;
}

fridge_t *retrieve_data(void)
{
    fridge_t *data_fridge = malloc(sizeof(fridge_t));
    int fd = open(".save", O_RDONLY);
    char **tab_content = (char **)0x0;

    if (fd == -1)
        return init_data(data_fridge);
    tab_content = retrieve_data_1(fd, data_fridge);
    close(fd);
    data_fridge = retrieve_data_2(tab_content, data_fridge);
    free_2d_array(tab_content);
    return data_fridge;
}

void save_data(fridge_t *data_fridge)
{
    int fd = open(".save", O_RDWR | O_CREAT | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    for (int i = 0; i < 8; i++)
        dprintf(fd, "%s = %d\n", data_fridge->ingredients[i],
        data_fridge->quantity[i]);
    close(fd);
    return;
}

int make_meal(char **tab_get, fridge_t *data_fridge, int len)
{
    if (len == 2 && !my_strcmp("make", *tab_get)) {
        if (!my_strcmp("pizza", tab_get[1])) {
            make_pizza(data_fridge);
            save_data(data_fridge);
            free_2d_array(tab_get);
            return 0;
        }
        if (!my_strcmp("pasta", tab_get[1])) {
            make_pasta(data_fridge);
            save_data(data_fridge);
            free_2d_array(tab_get);
            return 0;
        }
        mini_printf("'%s': meal unknow\n", tab_get[1]);
        free_2d_array(tab_get);
        return 0;
    }
    return 1;
}

int add_ingredients(char **tab_get, fridge_t *data_fridge, int len, char *str)
{
    int index = 0;

    if (len == 3 && !my_strcmp("addToFridge", *tab_get) &&
        !is_integer(tab_get[2])) {
        index = verif_ingredients(tab_get[1]);
        if (index == -1) {
            mini_printf("'%s': Invalid operation\n", str);
            free_2d_array(tab_get);
            return 0;
        }
        data_fridge->quantity[index] += my_getnbr(tab_get[2]);
        save_data(data_fridge);
        free_2d_array(tab_get);
        return 0;
    }
    return 1;
}

int disp(char **tab_get, fridge_t *data_fridge, int len)
{
    if (len == 2 && !my_strcmp("disp", *tab_get) &&
        !my_strcmp("fridge", tab_get[1])) {
        disp_fridge(data_fridge);
        free_2d_array(tab_get);
        return 0;
    }
    return 1;
}

int fridge(char **tab_get, fridge_t *data_fridge, char *str)
{
    int len = 0;

    str[my_strlen(str) - 1] = 0x0;
    tab_get = split(str, " \t");
    len = tab_len(tab_get);
    if (len == 1 && !my_strcmp("exit", *tab_get)) {
        free_f(str);
        free_2d_array(tab_get);
        free_data(data_fridge);
        exit(0);
    }
    if (!disp(tab_get, data_fridge, len) ||
        !make_meal(tab_get, data_fridge, len) ||
        !add_ingredients(tab_get, data_fridge, len, str))
        return 0;
    free_2d_array(tab_get);
    return 1;
}

int loop_firdge(void)
{
    char *str = (char *)0x0;
    size_t len_get = 0;
    char **tab_get = (char **)0x0;
    fridge_t *data_fridge = retrieve_data();

    while (1) {
        if (getline(&str, &len_get, stdin) == -1) {
            free_f(str);
            free_data(data_fridge);
            exit(0);
        }
        if (*str == '\n')
            continue;
        if (!fridge(tab_get, data_fridge, str))
            continue;
        mini_printf("'%s': Invalid operation\n", str);
    }
    return 0;
}

int main(int ac, char **av)
{
    if (!(ac == 1))
        return 84;
    return loop_firdge();
}
