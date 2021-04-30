# Practice-Problems

### Binary tree
```cpp
struct tree{
  int value;
  tree *left = nullptr,*right = nullptr;
};
```

### Graph
```cpp
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
};```
