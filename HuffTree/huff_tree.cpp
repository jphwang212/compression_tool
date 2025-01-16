#include "huff_leaf_node.cpp"
#include "huff_node.h"
#include "huff_parent_node.cpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
using namespace Huff_Node;

class Huff_Tree : Node {
private:
    Node *root;

public:
    Huff_Tree();
    Huff_Tree(char ch, int freq);
    Huff_Tree(Huff_Tree *l, Huff_Tree *r, int freq);
    Huff_Tree(const Huff_Tree &ht);
    ~Huff_Tree();
    int getWeight();
    Huff_Tree buildTree(vector<Huff_Tree *> nodes);
};

// vector<Huff_Tree> makeHuffVector(vector<Node *> nodes) {
//     vector<Huff_Tree> huff_vector;
//     Huff_Tree h;
//     for (Node *n : nodes) {
//         h = Huff_Tree(n->getElement(), n->getWeight());
//         huff_vector.push_back(h);
//     }
//     return huff_vector;
// }
Huff_Tree::Huff_Tree() {
    root = nullptr;
}
Huff_Tree::Huff_Tree(char ch, int freq) {
    root = new Huff_LeafNode(ch, freq);
}
Huff_Tree::Huff_Tree(Huff_Tree *l, Huff_Tree *r, int freq) {
    root = new Huff_ParentNode(freq, l, r);
}
Huff_Tree::Huff_Tree(const Huff_Tree &ht) {
    *this = ht;
}
Huff_Tree::~Huff_Tree() {
    delete root;
}
int Huff_Tree::getWeight() {
    return root->getWeight();
}

Huff_Tree Huff_Tree::buildTree(vector<Huff_Tree *> huff_trees) {
    Huff_Tree *tmp1, *tmp2, *tmp3;
    std::sort(huff_trees.begin(), huff_trees.end());
    std::reverse(huff_trees.begin(), huff_trees.end());
    std::make_heap(huff_trees.begin(), huff_trees.end(), Node::operator());
    while (huff_trees.size() > 1) {
        std::pop_heap(huff_trees.begin(), huff_trees.end());
        tmp1 = huff_trees.back();
        huff_trees.pop_back();
        std::pop_heap(huff_trees.begin(), huff_trees.end());
        tmp2 = huff_trees.back();
        huff_trees.pop_back();
        *tmp3 = Huff_Tree(tmp1, tmp2, tmp1->getWeight() + tmp2->getWeight());
        huff_trees.push_back(tmp3);
    }
    return *tmp3;
}
