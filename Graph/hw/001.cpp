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
bool isReachable(Graph *g, int source, int destination)
{
    if (!g)
        return false;
    bool *vis = new bool[g->num];
    for (int i = 0; i < g->num; i++)
        vis[i] = false;
    int size = 1;
    queue<int> dataset;
    dataset.push(source);
    vis[source] = true;
    while (!dataset.empty())
    {
        node *temp = g->linked[dataset.front()];
        dataset.pop();
        size--;
        while (temp)
        {
            if (!vis[temp->value])
            {
                if (temp->value == destination)
                    return true;
                dataset.push(temp->value);
                vis[temp->value] = true;
            }
            temp = temp->next;
        }
        if (!size)
        {
            size = dataset.size();
        }
    }
    return false;
}
void addEdge(Graph *&g, int src, int des)
{
    g->linked[src] = new node{des, g->linked[src]};
}
int main()
{
    Graph *cherry = new Graph(9);
    int edge[][2] = {{0, 1}, {0, 8}, {0, 7}, {1, 8}, {2, 8}, {2, 4}, {3, 2}, {5, 3}, {5, 8}, {6, 5}, {7, 5}, {7, 6}, {8, 3}};
    for (auto &i : edge)
    {
        addEdge(cherry, *i, *(i + 1));
    }
    string outcome[] = {" is not reachable from ", " is accessible from "};
    int a[][2] = {{5, 4}, {4, 3}, {3, 4}};
    for (auto &i : a)
    {
        cout << "node " << *(i+1) << outcome[isReachable(cherry, *i, *(i + 1))] << *i << endl;
    }
}
