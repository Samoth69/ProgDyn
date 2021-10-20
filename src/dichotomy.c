#include "dichotomy.h"

/**
 * Recherche par dichotomie dans un tableau d'entiers
 * @param array The array of values
 * @param size The size of the array
 * @param value The value to find
 * @return The position of the value found or -1
 */
int find_by_dichotomy(int array[], size_t size, int value)
{
    int ret = -1;
    int start_val = 0;
    int _size = size;

    // on divise les tableaux qui ont plus de 32 éléments
    while (_size > 32)
    {
        _size = _size / 2;
        if (array[start_val + _size] < value)
        {
            start_val += _size;
        }
    }

    // si le tableau fait moins de 32 éléments,
    // on fait une recherche 'brut' car suffisant
    for (int i = start_val; i <= (start_val + _size); i++)
    {
        if (array[i] == value)
        {
            ret = i;
            break;
        }
    }

    return ret;
}