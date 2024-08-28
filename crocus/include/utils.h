/*
** EPITECH PROJECT, 2024
** ANAGRAM
** File description:
** All functions prototypes
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct clean {
    int r;
    int i;
    int y;
    int u;
    char *new;
} clean_t;

typedef struct my_strcat {
    int index_0;
    int index_1;
    int index_2;
    char *src;
    char const *dest;
    char *res_cat;
} my_strcat_t;

typedef struct split {
    int a;
    int b;
    int i;
    int j;
    int k;
} split_t;

extern clean_t *e;

char *clean_str(char *str);

int count_word(char const *str, int (*func)(char));

void disp_tab(char **tab);

int err_putchar(char c);

int err_putnbr(int nb);

int err_putstr(char const *str);
int err_mini_printf(const char *format, ...);

void free_2d_array(char **map);

void free_3d_array(char ***map);

void *free_f(void *ptr);

int is_anum(char const c);

int is_alpha(char const c);

int is_char(char *str, char c);

int is_digit(char c);

int is_empty_line(char *str);

int is_integer(char const *str);

int is_sign(char const c);

int mini_printf(const char *format, ...);

int my_cheker(char const *map);

int my_getnbr(char const *str);

int my_putchar(char c);

int my_putnbr(int nb);

int my_putstr(char const *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char *s1, char *s2);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strdup(char const *str);

int my_strlen(const char *str);

int my_strlen_s(const char *str, char stop);

int my_strncmp(char *s1, char *s2, int n);

char **my_tabdup(char **tab);

int fs_open_file(char const *filepath);

char *read_map(int fd, char *filepath);

int special_wrtie(int fd, char *message, int s_return);

char **split(char *str, char *seg);

int tab_len(char **tab);

int three_tab_len(char ***tab);

#pragma once
