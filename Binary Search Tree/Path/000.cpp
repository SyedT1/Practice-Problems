#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class tree
{
public:
    int value;
    tree *left = nullptr, *right = nullptr;
    void ins(tree *&k, int v);
    void dis(tree *k);
};
void tree::ins(tree *&k, int v)
{
    if (!k)
    {
        k = new tree{v, nullptr, nullptr};
        return;
    }
    if (k->value < v)
        ins(k->right, v);
    else if (k->value > v)
        ins(k->left, v);
}
void dis(tree *k)
{
    if (!k)
        return;
    dis(k->left);
    cout << k->value << ' ';
    dis(k->right);
}
int countNodes(tree *n)
{
    if (!n)
        return 0;
    return 1 + countNodes(n->left) + countNodes(n->right);
}
void printPaths(int a[], int s)
{
    for (int j = 0; j < s; )
    {
        cout << a[j++] << ' ';
    }
    cout << endl;
}
void printPaths(tree *k, int a[], int s, int i)
{
    if (k == nullptr)
    {
        printPaths(a, i);
        return;
    }
    a[i] = k->value;
    printPaths(k->left, a, s, i + 1);
    if (k->left == nullptr || k->right == nullptr)
        return;
    printPaths(k->right, a, s, i + 1);
}
void printPaths(tree *k)
{
    if (!k)
        return;
    int numberofNodes = countNodes(k);
    int a[numberofNodes + 1] = {};
    int i = 0;
    printPaths(k, a, numberofNodes, i);
}
int main()
{
    tree *cherry = nullptr;
    int A[] = {4, 3, 0, -1, 2, 10, 9, 11};
    for (int i : A)
    {
        cherry->ins(cherry, i);
    }
    printPaths(cherry);
}
