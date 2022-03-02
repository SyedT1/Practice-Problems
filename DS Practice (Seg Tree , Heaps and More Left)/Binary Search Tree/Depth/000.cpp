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
    else if (k->value == v)
    {
        if (!k->right)
        {
            insert(k->right, v);
        }
        else
        {
            tree *subright = k->right, *subleft = k->left;
            tree *temp = new tree{v, subleft, subright};
            k->right = temp;
            return;
        }
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
int depth(tree *k, int v)
{
    if (!k)
        throw "doesn't exist";
    else if (k->value == v)
        return 0;
    return 1 + depth(v > k->value ? k->right : k->left, v);
}
int main()
{
    tree *l = nullptr;
    int ar[] = {1,2,-1,-3,-4,5,10};
    for (int i : ar)
    {
        insert(l, i);
    }
    try
    {
        cout << "Depth of value in the tree = " << depth(l,1) << '\n';
    }
    catch (const char *s)
    {
        cerr << " Null\n";
    }
    return 0;
}
