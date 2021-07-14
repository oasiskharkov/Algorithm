#include <iostream>

using namespace std;

void print_reversed(const char* str);

int main()
{
    const char* invitation = "Hello World!";
    cout << invitation << endl;
    print_reversed(invitation);
    cout << std::endl;
    return 0;
}

void print_reversed(const char* str)
{
    if(*str)
    {
        const char* s = str;
        print_reversed(++str);
        std::cout << *s;
    }
    return;
}
