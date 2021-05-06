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
    if (start == end)
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
void dfs(Graph *g, int src, int des)
{
    bool *vis = new bool[g->num];
    for (int i = 0; i < g->num; i++)
        vis[i] = false;
    int *arr = new int[g->num], counter = 0;
    dfs(g, src, des, vis, arr, counter);
}
int main()
{
    Graph *cherry = new Graph(9);
    int edge[][2] = {{0, 7}, {0, 8}, {0, 1}, {1, 8}, {2, 8}, {2, 4}, {3, 2}, {5, 3}, {5, 4}, {5, 8}, {6, 5}, {7, 6}, {7, 5}, {8, 3}};
    for (auto &i : edge)
    {
        addEdge(cherry, *i, *(i + 1));
    }
    int src_to_des[][2] = {{0, 8}, {0, 4}};
    for (auto &i : src_to_des)
    {
        cout << "if src is " << *i << " and des is " << *(i + 1) << ", then the paths will be:" << endl;
        dfs(cherry, *i, *(i + 1));
        cout << endl;
    }
}
