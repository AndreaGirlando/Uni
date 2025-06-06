//
//  bst.cpp
//  BST
//
//  Created by Misael Mongiovì on 20/05/24.
//

#include "bst.hpp"

template <typename T>
BST<T>& BST<T>::Insert(T val)
{
    BSTNode<T>* curr = root;
    BSTNode<T>* prec = NULL;
    while (curr != NULL)
    {
        prec = curr;
        if(val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    BSTNode<T>* newnode = new BSTNode<T>(val);
    newnode->parent = prec;
    if (prec == NULL)
        root = newnode;
    else if (val < prec->val)
        prec->left = newnode;
    else
        prec->right = newnode;
    return *this;
}

template <typename T>
void BST<T>::print(ostream& os, BSTNode<T>* node) const
{
    if (node!=NULL)
    {
        print(os,node->left);
        os << node->GetValue() << " ";
        print(os,node->right);
    }
}

template <typename T>
void BST<T>::printPreorder(ostream& os, BSTNode<T>* node) const
{
    if (node != NULL)
    {
        os << node->GetValue() << " ";
        printPreorder(os, node->left);
        printPreorder(os,node->right);
    }
}

template <typename T>
BSTNode<T>* BST<T>::Search(T val)
{
    return Search(val, root);
}

template <typename T>
BSTNode<T>* BST<T>::Search(T val, BSTNode<T>* node)
{
    if(node == NULL || val == node->val)
        return node;
    else if (val < node->val)
        return Search(val, node->left);
    else
        return Search(val, node->right);
}

template <typename T>
BSTNode<T>* BST<T>::Min(BSTNode<T>* p)
{
    if (p == NULL)
        p = root;
    if (p==NULL)
        return NULL;
    while(p->left!=NULL)
        p = p->left;
    return p;
}

template <typename T>
BSTNode<T>* BST<T>::Next(BSTNode<T>* p)
{
    // precondizione: assumiamo che p != NULL
    if (p->right)
        return Min(p->right);
    BSTNode<T>* parent = p->parent;
    while (parent!=NULL && p != parent->left)
    {
        p = parent;
        parent = p->parent;
    }
    return parent;
}

template <typename T>
BSTNode<T>* BST<T>::Trapianta(BSTNode<T>* dest, BSTNode<T>* src)
{
    if (dest->parent == NULL)
        root = src;
    else if (dest == dest->parent->left)
        dest->parent->left = src;
    else
        dest->parent->right = src;
    if (src != NULL)
        src->parent = dest->parent;
    return dest;
}

template <typename T>
void BST<T>::Remove(BSTNode<T>* p)
{
    // precondizione: p != NULL e deve essere un puntatore valido
    if ((p->left == NULL) && (p->right == NULL))
        // questo caso si potrebbe anche evitare in quanto è automaticamente gestito dal caso successivo
        // e un'implementazione opportuna di Trapianta
        if (p->parent == NULL)
            root = NULL;
        else if (p->parent->left == p)
            p->parent->left = NULL;
        else
            p->parent->right = NULL;
    else if (p->right == NULL)
        Trapianta(p, p->left);
    else if (p->left == NULL)
        Trapianta(p, p->right);
    else
    {
        BSTNode<T>* next = Min(p->right);
        if (p->right != next)
        {
            Trapianta(next, next->right);
            next->right = p->right;
            p->right->parent = next;
        }
        Trapianta(p, next);
        next->left = p->left;
        next->left->parent = next;
    }
    delete p;
}

template <typename T>
void BST<T>::Delete(BSTNode<T>* p)
{
    if(p!=NULL)
    {
        Delete(p->left);
        Delete(p->right);
        delete p;
    }
}

template <typename T>
ostream& operator<< (ostream& os, const BST<T>& bst)
{
    bst.print(os, bst.root);
    return os;
}
