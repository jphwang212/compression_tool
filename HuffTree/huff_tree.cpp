#include "huff_leaf_node.cpp";
#include "huff_node.h";
#include "huff_parent_node.cpp";
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using namespace Huff_Node;

class Huff_Tree {
private:
    Node *root;

public:
    Huff_Tree() {
        root = nullptr;
    }
    Huff_Tree(char ch, int freq) {
        root = new Huff_Leaf_Node(ch, freq);
    }
    Huff_Tree(char ch, Node *l, Node *r, int freq) {
        root = new Huff_Parent_Node(freq, l, r);
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
    Huff_Tree buildTree(vector<Node *> nodes);
};

Huff_Tree Huff_Tree::buildTree(vector<Node *> nodes) {
    Huff_Tree tmp1, tmp2, tmp3;
    std::sort(nodes.begin(), nodes.end());
    std::reverse(nodes.begin(), nodes.end());
    std::make_heap(nodes.begin(), nodes.end(), std::greater<Node>{});
}
