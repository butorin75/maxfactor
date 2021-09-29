// MaxFactor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

std::uint64_t sqrt64(uint64_t a)
{
    uint64_t min = 0;
    uint64_t max = ((uint64_t)1) << 32;
    while (1)
    {
        if (max <= 1 + min)
            return min;

        uint64_t sqt = min + (max - min) / 2;
        uint64_t sq = sqt * sqt;

        if (sq == a)
            return sqt;

        if (sq > a)
            max = sqt;
        else
            min = sqt;
    }
    return 1ULL;
}

bool is_prime(std::uint64_t x)
{
    std::uint64_t max = sqrt64(x);
    for (std::uint64_t i = 2; i <= max; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

std::uint64_t max_factor(std::uint64_t n) 
{
    std::uint64_t max_val = n/2 + 1;
    if ((max_val % 2) == 0) ++max_val;
    for (std::uint64_t i = max_val; i >= 2; i -= 2) {
        if (is_prime(i) && (n % i) == 0)
            return i;
    }
    return 1;
}

int main()
{
    std::cout << "MaxFactor 1.0\nPlease enter the number:";
    std::uint64_t n;
    std::cin >> n;
    std::cout << "Maximum simple divider: " << max_factor(n);
}

