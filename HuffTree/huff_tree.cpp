#include "huff_leaf_node.cpp"
#include "huff_node.h"
#include "huff_parent_node.cpp"
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
Huff_Tree Huff_Tree::buildTree(vector<Huff_Tree *> huff_trees) {
    struct custom {
        bool operator()(const Huff_Tree *lhs, const Huff_Tree *rhs) const {
            return (*lhs).root->getWeight() > (*rhs).root->getWeight();
        }
    };
    Huff_Tree *tmp1, *tmp2, *tmp3;
    std::sort(huff_trees.begin(), huff_trees.end());
    std::reverse(huff_trees.begin(), huff_trees.end());
    std::make_heap(huff_trees.begin(), huff_trees.end(), custom());
    while (huff_trees.size() > 1) {
        std::pop_heap(huff_trees.begin(), huff_trees.end());
        tmp1 = huff_trees.back();
        huff_trees.pop_back();
        std::pop_heap(huff_trees.begin(), huff_trees.end());
        tmp2 = huff_trees.back();
        huff_trees.pop_back();
        *tmp3 = Huff_Tree(tmp1->root->getElement(), tmp1->root->getWeight());
        huff_trees.push_back(tmp3);
    }
    return *tmp3;
}
