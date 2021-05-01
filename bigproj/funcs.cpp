#include "funcs.hpp"

void System_search::explore()
{
    //looping through the paths
    for (auto &p : fs::recursive_directory_iterator(m_pathing))
    {
        //check if path is a directory
        if (fs::is_directory(p))
        {
            if (fs::is_empty(p))
                m_folderContent.push_back(0); //if empty, that means it's content is 0
            //std::cout << p.path() << '\n';
            m_folders.push_back(p.path());
            m_folderSizes.push_back(0);
            m_folderContent.push_back(0);
        }
        //if path is not a directory -> file
        else
        {
            //enclosing folder
            fs::path enclFold = p.path().parent_path();
            m_files.push_back(p.path());                    //saving paths to files - filenames
            m_fileSizes.push_back(fs::file_size(p.path())); //saving files' sizes
            //count the files in this folder then go deeper-> add to content of folder
            std::vector<fs::path>::iterator it_path;
            std::vector<fs::path>::iterator it_path_start = m_folders.begin();
            std::vector<fs::path>::iterator it_path_end = m_folders.end();
            int depthCount = 0;
            for (it_path = it_path_start; it_path != it_path_end; it_path++)
            {
                if (*it_path == enclFold)   break;
                else
                    depthCount++;
            }
            m_folderContent[depthCount] += 1;
            m_folderSizes[depthCount] += m_fileSizes.back();
            //std::cout << "enclosing folder: " << enclFold << '\n';
            //std::cout << "depth: " << depthCount << std::endl;
        }
        //std::cout << "directory: " <<p.path() << '\n';
        //std::cout << "parent: "<< p.path().parent_path() << '\n';
    }
}
void System_search::checkR()
{
    for (int i = 0; i < m_files.size(); i++)
    {
        std::cout << "size: " << m_fileSizes[i] << "\t name: " << m_files[i] << "\n";
    }
    for (int i = 0; i < m_folders.size(); i++)
    {
        std::cout << "size: " << m_folderSizes[i] << "\t name: " << m_folders[i] << "\t stuff: " << m_folderContent[i] << "\n";
    }
}