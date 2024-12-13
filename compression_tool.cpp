#include <filesystem>
#include <iostream>
#include <sys/stat.h>

using namespace std;

static void readFile(string file) {
    struct stat buffer;
    int code = stat(file.c_str(), &buffer);
    if (code == 0) {
        cout << "File is valid.\n";
    } else {
        cout << "File is NOT valid.\nCode " << code;
    }
}

int main() {
    readFile("file");
    return 0;
}
