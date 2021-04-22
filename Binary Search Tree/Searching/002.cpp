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
void maximum(int &m, tree *l, int &r)
{
    if (!l)
        return;
    maximum(m, l->right, r);
    --m;
    if (m == 0)
    {
        r = l->value;
    }
    maximum(m, l->left, r);
}
int maximum(tree *l, int n)
{
    int q = 0;
    maximum(n, l, q);
    if (!(n < 1))
    {
        throw "number of nodes is less than the query";
    }
    return q;
}
void inOrder(tree *l)
{
    if (!l)
        return;
    inOrder(l->right);
    cout << l->value << ' ';
    inOrder(l->left);
}
int main()
{
    tree *l = nullptr;
    int a[] = {10, 9, 8, 1, 20, 19, 18, 17, 16};
    for (int i : a)
    {
        insert(l, i);
    }
    inOrder(l);
    cout << endl;
    int k;
    cout << "Enter the value of k = ";
    cin >> k;
    try
    {
        cout <<"Result = " << maximum(l, k) << '\n';
    }
    catch (const char *s)
    {
        cerr << "Number of nodes in the tree is lesser than query\n";
    }
}
