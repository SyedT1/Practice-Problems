#include <iostream>
#include <queue>
using namespace std;
class tree
{
public:
    int value;
    tree *left = nullptr, *right = nullptr;
};
void ins(tree *&k, int v)
{
    if (!k)
    {
        k = new tree{v, nullptr, nullptr};
        return;
    }
    if (k->value > v)
        ins(k->left, v);
    else if (k->value < v)
        ins(k->right, v);
}
void inO(tree *k)
{
    if (!k)
        return;
    inO(k->left);
    cout << k->value << ' ';
    inO(k->right);
}
void LvlO(tree *k)
{
    if (!k)
        throw "Null tree";
    int Qs = 1;
    queue<tree *> Q;
    Q.push(k);
    while (!Q.empty())
    {
        tree *curr = Q.front();
        cout<<curr->value<<' ';
        Q.pop();
        Qs--;
        if (curr->left)
            Q.push(curr->left);
        if (curr->right)
            Q.push(curr->right);
        if (!Qs)
        {
            Qs = Q.size();
            cout << endl;
        }
    }
}
int main()
{
    tree *cherry = nullptr;
    int A[] = {1, 2, 3, 4, 5, -1111, 4555};
    for (int i : A)
    {
        ins(cherry, i);
    }
    inO(cherry);
    cout << '\n';
    LvlO(cherry);
}
