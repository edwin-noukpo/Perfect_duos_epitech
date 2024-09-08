/*
** EPITECH PROJECT, 2024
** ASM
** File description:
** ASM
*/

#ifndef _ASM_
    #define _ASM_
    #include <time.h>
void verif_dictionary(char **tab);
char **dictionary(char *filepath);
int win_lost(char *word_s, int tries, int count);
void init_disp(char *word, char *word_s, int tries);
int init_tries(char *nb);
int *analyse_letter(char *line, char *word, char *word_s);
void hang_man_loop(char **tab, char *word, char *word_s, int tries);
char *retrieve_line(char **tab, char *word, char *word_s);
void hang_man(int ac, char **av);
#endif /* !_ASM_ */
