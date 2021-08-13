#include <iostream>

void print_coins_count(int price);
int hash_function(const char* str);

int main()
{
    // ====== TASK #1 ======
    char str[128];
    std::cout << "Input string: ";
    std::cin.getline(str, 128);
    std::cout << "Hash code is: " << hash_function(str) << std::endl;

    // ====== TASK #2 ======
    std::cout << "Input price: ";
    int price;
    std::cin >> price;
    print_coins_count(price);

    return 0;
}

int hash_function(const char* str)
{
    int code = 0;
    while(*str)
    {
        code += (int)(*str);
        str++;
    }
    return code;
}

void print_coins_count(int price)
{
    constexpr int size = 5;
    std::pair<int, int> used_coins[size]= { {50, 0}, {10, 0}, {5, 0}, {2, 0}, {1, 0} };

    for(int i = 0; i < size; ++i)
    {
        while(price - used_coins[i].first >= 0)
        {
            price -= used_coins[i].first;
            used_coins[i].second++;
        }
    }

    for(const auto& p : used_coins)
    {
        std::cout << "(" << p.first << "->" << p.second << ")" << std::endl;
    }
}
