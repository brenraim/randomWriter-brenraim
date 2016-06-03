//
//  main.cpp
//  randomWriter
//
//  Created by Brendan Raimann on 5/31/16.
//  Copyright © 2016 Brendan Raimann. All rights reserved.
//
//  Algorithm I used:
//
//  choose a random index and create initial seed
//  loop
//      search the data for occurances of the seed
//      when I find an occurance, add next char to RAIMANN_STRING
//      add random letter from string to output
//      remove first letter from seed and append the random letter that was added to output
//  repeat until output is long enough
//  print output


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main ()
{
    int seedLength = 5; //EDIT SEED LENGTH HERE
    
    /*
     * Takes the text file and combines it into a string in 'data'
    */
    string file;
    string data;
    ifstream myfile ("usdeclar.txt");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline(myfile,file);
            data += file;
        }
        myfile.close();
    }
 
    
    string RAIMANN_STRING = "";
    string output = "";
    int index;
    string seed;
    int x; //for traversing the data to find the seed
    int num; //for random value in RAIMANN_STRING
    string tempChar; // stores the latest char outputed by the algorithm
    
    
    srand(static_cast<unsigned int>(time(NULL)));
    index = rand() % (data.length() - seedLength);
    
    seed = data.substr(index, seedLength);
    
    
    while (output.length() < 400) //EDIT OUTPUT LENGTH HERE
    {
        x = 0;
        while (x < data.length() - seedLength)
        {
            if (data.substr(x, seedLength).compare(seed) == 0)
            {
                RAIMANN_STRING += data.substr(x + seedLength, 1);
            }
            x++;
        }
        
        num = rand() % RAIMANN_STRING.length();
        tempChar = RAIMANN_STRING.substr(num, 1);
        output += tempChar;
        seed = seed.substr(1, seedLength - 1) + tempChar;
        RAIMANN_STRING = "";
        
    }
    
    cout << output;
    cout << "\n\n";
}