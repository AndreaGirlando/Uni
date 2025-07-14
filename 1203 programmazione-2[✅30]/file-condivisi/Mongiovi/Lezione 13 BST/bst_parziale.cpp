#include <iostream>

using namespace std;

class BST;

class BSTNode 
{
private:
    BSTNode() : left(nullptr), right(nullptr) {}
public:
    int getVal() const {return val;}
private:
    int val;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
    friend class BST;
};

class BST
{
public:
    BST() : root(nullptr) {}
    ~BST() {Delete(root);}

    BST& Insert(int val);
    BSTNode* Search(int val);
    BSTNode* Min();
    BSTNode* Next(BSTNode* node);

    void Print();
    void PrintInorder();
//    friend ostream& operator<<(ostream& stream, BST& tree);

private:
    BSTNode* Search(BSTNode* node, int val);
    BSTNode* Min(BSTNode* node);
    void Print(BSTNode* node);
    void PrintInorder(BSTNode* node);
    void Delete(BSTNode* node);
    BSTNode* root;
};

//ostream& operator<<(ostream& stream, BST& tree)
//{
//    tree.PrintInorder(tree.root)
//}


int main() {
    BST albero;

    albero.Insert(10);
    albero.Print();
    albero.Insert(13);
    albero.Print();
    albero.Insert(5);
    albero.Print();
    albero.Insert(6);
    albero.Print();
    albero.Insert(12);
    albero.Print();

    albero.PrintInorder();
    BSTNode* p = albero.Min();
    cout << "Il minimo dell'albero e': " << p->getVal() << endl;
    cout << "I nodi dal minimo seguendo il successore sono: " << endl;
    while (p) {
        cout << p->getVal() << endl;
        p = albero.Next(p);
    }
    return 0;
}

BST& BST::Insert(int val)
{
    BSTNode* x = root;
    BSTNode* y = nullptr;
    while (x != nullptr)
    {
        y = x;
        if (val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    BSTNode* node = new BSTNode;
    node->val = val;
    node->parent = y;
    if (y == nullptr)
        root = node;
    else if (val < y->val)
        y->left = node;
    else
        y->right = node;
    return *this;
}

BSTNode* BST::Search(int val)
{
    return Search(root,val);
}

BSTNode* BST::Search(BSTNode* node, int val)
{
    if (node==nullptr || node->val == val)
        return node;
    else if (val < node->val)
        return Search(node->left, val);
    else
        return Search(node->right, val); 
}

BSTNode* BST::Min()
{
    return Min(root);
}

BSTNode* BST::Min(BSTNode* x)
{
    BSTNode* y = nullptr;
    while (x)
    {   
        y = x;
        x = x->left;
    } 
    return y;
}

BSTNode* BST::Next(BSTNode* x)
{
    // precondizione: x non deve essere un puntatore valido ad un nodo esistente
    if (x->right)
        return Min(x->right);
    BSTNode* y = x->parent;
    while (y != nullptr && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}


void BST::Print()
{
    Print(root);
    cout << endl;
}

void BST::Print(BSTNode* node)
{
    if (node)
    {
        cout << "this: " << node << " val: " << node->val << " parent: " << node->parent << " left: " << node->left << " right: " << node->right << endl;
        Print(node->left);
        Print(node->right);
    }
}

void BST::PrintInorder()
{
    PrintInorder(root);
    cout << endl;
}

void BST::PrintInorder(BSTNode* node)
{
    if (node)
    {
        PrintInorder(node->left);
        cout << node->val << " ";
        PrintInorder(node->right);
    }
}

void BST::Delete(BSTNode* node)
{
    if (node)
    {
        Delete(node->left);
        Delete(node->right);
        delete node;
    }
}