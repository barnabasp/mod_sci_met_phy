// Filesystem checker for University course - Made by Barnabas Porfy
// functions are from https://en.cppreference.com/w/cpp/header/filesystem
//
//////////////////////////////////////////////////////////////////////////////////
#include "funcs.hpp"

int main()
{
    //System_search temp("/Users/barnabasp/Documents/Code/mod_sci_met_phy/bigproj/");
    std::string path = pathInput();
    System_search temp(path);
    std::cout << "The program will now collect data and will show results...\n";
    //temp.startup();
    temp.explore();
    temp.avgFilesPerDirectory();
    temp.biggestFile();
    temp.biggestFolder();
    temp.avgFileSize();
    temp.avgFolderSize();
    temp.distributionOfExtensions();
    //temp.checkR();
}
