// Filesystem checker for University course - Made by Barnabas Porfy
// functions are from https://en.cppreference.com/w/cpp/header/filesystem
//
//////////////////////////////////////////////////////////////////////////////////
#include "funcs.hpp"

int main()
{
    //System_search temp("/Users/barnabasp/Documents/Code/mod_sci_met_phy/bigproj/");
    System_search temp("/Users/barnabasp/Documents/Code/Website");
    //temp.startup();
    temp.explore();
    temp.biggestFile();
    //temp.checkR();
}
