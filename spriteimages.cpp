#include "spriteimages.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QTextStream>

using std::ifstream;
using std::string;

spriteimages::spriteimages()
{
    string winwidth,winheight,wincolor;       // Declare your variables
    winwidth = winheight = wincolor = "";   // Set them all to 0

    string path = "Sprite_Images.txt";          // Storing your filename in a string
    ifstream fin;                          // Declaring an input stream object

    fin.open(path);                        // Open the file
    if(fin.is_open())                      // If it opened successfully
    {
        fin >> winwidth >> winheight >> wincolor;  // Read the values and
                           // store them in these variables
        fin.close();                   // Close the file
    }

}
