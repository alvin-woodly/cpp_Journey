#include <iostream>
#include <random>
#include <iomanip>

int main()
{   

    std::random_device rd{};
    std::seed_seq seed{rd(),rd(),rd(),rd(),rd(),rd()};
    std::mt19937 mt{seed};
    std::uniform_int_distribution dist{1,6};
    std::uniform_real_distribution<float> randfloat{1.0f,6.0f};
    

    std::cout << dist(mt) << '\n';
    std::cout << std::fixed << std::setprecision(2) << randfloat(mt) << '\n';
    return 0;
}
