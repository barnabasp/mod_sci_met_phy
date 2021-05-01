#ifndef funcs_hpp
#define funcs_hpp

#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

class System_search
{
private:
    struct stFiles
    {
        fs::path path;
        int size;
        std::string extension;
    };
    struct stFolders
    {
        fs::path path;
        int size;
        int content;
    };
    
    
    //private variables 
    std::string m_pathing;
    //containers for file properties
    std::vector<stFiles> m_structFiles;
    
    //containers for folder properties
    std::vector<stFolders> m_structFolders;
public:
    //constructors
    System_search() = default;
    System_search(std::string strPath)
    {
        m_pathing = strPath;
        stFolders temp;
        temp.size = 0;
        temp.path = fs::path(strPath);
        temp.content = 0;
        m_structFolders.push_back(temp);


    };
    //simple function to check the filesystem
    void startup()
    {
        fs::path currPath(m_pathing);
        std::cout << "root name  " << currPath.root_name() << std::endl;
        std::cout << "root directory  " << currPath.root_directory() << std::endl;
        std::cout << "root path  " << currPath.root_path() << std::endl;
        std::cout << "relative path  " << currPath.relative_path() << std::endl;
        std::cout << "parent path  " << currPath.parent_path() << std::endl;
        std::cout << "filename  " << currPath.filename() << std::endl;
        std::cout << "stem  " << currPath.stem() << std::endl;
        std::cout << "extension  " << currPath.extension() << std::endl;
    }
    //main function that gathers information on the folders and files
    void explore();
    void checkR();
};

#endif