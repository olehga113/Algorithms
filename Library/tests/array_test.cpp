#include "array.h"
#include <iostream>
#include <stdexcept>

int main()
{
    Array* arr = array_create(5);
    if (array_size(arr) != 5)
    {
        std::cerr << "Неверный размер массива" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < array_size(arr); i++)
    {
        array_set(arr, i, static_cast<Data>(i * 2));
    }

    for (size_t i = 0; i < array_size(arr); i++)
    {
        if (array_get(arr, i) != static_cast<Data>(i * 2))
        {
            std::cerr << "Неверное значение элемента массива" << std::endl;
            return 1;
        }
    }

    bool caughtOnGet = false;
    try
    {
        array_get(arr, array_size(arr));
    }
    catch (const std::out_of_range&)
    {
        caughtOnGet = true;
    }
    if (!caughtOnGet)
    {
        std::cerr << "array_get не бросил исключение при выходе за границы" << std::endl;
        return 1;
    }

    bool caughtOnSet = false;
    try
    {
        array_set(arr, array_size(arr) + 10, 1);
    }
    catch (const std::out_of_range&)
    {
        caughtOnSet = true;
    }
    if (!caughtOnSet)
    {
        std::cerr << "array_set не бросил исключение при выходе за границы" << std::endl;
        return 1;
    }

    array_destroy(arr);

    Array* empty = array_create(0);
    if (array_size(empty) != 0)
    {
        std::cerr << "Пустой массив имеет неверный размер" << std::endl;
        return 1;
    }
    array_destroy(empty);

    std::cout << "Все проверки массива пройдены успешно" << std::endl;
    return 0;
}
