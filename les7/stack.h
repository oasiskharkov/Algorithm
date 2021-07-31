#pragma once
#include <exception>
#include <iostream>

template <typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(const T& value);
    void pop();
    void clear();
    const T& peek() const;
    bool isEmpty() const;
private:
    struct Element
    {
        T elem;
        Element* next;
    };
    Element* head;
};

template<typename T>
Stack<T>::Stack() : head{nullptr}
{

}

template<typename T>
Stack<T>::~Stack()
{
    clear();
    delete head;
}

template<typename T>
void Stack<T>::clear()
{
    while(head != nullptr)
    {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T& value)
{
    Element* top = new Element;
    top->next = head;
    top->elem = value;
    head = top;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return head == nullptr;
}

template<typename T>
void Stack<T>::pop()
{
    Element* temp = head;
    if(isEmpty())
    {
        return;
    }
    head = head->next;
    delete temp;
}

template<typename T>
const T& Stack<T>::peek() const
{
    if(!isEmpty())
    {
        return head->elem;
    }
    throw std::logic_error("Stack is empty.");
}

