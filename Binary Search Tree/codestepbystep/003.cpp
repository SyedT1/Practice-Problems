#include <iostream>
#include <queue>
using namespace std;
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};
int depthSum(BinaryTreeNode *k)
{
    if (!k)
        return 0;
    int sm = 0, cn = 1, depth = 1;
    queue<BinaryTreeNode *> node;
    node.push(k);
    while (!node.empty())
    {
        BinaryTreeNode *curr = node.front();
        sm += (curr->data * depth);
        node.pop();
        cn--;
        if (curr->left)
            node.push(curr->left);
        if (curr->right)
            node.push(curr->right);
        if (!cn)
        {
            cn = node.size();
            depth++;
        }
    }
    return sm;
}
void ins(BinaryTreeNode *&k, int v)
{
    if (!k)
    {
        k = new BinaryTreeNode{v, nullptr, nullptr};
        return;
    }
    else if (k->data < v)
        ins(k->right, v);
    else if (k->data > v)
        ins(k->left, v);
}
int main()
{
    BinaryTreeNode *cherry = nullptr;
    int a[] = {10, 7, 16, 3, 9, 24, 8, 25};
    for (int i : a)
        ins(cherry, i);
    cout << depthSum(cherry) << endl;
    return 0;
}
