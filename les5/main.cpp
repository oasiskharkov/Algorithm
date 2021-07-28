#include "common.h"
#include <memory>

using namespace std;
constexpr int SIZE = 30;

template<typename T>
void quick_sort(T* arr, int first, int last)
{
    int i = first;
    int j = last;

    const T& x = arr[(first + last) / 2];
    do {
        while(arr[i] < x) i++;
        while(arr[j] > x) j--;

        if(i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }

    } while (i <= j);
    if(i < last) quick_sort(arr, i, last);
    if(j > first) quick_sort(arr, first, j);
}

template<typename T>
void insert_sort(T* arr, int first, int last)
{
    int pos;
    T temp;
    for(int i = first + 1; i <= last; ++i)
    {
        temp = arr[i];
        pos = i - 1;
        while(pos >= 0 and arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

template<typename T>
void improved_quick_sort(T* arr, int first, int last)
{
    if(last - first + 1 <= 10)
    {
        insert_sort(arr, first, last);
    }
    else
    {
        int middle = (first + last) / 2;

        if (arr[first] > arr[last])
        {
            std::swap(arr[first], arr[last]);
        }

        if (arr[middle] < arr[first])
        {
            std::swap(arr[first], arr[middle]);
        }
        else if (arr[last] < arr[middle])
        {
            std::swap(arr[last], arr[middle]);
        }

        int i = first;
        int j = last;

        const T& x = arr[middle];
        do {
            while(arr[i] < x) i++;
            while(arr[j] > x) j--;

            if(i <= j)
            {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }

        } while (i <= j);
        if (i < last) improved_quick_sort(arr, i, last);
        if (j > first) improved_quick_sort(arr, first, j);
    }
}

void block_sort(int* arr, int size)
{
    const int max = size;
    const int b = 10;

    int buckets[b][max + 1];
    for(int i = 0; i < b; ++i)
    {
        buckets[i][max] = 0;
    }

    for(int digit = 1; digit < 1'000'000'000; digit *= 10)
    {
        for(int i = 0; i < max; ++i)
        {
            int d = (arr[i] / digit) % 10;
            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max] = counter;
        }
        int idx = 0;
        for(int i = 0; i < b; ++i)
        {
            for(int j = 0; j < buckets[i][max]; ++j)
            {
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

void block_sort_even(int* arr, int size)
{
    const int max = size;
    const int b = 10;

    int buckets[b][max + 1];
    for(int i = 0; i < b; ++i)
    {
        buckets[i][max] = 0;
    }

    for(int digit = 1; digit < 1'000'000'000; digit *= 10)
    {
        for(int i = 0; i < max; ++i)
        {
            if (arr[i] % 2 == 0)
            {
                int d = (arr[i] / digit) % 10;
                int counter = buckets[d][max];
                buckets[d][counter] = arr[i];
                counter++;
                buckets[d][max] = counter;
                arr[i] = -1;
            }


        }
        int idx = 0;
        for(int i = 0; i < b; ++i)
        {
            for(int j = 0; j < buckets[i][max]; ++j)
            {
                while(arr[idx] != -1) idx++;

                arr[idx] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
}

/*void block_sort_even(int* arr, int size)
{
    int* p = new int[size];
    int counter = 0;
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] % 2 == 0)
        {
            p[counter++] = arr[i];
        }
    }

    block_sort(p, counter);

    int cnt = 0;
    for(int i = 0; i < size; ++i)
    {
        if(arr[i] % 2 == 0)
        {
            arr[i] = p[cnt++];
        }
    }
    delete [] p;
}*/

int main()
{

    srand((unsigned)time(nullptr));
    auto deleter_i = [&](int* p) {delete[] p; };

    // ====== TASK #1 ======
    std::unique_ptr<int[], decltype(deleter_i)> arr{ new int[SIZE], deleter_i };
    fill_random_array(arr.get(), SIZE);
    print_array(arr.get(), SIZE);
    improved_quick_sort(arr.get(), 0, SIZE - 1);
    print_array(arr.get(), SIZE);

    // ====== TASK #2 ======
    std::unique_ptr<int[], decltype(deleter_i)> arr1{ new int[SIZE], deleter_i };
    fill_random_array(arr1.get(), SIZE);
    print_array(arr1.get(), SIZE);
    block_sort_even(arr1.get(), SIZE);
    //block_sort(arr1.get(), SIZE);
    print_array(arr1.get(), SIZE);

    return 0;
}
