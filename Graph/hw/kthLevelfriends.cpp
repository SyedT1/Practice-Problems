#include <iostream>
#include <queue>
using namespace std;
struct Set
{
    string data;
    Set *left = nullptr, *right = nullptr;
};
struct node
{
    string value;
    node *next = nullptr;
};

struct Graph
{
    int num = 0;
    node **linked = nullptr;
    Graph(int v)
    {
        num = v;
        linked = new node *[num];
        for (int i = 0; i < num; i++)
            linked[i] = nullptr;
    }
};
queue<string> kthLevelFriends(int K, Graph *g, string src)
{
    if (!g)
        throw "null";
    bool *vis = new bool[g->num];
    for (int i = 0; i < g->num; i++)
        vis[i] = false;
    queue<string> collect;
    collect.push(src);
    if (!K)
        return collect;
    vis[src[0] - 'A'] = true;
    int hold = 1;
    while (!collect.empty())
    {
        node *curr = g->linked[collect.front()[0] - 'A'];
        collect.pop();
        hold--;
        while (curr)
        {
            if (!vis[curr->value[0] - 'A'])
            {
                collect.push(curr->value);
                vis[curr->value[0] - 'A'] = true;
            }
            curr = curr->next;
        }
        if (!hold)
        {
            hold = collect.size();
            K--;
            if (!K)
            {
                return collect;
            }
        }
    }
    return queue<string>{};
}
void sortorder(Set *&friendlist, string s)
{
    if (!friendlist)
    {
        friendlist = new Set{s, nullptr, nullptr};
        return;
    }
    else if (s > friendlist->data)
        sortorder(friendlist->right, s);
    else if (s < friendlist->data)
        sortorder(friendlist->left, s);
}
void ins_queue(Set *friendlist, queue<string> &k)
{
    if (!friendlist)
        return;
    ins_queue(friendlist->left, k);
    k.push(friendlist->data);
    ins_queue(friendlist->right, k);
}
void sortorder(queue<string> &k)
{
    Set *friendlist = nullptr;
    while (!k.empty())
    {
        sortorder(friendlist, k.front());
        k.pop();
    }
    ins_queue(friendlist, k);
}
ostream &operator<<(ostream &out, queue<string> k)
{
    sortorder(k);
    out << "{";
    while (!k.empty())
    {
        out << k.front();
        k.pop();
        if (!k.size())
            continue;
        out << ',';
    }
    out << '}';
    return out;
}
void kthLevelFriends(Graph *g, string src, int K)
{
    queue<string> fallout = kthLevelFriends(K, g, src);
    cout << fallout << endl;
}
void addEdge(Graph *&g, string src, string des)
{
    g->linked[src[0] - 'A'] = new node{des, g->linked[src[0] - 'A']};
}
string fm(int x)
{
    if (!x)
        return "no friends ";
    else if (x == 1)
    {
        return "friends ";
    }
    return "friends-of-" + fm(x - 1);
}
int main()
{
    Graph *cherry = new Graph(9);
    string edge[][2] = {{"A", "B"}, {"A", "D"}, {"B", "E"}, {"C", "B"}, {"D", "G"}, {"E", "D"}, {"E", "F"}, {"F", "C"}, {"H", "G"}, {"H", "E"}, {"I", "F"}, {"I", "H"}};
    for (auto &i : edge)
    {
        addEdge(cherry, *i, *(i + 1));
    }
    try
    {
        for (string s : {"A", "B", "C", "D", "E", "F", "G", "H", "I"})
        {
            for (int j = 0; j < 4; j++)
            {
                cout << fm(j) + "of " + s + " : ";
                kthLevelFriends(cherry, s, j);
            }
        }
    }
    catch (const char *s)
    {
        cout << s << endl;
    }
    return 0;
}
