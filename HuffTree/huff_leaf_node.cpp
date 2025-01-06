#include "huff_node.h"
#include <iostream>

using namespace Huff_Node;
using namespace std;

class Huff_Leaf_Node : public Node {
private:
    char element;
    int freq;
    Node *left;
    Node *right;

public:
    Huff_Leaf_Node(char ch, int freq) : Node(ch, freq) {
        element = ch;
        freq = freq;
        left = nullptr;
        right = nullptr;
    }
    bool isLeaf() {
        return true;
    }
    char getElement() {
        return element;
    }
    int getWeight() {
        return freq;
    }
    Node *getLeft() {
        return nullptr;
    }
    Node *getRight() {
        return nullptr;
    }
};
