#include <iostream>

template <typename T>
void print_array(T* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void bubble_sort(T* arr, int size)
{
    for(int a = 0; a < size; ++a)
    {
        for(int b = size - 1; b > 0; --b)
        {
            if(arr[b] < arr[b - 1])
            {
                std::swap(arr[b], arr[b - 1]);
            }
        }
    }
}

template <typename T>
void fill_random_array(T* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = rand() % size + 1;
    }
}
