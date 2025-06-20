#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace std::filesystem;

int main(){
    path dir = "mydir";
    if(!exists(dir)){
        create_directories(dir);
        cout << "Directory created: " << dir << endl;
    }
    cout << "Current path is: " << current_path() << endl;
}