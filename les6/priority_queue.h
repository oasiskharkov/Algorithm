#pragma once

#include <iostream>

template <typename T, int Size>
class PriorityQueue
{
public:
  PriorityQueue();
  ~PriorityQueue();
  void insert(const T& value);
  void remove();
  bool is_empty() const;
  const T& front() const;
private:
  int get_top_index() const;
private:
  T* arr;
  int counter;
  int head;
  int tail;
};

template<typename T, int Size>
PriorityQueue<T,Size>::PriorityQueue() :
    arr {new T[Size]},
    counter {0},
    head {-1},
    tail {-1}
{
}

template<typename T, int Size>
PriorityQueue<T,Size>::~PriorityQueue()
{
    delete [] arr;
}

template<typename T, int Size>
bool PriorityQueue<T,Size>::is_empty() const
{
    return counter == 0;
}

template<typename T, int Size>
void PriorityQueue<T,Size>::insert(const T& value)
{
    if(counter == Size)
    {
        std::cout << "Priority queue is full." << std::endl;
        return;
    }

    if(is_empty())
    {
        tail = head = 0;
        arr[tail] = value;
    }
    else if(tail > 0)
    {
        arr[--tail] = value;
    }
    else
    {
        arr[++head] = value;
    }
    counter++;
}

template<typename T, int Size>
int PriorityQueue<T,Size>::get_top_index() const
{
    if(is_empty())
    {
        return -1;
    }

    int priority = arr[tail].first;
    int index = tail;
    for(int i = tail; i <= head; ++i)
    {
        if(arr[i].first < priority)
        {
            priority = arr[i].first;
            index = i;
        }
    }
    return index;
}


template<typename T, int Size>
void PriorityQueue<T,Size>::remove()
{
    if(is_empty())
    {
        std::cout << "Priority queue is empty." << std::endl;
        return;
    }

    int index = get_top_index();

    if(index == tail)
    {
        if(counter == 1)
        {
            tail = -1;
            head = -1;
        }
        else
        {
            tail++;
        }
    }
    else if(index == head)
    {
        if(counter == 1)
        {
            tail = -1;
            head = -1;
        }
        else
        {
            head--;
        }
    }
    else
    {
        for(int j = index; j > tail; --j)
        {
            arr[j] = arr[j - 1];
        }
        tail++;
    }
    counter--;
}

template<typename T, int Size>
const T& PriorityQueue<T,Size>::front() const
{
    if(is_empty())
    {
        throw std::logic_error("Priority queue is empty.");
    }

    int index = get_top_index();
    return arr[index];
}

