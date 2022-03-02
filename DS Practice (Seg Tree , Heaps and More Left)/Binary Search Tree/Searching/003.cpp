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
void minimum(int &m, tree *l, int &r)
{
    if (!l)
        return;
    minimum(m, l->left, r);
    --m;
    if (m == 0)
    {
        r = l->value;
    }
    minimum(m, l->right, r);
}
int minimum(tree *l, int n)
{
    int q = 0;
    minimum(n, l, q);
    if (!(n < 1))
    {
        throw "Number of nodes in the tree is lesser than query\n";
    }
    return q;
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
        cout <<"Result = " << minimum(l, k) << '\n';
    }
    catch (const char *s)
    {
        cerr << s ; 
    }
}
