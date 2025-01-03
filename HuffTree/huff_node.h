#ifndef HUFF_NODE_H
#define HUFF_NODE_H
#include <iostream>

namespace Huff_Node {
class Node {
private:
    char element;
    int freq;
    Node *left;
    Node *right;

public:
    Node(char ch, int freq);
    Node(char ch, int freq, Node *left, Node *right);
    bool isLeaf();
    char getElement();
    int getWeight();
};

} // namespace Huff_Node

#endif
