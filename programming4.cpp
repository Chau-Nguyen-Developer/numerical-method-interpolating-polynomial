//PROGRAMMER: Ngoc Chau Nguyen
//DATE: 2025-04-23
//DESCRIPTION: Placeholder
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

    int count = 0;

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
                ++count;
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
    std::cout << "Size of vector 4: " << vector4.size() << std::endl;
    std::cout << "This is vector 5" << std::endl;
    for(size_t i = 1; i < vector4.size(); ++i)
    {
        vector5.push_back((vector4[i] - vector4[i -1]) / (vector1[i + 2] - vector1[i -1]));
       std::cout << vector5[i-1] << std::endl;
    }
    
    std::cout << "Print out first part";
    std::cout << (vector4[1] - vector4[0]) << std::endl;

    //print out second part
    std::cout << "Print out second part." << std::endl;
    std::cout << (vector1[3] - vector1[0]);

    //print out interpolating polynomial

    //cast vector1<double> to vector string

    std::vector<std::string> vector1String;
    for (const double& number: vector1)
    {
        vector1String.push_back("(x - " + std::to_string(number) + ")");
    }

    //print out the vector1String for now.
    std::cout << "print out the vector1String for now." << std::endl;
    for(const auto& str: vector1String)
    {
        std::cout << str << std::endl;
    }

    //print out the first element of each vector (from vector 2 to vector 5)
    std::vector<std::vector<double>> vectorList;
    vectorList.push_back(vector2);
    vectorList.push_back(vector3);
    vectorList.push_back(vector4);
    vectorList.push_back(vector5);

    //create a new vector that stores only first elements from vector 2 to vector 5
    std::vector<double> firstElement;

    for (const auto& vec: vectorList)
    {
        firstElement.push_back(vec[0]);
    }

    //print out first element
    std::cout << "Testing--print out first element of each neccessary vector." << std::endl;
    for (const auto& number: firstElement)
    {
        std::cout << number <<std::endl;
    }

    //print out interpolating polynomial
    std::cout << "Print out interpolating polynomial--testing" << std::endl;
    std::cout << firstElement[0];
    for(size_t i = 1; i < firstElement.size(); ++i)
    {
        std::cout << " + " << firstElement[i];
        for(size_t j = 0; j < i; ++j)
        {
            std::cout <<vector1String[j];
        } 
    }

    //create a vector that has the format (x-value)

    //enum class VectorEnum {vector1=1, vector2=2, vector3 = 3, vector4 = 4, vector5 = 5};

    
    // std::vector<std::vector<double>> vectorList;
    // // vectorList.push

    // for (int i = 0; i < count; ++i)
    // {

    // }

    return 0;

}
