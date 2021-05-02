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
    std::cout << "The biggest file has the following attributes: \n";
    for(; it_f != tempFiles.end(); it_f++)
    {
        std::cout << "Size: " << it_f->size << " bytes\t Path-to-file: " << it_f->path << "\n";
    }
}
//look for biggest folder in the collected folders
void System_search::biggestFolder()
{
    std::vector<stFolders> tempFolders = m_structFolders;
    std::sort(tempFolders.begin(), tempFolders.end(), []( const stFolders &a_folder, const stFolders &b_folder )
                 { return ( a_folder.size < b_folder.size ); } );
    std::vector<stFolders>::iterator it_f = tempFolders.end() - 1;
    std::cout << "The biggest folder has the following attributes: \n";
    for(; it_f != tempFolders.end(); it_f++)
    {
        std::cout << "Size: " << it_f->size << " bytes\t Path-to-folder: " << it_f->path << "\t Content in folder: " << it_f->content << "\n";
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
//Simple mean calculation for file sizes
void System_search::avgFileSize()
{
    std::vector<int> sizes; //holder for size of files
    //looping through the files and extracting the size attribute
    for(std::vector<stFiles>::iterator it_f = m_structFiles.begin(); it_f != m_structFiles.end(); it_f++)
    {
        sizes.push_back(it_f->size);
    }

    //sum and mean calculation
    double sum = std::accumulate(sizes.begin(), sizes.end(), 0.0);
    double mean = sum/sizes.size();
    std::cout << "Mean size of files: " << mean << " bytes\n";

}
//Simple mean calculation for folder sizes
void System_search::avgFolderSize()
{
    std::vector<int> sizes; //holder for size of folders
    //looping through the folders and extracting the contents
    for(std::vector<stFolders>::iterator it_f = m_structFolders.begin(); it_f != m_structFolders.end(); it_f++)
    {
        sizes.push_back(it_f->size);
    }

    //sum and mean calculation
    double sum = std::accumulate(sizes.begin(), sizes.end(), 0.0);
    double mean = sum/sizes.size();
    std::cout << "Mean size of folders: " << mean << " bytes\n";

}
//creates a non-normalized distribution of file extensions
void System_search::distributionOfExtensions()
{
    std::map<std::string, int> fileExtensions; //map to store the number of extensions
    std::map<std::string, int>::iterator it; //iterator to find if the map contains already an extension
    for(std::vector<stFiles>::iterator it_f = m_structFiles.begin(); it_f != m_structFiles.end(); it_f++)
    {
        it = fileExtensions.find(it_f->extension); //find the current extension
        if (it != fileExtensions.end())
        {
            it->second += 1; //if found, increase its multiplicity by one
        }
        else
            fileExtensions.insert(std::pair<std::string, int>(it_f->extension, 1)); //just add to the map
    }
    std::cout << "The filesystem contains:";
    for (auto& x: fileExtensions)
        std::cout << " [\"" << x.first << "\": " << x.second << "]";
    std::cout << '\n';

}
//Prints out all the files and folders from the folder in the input
void System_search::checkR()
{
    for(std::vector<stFiles>::iterator it_f = m_structFiles.begin(); it_f != m_structFiles.end(); it_f++)
    {
        std::cout << "Size: " << it_f->size << " bytes\t Path-to-file: " << it_f->path << "\n";
    }
    for(std::vector<stFolders>::iterator it_f = m_structFolders.begin(); it_f != m_structFolders.end(); it_f++)
    {
        std::cout << "Size: " << it_f->size << " bytes\t Path-to-folder: " << it_f->path << "\t Content in folder: " << it_f->content << "\n";
    }
}