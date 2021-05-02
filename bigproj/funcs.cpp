#include "funcs.hpp"
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-Class functions+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

//Collect data from the given directory. This goes recursively into all folders and checks all files' path, size and name
//then logs them into a private class variable to hold for further functions.
void System_search::explore()
{
    stFolders folders;
    stFiles files;

    std::vector<fs::path> tmp_folders;
    std::vector<int> tmp_folderSizes;
    std::vector<int> tmp_folderContent;

    //initialize folders
    tmp_folders.push_back(fs::path(m_pathing)); //since the starting directory is not the first
    tmp_folderSizes.push_back(0); //need to have consistent size of vectors
    tmp_folderContent.push_back(0);
    //have to do it again because of struct
    /*
    folders.path = fs::path(m_pathing);
    folders.size = 0;
    folders.content = 0;
    m_structFolders.push_back(folders);
    */
    //looping through the paths
    for (auto &p : fs::recursive_directory_iterator(m_pathing))
    {
        //check if path is a directory
        if (fs::is_directory(p))
        {
            //setup for later counting
            tmp_folders.push_back(p.path());
            tmp_folderSizes.push_back(0);
            tmp_folderContent.push_back(0);

        }
        //if path is not a directory -> file
        else
        {
            //enclosing folder
            fs::path enclFold = p.path().parent_path();

            // saving files' attributes 
            files.path = p.path();
            files.size = fs::file_size(p.path());
            files.extension = p.path().extension();
            //iterator setup
            std::vector<fs::path>::iterator it_path;
            std::vector<fs::path>::iterator it_path_start = tmp_folders.begin();
            std::vector<fs::path>::iterator it_path_end = tmp_folders.end();
            
            int depthCount = 0; //folder depth counter
            for (it_path = it_path_start; it_path != it_path_end; it_path++) //looping through the folders already visited
            {
                if (*it_path == enclFold)   break; //if we are at the same folder as the file is quit the loop
                else
                    depthCount++; //add 1 to the depth count
            }

            tmp_folderContent[depthCount] += 1; //the amount of files in the current folder is increased by 1
            folders.content +=1;
            for(int iDepth = 0; iDepth <= depthCount; iDepth++) //add the sizes to all folders enclosing the current folder + to the current folder
            {
                tmp_folderSizes[iDepth] += files.size;
            }
            m_structFiles.push_back(files);
        }
    }
    //iterating through temporary holders for folder attributes
    //adding to folder struct for easier manipulation later
    for(int iFolder = 0; iFolder < tmp_folderSizes.size(); iFolder++)
    {
        m_structFolders[iFolder].size = tmp_folderSizes[iFolder];
        m_structFolders[iFolder].content = tmp_folderContent[iFolder];
        m_structFolders[iFolder].path = tmp_folders[iFolder];
        m_structFolders.push_back(folders);
    }
    m_structFolders.pop_back();
}
//look for biggest file in the collected folders
void System_search::biggestFile()
{
    std::vector<stFiles> tempFiles = m_structFiles;
    std::sort(tempFiles.begin(), tempFiles.end(), []( const stFiles &a_file, const stFiles &b_file )
                 { return ( a_file.size < b_file.size ); } );
    std::vector<stFiles>::iterator it_f = tempFiles.end() - 1;
    for(; it_f != tempFiles.end(); it_f++)
    {
        std::cout << "size: " << it_f->size << "\t name: " << it_f->path << "\n";
    }
}
//look for biggest folder in the collected folders
void System_search::biggestFolder()
{
    std::vector<stFolders> tempFolders = m_structFolders;
    std::sort(tempFolders.begin(), tempFolders.end(), []( const stFolders &a_folder, const stFolders &b_folder )
                 { return ( a_folder.size < b_folder.size ); } );
    std::vector<stFolders>::iterator it_f = tempFolders.end() - 1;
    for(; it_f != tempFolders.end(); it_f++)
    {
        std::cout << "size: " << it_f->size << "\t name: " << it_f->path << "\t stuff:" << it_f->content << "\n";
    }
}
//Counts the sum of files per directory, then calculates the mean file content
void System_search::avgFilesPerDirectory()
{
    std::vector<int> contents; //holder for contents of files
    //looping through the folders and extracting the contents
    for(std::vector<stFolders>::iterator it_f = m_structFolders.begin(); it_f != m_structFolders.end(); it_f++)
    {
        contents.push_back(it_f->content);
    }
    //sum and mean calculation
    double sum = std::accumulate(contents.begin(), contents.end(), 0.0);
    double mean = sum/contents.size();
    std::cout << "Total files in folders: " << sum << "\t mean content per folder: " << mean << "\n";
}
void System_search::checkR()
{
    for(std::vector<stFiles>::iterator it_f = m_structFiles.begin(); it_f != m_structFiles.end(); it_f++)
    {
        std::cout << "size: " << it_f->size << "\t name: " << it_f->path << "\n";
    }
    for(std::vector<stFolders>::iterator it_f = m_structFolders.begin(); it_f != m_structFolders.end(); it_f++)
    {
        std::cout << "size: " << it_f->size << "\t name: " << it_f->path << "\t stuff:" << it_f->content << "\n";
    }
}