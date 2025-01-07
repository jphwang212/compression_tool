#include "huff_node.h"
#include <iostream>

using namespace Huff_Node;
using namespace std;

class Huff_Leaf_Node : public Node {
private:
    char element;
    int freq;

public:
    Huff_Leaf_Node(char ch, int freq) {
        element = ch;
        freq = freq;
    }
    bool isLeaf() {
        return true;
    }
    char getElement() {
        return element;
    }
    int getWeight() {
        return freq;
    }
};
