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
void SmofKSmallest(int &m, tree *l, int &r)
{
    if (!l)
        return;
    SmofKSmallest(m, l->left, r);
    --m;
    if (m>=0)
    {
        r += l->value;
    }
    SmofKSmallest(m, l->right, r);
}
int SmofKSmallest(tree *l, int n)
{
    int q = 0;
    SmofKSmallest(n, l, q);
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
    int a[] = {8,5,2,7,3,11};
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
        cout << "Result = " << SmofKSmallest(l, k) << '\n';
    }
    catch (const char *s)
    {
        cerr << s;
    }
}
