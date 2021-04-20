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
void deleteNode(tree *&l, bool right)
{
    if (right)
    {
        //deals with l->right->data
        tree *subright = l->right;
        if (subright->left != nullptr && subright->right != nullptr)
        {
            while (subright->left->left != nullptr)
            {
                subright = subright->left;
            }
            tree *fan = subright->left;
            l->right->value = subright->left->value;
            delete fan;
            subright->left = nullptr;
        }
        else if (subright->left == nullptr)
        {
            tree *fan = l->right;
            l->right = subright->right;
            delete fan;
        }
        else
        {
            tree *fan = l->right;
            l->right = subright->left;
            delete fan;
        }
    }
    else
    {
        //deals with l->left->data
        tree *subleft = l->left;
        if (subleft->left != nullptr && subleft->right != nullptr)
        {
            while (subleft->left->left != nullptr)
            {
                subleft = subleft->left;
            }
            tree *fan = subleft->left;
            l->left->value = subleft->left->value;
            delete fan;
            subleft->left = nullptr;
        }
        else if (subleft->left == nullptr)
        {
            tree *fan = l->left;
            l->left = subleft->right;
            delete fan;
        }
        else
        {
            tree *fan = l->left;
            l->left = subleft->left;
            delete fan;
        }
    }
}
void deleteNode(tree *&l)
{
    if (!l)
        return;
    deleteNode(l->left);
    deleteNode(l->right);
    if (l->left != nullptr)
    {
        if (l->left->value % 2)
        {
            deleteNode(l, false);
        }
        else if (l->value % 2)
        {
            l = l->left;
        }
    }
    else if (l->right != nullptr)
    {
        if (l->right->value % 2)
        {
            deleteNode(l, true);
        }
        else if (l->value % 2)
        {
            l = l->right;
        }
    }
    else if (l->left == nullptr && l->right == nullptr)
    {
        if (l->value % 2)
        {
            tree *temp = l;
            delete temp;
            l = nullptr;
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
    deleteNode(l);
    cout << '\n';
    inOrder(l);
}
