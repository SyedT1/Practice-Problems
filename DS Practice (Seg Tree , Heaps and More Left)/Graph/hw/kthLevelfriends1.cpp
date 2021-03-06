#include <iostream>
#include <queue>
using namespace std;
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
struct Set
{
   char c;
   Set *left = nullptr, *right = nullptr;
};
void friends(Set *&k, char a)
{
   if (!k)
   {
      k = new Set{a, nullptr, nullptr};
      return;
   }
   else if (k->c > a)
      friends(k->left, a);
   else if (k->c < a)
      friends(k->right, a);
}
void display(Set *k)
{
   if (!k)
   {
      return;
   }
   display(k->left);
   cout << k->c << ' ';
   display(k->right);
}
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
         if (K == 1)
         {
            collect.push(curr->value);
         }
         else if (!vis[curr->value[0] - 'A'])
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
   return {};
}
ostream &operator<<(ostream &out, queue<string> k)
{
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
   if (K == 0)
   {
      cout << src;
      return;
   }
   queue<string> fallout = kthLevelFriends(K - 1, g, src);
   Set *friendlist = nullptr;
   while (!fallout.empty())
   {
      node *curr = g->linked[fallout.front()[0] - 'A'];
      while (curr)
      {
         if (curr->value[0] != src[0])
            friends(friendlist, curr->value[0]);
         curr = curr->next;
      }
      fallout.pop();
   }
   if (!friendlist)
   {
      throw "no friends";
   }
   display(friendlist);
}
void addEdge(Graph *&g, string src, string des)
{
   g->linked[src[0] - 'A'] = new node{des, g->linked[src[0] - 'A']};
}
string fm(int x)
{
   if (x == 1)
   {
      return "friends of ";
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
   string findfriends[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
   for (string i : findfriends)
   {
      for (int j = 0; j < 5; j++)
      {
         cout << (!j ? "for " + i + " if K = 0: " : fm(j) + i + ": ");
         try
         {
            kthLevelFriends(cherry, i, j);
            cout << endl;
         }
         catch (const char *s)
         {
            cout << s << endl;
         }
      }
      cout << endl;
   }
   return 0;
}
