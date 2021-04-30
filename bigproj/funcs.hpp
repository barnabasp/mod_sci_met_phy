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
    std::string _pathing;
    //containers for file properties
    std::vector<fs::path> _files;
    std::vector<int> _fileSizes;
    
    //containers for folder properties
    std::vector<fs::path> _folders;
    std::vector<int> _folderSizes;
    std::vector<int> _folderContent;
public:
    //constructors
    System_search() = default;
    System_search(std::string strPath)
    {
        _pathing = strPath;
    };
    //simple function to check the filesystem
    void startup()
    {
        fs::path currPath(_pathing);
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
    void explore()
    {
        //looping through the paths
        for(auto& p: fs::recursive_directory_iterator(_pathing))
        {
            //std::cout << p.path() << '\n';
            //std::cout << fs::is_directory(p) << '\n';
            //check if path is a directory
            if(fs::is_directory(p))
            {
                if(fs::is_empty(p)) _folderContent.push_back(0);
                std::cout << p.path() << '\n';
                continue;
            }
            //if path is not a directory
            else
            {
                //std::cout << fs::file_size(p) << '\n';
                _files.push_back(p.path());
                _fileSizes.push_back(fs::file_size(p.path()));
                //count the files in this folder then go deeper-> add to content of folder
            }
        }
    }
};

#endif