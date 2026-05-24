#include <iostream>
#include "HelloWorld.h"
#include <string_view>


int main()
{
    std::cout << HelloWorld::PrintHelloWorld();
    return 0;

};
namespace HelloWorld{

    std::string_view PrintHelloWorld()
    {
        return {"Hello world"};
    };
}
