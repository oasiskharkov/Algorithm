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
  bool isEmpty() const;
  const T& front() const;
private:
  int getTopIndex() const;
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
bool PriorityQueue<T,Size>::isEmpty() const
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

    if(isEmpty())
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
int PriorityQueue<T,Size>::getTopIndex() const
{
    if(isEmpty())
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
    if(isEmpty())
    {
        std::cout << "Priority queue is empty." << std::endl;
        return;
    }

    int index = getTopIndex();

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
    if(isEmpty())
    {
        throw std::logic_error("Priority queue is empty.");
    }

    int index = getTopIndex();
    return arr[index];
}

