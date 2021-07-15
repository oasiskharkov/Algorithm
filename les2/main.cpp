#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int val);
int sum(int first, int last);

int main()
{
    int val;
    std::cout << "Input value: ";
    std::cin >> val;
    std::cout << "Value is " << (is_prime(val) ? "prime." : "now prime.") << std::endl;

    std::cout << "Sum from 1 to 10 is " << sum(1, 10) << std::endl;
    return 0;
}

bool is_prime(int val)
{
    if (val <= 1 || (val != 2 && !(val % 2)))
    {
        return false;
    }
    else
    {
        int max_dev = (int)sqrt(val);
        for(int dev = 3; dev <= max_dev; dev += 2)
        {
            if(!(val % dev))
            {
                return false;
            }
        }
    }
    return true;
}

int sum(int first, int last)
{
    int sum = 0;
    for(int i = first; i <= last; ++i)
    {
        sum += i;
    }
    return sum;
}
