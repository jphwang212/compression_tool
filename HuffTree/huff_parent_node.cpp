#include "huff_node.h"
#include <iostream>

using namespace Huff_Node;
using namespace std;

class Huff_Parent_Node : public Node {
private:
    char element;
    int freq;
    Node *left;
    Node *right;

public:
    Huff_Parent_Node(char ch, int freq, Node *left, Node *right) : Node(ch, freq, left, right) {
        element = ch;
        freq = freq;
        left = left;
        right = right;
    }
    bool isLeaf() {
        return false;
    }
    char getElement() {
        return element;
    }
    int getWeight() {
        return freq;
    }
    Node *getLeft() {
        return left;
    }
    Node *getRight() {
        return right;
    }
};
