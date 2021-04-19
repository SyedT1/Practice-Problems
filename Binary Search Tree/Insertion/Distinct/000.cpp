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
void printData(tree *k)
{
    if (!k)
        return;
    printData(k->left);
    cout << k->value << ' ';
    printData(k->right);
}
int main()
{
    tree *l = nullptr;
    int ar[] = {-1, 2334, -44, 0, -123, 12};
    for (int i : ar)
    {
        insert(l, i);
    }
    printData(l);
}
