/*
** EPITECH PROJECT, 2024
** MY_NAVY
** File description:
** Function to count number of word in a function
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/utils.h"
#include "../../include/struct.h"
#include "../../include/robot.h"
#include "../../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../../include/tree/tree.h"

int character_used_handling(sandpile_t *sand)
{
    int x = 0;

    if (!*sand->av[2])
        return special_wrtie(2, "Sandpile: Sand string is empty.\n", 0);
    if (my_strlen(sand->av[2]) > 4)
        return special_wrtie(2, "Sandpile: More characters defined.\n", 0);
    if (my_strlen(sand->av[2]) < 4)
        return special_wrtie(2, "Sandpile: Fewer characters defined.\n", 0);
    sand->characters_used = sand->av[2];
    while (sand->content[x])
        if (is_char(sand->characters_used, sand->content[x]) ||
        sand->content[x] == '\n')
            x++;
        else
            return special_wrtie(2, "Sandpile: Bad definition of characters used on the initial grid / Initial grid have a grains whom is not stable.\n", 0);
    return 1;
}

int grid_handling(sandpile_t *sand)
{
    sand->content = read_map(sand->fd, sand->av[1]);
    close(sand->fd);
    if (!*sand->content || !sand->content)
        return special_wrtie(2, "Sandpile: File is empty.\n", 0);
    sand->char_matrix = split(sand->content, "\n");
    sand->height = tab_len(sand->char_matrix);
    sand->weight = my_strlen(sand->char_matrix[0]);
    for (int x = 0; sand->char_matrix[x]; x++)
        sand->len_content += my_strlen(sand->char_matrix[x]);
    if (!(sand->height * sand->weight == sand->len_content)) {
        free_2d_array(sand->char_matrix);
        return special_wrtie(2, "Sandpile: Initial grid must be rectangular.\n", 0);
    }
    return 1;
}

int  error_handling(sandpile_t *sand)
{
    if (!(sand->ac == 4))
        return 0;
    sand->fd = fs_open_file(sand->av[1]);
    if (sand->fd == -1)
        return 0;
    if (!grid_handling(sand)) {
        free_f(sand->content);
        return 0;
    }
    if (!character_used_handling(sand) || !iterations_handling(sand)) {
        free_f(sand->content);
        free_2d_array(sand->char_matrix);
        return 0;
    }
    return 1;
}
