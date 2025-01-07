#include "huff_node.h"
#include <iostream>

using namespace Huff_Node;
using namespace std;

class Huff_Parent_Node : public Node {
private:
    int freq;
    Node *left;
    Node *right;

public:
    Huff_Parent_Node(int freq, Node *left, Node *right) {
        freq = freq;
        left = left;
        right = right;
    }
    bool isLeaf() {
        return false;
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
