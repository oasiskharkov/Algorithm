#include "tree.h"

constexpr int treesCount = 50;
constexpr int maxElementsCount = 10000;

int main()
{
    srand(unsigned(time(nullptr)));

    // ====== TASK# 1,2,3 ======
    int balanced_tree_counter = 0;
    for(int i = 0; i < treesCount; ++i)
    {
        Tree<int> tree;
        for(int j = 0; j < maxElementsCount; ++j)
        {
            tree.insert(rand() % maxElementsCount + 1);
        }

        if(tree.is_balanced(tree.get_root()))
        {
            balanced_tree_counter++;
        }
    }
    std::cout << 100.0f * balanced_tree_counter/treesCount << std::endl;

    // ====== TASK# 4 ======
    Tree<int> tree;
    tree.insert(6);
    tree.insert(5);
    tree.insert(9);
    tree.insert(8);
    tree.insert(3);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(10);

    std::cout << tree.size() << std::endl;
    tree.print_tree(tree.get_root());
    tree.remove(9);
    std::cout << tree.size() << std::endl;
    tree.print_tree(tree.get_root());
    tree.remove(6);
    std::cout << tree.size() << std::endl;
    tree.print_tree(tree.get_root());
    tree.remove(3);
    std::cout << tree.size() << std::endl;
    tree.print_tree(tree.get_root());

    Tree<int>::Element* node2 = tree.search(tree.get_root(), 2);
    if(node2 and node2->elem == 2)
    {
        std::cout << "Element was found." << std::endl;
    }
    else
    {
        std::cout << "Element was not found." << std::endl;
    }

    Tree<int>::Element* node4 = tree.search(tree.get_root(), 4);
    if(node4 and node4->elem == 4)
    {
        std::cout << "Element was found." << std::endl;
    }
    else
    {
        std::cout << "Element was not found." << std::endl;
    }


    return 0;
}
