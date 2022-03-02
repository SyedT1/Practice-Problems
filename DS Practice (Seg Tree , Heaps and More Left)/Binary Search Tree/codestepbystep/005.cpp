#include <iostream>
#include <stack>
using namespace std;
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};
void insert(BinaryTreeNode *&k, int v)
{
    if (!k)
    {
        k = new BinaryTreeNode{v, nullptr, nullptr};
        return;
    }
    else if (k->data > v)
        insert(k->left, v);
    else if (k->data < v)
        insert(k->right, v);
}

bool findTreeNode(BinaryTreeNode *k, int value)
{
    if (!k)
    {
        return false;
    }
    else if (k->data == value)
        return true;
    else if (k->data > value)
        return findTreeNode(k->left, value);
    else if (k->data < value)
        return findTreeNode(k->right, value);
}
int distance(BinaryTreeNode *k, int value)
{
    if (!k || k->data == value)
        return 0;
    else if (k->data < value)
        return 1 + distance(k->right, value);
    else if (k->data > value)
        return 1 + distance(k->left, value);
}
void subcase(BinaryTreeNode *k, int x, int y, int &max, int &rev_max)
{
    if (!k)
        return;
    subcase(k->left, x, y, max, rev_max);
    subcase(k->right, x, y, max, rev_max);
    if (k->data == x && findTreeNode(k, y))
    {
        max = distance(k, y);
    }
    if (k->data == y && findTreeNode(k, x))
    {
        rev_max = distance(k, x);
    }
}
void pass_(BinaryTreeNode *k, stack<BinaryTreeNode *> &drag, int val)
{
    if (!k)
    {
        return;
    }
    if (k->data == val)
    {
        drag.push(k);
        return;
    }
    drag.push(k);
    if (k->data > val)
        pass_(k->left, drag, val);
    else if (k->data < val)
        pass_(k->right, drag, val);
}
void getDistance(int x, int y, BinaryTreeNode *k, int &sm)
{
    stack<BinaryTreeNode *> alt;
    pass_(k, alt, x);
    while (!alt.empty())
    {
        if (findTreeNode(alt.top(), y))
        {
            sm += distance(alt.top(), y);
            break;
        }
        sm++;
        alt.pop();
    }
}
int getDistance(BinaryTreeNode *k, int x, int y)
{
    if (findTreeNode(k, x) && findTreeNode(k, y))
    {
        if (x == y)
            return 0;
        int mx = 0, rev_max = 0;
        subcase(k, x, y, mx, rev_max);
        if (!max(mx, rev_max))
        {
            if (x > y)
            {
                swap(x, y);
            }
            int count = 0, sum = 0;
            getDistance(x, y, k, sum);
            return sum;
        }
        return max(mx, rev_max);
    }
    return -1;
}
int main()
{
    BinaryTreeNode *cherry = nullptr;
    int a[] = {10, 4, 16, 3, 9, 20, 7, 18, 25, 5, 8, 22, 26};
    for (int i : a)
        insert(cherry, i);
    int from, to;
    cin >> from >> to;
    cout << getDistance(cherry, from, to) << endl;
    return 0;
}
