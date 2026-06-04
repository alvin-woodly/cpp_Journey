
/*
    an lvalue is an entity with an identifier namely: classes,variables,pointers etc.

    a refrence to an lvalue creates an alias to a variable
*/


#include <iostream>
#include <string>

//we can pass by refrence and pass by address
//* pass by refrence
void print(const std::string& something)
{
    std::cout << something << '\n';
}

//* pass by address
void print(const std::string* something)
{
    std::cout<< *something << '\n';
}

//! both have the same benefits but refrences are cleaner and safer to use

//* passing by address copies the pointer,meaning the original is unaffected
//*if you want to affect the original you pass by address...by refrence LOL

void print(const std::string*& something)
{
    std::cout<< *something << '\n';
}
//* yeah.... thats right, this exists 👆🏾 ??, the original pointer will now be affected,
//* you either change the value of the object in the address or the address itself
//* logically this makes sense though, because we are passing a refrence to the pointer
//* meaning no copies are made.

int main()
{
    //lvalue x
    int x {5};
    //refrence to lvalue X,basically an alias for X
    int& refX{x};

    std::cout << x << '\n'; // 5
    std::cout << refX << '\n'; // 5 because it refrences x 

    //increment refX, this impacts x as well
    refX++;

    std::cout << x << '\n'; // x is now 6 because its 'alias' refX was incremented
    std::cout << refX << '\n'; //refX is 6
    
    //increment x
    x++;

    std::cout << x << '\n'; //is 7 now
    std::cout << refX <<'\n'; //refX is 7 too, because x was incremented and this refrences X


    double d {12.22};
    //!int& refD{ d}; -> error cannot initialize a int refrence with a double lvalue

    //adress of operator (&) in front of a variable
    std::cout << &d << '\n';

    //derefrence operator (*) in front if a adress of operator
    std::cout << *(&d) << '\n';

    //pointers are objects that hold the address of other objects,they can be
    //derefrenced too get the value thats in that (memory) address as n lvalue
    //because of this pointers can be changed to point to other memory adresses
    //pointers their derefrenced value can also be changed which will change the
    //object being held at that memory address

    float f1{1.22f};
    float* floatptr {&f1}; //float pointer points to the address of f1

    std::cout << f1 << '\n';
    std::cout << floatptr << '\n';
    std::cout << *floatptr << '\n'; // derfrenced floatptr 

    //we can change the value the derefrenced pointer "points to",in other words
    //we can change the value that the address holds
    float f2{556.65f};
    *floatptr = f2; //floatptr (the address of f1) now holds the value of f2

    std::cout << *floatptr <<'\n';
    floatptr = &f2; //floatptr now points to the address of f2
    std::cout << floatptr << '\n';

    // a pointer that points to nothing is a null pointer.
    //use nullptr
    int* intNullPtr{nullptr};

    //this makes it easier to avoid dangling pointers
    //(when the object that is being pointed to is destroyed)

    

    //! 𝘀𝘁𝗱::𝗰𝗼𝘂𝘁 << *𝗶𝗻𝘁𝗡𝘂𝗹𝗹𝗣𝘁𝗿 << '\𝗻'; -> 𝗔𝗩𝗢𝗜𝗗 𝗧𝗛𝗜𝗦, 𝗶𝘁 𝘄𝗶𝗹𝗹 𝗰𝗿𝗮𝘀𝗵 𝘆𝗼𝘂𝗿 𝗽𝗿𝗼𝗴𝗿𝗮𝗺⁡
    //you can easily check if a pointer is NULL, as long as YOU reassign it to a nullptr
    //pointers arent automatically deleted after a scope , this results in dangling pointers
    
    if(intNullPtr == nullptr) //* we can check for null pointers like this
    {
        std::cout <<"pointer is null" <<'\n';
    }
    else
    {
        std::cout <<"pointer is not null" << '\n'; 
    }
    
    
    //*in most cases its best to use refrences over pointers,as they are safer

    //* CONST in pointers

    // you can make a pointer const ,(so it cannot change the address its pointing at)
    //but we can also make the value (derefrenced pointer) const

    char letter{'c'};
    char* charPtr{&letter};

    //make the pointer (itself) const:
    char* const charConstPtr{&letter};
    char letter2{'x'};

    //!charConstPtr = &letter2; cannot do this "expression must be a modifiable lvalue"

    //make the value of the pointer's address const:
    const char* constCharPtr{&letter};

    //! *constCharPtr = 'e'; cannot do this "expression must be a modifiable lvalue"

    //we can do both and make it so the pointer cannot be changed,neither its value
    const char* const constCharConstPtr{&letter}; //essentially makes the pointer read-only
    //! constCharConstPtr = &letter2; -> expression must be modifiable lvalue (pointer is const)
    //! *constCharConstPtr = 'g'; -> expression must be modifiable lvalue (value is const)


    //passing by refrence function argument
    std::string hello_world {"Hello World"};
    print(hello_world);

    //passing by address
    std::string* hello_world_ptr{&hello_world};
    print(hello_world_ptr);
    return 0;
}
