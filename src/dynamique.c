#include "dynamique.h"

/**
 * @brief generate the matrix
 * 
 * @param tb array in form of dual pointer array (also known as matrix)
 * @param size number of rows/cols
 * @param black_point_count number of black point on the matrix
 */
void dyna_gen_tableau(int **tb, int size, int black_point_count)
{
    //cleaning (filling 0 at first)
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            tb[i][j] = 0;
        }
    }

    srand(time(NULL));

    //make sure we have the expected amount of black point,
    //even in the event that the same coord are outputted twice by the rand()
    int counter = 0;
    while (counter < black_point_count)
    {
        int x = rand() % size;
        int y = rand() % size;
        if (tb[x][y] == 0)
        {
            tb[x][y] = 1;
            counter++;
        }
    }
}

/**
 * @brief print the given array on STDOUT
 * 
 * @param tb array
 * @param size the of the array
 */
void dyna_print_tableau(int **tb, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            switch (tb[i][j])
            {
            case 0:
                putchar(' ');
                break;
            case 1:
                putchar('*');
                break;
            case 2:
                putchar('#');
                break;
            }
        }
        putchar('\n');
    }
}

void initElem(pointList *pt)
{
    pt->size = 0;
}

void addElem(pointList *pt, int x, int y)
{
    pt->x[pt->size] = x;
    pt->y[pt->size] = y;
    pt->size++;
}

bool coordInside(pointList *pt, int startX, int endX, int startY, int endY)
{
    bool ret = false;
    for (int i = 0; i < pt->size; i++)
    {
        if (startX >= pt->x[i] && pt->x[i] <= endX &&
            startY >= pt->y[i] && pt->y[i] <= endY)
        {
            ret = true;
            break;
        }
    }
    return ret;
}

void clearElem(pointList *pt)
{
    pt->size = 0;
}

/**
 * @brief Search the biggest square with no '*' inside.
 * This square will be marked with '#' in the array
 * 
 * @param tb array
 * @param size size of the array
 */
void dyna_search_pgcb(int **tb, int size)
{
    int bestSize = 0;
    // int bestX = 0;
    // int bestY = 0;

    pointList *pts = (pointList *)malloc(sizeof(pointList));
    initElem(pts);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (tb[i][j] != 1)
            {
                int res = dyna_search_square(tb, size, i, j);
                if (res > bestSize)
                {
                    clearElem(pts);
                    bestSize = res;
                    //bestX = i;
                    //bestY = j;
                    addElem(pts, i, j);
                }
                else if (res == bestSize)
                {
                    if (!coordInside(pts, i, i + bestSize, j, j + bestSize))
                        addElem(pts, i, j);
                }
            }
        }
    }

    for (int ptt = 0; ptt < pts->size; ptt++)
    {
        for (int i = pts->x[ptt]; i < pts->x[ptt] + bestSize; i++)
        {
            for (int j = pts->y[ptt]; j < pts->y[ptt] + bestSize; j++)
            {
                if (tb[i][j] == 0)
                    tb[i][j] = 2;
            }
        }
    }

    printf("bestSize: %d\n", bestSize);
    // printf("bestX: %d\n", bestX);
    // printf("bestY: %d\n", bestY);
}

/**
 * @brief Compute the biggest array size for a square before hitting a '*' in the main array
 * 
 * @param tb main array
 * @param size size of the main array
 * @param curX start x position on the main array
 * @param curY start y position on the main array
 * @return int the last valid size before hiting a '*'
 */
int dyna_search_square(int **tb, int size, int curX, int curY)
{
    //will go to true once a '*' has been reach, or end of array
    bool done = false;

    //size of the square
    int square_size = 1;
    while (!done)
    {
        //if the size of the research square exceeds the size of the array
        if (curX + square_size >= size || curY + square_size >= size)
        {
            done = true;
        }
        else
        {
            int maxX = curX + square_size;
            int maxY = curY + square_size;
            for (int i = curX; i < maxX && !done; i++)
            {
                if (tb[i][maxY] == 1)
                {
                    done = true;
                }
            }
            for (int j = curY; j < maxY && !done; j++)
            {
                if (tb[maxX][j] == 1)
                {
                    done = true;
                }
            }
            if (tb[maxX][maxY] == 1)
            {
                done = true;
            }

            if (!done)
                square_size++;
        }
    }

    return square_size;
}