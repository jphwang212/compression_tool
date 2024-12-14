#include <filesystem>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

using namespace std;

static void readFile(string file, unordered_map<char, int> *charFreq) {
    struct stat buffer;
    char ch;
    int code = stat(file.c_str(), &buffer);
    if (code != 0) {
        cout << "File is not valid.\ncode " << code << "\n";
        return;
    }
    std::locale::global(std::locale(""));
    std::ifstream readFile(file);
    if (readFile.is_open()) {
        while (readFile.get(ch)) {
            if (ch == ' ' || ch == '\n' || ch == '\'') {
                continue;
            }
            if ((*charFreq).find(ch) == (*charFreq).end()) {
                charFreq->insert({ch, 1});
            } else {
                charFreq->at(ch)++;
            }
        }
    }
}

static void printCharFrequency(unordered_map<char, int> *charFreq) {
    cout << "*******Char Frequency*******\n";
    for (const auto &pair : *charFreq) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
    unordered_map<char, int> charFrequency = unordered_map<char, int>();
    readFile("test.txt", &charFrequency);
    printCharFrequency(&charFrequency);
    return 0;
}
