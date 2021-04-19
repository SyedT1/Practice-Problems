#include <iostream>
using namespace std;
class tree
{
public:
    int value;
    tree *left = nullptr, *right = nullptr;
};
void insert(tree *&k, int v)
{
    if (k == nullptr)
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
void preOrder(tree *l)
{
    if (!l)
        return;
    cout << l->value << ' ';
    preOrder(l->left);
    preOrder(l->right);
}
int main()
{
    tree *l = nullptr;
    int ar[] = {1, -1, -3, -8, -10, 0, -2, -7, -6, -5, -4, 10, 9, 19};
    for (int i : ar)
    {
        insert(l, i);
    }
    preOrder(l);
}
