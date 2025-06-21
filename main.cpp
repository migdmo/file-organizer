#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;
using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

void check_current_directory() {
    try {
        fs::path dir = fs::current_path();
        if (fs::is_empty(dir)) {
            std::cout << "Current directory is empty." << std::endl;
        } else {
            std::cout << "Current directory is not empty." << std::endl;
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
int main(){
    fs::path dir = "mydir";
    if(!exists(dir)){
        create_directories(dir);
        cout << "Directory created: " << dir << endl;
    }
    check_current_directory(); 
    try {
        for (const auto& dirEntry : fs::recursive_directory_iterator(fs::current_path())) {
            if (dirEntry.path().string().find(".git") != std::string::npos)
                continue; 

            cout << dirEntry.path().filename() << endl;
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Erro ao percorrer diretórios: " << e.what() << endl;
    }

    return 0;
}