#include <iostream>
#include <cmath>
#include <memory>

using namespace std;

constexpr int SIZE {11};
constexpr double limit = 400.0;

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

template <typename T>
void fill_array(T* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        T value;
        std::cin >> value;
        arr[i] = value;
    }
}

template <typename T>
void reverse_array(T* arr, int size)
{
    for(int i = 0; i < size - i - 1; ++i)
    {
        std::swap(arr[i], arr[size - i - 1]);
    }
}

double func(double value)
{
    return sqrt(fabs(value)) + 5 * pow(value, 3);
}

void check_value(double* arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        double y = func(arr[i]);
        if(y > limit)
        {
            std::cout << "Value " << y <<  " is more than limit 400." << std::endl;
        }
        else
        {
            std::cout << "Value " << y << " is OK." << std::endl;
        }
    }
}

int main()
{
    // ====== TASK #1 ======
    srand((unsigned)time(nullptr));
    auto deleter_i = [&](int* p) {delete[] p; };
    std::unique_ptr<int[], decltype(deleter_i)> arr{ new int[SIZE], deleter_i };

    fill_random_array(arr.get(), SIZE);
    print_array(arr.get(), SIZE);
    bubble_sort(arr.get(), SIZE);
    print_array(arr.get(), SIZE);

    // ====== TASK #2 =====

    auto deleter_d = [&](double* p) {delete[] p; };
    std::unique_ptr<double[], decltype(deleter_d)> p{ new double[SIZE], deleter_d };

    std::cout << "Input sequence from 11 numbers with floating point." << std::endl;
    fill_array(p.get(), SIZE);
    reverse_array(p.get(), SIZE);
    print_array(p.get(), SIZE);
    check_value(p.get(), SIZE);

    return 0;
}


