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
#include "../../../include/robot.h"

Test(crocus, call_functon)
{
    char *expected = " 000   000   000  0000    00  00000  000  00000  000   000 \n0   0 0 00  0   0     0  0 0  0     0         0 0   0 0   0\n0   0   00     0   000  0  0  0000  0000     0   000   0000\n0   0   00   0        0 00000     0 0   0   0   0   0     0\n 000   0000 00000 0000     0  0000   000   0     000   000 \n";
    cr_redirect_stdout();
    crocus("0123456789", NULL);
    cr_assert_stdout_eq_str(expected);
}

Test(crocus, call_functon_2)
{
    char *expected = " aaa   sss   ttt  eeee    kk  aaaaa  sss  ttttt  eee   kkk \na   a s ss  t   t     e  k k  a     s         t e   e k   k\na   a   ss     t   eee  k  k  aaaa  ssss     t   eee   kkkk\na   a   ss   t        e kkkkk     a s   s   t   e   e     k\n aaa   ssss ttttt eeee     k  aaaa   sss   t     eee   kkk \n";
    cr_redirect_stdout();
    crocus("0123456789", "astek");
    cr_assert_stdout_eq_str(expected);
}

Test(crocus, call_functon_3)
{
    char *expected = " 000 \n0   0\n0   0\n0   0\n 000 \n";
    cr_redirect_stdout();
    crocus("0", NULL);
    cr_assert_stdout_eq_str(expected);
}