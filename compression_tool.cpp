#include <filesystem>
#include <iostream>
#include <sys/stat.h>

using namespace std;

static void readFile(string file) {
    struct stat buffer;
    int code = stat(file.c_str(), &buffer);
    cout << "Code = " << code;
}

int main() {
    readFile("file");
    return 0;
}
