#include "stack.h"
#include "list.h"
#include <string>
#include <vector>

bool check_statement(const std::string& statement)
{
    Stack<char> stack;
    for(const auto& ch : statement)
    {
        if(ch == '[' or ch == '{' or ch == '(')
        {
            stack.push(ch);
        }
        else if(ch == ')')
        {
            if( !stack.isEmpty() and stack.peek() == '(')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        else if(ch == ']')
        {
            if( !stack.isEmpty() and stack.peek() == '[')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        else if(ch == '}')
        {
            if( !stack.isEmpty() and stack.peek() == '{')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return stack.isEmpty();
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
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    std::cout << "List: ";
    list.print();
    std::cout << "Front: " << list.front() << " Back: " << list.back() << std::endl;
    std::cout << "List is " << (list.isSorted() ? "sorted" : "unsorted") << std::endl;
    std::cout << "Copy: ";
    List<int> copy = list.copy();
    copy.print();
    std::cout << "Front: " << copy.front() << " Back: " << copy.back() << std::endl;

    List<int> list1;
    list1.insert(4);
    list1.insert(5);
    list1.insert(2);
    list1.insert(3);
    list1.insert(1);
    std::cout << "List: ";
    list1.print();
    std::cout << "Front: " << list1.front() << " Back: " << list1.back() << std::endl;
    std::cout << "List is " << (list1.isSorted() ? "sorted" : "unsorted") << std::endl;
    std::cout << "Copy: ";
    List<int> copy1 = list1.copy();
    copy1.print();
    std::cout << "Front: " << copy1.front() << " Back: " << copy1.back() << std::endl;

    return 0;
}
