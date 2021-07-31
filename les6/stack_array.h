#pragma once

#include <iostream>

template <typename T, int Size>
class StackArray
{
public:
  StackArray();
  ~StackArray();
  void pop();
  void push(const T& value);
  bool isEmpty() const;
  const T& peek() const;
private:
  T* arr;
  int index = -1;
};

template <typename T, int Size>
StackArray<T, Size>::StackArray()
{
    arr = new T[Size];
}

template <typename T, int Size>
StackArray<T, Size>::~StackArray()
{
    delete [] arr;
}

template<typename T, int Size>
bool StackArray<T, Size>::isEmpty() const
{
    return index < 0;
}

template<typename T, int Size>
void StackArray<T, Size>::push(const T& value)
{
    if(index < Size - 1)
    {
        arr[++index] = value;
    }
    else
    {
        std::cout << "Stack is full." << std::endl;
    }
}

template<typename T, int Size>
void StackArray<T, Size>::pop()
{
    if(!isEmpty())
    {
        --index;
    }
    else
    {
        std::cout << "Stack is empty." << std::endl;
    }
}

template<typename T, int Size>
const T& StackArray<T, Size>::peek() const
{
    if(!isEmpty())
    {
        return arr[index];
    }
    throw std::logic_error("Stack is empty.");
}
