#include <iostream>
using namespace std;
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left, *right;
};
void postOrder(BinaryTreeNode *m)
{
    if (!m)
        return;
    postOrder(m->left);
    postOrder(m->right);
    cout << m->data << ' ';
}
void countLeftNodes(BinaryTreeNode *a, int &c)
{
    if (!a)
        return;
    countLeftNodes(a->left, c);
    if(a->left!=nullptr)c++;
    countLeftNodes(a->right, c);
}
int countLeftNodes(BinaryTreeNode *k)
{
    int count_left = 0;
    countLeftNodes(k, count_left);
    return count_left;
}
int main()
{
    BinaryTreeNode *k = new BinaryTreeNode{2, nullptr, nullptr};
    k->right = new BinaryTreeNode{1, nullptr, nullptr};
    k->right->left = new BinaryTreeNode{7, nullptr, nullptr};
    k->right->right = new BinaryTreeNode{6, nullptr, nullptr};
    k->right->left->left =
        new BinaryTreeNode{4, new BinaryTreeNode{3, nullptr}, new BinaryTreeNode{5, nullptr}};
    k->right->right->right = new BinaryTreeNode{9, new BinaryTreeNode{8, nullptr, nullptr}, nullptr};
    //postOrder(k);
    cout << countLeftNodes(k);
}
