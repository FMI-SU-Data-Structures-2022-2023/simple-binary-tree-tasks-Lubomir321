#include "solution.h"
#include <iostream>


int countElements(Node* tree) {
   if (tree == NULL)
        return 0;
    return  1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) {
     if (tree == NULL)
        return 0;
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) {
   if (!tree)
        return 0;
    return 1 + std::max(height(tree->left),height(tree->right));
}

int sumElements(Node* tree) {
    if (tree == NULL)
        return 0;
    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    if (tree == NULL)
        return 0;
    if (!level)
        return tree->key;
    return sumElementsAtLevel(tree->left, level - 1)
        + sumElementsAtLevel(tree->right, level - 1);
}
bool isMirror(struct Node* root1, struct Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
 
    
    if (root1 && root2 && root1->key == root2->key)
        return isMirror(root1->left, root2->right)
               && isMirror(root1->right, root2->left);
 
    
    return false;
}
 

bool isSymmetric(struct Node* tree)
{
    return isMirror(root, root);
}

bool isBST(Node* tree)
{
   return false;
}

