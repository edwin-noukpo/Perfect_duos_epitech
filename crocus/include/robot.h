/*
** EPITECH PROJECT, 2024
** ASM
** File description:
** ASM
*/

#ifndef _ASM_
    #define _ASM_
    #include <limits.h>

typedef struct crocus_s {
    int ac;
    char **av;
    char *tab_number;
    char *tab_string;
    int nb_n;
    int nb_s;
    int x;
} crocus_t;

char **change_letter(char **str, char letter);

char change_s(char actu_letter, char new_letter);

void crocus(char *tab_number, char *tab_string);

char crocus_character(char *tab_string, int nb);

void display_crocus(char ***tab);

void display_s(char ***tab, int i);

int error_handling(crocus_t *croc);

char **five(void);

char **get_tab_number(int nb);

char **get_tab_number_s(int nb);

char **height(void);

char **four(void);

int loop_handling_number(crocus_t *croc);

int loop_handling_string(crocus_t *croc);

char **nine(void);

char **one(void);

char **seven(void);

char **six(void);

char **three(void);

char **two(void);

char **zero(void);

#endif /* !_ASM_ */
