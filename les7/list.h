#pragma once

#include <iostream>

template <typename T>
class List
{
private:
    struct Element
    {
        T elem;
        Element* next;
    };
public:
    List();
    ~List();
    void insert_back(const T& value);
    void insert_front(const T& value);
    Element* remove(const T& value);
    void clear();
    int size() const;
    const T& front() const;
    const T& back() const;
    bool is_empty() const;
    bool is_sorted() const;
    List<T> copy() const;
    void print() const;
    void reverse();
private:
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
    counter = 0;
}

template<typename T>
void List<T>::insert_back(const T& value)
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
void List<T>::insert_front(const T& value)
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
        head->next = ins;
        head = ins;
    }
    counter++;
}

template<typename T>
typename List<T>::Element* List<T>::remove(const T& value)
{
    Element* prev = nullptr;
    Element* current = tail;
    while(current)
    {
        if(current->elem == value)
        {
            if(current == tail)
            {
                if (head == tail)
                {
                    head = tail = nullptr;
                }
                else
                {
                    tail = current->next;
                }
            }
            else if (current == head)
            {
                head = prev;
                head->next = nullptr;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            counter--;
            return prev;
        }
        prev = current;
        current = current->next;
    }
    return nullptr;
}

template<typename T>
const T& List<T>::front() const
{
    if(is_empty())
    {
        throw std::logic_error("List is empty.");
    }
    return head->elem;
}

template<typename T>
const T& List<T>::back() const
{
    if(is_empty())
    {
        throw std::logic_error("List is empty.");
    }
    return tail->elem;
}

template<typename T>
int List<T>::size() const
{
    return counter;
}

template<typename T>
bool List<T>::is_empty() const
{
    return counter == 0;
}

template<typename T>
bool List<T>::is_sorted() const
{
    if(is_empty())
    {
        throw std::logic_error("List is empty.");
    }

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
    if(is_empty())
    {
        throw std::logic_error("List is empty.");
    }

    List<T> copy;
    Element* temp = tail;
    while(temp)
    {
        copy.insert_front(temp->elem);
        temp = temp->next;
    }
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
    if(is_empty())
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Element* temp = tail;
    while(temp)
    {
        std::cout << temp->elem << ' ';
        temp = temp->next;
    }
    std::cout << std::endl;
}
