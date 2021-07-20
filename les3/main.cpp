#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int SIZE = 8;

void print_binary_form(int val);
int power(int a, int b);
int power_plus(int a, int b);
int to_digit(char letter);
int count_king_moves(int i, int j);

static int field[SIZE][SIZE] = {
    {1, 0, 1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 1, 0, 0, 1},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 0, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 1, 0, 1, 1, 0},
    {1, 0, 1, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 1, 0},
};

int main()
{
    // ====== TASK #1 ======
    int value;
    std::cout << "Input value: ";
    std::cin >> value;
    std::cout << "Binary form: ";
    if (value != 0)
    {
        print_binary_form(value);
    }
    else
    {
        std::cout << 0;
    }
    std::cout << endl;

    // ====== TASK #2 ======
    int a, b;
    std::cout << "Input value: ";
    std::cin >> a;
    std::cout << "Input power: ";
    std::cin >> b;
    std::cout << "Power of value is: " << power(a, b) << std::endl;

    // ====== TASK #3 ======
    int a1, b1;
    std::cout << "Input value: ";
    std::cin >> a1;
    std::cout << "Input power: ";
    std::cin >> b1;
    std::cout << "Power of value is: " << power_plus(a1, b1) << std::endl;

    // ====== TASK #4 ======
    char letter;
    int digit;
    int i, j;
    bool condition;
    std::string coordinates;
    do
    {
        std::cout << "Input king coordinates (a-h)(1-8): ";
        std::cin >> coordinates;
        std::transform(coordinates.begin(), coordinates.end(), coordinates.begin(), ::tolower);
        sscanf(coordinates.c_str(), "%c%i", &letter, &digit);
        i = digit - 1;
        j = to_digit(letter);
        if(j == -1 or i >= SIZE or i < 0)
        {
            std::cout << "Incorrect start postion, try one more time." << std::endl;
            condition = true;
        }
        else if (field[i][j])
        {
            std::cout << "Cell is busy, try another cell." << std::endl;
            condition = true;
        }
        else
        {
            condition = false;
        }
    } while(condition);

    std::cout << "The number of king moves is: " << count_king_moves(i, j) << std::endl;

    return 0;
}

void print_binary_form(int val)
{
    if(!val)
    {
        return;
    }
    int bit = val % 2;
    val /= 2;
    print_binary_form(val);
    std::cout << bit;
}

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    return a * power(a, b - 1);
}

int power_plus(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    if(b % 2 == 0)
    {
        return power(a * a, b / 2);
    }
    else
    {
        return a * power(a, b - 1);
    }
}

int count_king_moves(int i, int j)
{
    static int counter = -1;
    if(i >= SIZE or i < 0 or j >= SIZE or j < 0 or field[i][j] == 1)
    {
        return 0;
    }

    counter++;
    field[i][j] = 1;

    count_king_moves(i - 1, j - 1);
    count_king_moves(i - 1, j);
    count_king_moves(i - 1, j + 1);
    count_king_moves(i, j - 1);
    count_king_moves(i, j + 1);
    count_king_moves(i + 1, j - 1);
    count_king_moves(i + 1, j);
    count_king_moves(i + 1, j + 1);

    return counter;
}

int to_digit(char letter)
{
    static std::unordered_map<char, int> pairs = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}};
    if (pairs.find(letter) != pairs.end())
    {
        return pairs.at(letter);
    }
    return -1;
}
