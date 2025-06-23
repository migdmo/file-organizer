#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;
using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;


void create_dir_ext()
{
    try
    {
        for (const auto &dirEntry : fs::recursive_directory_iterator(fs::current_path()))

        {
            if (dirEntry.path().filename() != "main.cpp")
            {
                if (dirEntry.path().string().find(".git") != std::string::npos)
                    continue;
                if (dirEntry.is_regular_file())
                {
                    auto ext = dirEntry.path().extension().string();

                    if (!ext.empty() && ext[0] == '.')
                        ext = ext.substr(1);

                    if (!ext.empty())
                    {
                        fs::path targetDir = fs::current_path() / ext;
                        if (!fs::exists(targetDir))
                        {
                            fs::create_directories(targetDir);
                            std::cout << "Directory created: " << targetDir << std::endl;
                        }

                        fs::path destino = targetDir / dirEntry.path().filename();

                        fs::rename(dirEntry.path(), destino);

                        std::cout << "File moved to: " << destino << std::endl;
                    }
                }
            }
        }
    }

    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main()
{
    create_dir_ext();


    return 0;
}