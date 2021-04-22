#include <iostream>
using namespace std;
class tree
{
public:
    int value;
    tree *left = nullptr, *right = nullptr;
};
void ins(tree *&l, int v)
{
    if (!l)
    {
        l = new tree{v, nullptr, nullptr};
        return;
    }
    else if (l->value < v)
        ins(l->right, v);
    else if (l->value > v)
        ins(l->left, v);
}
void inOrder(tree *l)
{
    if (!l)
        return;
    inOrder(l->left);
    cout << l->value << ' ';
    inOrder(l->right);
}
void AddNodeGreater(tree *&l, int &s)
{
    if (!l)
        return;
    AddNodeGreater(l->right, s);
    s += l->value;
    l->value = s;
    AddNodeGreater(l->left, s);
}
void AddNodeGreater(tree *&l)
{
    int sm = 0;
    AddNodeGreater(l, sm);
}
int main()
{
    tree *k = nullptr;
    int A[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i : A)
        ins(k, i);
    inOrder(k);
    AddNodeGreater(k);
    cout << endl;
    inOrder(k);
}
