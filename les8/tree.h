#pragma once

#include <iostream>

template <typename T>
class Tree
{
public:
    struct Element
    {
      T elem;
      Element* left;
      Element* right;
    };
public:
    Tree();
    ~Tree();
    void clear(Element* temp);
    void insert(const T& value);
    void remove(const T& value);
    int size() const;
    int get_height(Element* temp) const;
    bool is_empty() const;
    bool is_balanced(Element* temp) const;
    Element* get_root() const;
    Element* search(Element* temp, const T& value) const;
    void print_tree(Element* temp) const;
private:
    Element* get_successor(Element* node);
private:
    Element* root;
    int counter;
};

template <typename T>
Tree<T>::Tree() :
    root {nullptr},
    counter {0}
{

}

template <typename T>
Tree<T>::~Tree()
{
    clear(root);
}

template <typename T>
void Tree<T>::clear(Element* temp)
{
    if(temp == nullptr)
    {
        return;
    }
    clear(temp->left);
    clear(temp->right);
    if(temp == root)
    {
        root = nullptr;
    }
    delete temp;
    temp = nullptr;
    counter--;
}

template <typename T>
typename Tree<T>::Element* Tree<T>::get_root() const
{
    return root;
}

template <typename T>
int Tree<T>::size() const
{
    return counter;
}

template <typename T>
bool Tree<T>::is_empty() const
{
    return counter == 0;
}

template <typename T>
void Tree<T>::print_tree(Element* temp) const
{
    if (temp)
    {
        std::cout << temp->elem;

        std::cout << "(";
        if (temp->left)
        {
            print_tree(temp->left);
        }
        else
        {
            std::cout << "null";
        }
        std::cout << ",";
        if (temp->right)
        {
            print_tree(temp->right);
        }
        else
        {
            std::cout << "null";
        }
        std::cout << ")";
    }
    if(temp == root)
    {
        std::cout << std::endl;
    }
}

template <typename T>
void Tree<T>::insert(const T& value)
{
    Element* son = new Element;
    son->elem = value;
    son->left = nullptr;
    son->right = nullptr;

    if(root == nullptr)
    {
        root = son;
        counter++;
        return;
    }

    Element* temp = root;
    Element* parent = nullptr;
    while(temp)
    {
        parent = temp;
        if(value > temp->elem)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    value > parent->elem ? parent->right = son : parent->left = son;
    counter++;
}

template <typename T>
void Tree<T>::remove(const T& value)
{
    Element* current = root;
    Element* parent = nullptr;
    bool is_left_child = true;
    while(current && current->elem != value)
    {
        parent = current;
        if(value > current->elem)
        {
            current = current->right;
            is_left_child = false;
        }
        else
        {
            current = current->left;
            is_left_child = true;
        }
    }

    if(!current)
    {
        return;
    }

    if (current->left == nullptr && current->right == nullptr)
    {
        if (current == root)
        {
            root = nullptr;
        }
        else
        {
            if (is_left_child)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
        }
    }
    else if (current->right == nullptr)
    {
        if (current == root)
        {
            root = current->left;
        }
        else
        {
            if (is_left_child)
            {
                parent->left = current->left;
            }
            else
            {
                parent->right = current->left;
            }
        }
    }
    else if (current->left == nullptr)
    {
        if (current == root)
        {
            root = current->right;
        }
        else
        {
            if (is_left_child)
            {
                parent->left = current->right;
            }
            else
            {
                parent->right = current->right;
            }
        }
    }
    else
    {
        Element* successor = get_successor(current);
        if (current == root)
        {
            root = current->right;
        }
        else
        {
            if (is_left_child)
            {
                parent->left = successor;
            }
            else
            {
                parent->right = successor;
            }
        }
        successor->left = current->left;
    }
    delete current;
    current = nullptr;
    counter--;
}

template <typename T>
typename Tree<T>::Element* Tree<T>::get_successor(Element* node) {
    Element* current = node->right;
    Element* parent = node;
    Element* temp = node;

    while (current != nullptr) {
        parent = temp;
        temp = current;
        current = current->left;
    }
    return temp;
}

template <typename T>
typename Tree<T>::Element* Tree<T>::search(Element* temp, const T& value) const
{
    if(!temp)
    {
        return nullptr;
    }

    if(temp->elem == value)
    {
        return temp;
    }

    if(value > temp->elem)
    {
        return search(temp->right, value);
    }
    else
    {
        return search(temp->left, value);
    }
}

template <typename T>
int Tree<T>::get_height(Element* temp) const
{
    int hl = 0, hr = 0;
    if (!temp)
    {
        return 0;
    }
    if (temp->left)
    {
        hl = get_height(temp->left);
    }
    if(temp->right)
    {
        hr = get_height(temp->right);
    }
    return (std::max(hl, hr) + 1);
}

template <typename T>
bool Tree<T>::is_balanced(Element* temp) const
{
    return (temp == nullptr) or (is_balanced(temp->left) and is_balanced(temp->right) and abs(get_height(temp->left) - get_height(temp->right)) <= 1);
}
