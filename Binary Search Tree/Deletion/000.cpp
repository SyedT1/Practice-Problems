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

void deleteNode(tree *&l)
{
    tree *sub = l->right;
    while (sub->left->left != nullptr)
    {
        sub = sub->left;
    }
    l->value = sub->left->value;
    tree *temp = sub->left, *rig = sub->left->right;
    delete temp;
    sub->left = rig;
}
void deleteNode(tree *&l, int from, int to)
{
    if (!l)
        return;
    deleteNode(l->left, from, to);
    deleteNode(l->right, from, to);
    if (l->value >= from && l->value <= to)
    {
        if (l->right == nullptr && l->left == nullptr)
        {
            tree *k = l;
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
                deleteNode(l);
            }
        }
    }
}
void inOrder(tree *l)
{
    if (!l)
        return;
    inOrder(l->left);
    cout << l->value << ' ';
    inOrder(l->right);
}
int main()
{
    tree *l = nullptr;
    int ar[] = {4, 2, 1, 100, 55, 57, 58};
    for (int i : ar)
    {
        insert(l, i);
    }
    inOrder(l);
    int from, to;
    cout << '\n';
    cout << "From : ";
    cin >> from;
    cout << "To : ";
    cin >> to;
    deleteNode(l, from, to);
    inOrder(l);
}
