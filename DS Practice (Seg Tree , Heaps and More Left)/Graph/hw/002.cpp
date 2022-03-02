#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int value;
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
void printLevel(Graph *g)

{
    if (!g)
        return;
    bool *vis = new bool[g->num];
    for (int i = 0; i < g->num; i++)
        vis[i] = false;
    int size = 1;
    queue<int> dataset;
    dataset.push(0);
    vis[0] = true;
    while (!dataset.empty())
    {
        node *temp = g->linked[dataset.front()];
        cout << dataset.front() << ' ';
        dataset.pop();
        size--;
        while (temp)
        {
            if (!vis[temp->value])
            {
                dataset.push(temp->value);
                vis[temp->value] = true;
            }
            temp = temp->next;
        }
        if (!size)
        {
            size = dataset.size();
            cout << endl;
        }
    }
}
void addEdge(Graph *&g, int src, int des)
{
    g->linked[src] = new node{des, g->linked[src]};
}
int main()
{
    Graph *cherry = new Graph(9);
    int edge[][2] = {{0, 7}, {0, 8}, {0, 1}, {1, 8}, {2, 8}, {2, 4}, {3, 2}, {5, 3}, {5, 4}, {5, 8}, {6, 5}, {7, 6}, {7, 5}, {8, 3}};
    for (auto &i : edge)
    {
        addEdge(cherry, *i, *(i + 1));
    }
    printLevel(cherry);
}
