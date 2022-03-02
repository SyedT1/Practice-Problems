#include <iostream>
using namespace std;
struct tree
{
    int value;
    tree *left = nullptr, *right = nullptr;
};
void insert(tree *&k, int v)
{
    if (!k)
    {
        k = new tree{v, nullptr, nullptr};
        return;
    }
    else if (k->value < v)
    {
        insert(k->right, v);
    }
    else if (k->value > v)
    {
        insert(k->left, v);
    }
}
int height(tree *l, int m)
{
    if (l == nullptr)
    {
        return m - 1;
    }
    return max(height(l->right, m + 1), height(l->left, m + 1));
}
int height(tree *l)
{
    return height(l, 0);
}
int main()
{
    tree *l = nullptr;
    int a[] = {4, 2, 1, 100, 56, 57, 58};
    for (int i : a)
    {
        insert(l, i);
    }
    cout << height(l);
}
