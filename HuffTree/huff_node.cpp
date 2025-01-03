#include "huff_node.h"
#include <iostream>

using namespace Huff_Node;
using namespace std;

class Huff_Node {
private:
    char ch;
    int freq;
    Huff_Node *left;
    Huff_Node *right;

public:
    Huff_Node(char ch, int freq) {
        ch = ch;
        freq = freq;
        left = nullptr;
        right = nullptr;
    }
    Huff_Node(char ch, int freq, Huff_Node *left, Huff_Node *right) {
        ch = ch;
        freq = freq;
        left = left;
        right = right;
    }
    bool operator<(const Huff_Node &other) const {
        return freq < other.freq;
    }
    bool operator==(const Huff_Node &other) const {
        return freq == other.freq && ch == other.ch;
    }
};
