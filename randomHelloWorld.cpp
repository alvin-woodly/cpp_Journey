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
#include <cassert>

namespace{

    //constexpr because the value is known at compile time
    constexpr std::string_view choices [2] {"Hello","World"};

    bool isNumber(std::string_view userInput);
    
}

int main()
{
    
    int int_rolls{};
    std::string rolls{};
    
    //look at that,i've found a reason to use a do-while loop :)
    do{
        std::cout <<"How many times would you like to roll?" << '\n';
        std::cout <<"please enter numbers only " << '\n';
        std::cin >> rolls;

        if(std::cin.eof())
        {
            std::exit(1);
        }

        //clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    while(!isNumber(rolls));

    int_rolls = std::stoi(rolls);
    assert(int_rolls > 0);
    

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
        if(userInput.empty())
        {
            return false;
        }

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
