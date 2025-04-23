//PROGRAMMER: Ngoc Chau Nguyen
//DATE: 2025-04-23
//DESCRIPTION: This program is a simple C++ program that prints "Hello, World!" to the console.
//ASSISTANT: CHAT GPT and classmate Jasper Liu

#include <iostream> //do I need it?
#include <fstream>
#include <sstream> //string stream -- allows me to treat a string as if it is a stream


int main()
{
    //Read two lines of numbers in input.txt and store them into two vectors
    //std::ifstream -- standard input file stream. Read data from a file.
    std::ifstream inputFile("input.txt");
    std::string word;

    if(inputFile.is_open())
    {
        while(inputFile >> word)
        {
            //while input file was still able to read word-by-word
            std::cout << word << std::endl;
        }
        
        inputFile.close(); //closes the file
    }
    else
    {
        std::cout << "File could not be opened!" << std::endl;
    }

    return 0;

}
