#include "HuffTree/huff_node.h"
#include "HuffTree/huff_tree.cpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

using namespace std;
using namespace Huff_Node;

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

vector<Huff_Tree *> buildHuffSetup(unordered_map<char, int> *charFreq) {
    vector<Huff_Tree *> nodes;
    Huff_Tree *ht;
    for (const auto &pair : (*charFreq)) {
        *ht = Huff_Tree(pair.first, pair.second);
        nodes.push_back(ht);
    }
    return nodes;
}

void destroyTree(Huff_Tree *tree) {
    if (tree == nullptr) {
        return;
    }
    if (!(tree->Huff_Tree::isLeaf())) {
        destroyTree(tree->getLeft());
        destroyTree(tree->getRight());
    }
    delete tree;
}

int main() {
    unordered_map<char, int> charFrequency = unordered_map<char, int>();
    readFile("test.txt", &charFrequency);
    printCharFrequency(&charFrequency);
    vector<Huff_Tree *> trees = buildHuffSetup(&charFrequency);
    destroyTree(trees[0]);

    // TODO
    /**
     * @brief
     * figure out class templates
     * compile fails possibly due to this
     */
    return 0;
}
