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
#include "../include/utils.h"
#include "../include/struct.h"
#include "../include/robot.h"
#include "../include/all_linked_list/doubly_linked_list/d_list.h"
#include "../include/tree/tree.h"

/*
    FRACTALS
    //man Google pour l' utilisation de exclamation en c '!'

    Mon Algo consiste a determier le nouveau positionnement des carateres de l' anciens
    fractals pour ensuite former le nouveu fractals grace aux deux patterns.


    //iteration 0

     0
    +-+
   0|#|
    +-+

    //iteration 1

    *creation matrice fractal et nouveau positionnement des characters
     0 1
    +-+-+
   0|#| |
    +-+-+
   1| | |
    +-+-+


    *remplacement des patternes pour former le nouveau fractal
     0 1
    +-+-+
   0|#|#|
    +-+-+
   1|#|.|
    +-+-+

    //iteration 2

    *creation matrice fractal et nouveau positionnement des characters
     0 1 2 3
    +-+-+-+-+
   0|#| |#| |
    +-+-+-+-+
   1| | | | |
    +-+-+-+-+
   2|#| |.| |
    +-+-+-+-+
   3| | | | |
    +-+-+-+-+


    *remplacement des patternes pour former le nouveau fractal
     0 1 2 3
    +-+-+-+-+
   0|#|#|#|#|                   ####
    +-+-+-+-+                   #.#.
   1|#|.|#|.|                   ##..
    +-+-+-+-+       ---->       ##..
   2|#|#|.|.|
    +-+-+-+-+
   3|#|.|.|.|
    +-+-+-+-+

    //iteration 3

     0 1 2 3 4 5 6 7
    +-+-+-+-+-+-+-+-+
   0|#| |#| |#| |#| |
    +-+-+-+-+-+-+-+-+
   1| | | | | | | | |
    +-+-+-+-+-+-+-+-+
   2|#| |.| |#| |.| |
    +-+-+-+-+-+-+-+-+
   3| | | | | | | | |
    +-+-+-+-+-+-+-+-+
   4|#| |#| |.| |.| |
    +-+-+-+-+-+-+-+-+
   5| | | | | | | | |
    +-+-+-+-+-+-+-+-+
   6|#| |.| |.| |.| |
    +-+-+-+-+-+-+-+-+
   7| | | | | | | | |
    +-+-+-+-+-+-+-+-+


     0 1 2 3 4 5 6 7
    +-+-+-+-+-+-+-+-+
   0|#|#|#|#|#|#|#|#|
    +-+-+-+-+-+-+-+-+
   1|#|.|#|.|#|.|#|.|
    +-+-+-+-+-+-+-+-+
   2|#|#|.|.|#|#|.|.|                  ########
    +-+-+-+-+-+-+-+-+                  #.#.#.#.
   3|#|.|.|.|#|.|.|.|                  ##..##..
    +-+-+-+-+-+-+-+-+      --->        #...#...
   4|#|#|#|#|.|.|.|.|                  ####....
    +-+-+-+-+-+-+-+-+                  #.#.....
   5|#|.|#|.|.|.|.|.|                  ##......
    +-+-+-+-+-+-+-+-+                  #.......
   6|#|#|.|.|.|.|.|.|
    +-+-+-+-+-+-+-+-+
   7|#|.|.|.|.|.|.|.|
    +-+-+-+-+-+-+-+-+

*/

int main(int ac, char **av)
{
    fractal_t *frac = malloc(sizeof(fractal_t));

    *frac = (fractal_t) {ac, av, 0, (char **)0x0,
    (char **)0x0, 0, 0, 0, 0, 0, 0, (char **)0x0,
    1, 1, 0, 0, 0, 0, 0, (char **)0x0};
    if (!error_handling(frac)) {
        free_f(frac);
        return 84;
    }
    if (!iteration_zero(frac))
        return 0;
    if (!iterations(frac))
        return 84;
    return 0;
}
