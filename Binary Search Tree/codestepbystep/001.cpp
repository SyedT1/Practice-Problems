#include <iostream>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left = nullptr, *right = nullptr;
};
void insert(BinaryTreeNode *&k, int v)
{
    if (k == nullptr)
    {
        k = new BinaryTreeNode{v, nullptr, nullptr};
        return;
    }
    else if (k->data < v)
    {
        insert(k->right, v);
    }
    else if (k->data > v)
    {
        insert(k->left, v);
    }
}

void range(BinaryTreeNode *&l, BinaryTreeNode *&k)
{
    if (!l->left->left)
    {
        k->data = l->left->data;
        BinaryTreeNode *temp = l->left, *rig = l->left->left;
        delete temp;
        l->left = rig;
        return;
    }
    range(l->left->left, k);
}
void range(int &count, BinaryTreeNode *&l, int from, int to)
{
    if (!l)
        return;
    range(count, l->left, from, to);
    range(count, l->right, from, to);
    if (!(l->data >= from && l->data <= to))
    {
        count++;
        if (l->right == nullptr && l->left == nullptr)
        {
            BinaryTreeNode *k = l;
            delete k;
            l = nullptr;
        }
        else if (l->right == nullptr)
        {
            l = l->left;
        }
        else if (l->left == nullptr)
        {
            l = l->right;
        }
        else
        {
            if (l->right->left == nullptr)
            {
                l = l->right;
            }
            else
            {
                range(l->right, l);
            }
        }
    }
}
int range(BinaryTreeNode *&l, int from, int to)
{
    if(from > to)throw -1;
    int count = 0;
    range(count, l, from, to);
    return count;
}
void inOrder(BinaryTreeNode *l)
{
    if (!l)
        return;
    inOrder(l->left);
    cout << l->data << ' ';
    inOrder(l->right);
}
int main()
{
    BinaryTreeNode *l = nullptr;
    int ar[] = {50, 38, 42, 14, 8, 20, 26, 90, 54, 72, 61, 83};
    for (int i : ar)
    {
        insert(l, i);
    }
    inOrder(l);
    int from, to;
    cout << '\n';
    cout << "Deletion of keys outside a given range  " << endl;
    cout << "Min : ";
    cin >> from;
    cout << "Max : ";
    cin >> to;
    cout << range(l, from, to) << endl;
    inOrder(l);
}
