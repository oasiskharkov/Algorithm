#include "stack_array.h"
#include "priority_queue.h"

constexpr int size = 100;

void print_binary(int val)
{
    StackArray<int, size> stackArray;

    if(!val)
    {
         stackArray.push(0);
    }
    else
    {
        while(val)
        {
            stackArray.push(val % 2);
            val /= 2;
        }
    }
    std::cout << "Binary form: ";
    while(!stackArray.is_empty())
    {
        std::cout << stackArray.peek();
        stackArray.pop();
    }
    std::cout << std::endl;
}

int main()
{
    // ====== TASK #1 ======
    PriorityQueue<std::pair<int,int>, size> pq;
    pq.insert({6, 7});
    pq.insert({1, 10});
    pq.insert({4, 3});
    pq.insert({2, 5});
    pq.insert({3, 8});

    while(!pq.is_empty())
    {
        std::cout << pq.front().second << ' ' << std::endl;
        pq.remove();
    }


    // ====== TASK #2 ======
    int val;
    std::cout << "Input value: ";
    std::cin >> val;
    print_binary(val);


    return 0;
}
