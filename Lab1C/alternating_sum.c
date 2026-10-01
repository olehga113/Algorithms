#include <stdio.h>
#include "array.h"

Array *read_array(const char *filename)
{
    FILE *input = fopen(filename, "r");

    if (input == NULL)
        return NULL;

    int n;

    if (fscanf(input, "%d", &n) != 1 || n <= 0)
    {
        fclose(input);
        return NULL;
    }

    Array *arr = array_create((size_t)n, NULL);

    if (arr == NULL)
    {
        fclose(input);
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        int value;

        if (fscanf(input, "%d", &value) != 1)
        {
            array_delete(arr);
            fclose(input);
            return NULL;
        }

        array_set(arr, (size_t)i, (Data)value);
    }

    fclose(input);
    return arr;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    Array *arr = read_array(argv[1]);

    if (arr == NULL)
        return 1;

    long long result = 0;

    for (size_t i = 0; i < array_size(arr); ++i)
    {
        int value = (int)array_get(arr, i);

        if (i % 2 == 0)
            result += value;
        else
            result -= value;
    }

    printf("%lld\n", result);

    array_delete(arr);

    return 0;
}
