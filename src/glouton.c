#include "glouton.h"

void GloutonFillByQP(glouton *g, size_t size, int W, glouton *out, int *size_out)
{
    int wsum = 0;
    int counter = 0;

    GloutonTriParQP(g, size);
    for (int i = 0; i < size && wsum <= W; i++)
    {
        out[counter] = g[i];
        wsum += out[counter].w;
        counter++;
    }

    *size_out = counter;
}

void GloutonTriParQP(glouton *data, int size)
{
    glouton temp;
    int j = 0;
    for (int i = 1; i < size; i++)
    {
        temp = data[i];
        j = i;

        float curP = (float)temp.c / temp.w;
        float j1 = (float)data[j - 1].c / data[j - 1].w;

        while (curP > j1 && j > 0)
        {
            data[j] = data[j - 1];
            j--;
        }

        data[j] = temp;
    }
}