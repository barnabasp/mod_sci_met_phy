#ifndef funcs_hpp
#define funcs_hpp

#include <fstream>
#include <iostream>
#include <filesystem>
//namespace fs = std::filesystem;

class System_search
{
    public:
    System_search();
    System_search(int a);
    //system_search::system_search(std::string strpath);
    /*void startup(std::string strpath)
    {
        fs::path currPath(strpath);
        std::cout << "root name  " << currPath.root_name() << std::endl;
        std::cout << "root directory  " << currPath.root_directory() << std::endl;
        std::cout << "root path  " << currPath.root_path() << std::endl;
        std::cout << "relative path  " << currPath.relative_path() << std::endl;
        std::cout << "parent path  " << currPath.parent_path() << std::endl;
        std::cout << "filename  " << currPath.filename() << std::endl;
        std::cout << "stem  " << currPath.stem() << std::endl;
        std::cout << "extension  " << currPath.extension() << std::endl;
    }*/
    ~System_search();
};

#endif