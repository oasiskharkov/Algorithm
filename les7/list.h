#pragma once

#include <iostream>

template <typename T>
class List
{
public:
    List();
    ~List();
    void insert(const T& value);
    void clear();
    int size() const;
    const T& front() const;
    const T& back() const;
    bool isEmpty() const;
    bool isSorted() const;
    List<T> copy() const;
    void print() const;
    void reverse();
private:
    struct Element
    {
        T elem;
        Element* next;
    };
    Element* head;
    Element* tail;
    int counter;
};


template<typename T>
List<T>::List() :
    head {nullptr},
    tail {nullptr},
    counter {0}
{

}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::clear()
{
    while(tail)
    {
        Element* temp = tail;
        tail = tail->next;
        delete temp;
    }
    tail = nullptr;
    head = nullptr;
}

template<typename T>
void List<T>::insert(const T& value)
{
    Element* ins = new Element;
    ins->elem = value;
    ins->next = nullptr;

    if(head == nullptr)
    {
        head = ins;
        tail = ins;
    }
    else
    {
        ins->next = tail;
        tail = ins;
    }
    counter++;
}

template<typename T>
const T& List<T>::front() const
{
    return head->elem;
}

template<typename T>
const T& List<T>::back() const
{
    return tail->elem;
}

template<typename T>
int List<T>::size() const
{
    return counter;
}

template<typename T>
bool List<T>::isEmpty() const
{
    return counter == 0;
}

template<typename T>
bool List<T>::isSorted() const
{
    Element* temp = tail;
    while(temp && temp->next)
    {
        if (temp->elem > temp->next->elem)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

template<typename T>
List<T> List<T>::copy() const
{
    List<T> copy;
    Element* temp = tail;
    while(temp)
    {
        copy.insert(temp->elem);
        temp = temp->next;
    }
    copy.reverse();
    return copy;
}

template<typename T>
void List<T>::reverse()
{
    Element* prev = nullptr;
    while(tail)
    {
        Element* temp = tail->next;
        if(prev == nullptr)
        {
            head = tail;
        }
        tail->next = prev;
        prev = tail;
        tail = temp;
    }
    tail = prev;
}

template<typename T>
void List<T>::print() const
{
    Element* temp = tail;
    while(temp)
    {
        std::cout << temp->elem << ' ';
        temp = temp->next;
    }
    std::cout << std::endl;
}
