/*
    constexpr functions CAN run code at compile time.
    in order to guarantee it runs at compile time,use consteval

    you can use if consteval {
        as a means to run code at compile time with specific instructions
    }

    constexpr functions wont run at compile time if their arguments are non-const
    (it will run like a normal function, at runtime)

*/

#include <iostream>

constexpr int add(int a, int b)
{
    if consteval
    {
        return a+b+2000;
    }
    else
    {
        return a+b;
    }
}

//consteval forces compile time calculations on constexpr
//BE CAREFUL it cant do any I/O operations or dynamic memory allocation
//best suited for simple calculations
consteval auto forceCompileTime(auto a, auto b) //this is a wrapper for add()
{   
    return add(a,b);
}

int main ()
{
    int x{5};
    int userinp;
    constexpr int y {20};
    constexpr int z{40};

    
    std::cin >> userinp;
    
       
    std::cout << add(x,x) << '\n';
    constexpr int ans = {add(y,z)};
    std::cout << ans <<'\n';

    std::cout << add(x,x) << '\n';
    std::cout << add(x,y) << '\n';
    std::cout <<add(y,z) << '\n';

    std::cout << add(x,userinp) << '\n';
    std::cout << add (userinp,userinp) << '\n';

    int CT { forceCompileTime(12,2)};
    std::cout << CT << '\n';
}
