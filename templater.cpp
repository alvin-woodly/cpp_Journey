#include <iostream>
#include <string_view>


//template function
template <typename T>
T printer(T value)
{
    return value;
}


//template function with 2 different types
template <typename T, typename U>
T tempfunc(T para1, U Para2)
{
    return para1;
}

//template function with 2 different types but can return any
template <typename T, typename U>

//overloaded  tempfunc
auto tempfunc2(T para1, U para2) //note auto
{
    return (para1 > para2)? para1 : para2;
}

int main()
{
    std::cout << printer<std::string_view>("Hello world");
    std::cout << tempfunc2(true, 7.0f);
    return 0;
}
