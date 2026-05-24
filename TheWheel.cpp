/*
    everyone loves the wheel right? cant make a decision?
    let the wheel decide! put your faith in your luck sometimes
    who knows, maybe you'll win the lottery?

    this program simulates a "wheel of fortune",
    the user can enter the amount of options and then proceed
    to input each options and then let faith decide!

*/
#include <iostream>
#include <string>
#include <string_view>
#include <random>
#include <limits>
#include <vector>

namespace {
    bool ProgramRunning {true};
}

int main()
{
    std::cout<<"welcome to the wheel of fortune! \n";
    while(ProgramRunning)
    {
        //print instructions to exit program
        std::cout << "to exit the program press x, any other button will continue the program : ";
        //see if user wants to exit
        //take user input and store as string
        std::string userinput{};
        std::getline(std::cin, userinput);
        
        //turn the string to a char , reading the first index of the string
        char userInputChar {userinput[0]};

        //terminate program if the char is x
        if (userInputChar == 'x')
        {
            ProgramRunning = false;
        }
        else
        {       
            //print instructions to use program
            std::cout << "how many options would you like to add? \n";
            
            //store the amount of options
            int options{};
            std::cin>> options;
            //clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            //collection (vector) for the options, vectors can grow and shrink dynamically
            std::vector<std::string> wheelOptions;
            //store every option
            for(int i= 0; i < options;i++)
            {
                std::cout<< "enter your option : " << '\n';
                std::string userOption{};
                std::getline(std::cin, userOption);
                wheelOptions.push_back(userOption);
            };

            //read the options back to the user
            std::cout <<"\n your options are : " << '\n';
            for(std::string_view strValue : wheelOptions)
            {
                std::cout<< strValue << '\n';
            };

            //randomness!!
            std::random_device rd;
            std::mt19937 rng(rd());
            std::uniform_int_distribution<>dist(0,wheelOptions.size()-1);
            std::cout <<"The wheel is spinning......" << '\n';
            int randomValue = dist(rng);

            std::cout << "the winner is ..... => " << wheelOptions[randomValue] <<"!! \n";

        };

        //program logic
    };
    
    return 0;
}
