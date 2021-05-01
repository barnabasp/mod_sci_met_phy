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
    //private variables 
    std::string m_pathing;
    //containers for file properties
    std::vector<fs::path> m_files;
    std::vector<int> m_fileSizes;
    
    //containers for folder properties
    std::vector<fs::path> m_folders;
    std::vector<int> m_folderSizes;
    std::vector<int> m_folderContent;
public:
    //constructors
    System_search() = default;
    System_search(std::string strPath)
    {
        m_pathing = strPath;

        //initialize folders
        m_folders.push_back(fs::path(m_pathing)); //since the starting directory is not the first
        m_folderSizes.push_back(0); //need to have consistent size of vectors
        m_folderContent.push_back(0);
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