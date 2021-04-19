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

bool search(tree *k, int v)
{
    if (!k)
        return false;
    else if (k->value == v)
        return true;
    bool lookup = search(v > k->value ? k->right : k->left, v);
    return lookup;
}
int main()
{
    tree *l = nullptr;
    int ar[] = {1, 1, 2, 3, 3, 3, 3, -1, -3, -8, -10, -10, 0, 0, 0, -2, -7, -6, -5, -4, 10, 11, 11, 10, 10, 10, 10, 9, 19};
    for (int i : ar)
    {
        insert(l, i);
    }
    string state[] = {"Not found", "Found"};
    cout << state[search(l, -10)];
}
