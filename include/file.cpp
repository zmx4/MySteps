#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
std::vector<std::string> getFilesInDirectory(const std::string &directoryPath)
{
    std::vector<std::string> fileNames;
    for (const auto &entry : std::filesystem::directory_iterator(directoryPath))
    {
        if (entry.is_regular_file())
        {
            fileNames.push_back(entry.path().filename().string());
        }
    }
    return fileNames;
}
std::vector<std::string> getFilesInDirectory(const std::string &directoryPath, std::string fileExtension)
{
    std::vector<std::string> fileNames;
    for (const auto &entry : std::filesystem::directory_iterator(directoryPath))
    {
        if (entry.is_regular_file() && entry.path().extension() == fileExtension)
        {
            fileNames.push_back(entry.path().filename().string());
        }
    }
    return fileNames;
}
std::string readFileContent(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}
void writeFileContent(const std::string &filePath, const std::string &content)
{
    std::ofstream file(filePath);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filePath);
    }
    file << content;
    file.close();
}
int main()
{
    std::string directoryPath;
    std::string fileExtension;
    std::string outputFile = "output.txt";
    std::cout << "Enter directory path: ";
    // std::cin >> directoryPath;
    std::getline(std::cin, directoryPath);
    std::cout << "Enter file extension (e.g., .txt): ";
    // std::cin >> fileExtension;
    std::getline(std::cin, fileExtension);
    // if(fileExtension.empty())
    // {
    //     fileExtension = ".txt"; // Default to .txt if no extension is provided
    // }
    if (directoryPath.empty())
    {
        directoryPath = "."; // Default to current directory if no path is provided
    }
    if (!std::filesystem::exists(directoryPath) || !std::filesystem::is_directory(directoryPath))
    {
        std::cerr << "Error: Invalid directory path." << std::endl;
        return 1;
    }
    try
    {
        std::vector<std::string> files;
        if (!fileExtension.empty())
            files = getFilesInDirectory(directoryPath, fileExtension);
        else
            files = getFilesInDirectory(directoryPath);
        for (const auto &file : files)
        {
            std::cout << file << std::endl;
            std::string content = readFileContent(directoryPath + "/" + file);
            writeFileContent(outputFile, content);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}