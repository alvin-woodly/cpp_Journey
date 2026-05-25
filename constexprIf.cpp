#include <iostream>

constexpr int x{900};

int main()
{
    if constexpr (x == 500)
    {
        std::cout << "x is 500";
    }

    switch (x)
    {
        case 200:
            std::cout << "x is 200 " << '\n'  ;
            break;
        case 500:
            std::cout <<"x is 500" << '\n';
            break;
        
        default:
            break;

    }

    return 0;
}
