#include "huff_node.h"
#include <iostream>

using namespace Huff_Node;
using namespace std;

class Huff_ParentNode : public Node {
private:
    Node *left;
    Node *right;

public:
    Huff_ParentNode(int freq, Node *left, Node *right);
    bool isLeaf();
    Node *getLeft();
    Node *getRight();
};

Huff_ParentNode::Huff_ParentNode(int freq, Node *left, Node *right) {
    freq = freq;
    left = left;
    right = right;
}

bool Huff_ParentNode::isLeaf() {
    return false;
}

Node *Huff_ParentNode::getLeft() {
    return left;
}

Node *Huff_ParentNode::getRight() {
    return right;
}
