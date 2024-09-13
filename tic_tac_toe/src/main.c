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

typedef struct tictactoe_s {
    int ac;
    char **av;
    char p_1;
    char p_2;
    int grid_size;
    int x;
    int nb_p1;
    int nb_p2;
    int nb_s;
    char **grid;
    int index_player;
    char *str;
    size_t len_str;
    char **coordonates;
    int x_pos;
    int y_pos;
} tictactoe_t;

int special_wrtie(int fd, char *message, int s_return)
{
    write(fd, message, my_strlen(message));
    return s_return;
}

int check_arg(char *flag)
{
    char *tab_flag[] = {"-p1", "-p2", "-s", (char *)0x0};

    if (!flag)
        return 1;
    for (int x = 0; tab_flag[x]; x++)
        if (!my_strcmp(tab_flag[x], flag))
            return 1;
    return 0;
}

void tictactoe_grid_s(tictactoe_t *tic)
{
    for (int x = 1; x < tic->grid_size + 2; x++) {
        *tic->grid[tic->grid_size + 1] = '+';
        tic->grid[tic->grid_size + 1][x] = '-';
        tic->grid[tic->grid_size + 1][tic->grid_size + 1] = '+';
        tic->grid[tic->grid_size + 1][tic->grid_size + 2] = '\0';
    }
    tic->grid[tic->grid_size + 2] = (char *)0x0;
}

void tictactoe_grid(tictactoe_t *tic)
{
    tic->grid = malloc(sizeof(char *) * (tic->grid_size + 3));
    for (int x = 0; x < tic->grid_size + 2; x++)
        tic->grid[x] = malloc(sizeof(char) * (tic->grid_size + 3));
    for (int x = 1; x < tic->grid_size + 2; x++) {
        *tic->grid[0] = '+';
        tic->grid[0][x] = '-';
        tic->grid[0][tic->grid_size + 1] = '+';
        tic->grid[0][tic->grid_size + 2] = '\0';
    }
    for (int x = 1; x < tic->grid_size + 1; x++)
        for (int y = 1; y < tic->grid_size + 2; y++) {
            *tic->grid[x] = '|';
            tic->grid[x][y] = ' ';
            tic->grid[x][tic->grid_size + 1] = '|';
            tic->grid[x][tic->grid_size + 2] = '\0';
        }
    tictactoe_grid_s(tic);
    disp_tab(tic->grid);
    return;
}

int horizontal(tictactoe_t *tic, char player)
{
    int y = 0;

    for (int x = 1; x <= tic->grid_size; x++) {
        y = 1;
        while (tic->grid[x][y] == player)
            y++;
        if (y == tic->grid_size + 1)
            return 0;
    }
    return 1;
}

int vertical(tictactoe_t *tic, char player)
{
    int y = 0;

    for (int x = 1; x <= tic->grid_size; x++) {
        y = 1;
        while (tic->grid[y][x] == player)
            y++;
        if (y == tic->grid_size + 1)
            return 0;
    }
    return 1;
}

int diagonal(tictactoe_t *tic, char player)
{
    int x = 1;

    while (tic->grid[x][x] == player)
        x++;
    if (x == tic->grid_size + 1)
        return 0;
    return 1;
}

int in_diagonal(tictactoe_t *tic, char player)
{
    int x = 1;
    int y = tic->grid_size;

    while (tic->grid[x][y] == player) {
        x++;
        y--;
    }
    if (x == tic->grid_size + 1)
        return 0;
    return 1;
}

int check_conditions(tictactoe_t *tic, char character)
{
    if (!horizontal(tic, character))
        return 0;
    if (!vertical(tic, character))
        return 0;
    if (!diagonal(tic, character))
        return 0;
    if (!in_diagonal(tic, character))
        return 0;
    return 1;
}

int put_character(tictactoe_t *tic)
{
    tic->x_pos += 1;
    tic->y_pos += 1;
    if ((tic->index_player % 2))
        if (tic->grid[tic->x_pos][tic->y_pos] == ' ')
            tic->grid[tic->x_pos][tic->y_pos] = tic->p_1;
        else {
            free_2d_array(tic->coordonates);
            return 0;
        }
    else
        if (tic->grid[tic->x_pos][tic->y_pos] == ' ')
            tic->grid[tic->x_pos][tic->y_pos] = tic->p_2;
        else {
            free_2d_array(tic->coordonates);
            return 0;
        }
    return 1;
}

int prompt_error_handling(tictactoe_t *tic)
{
    if (*tic->str == '\n')
        return 0;
    if (!my_strlen_s(tic->str, ',') || my_strlen_s(tic->str, ',') > 1)
        return 0;
    tic->coordonates = split(tic->str, ", \t\n");
    if (!(tab_len(tic->coordonates) == 2) || is_integer(tic->coordonates[0]) ||
        is_integer(tic->coordonates[1])) {
        free_2d_array(tic->coordonates);
        return 0;
    }
    tic->x_pos = my_getnbr(tic->coordonates[1]);
    tic->y_pos = my_getnbr(tic->coordonates[0]);
    if (tic->x_pos < 0 || tic->y_pos < 0 || tic->x_pos >= tic->grid_size ||
        tic->y_pos >= tic->grid_size) {
        free_2d_array(tic->coordonates);
        return 0;
    }
    if (!put_character(tic))
        return 0;
    return 1;
}

int end_game(tictactoe_t *tic)
{
    if ((tic->index_player % 2))
        if (!check_conditions(tic, tic->p_1)) {
            my_putstr("Player 1 won!\n");
            free_2d_array(tic->coordonates);
            free_f(tic->str);
            free_2d_array(tic->grid);
            free_f(tic);
            return 0;
        }
    else
        if (!check_conditions(tic, tic->p_2)) {
            my_putstr("Player 2 won!\n");
            free_2d_array(tic->coordonates);
            free_f(tic->str);
            free_2d_array(tic->grid);
            free_f(tic);
            return 0;
        }
    return 1;
}

int read_line(tictactoe_t *tic)
{
    if (getline(&tic->str, &tic->len_str, stdin) == -1) {
        free_f(tic->str);
        free_2d_array(tic->grid);
        free_f(tic);
        return 0;
    }
    return 1;
}

int retrieve_flag_p1_s(tictactoe_t *tic)
{
    if (tic->x + 1 < tic->ac) {   
        if (my_strlen(tic->av[tic->x + 1]) == 1) {
            tic->p_1 = *tic->av[tic->x + 1];
            tic->x++;
        } else
            return special_wrtie(2, "Tictactoe: Bad defintion of the character used bad the first player.\n", 0);
    } else
        return special_wrtie(2, "Tictactoe: the character of first player not define.\n", 0);
    return 1;
}

int retrieve_flag_p1(tictactoe_t *tic)
{
    if (!my_strcmp("-p1", tic->av[tic->x])) {
        tic->nb_p1++;
        if (!retrieve_flag_p1_s(tic))
            return 0;
    }
    return 1;
}

int retrieve_flag_p2_s(tictactoe_t *tic)
{
    if (tic->x + 1 < tic->ac) {   
        if (my_strlen(tic->av[tic->x + 1]) == 1) {
            tic->p_2 = *tic->av[tic->x + 1];
            tic->x++;
        } else
            return special_wrtie(2, "Tictactoe: Bad defintion of the character used bad the second player.\n", 0);
    } else
        return special_wrtie(2, "Tictactoe: the character of second player not define.\n", 0);
    return 1;
}

int retrieve_flag_p2(tictactoe_t *tic)
{
    if (!my_strcmp("-p2", tic->av[tic->x])) {
        tic->nb_p2++;
        if (!retrieve_flag_p2_s(tic))
            return 0;
    }
    return 1;
}

int retrieve_flag_grid_size_s1(tictactoe_t *tic)
{   
    if (!is_integer(tic->av[tic->x + 1])) {
        tic->grid_size = my_getnbr(tic->av[tic->x + 1]);
        if (tic->grid_size < 0)
            return special_wrtie(2, "Tictactoe: Negative grid size define by users.\n", 0);
        tic->x++;
    } else
        return special_wrtie(2, "Tictactoe: Grid size must be an integer.\n", 0);
    return 1;
}

int retrieve_flag_grid_size_s(tictactoe_t *tic)
{
    if (tic->x + 1 < tic->ac) {
        if (!retrieve_flag_grid_size_s1(tic))
            return 0;
    } else
        return special_wrtie(2, "Tictactoe: the grid size is not define.\n", 0);
    return 1;
}

int retrieve_flag_grid_size(tictactoe_t *tic)
{
    if (!my_strcmp("-s", tic->av[tic->x])) {
        tic->nb_s++;
        if (!retrieve_flag_grid_size_s(tic))
            return 0;
    }
    return 1;
}

int retrieve_arguments(tictactoe_t *tic)
{
    if (tic->ac > 7)
        return 0;
    for (tic->x = 1; tic->av[tic->x]; tic->x++) {
        if (!retrieve_flag_p1(tic))
            return 0;
        if (!retrieve_flag_p2(tic))
            return 0;
        if (!retrieve_flag_grid_size(tic))
            return 0;
        if (!check_arg(tic->av[1]))
            return special_wrtie(2, "Tictactoe: Blablabla ? Read your subject please\n", 0);
        if (!check_arg(tic->av[tic->x + 1]))
            return special_wrtie(2, "Tictactoe: Blablabla ? Read your subject please\n", 0);
    }
    return 1;
}

int loop_tictactoe(tictactoe_t *tic)
{
    tictactoe_grid(tic);
    while (1) {
        if ((tic->index_player % 2))
            my_putstr("Player 1> ");
        else
            my_putstr("Player 2> ");
        if (!read_line(tic))
            return 0;
        if (!prompt_error_handling(tic))
            continue;
        disp_tab(tic->grid);
        if (!end_game(tic))
            return 0;
        free_2d_array(tic->coordonates);
        tic->index_player++;
    }
    free_f(tic->str);
    free_2d_array(tic->grid);
    free_f(tic);
    return 1;
}

int erro_message(tictactoe_t *tic)
{
    if (tic->p_1 == tic->p_2)
        return special_wrtie(2, "Tictactoe: Why double definition of same character ? Please are You mad !?\n", 0);
    if (tic->nb_p1 > 1)
        return special_wrtie(2, "Tictactoe: Why many definition of flag -p1 ? Read your subject please\n", 0);
    if (tic->nb_p2 > 1)
        return special_wrtie(2, "Tictactoe: Why many definition of flag -p2 ? Read your subject please\n", 0);
    if (tic->nb_s > 1)
        return special_wrtie(2, "Tictactoe: Why many definition of flag -s ? Read your subject please\n", 0);
    return 1;
}

int main(int ac, char **av)
{
    tictactoe_t *tic = malloc(sizeof(tictactoe_t));

    *tic = (tictactoe_t) {ac, av, 'X', 'O', 3, 0, 0, 0, 0, (char **)0x0,
    1, (char *)0x0, 0, (char **)0x0, 0, 0};
    if (!retrieve_arguments(tic)) {
        free_f(tic);
        return 84;
    }
    if (!erro_message(tic)) {
        free_f(tic);
        return 84;
    }
    if (!loop_tictactoe(tic))
        return 0;
    return 0;
}
