#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int value;
    node *next = nullptr;
};
struct graph
{
    int numberofVertex = 0;
    node **arr;
    graph(int v)
    {
        numberofVertex = v;
        arr = new node *[numberofVertex];
        for (int i = 0; i < numberofVertex; i++)
            arr[i] = nullptr;
    }
};
void addEdge(graph *&g, int src, int des)
{
    g->arr[src] = new node{des, g->arr[src]};
}
void display(graph *g)
{
    for (int i = 0; i < g->numberofVertex; i++)
    {
        cout << "Vertex " << i << " is connected to : ";
        if (!g->arr[i])
        {
            cout << "Nullptr" << endl;
            continue;
        }
        for (node *print = g->arr[i]; print; print = print->next)
        {
            cout << print->value << ' ';
        }
        cout << endl;
    }
}
void bfs(graph *g, int start)
{
    bool *vis = new bool[g->numberofVertex];
    for (int i = 0; i < g->numberofVertex; i++)
        vis[i] = false;
    int brk = 1;
    queue<int> globe;
    globe.push(start);
    vis[start] = true;
    while (!globe.empty())
    {
        node *curr = g->arr[globe.front()];
        cout << globe.front() << ' ';
        globe.pop();
        brk--;
        while (curr)
        {
            if (!vis[curr->value])
            {
                globe.push(curr->value);
                vis[curr->value] = true;
            }
            curr = curr->next;
        }
        if (!brk)
        {
            brk = globe.size();
            cout << endl;
        }
    }
}
int main()
{
    graph *g = new graph(6);
    int ar[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {3, 4}, {4, 5}, {2, 5}};
    for (auto &i : ar)
    {
        addEdge(g, *i, *(i + 1));
    }
    display(g);
    cout << endl;
    bfs(g, 0);
}
