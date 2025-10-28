#ifndef EX13_28_H
#define EX13_28_H

#include <string>

using std::string;

class TreeNode {
public:
    TreeNode(): value(string()), count(new int(1)), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode &rhs): value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
    TreeNode& operator=(const TreeNode&);
    ~TreeNode();
private:
    string   value;
    int      *count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode &rhs) {
    ++*rhs.count;
    if (--*count == 0) {
        delete count;
        delete left;
        delete right;
    }
    value = rhs.value;
    count = rhs.count;
    left  = rhs.left;
    right = rhs.right;
    return *this;
}

TreeNode::~TreeNode() {
    if (--*count == 0) {
        delete count;
        delete left;
        delete right;
    }
}

class BinStrTree {
public:
    BinStrTree(): root(new TreeNode()) { }
    BinStrTree(const BinStrTree &bst): root(new TreeNode(*bst.root)) { }
    BinStrTree& operator=(const BinStrTree&);
    ~BinStrTree() { delete root; }
private:
    TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree &bst) {
    TreeNode* p_root = new TreeNode(*bst.root);
    delete root;
    root = p_root;
    return *this;
}

#endif