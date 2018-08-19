#include <string>
int main() {}

// (a) act like value

class TreeNode {
public:
    TreeNode(const std::string &s = std::string()) : value(s), count(1), left(new TreeNode(std::string())), right(new TreeNode(std::string())) { }
    TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(new TreeNode(*tn.left)), right(new TreeNode(*tn.right)) { }
    TreeNode& operator= (const TreeNode&);
    ~TreeNode();
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode& TreeNode::operator= (const TreeNode &rhs) {
    auto tleft = new TreeNode(*rhs.left);
    auto tright = new TreeNode(*rhs.right);
    delete left;
    delete right;
    value = rhs.value;
    count = rhs.count;
    left = tleft;
    right = tright;
    return *this;
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}

// (b) act like pointer

class BinStrTree {
public:
    BinStrTree(const TreeNode &tn = TreeNode()) : root(new TreeNode(tn)), use(new size_t(1)) { }
    BinStrTree(const BinStrTree &bst) : root(bst.root), use(bst.use) { ++*use; }
    BinStrTree& operator= (const BinStrTree&);
    ~BinStrTree();
private:
    TreeNode *root;
    size_t *use;
};

BinStrTree& BinStrTree::operator= (const BinStrTree &rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete root;
        delete use;
    }
    root = rhs.root;
    use = rhs.use;
    return *this;
}

BinStrTree::~BinStrTree() {
    if (--*use == 0) {
        delete root;
        delete use;
    }
}
