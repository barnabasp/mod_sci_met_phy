// Filesystem checker for University course - Made by Barnabas Porfy
// functions are from https://en.cppreference.com/w/cpp/header/filesystem
//
//////////////////////////////////////////////////////////////////////////////////
#include "funcs.hpp"

int main()
{
    /*
    fs::create_directories("sandbox/a/b");
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
    for(auto& p: fs::directory_iterator("sandbox"))
        std::cout << p.path() << '\n';
    fs::remove_all("sandbox");
    */
    //fs::path currPath("/Users/barnabasp/Documents/Code/mod_sci_met_phy/bigproj/");
    //temp::startup("/Users/barnabasp/Documents/Code/mod_sci_met_phy/bigproj/")
    //system_search temp("/Users/barnabasp/Documents/Code/mod_sci_met_phy/bigproj/");
    System_search a(1);
    /*
        std::cout << "root name  " << currPath.root_name() << std::endl;
        std::cout << "root directory  " << currPath.root_directory() << std::endl;
        std::cout << "root path  " << currPath.root_path() << std::endl;
        std::cout << "relative path  " << currPath.relative_path() << std::endl;
        std::cout << "parent path  " << currPath.parent_path() << std::endl;
        std::cout << "filename  " << currPath.filename() << std::endl;
        std::cout << "stem  " << currPath.stem() << std::endl;
        std::cout << "extension  " << currPath.extension() << std::endl;
    */
}
//space visibility
