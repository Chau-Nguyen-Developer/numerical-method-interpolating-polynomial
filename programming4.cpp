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
    std::cout << "x         f[]         f[,]        f[, ,]" << std::endl;

    for(size_t i = 0; i < vector1.size(); ++i)
    {
        std::cout << vector1[i] << "            " << vector2[i] << std::endl;

    }

    std::vector<double> vector3;
    std::cout << "This is vector 3" << std::endl;
    for(size_t i = 1; i < vector1.size(); ++i)
    {
        vector3.push_back((vector2[i] - vector2[i-1]) / (vector1[i] - vector1[i-1]));
        std::cout << vector3[i-1] << std::endl;
    }

    std::vector<double> vector4;
    std::cout << "This is vector 4" << std::endl;
    std::cout <<"print out"<< std::endl;

    for(size_t i = 1; i < vector3.size(); ++i)
    {
        vector4.push_back((vector3[i] - vector3[i-1]) / (vector1[i+1] - vector1[i-1]));
        std::cout << vector4[i-1] << std::endl;
    }

    std::vector<double> vector5;
    std::cout << "This is vector 5" << std::endl;
    // for(size_t i = 1; vector4.size(); ++i)
    // {
    //     vector5.push_back((vector4[i] - vector4[i -1]) / (vector1[i + 2] - vector1[i -1]));
    //    std::cout << vector5[i-1] << std::endl;
    // }
    
    std::cout << "Print out first part";
    std::cout << (vector4[1] - vector4[0]) << std::endl;

    //print out second part
    std::cout << "Print out second part." << std::endl;
    std::cout << (vector1[3] - vector1[0]);

    

    return 0;

}
