#include <iostream>
#include <queue>
using namespace std;
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};
int sumCousin(BinaryTreeNode *k, int val)
{
    if (!k || k->data == val)
        return 0;
    int sm = 0, cn = 1;
    bool isIt = false;
    queue<BinaryTreeNode *> node;
    node.push(k);
    while (!node.empty())
    {
        BinaryTreeNode *curr = node.front();
        node.pop();
        cn--;
        if ((curr->left != nullptr && curr->left->data == val) || (curr->right != nullptr && curr->right->data == val))
        {
            isIt = true;
        }
        else
        {
            if (curr->left)
                node.push(curr->left);
            if (curr->right)
                node.push(curr->right);
        }
        if (!cn)
        {
            if (isIt)
                break;
            cn = node.size();
        }
    }
    if (!isIt)
        return 0;
    while (!node.empty())
    {
        sm += node.front()->data;
        node.pop();
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
    int a[] = {10, 4, 3,2,1, 9, 16, 20, 7, 5, 8, 25, 22, 26};
    for (int i : a)
        ins(cherry, i);
    cout << sumCousin(cherry,8) << endl;
    return 0;
}
