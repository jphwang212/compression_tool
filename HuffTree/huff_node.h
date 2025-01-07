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
    bool isLeaf();
    char getElement();
    int getWeight();
    Node *getLeft();
    Node *getRight();

    bool operator>(const Node &other) const {
        return freq > other.freq;
    }
    bool operator<(const Node &other) const {
        return freq < other.freq;
    }
    bool operator==(const Node &other) const {
        return freq == other.freq && element == other.element;
    }
};

} // namespace Huff_Node

#endif
