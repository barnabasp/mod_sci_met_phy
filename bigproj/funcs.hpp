#ifndef funcs_hpp
#define funcs_hpp

#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

class System_search
{
    private:
    std::string pathing;
    public:
    System_search() = default;
    System_search(std::string strPath)
    {
        pathing = strPath;
    };
    void startup()
    {
        fs::path currPath(pathing);
        std::cout << "root name  " << currPath.root_name() << std::endl;
        std::cout << "root directory  " << currPath.root_directory() << std::endl;
        std::cout << "root path  " << currPath.root_path() << std::endl;
        std::cout << "relative path  " << currPath.relative_path() << std::endl;
        std::cout << "parent path  " << currPath.parent_path() << std::endl;
        std::cout << "filename  " << currPath.filename() << std::endl;
        std::cout << "stem  " << currPath.stem() << std::endl;
        std::cout << "extension  " << currPath.extension() << std::endl;
    }
};

#endif