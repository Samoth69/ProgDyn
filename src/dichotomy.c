#include "dichotomy.h"

/**
 * dichotomy search inside array
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

    // we divise array that have more than 32 values.
    while (_size > 32)
    {
        _size = _size / 2;
        if (array[start_val + _size] < value)
        {
            start_val += _size;
        }
    }

    // when here, the array has AT MAX 32 items
    // at this point, we are doing a basic 'brute force' search with a for loop
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