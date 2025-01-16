#include "huff_node.h"
#include <iostream>

using namespace Huff_Node;
using namespace std;

class Huff_LeafNode : public Node {
    using Node::getElement;
    using Node::getWeight;

public:
    Huff_LeafNode();
    Huff_LeafNode(char ch, int weight);
    bool isLeaf();
    bool operator<(Node *other) const {
        return this < other;
    }
};

Huff_LeafNode::Huff_LeafNode() {
    Node::setElement(NULL);
    Node::setWeight(NULL);
}

Huff_LeafNode::Huff_LeafNode(char ch, int weight) {
    Node::setElement(ch);
    Node::setWeight(weight);
}

bool Huff_LeafNode::isLeaf() {
    return true;
}
