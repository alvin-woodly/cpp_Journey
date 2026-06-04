/*
    return types of parameters can be refs or pointers too
    *always prefer to return a const refrence,unless you need to modify the value after
    *if a variable is created and must be returned, make it STATIC this applies for both 
    *return by ref or return by address
    ! keep in mind that a static variable will be shared, hence why you should return const
    *if you wish to return via ref or address and store it as a copy, then store it in a normal variable
    * if you store the return value as a ref or pointer , the variable will basically be another alias

*/

#include <iostream>
#include <string>

// this function returns the same paramater it recieves as const
const std::string& returnstr(const std::string& para1)
{
    return para1;
}

//return by address,variable made static to extend lifespan
const std::string* returnstrptr(const std::string* para1)
{
    static std::string var {"Hello"};
    std::cout << &var << '\n';
    return &var;
}



int main()
{
    std::string HelloW {"Hello World"};
    //makes copy
    const std::string HelloWorld {returnstr(HelloW)};

    //returns the original
    const std::string& HelloWorldRef {returnstr(HelloW)};
    std::cout << &HelloW << '\n';

    //alias for HelloWorld,if i were to modify this it would be reflected
    std::cout << &HelloWorld << '\n';

    std::string strTest {"Boss"};
    const std::string* strPtr {returnstrptr(&strTest)};

    std::cout << strPtr << " @ " << *strPtr << '\n';
    return 0;
}
