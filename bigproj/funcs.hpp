#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <fstream>
#include <iostream> 
#include <filesystem> //for the exercise itself, C++ 17 REQUIRED
#include <vector> //for storing data of the filesystem
#include <algorithm> //for std::sort
#include <numeric> //for std::accumulate
#include <map> //for distributions
namespace fs = std::filesystem;
std::string pathInput();
class System_search
{
private:
    struct stFiles
    {
        fs::path path;
        long size;
        std::string extension;
    };
    struct stFolders
    {
        fs::path path;
        long size;
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

        //initialize the folder container with the starting directory
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
    void biggestFile();
    void biggestFolder();
    void avgFilesPerDirectory();
    void avgFileSize();
    void avgFolderSize();
    void distributionOfExtensions();
};

#endif /*FUNCS_HPP*/