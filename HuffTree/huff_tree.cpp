#include "huff_leaf_node.cpp";
#include "huff_node.h";
#include "huff_parent_node.cpp";
#include <iostream>

using namespace std;
using namespace Huff_Node;

class Huff_Tree {
private:
    Node *root;

public:
    Huff_Tree(char ch, int freq) {
        root = new Huff_Leaf_Node(ch, freq);
    }
    Huff_Tree(char ch, Node *l, Node *r, int freq) {
        root = new Huff_Parent_Node(ch, freq, l, r);
    }
    int getWeight() {
        return root->getWeight();
    }
    bool operator<(Huff_Tree &other) const {
        return root->getWeight() < (&other)->getWeight();
    }
    bool operator==(Huff_Tree &other) const {
        return root->getWeight() == (&other)->getWeight() && root->getElement() == (&other)->getWeight();
    }
};
