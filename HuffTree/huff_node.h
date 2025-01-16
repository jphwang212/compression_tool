#ifndef HUFF_NODE_H
#define HUFF_NODE_H
#include <iostream>

namespace Huff_Node {
class Huff_Leaf_Node;
class Huff_Parent_Node;
class Node {
private:
    char element;
    int freq;
    Node *left;
    Node *right;

public:
    Node();
    Node(char ch, int fr);
    Node(Node *l, Node *r, int fr);
    bool isLeaf();
    char getElement();
    int getWeight();
    Node *getLeft();
    Node *getRight();
    void setElement(char ch);
    void setWeight(int weight);
    void setLeft(Node *l);
    void setRight(Node *r);

    bool operator>(const Node &other) const {
        return freq > other.freq;
    }
    bool operator<(const Node &other) const {
        return freq < other.freq;
    }
    bool operator==(const Node &other) const {
        return freq == other.freq && element == other.element;
    }
    Node &operator=(const Node &rhs) {
        if (this == &rhs) {
            return *this;
        }
        element = rhs.element;
        freq = rhs.freq;
        left = rhs.left;
        right = rhs.right;
        return *this;
    }
    bool operator()(Node *lhs, Node *rhs) const {
        return lhs->getWeight() > rhs->getWeight();
    }
};

Node::Node() {
    element = NULL;
    freq = 0;
    left = nullptr;
    right = nullptr;
}

Node::Node(char ch, int fr) {
    element = ch;
    freq = fr;
    left = nullptr;
    right = nullptr;
}

Node::Node(Node *l, Node *r, int fr) {
    element = NULL;
    left = l;
    right = r;
    freq = fr;
}
void Node::setElement(char ch) {
    element = ch;
}
void Node::setWeight(int weight) {
    freq = weight;
}
void Node::setLeft(Node *l) {
    left = l;
}
void Node::setRight(Node *r) {
    right = r;
}

} // namespace Huff_Node

#endif
