#include "solution.h"
#include <iostream>
#include <vector>

int countElements(Node* tree) {
    if (!tree)
        return 0;
    return 1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) {
    if (!tree)
        return 0;
    if (!tree->left && !tree->right)
        return 1;
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) {
    if (!tree)
        return 0;
    return 1 + std::max(height(tree->left), height(tree->right));
}

int sumElements(Node* tree) {
    if (!tree)
        return 0;
    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    if (!tree)
        return 0;
    if (level == 0)
        return tree->key;
    return sumElementsAtLevel(tree->left, level- 1) + sumElementsAtLevel(tree->right, level - 1);
}
bool helpIsSymmetric(Node* tree1, Node* tree2)
{
    if (!tree1 && !tree2)
        return true;

    if (tree1 && tree2 && tree1->key == tree2->key)
        return helpIsSymmetric(tree1->left, tree2->right) &&
        helpIsSymmetric(tree1->right , tree2->left);

    return false;
}
bool isSymmetric(Node* tree) {
    if (!tree)
        return true;
    return helpIsSymmetric(tree->left, tree->right);
}
void inOrder(Node* tree, std::vector<int>& v)
{
    if (!tree)
        return;

    inOrder(tree->left, v);
    v.push_back(tree->key);
    inOrder(tree->right, v);
}
bool isBST(Node* tree) {
    std::vector<int> v;
    inOrder(tree, v);
    for (int i = 0; i < v.size()- 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}
