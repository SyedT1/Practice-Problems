#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next = nullptr;
};

struct Graph
{
    int num = 0;
    node **arr = nullptr;
    Graph(int v)
    {
        num = v;
        arr = new node *[num];
        for (int i = 0; i < num; i++)
            arr[i] = nullptr;
    }
};
void addEdge(Graph *&g, int src, int des)
{
    g->arr[src] = new node{des, g->arr[src]};
}
void print_list(Graph *g)
{
    for (int i = 0; i < g->num; i++)
    {
        cout << i << ":";
        if (!g->arr[i])
        {
            cout << "nullptr";
        }
        else
        {
            for (node *j = g->arr[i]; j; j = j->next)
            {
                cout << j->data << ' ';
            }
        }
        cout << endl;
    }
}
void printArray(int *arr, int c)
{
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
void dfs(Graph *g, int start, int end, bool *vis, int *arr, int counter)
{
    vis[start] = true;
    arr[counter] = start;
    counter++;
    if (!(g->arr[start]))
    {
        printArray(arr, counter);
    }
    node *n = g->arr[start];
    while (n)
    {
        if (!vis[n->data])
        {
            dfs(g, n->data, end, vis, arr, counter);
        }
        n = n->next;
    }
    vis[start] = false;
}
void dfs(Graph *g)
{
    bool *vis = new bool[g->num];
    for (int i = 0; i < g->num; i++)
        vis[i] = false;
    int *arr = new int[g->num], counter = 0;
    dfs(g, 0, g->num - 1, vis, arr, counter);
}
int main()
{
    Graph *g = new Graph(10);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 6);
    addEdge(g, 2, 3);
    addEdge(g, 3, 6);
    addEdge(g, 3, 5);
    addEdge(g, 5, 4);
    print_list(g);
    dfs(g);
}
