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
int getLeastDistance(Graph *g, int src, int dest)
{
   if (!g)
      throw "null";
   bool *vis = new bool[g->num];
   for (int i = 0; i < g->num; i++)
      vis[i] = false;
   queue<int> collect;
   collect.push(src);
   vis[src] = true;
   int min_dis = 0, hold = 1;
   while (!collect.empty())
   {
      node *curr = g->linked[collect.front()];
      collect.pop();
      hold--;
      while (curr)
      {
         if (!vis[curr->value])
         {
            if (curr->value == dest)
            {
               return min_dis + 1;
            }
            collect.push(curr->value);
            vis[curr->value] = true;
         }
         curr = curr->next;
      }
      if (!hold)
      {
         hold = collect.size();
         min_dis++;
      }
   }
   throw "destination not found or unreachable";
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
   try
   {
      cout << getLeastDistance(cherry, 0, 4) << endl;
   }
   catch (const char *s)
   {
      cout << s << endl;
   }
   return 0;
}
