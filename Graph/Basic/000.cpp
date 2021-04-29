#include <iostream>
using namespace std;
struct node
{
    int value;
    node *next = nullptr;
};
struct graph
{
    int vnum = 0;
    node **adjList;
    graph(int v)
    {
        vnum = v;
        adjList = new node *[vnum];
        for (int i = 0; i < vnum; i++)
            adjList[i] = nullptr;
    }
};
void ins(graph *&k, int src, int des)
{
    k->adjList[src] = new node{des, k->adjList[src]};
}
int main()
{
    graph *tree = new graph(4);
    ins(tree, 0, 1);
    ins(tree, 0, 2);
    ins(tree, 0, 3);
    ins(tree, 1, 2);
    ins(tree, 2, 3);
    ins(tree, 3, 1);
    for (int i = 0; i < 4; i++)
    {
        node *t = tree->adjList[i];
        cout << i << " is connected to  = ";
        for (node *i = t; i; i = i->next)
            cout << i->value << ' ';
        cout << endl;
    }
}
