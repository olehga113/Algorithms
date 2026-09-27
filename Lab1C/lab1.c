#include <stdio.h>
#include "array.h"

Array *array_create_and_read(FILE *input)
{
    int n;

    if (fscanf(input, "%d", &n) != 1 || n <= 0)
        return NULL;

    Array *arr = array_create(n, NULL);

    if (arr == NULL)
        return NULL;

    for (int i = 0; i < n; ++i)
    {
        int x;
        fscanf(input, "%d", &x);
        array_set(arr, i, (Data)x);
    }

    return arr;
}

void task1(Array *arr)
{
    if (arr == NULL)
        return;

    for (size_t i = 0; i < array_size(arr); ++i)
    {
        printf("%d", (int)array_get(arr, i));

        if (i + 1 < array_size(arr))
            printf(" ");
    }

    printf("\n");
}

void task2(Array *arr)
{
    if (arr == NULL)
        return;

    for (size_t i = 0; i < array_size(arr); ++i)
    {
        printf("%d", (int)array_get(arr, i));

        if (i + 1 < array_size(arr))
            printf(" ");
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
        return 1;

    Array *arr = array_create_and_read(input);
    task1(arr);
    array_delete(arr);

    arr = array_create_and_read(input);
    task2(arr);
    array_delete(arr);

    fclose(input);

    return 0;
}
