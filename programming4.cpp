//PROGRAMMER: Ngoc Chau Nguyen
//DATE: 2025-04-23
//DESCRIPTION: This program is a simple C++ program that prints "Hello, World!" to the console.
//ASSISTANT: CHAT GPT and classmate Jasper Liu

#include <iostream> //do I need it?
#include <fstream>
#include <sstream> //string stream -- allows me to treat a string as if it is a stream
#include <vector>


int main()
{
    //Read two lines of numbers in input.txt and store them into two vectors
    //std::ifstream -- standard input file stream. Read data from a file.
    std::ifstream inputFile("input.txt");
    std::string line;
    std::vector<double> vector1;
    std::vector<double> vector2;


    if(inputFile.is_open())
    {
        //Read the first line into first vector.
        //(Use while loop if want to read continuously)

        if(std::getline(inputFile, line)) 
        //getline function reads an entire line of text from a stream
        //(in this case, that stream is inputFile)
        {
            std::stringstream ss(line); //treat string like a stream. Able to extract tokens using >>.
            double number;
            while(ss >> number)
            {
                vector1.push_back(number);
            }

        }

        //Read the second line  //A few thought: maybe create a separate function to read each line
        if(std::getline(inputFile, line))
        {
            std::stringstream ss(line);
            double number;
            while(ss >> number)
            {
                vector2.push_back(number);
            }
        }

        inputFile.close(); //closes the file
    }
    else
    {
        std::cout << "File could not be opened!" << std::endl;
    }

    //Print out vectors to check. 
    std::cout << "My Vector1: " << std::endl;

    for(const double& num: vector1)
    {
        std::cout << num << " ";
    }
    
    std::cout <<std::endl;
    
    std::cout << "My Vector2: " << std::endl;

    for(const double& num: vector2)
    {
        std::cout << num << " ";
    }

    return 0;

}
