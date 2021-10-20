#include <stdlib.h>

typedef struct
{
    int c;
    int w;
} glouton;

void GloutonFillByQP(glouton* g, size_t size, int W, glouton *out, int *size_out);
void GloutonTriParQP(glouton *data, int size);