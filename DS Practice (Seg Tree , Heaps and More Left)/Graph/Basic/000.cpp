#include <iostream>
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
int main()
{
    graph *g = new graph(5);
    int a[][2] = {{0, 1}, {0, 3}, {0, 2}, {1, 3}, {3, 4}, {4, 5}, {2, 5}};
    for (auto &i : a)
    {
        addEdge(g, *i, *(i + 1));
    }
    display(g);
}
