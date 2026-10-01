#include <stdio.h>
#include "array.h"

int main(void)
{
    Array *arr = array_create(5, NULL);

    if (arr == NULL)
        return 1;

    if (array_size(arr) != 5)
        return 1;

    for (size_t i = 0; i < 5; ++i)
        array_set(arr, i, (Data)(i * 10));

    for (size_t i = 0; i < 5; ++i)
    {
        if (array_get(arr, i) != (Data)(i * 10))
            return 1;
    }

    array_delete(arr);

    printf("Array test passed\n");
    return 0;
}
