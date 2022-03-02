#include <iostream>
#include <stack>
using namespace std;
class tree
{
public:
    int value;
    tree *left = nullptr, *right = nullptr;
    void ins(tree *&k, int v);
    void dis(tree *k);
};
void tree::ins(tree *&k, int v)
{
    if (!k)
    {
        k = new tree{v, nullptr, nullptr};
        return;
    }
    if (k->value < v)
        ins(k->right, v);
    else if (k->value > v)
        ins(k->left, v);
}
void dis(tree *k)
{
    if (!k)
        return;
    dis(k->left);
    cout << k->value << ' ';
    dis(k->right);
}
void PostTrav(tree *k)
{
    if (!k)
        return;
    stack<tree *> s;
    s.push(k);
    while (!s.empty())
    {
        if (s.top()->left)
        {
            s.push(s.top()->left);
        }
        else if (s.top()->right)
        {
            s.push(s.top()->right);
        }
        else
        {
            cout << s.top()->value << ' ';
            tree *temp = s.top();
            s.pop();
            if (s.top()->left == temp)
            {
                s.top()->left = nullptr;
            }
            else if (s.top()->right == temp)
            {
                s.top()->right = nullptr;
            }
        }
    }
}
int main()
{
    tree *cherry = nullptr;
    int A[] = {4, 3, 0, -1, 2, 10, 9, 11};
    for (int i : A)
    {
        cherry->ins(cherry, i);
    }
    PostTrav(cherry);
}
