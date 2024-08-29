/*
** EPITECH PROJECT, 2024
** ASM
** File description:
** ASM
*/

#ifndef _ASM_
    #define _ASM_
    #include <limits.h>

typedef struct sandpile_s {
    int ac;
    char **av;
    int fd;
    char *characters_used;
    int iterations;
    int **sand_matrix;
    char *content;
    char **char_matrix;
    int height;
    int weight;
    int len_content;
    int x_grain;
    int y_grain;
    int x_center;
    int y_center;
} sandpile_t;


int choose_number(sandpile_t *sand, char char_string);
int choose_character_s(sandpile_t *sand, int number, int x);
char choose_character(sandpile_t *sand, int number);
int character_used_handling(sandpile_t *sand);
void disp_matrix(sandpile_t *sand);
int error_handling(sandpile_t *sand);
void free_sand(sandpile_t *sand);
int grid_handling(sandpile_t *sand);
void handling_reaction(sandpile_t *sand);
int iterations_handling(sandpile_t *sand);
void matrix(sandpile_t *sand);
void replace_matrix(sandpile_t *sand);
void sandpile_handling(sandpile_t *sand);
#endif /* !_ASM_ */
