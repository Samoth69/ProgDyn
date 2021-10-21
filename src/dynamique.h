#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void dyna_gen_tableau(int **tb, int size, int black_point_count);
void dyna_print_tableau(int **tb, int size);
void dyna_search_pgcb(int **tb, int size);