#include "stack.h"
#include "list.h"
#include <string>
#include <vector>

constexpr int size = 3;

bool check_statement(const std::string& statement)
{
    Stack<char> stack;
    std::pair<char, char> braces[size] = {{'[', ']'}, {'(', ')'}, {'{', '}'}};
    for(const auto& ch : statement)
    {
        for(int i = 0; i < size; ++i)
        {
            if(ch == braces[i].first)
            {
                stack.push(ch);
            }
            else if(ch == braces[i].second)
            {
                if(!stack.is_empty() and stack.peek() == braces[i].first)
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return stack.is_empty();
}

int main()
{

    // ====== TASK #1 ======
    std::string statement;
    std::cout << "Input statement: ";
    std::cin >> statement;
    std::cout << "Statement is " << (check_statement(statement) ? "correct" : "incorrect") << std::endl;
    std::vector<std::string> correct_statements {"()", "{([])}", "()[]{}", "()[({}())]", "(([]{([])}))", "{[]()([]){(())}}"};
    std::vector<std::string> incorrect_statements {"{", "((", "()[", "]]", "()()[]{", "()(([]{([])})", "{[]()([]){(())}", "({[})"};
    for(const auto& st: correct_statements)
    {
        std::cout << "Statement is " << (check_statement(st) ? "correct" : "incorrect") << std::endl;
    }
    for(const auto& st: incorrect_statements)
    {
        std::cout << "Statement is " << (check_statement(st) ? "correct" : "incorrect") << std::endl;
    }

    // ====== TASK #2,3 ======
    List<int> list;
    list.insert_front(1);
    list.insert_front(2);
    list.insert_front(3);
    list.insert_front(4);
    list.insert_front(5);

    std::cout << "List: ";
    list.print();
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Back: " << list.back() << " Front: " << list.front() <<std::endl;
    std::cout << "List is " << (list.is_sorted() ? "sorted" : "unsorted") << std::endl;
    std::cout << "Copy: ";
    List<int> copy = list.copy();
    copy.print();
    std::cout << "Size: " << copy.size() << std::endl;
    std::cout << "Back: " << copy.back() << " Front: " << copy.front() << std::endl;

    List<int> list1;
    list1.insert_front(4);
    list1.insert_front(5);
    list1.insert_front(2);
    list1.insert_front(3);
    list1.insert_front(1);

    std::cout << "List: ";
    list1.print();
    std::cout << "Size: " << list1.size() << std::endl;
    std::cout << "Back: " << list1.back() << " Front: " << list1.front()  << std::endl;
    std::cout << "List is " << (list1.is_sorted() ? "sorted" : "unsorted") << std::endl;
    std::cout << "Copy: ";
    List<int> copy1 = list1.copy();
    copy1.print();
    std::cout << "Size: " << copy1.size() << std::endl;
    std::cout << "Back: " << copy1.back() << " Front: " << copy1.front() << std::endl;

    return 0;
}
