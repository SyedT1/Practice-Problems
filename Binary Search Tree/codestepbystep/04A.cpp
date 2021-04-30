#include <iostream>
#include <queue>
using namespace std;
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};
bool hasPath(BinaryTreeNode *k, int start, int end)
{
    if (!k)
        return false;
    bool eval = hasPath(k->left, start, end) || hasPath(k->right, start, end);
    if (k->data == start)
    {
        if (start == end)
            return true;
        else
            return true && (hasPath(k->left, end, end) || hasPath(k->right, end, end));
    }
    else
        return eval;
}

int main()
{
    string outcome[] = {"false", "true"};
    BinaryTreeNode *cherry = new BinaryTreeNode{67, new BinaryTreeNode{38, nullptr, nullptr}, new BinaryTreeNode{152, new BinaryTreeNode{99, nullptr, nullptr}, nullptr}};
    cherry->left->left = new BinaryTreeNode{16, nullptr, nullptr};
    cherry->left->right = new BinaryTreeNode{42, new BinaryTreeNode{40, nullptr, nullptr}, nullptr};
    cout << hasPath(cherry, 52, 99) << endl;
    int testcases[][2] = {{67, 99}, {67, 67}, {16, 16}, {99, 67}, {38, 99}, {67, 100}, {-1, 40}, {34, 64}};
    for (auto &i : testcases)
    { 
        cout << "hasPath(tree," << *i << ", " << *(i + 1) << ") = " << outcome[hasPath(cherry, *i, *(i + 1))] << endl;
    }
}
