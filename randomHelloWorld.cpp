/*
    this program just prints out either "Hello" or "World"
    its choice is completely random, you decide how many times
    it should print by inserting a number of rolls

    this is to solidify the use of mersenne twister for randomness

*/


#include <iostream>
#include <string_view>
#include <string>
#include <random>
#include <limits>
#include <cctype>

namespace{

    //constexpr because the value is known at compile time
    constexpr std::string_view choices [2] {"Hello","World"};

    bool isNumber(std::string_view userInput);
    
}

int main()
{
    
    int int_rolls{};
    std::string rolls{};
    
    //if input fails reset the operation mode to normal
    if(!std::cin)
    {
        std::cin.clear();
    }
    
    do{
        std::cout <<"How many times would you like to roll?" << '\n';
        std::cout <<"please enter numbers only " << '\n';
        std::cin >> rolls;
    }
    while(!isNumber(rolls));

    int_rolls = std::stoi(rolls);

    //clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    //random device
    std::random_device rd;

    //seed sequence
    std::seed_seq seed_sequence{rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd()};

    //mersenne twister PRNG engine
    std::mt19937 mt(seed_sequence);

    //uniform int distribution
    std::uniform_int_distribution dist{0,1};

    //print either "Hello" or "World" an X amount of times
    for(int i=0;i < int_rolls; i++)
    {
        std::cout << choices[dist(mt)] << '\n';
    }
    return 0;
}


namespace{

    bool isNumber(std::string_view userInput)
    {
        for(char c : userInput)
        {
            if(!std::isdigit(c))
            {
                return false;
            }
        }
    
        return true;
    }
}
