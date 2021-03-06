## PreOrder Traversal
+ Evaluates Root Node before moving to children
+ Top to bottom
+ Prints first: **Root** Node 
```cpp
void preOrder(tree *l)
{
    if (!l)
        return;
    cout << l->value << ' ';
    preOrder(l->left);
    preOrder(l->right);
}
```

## PostOrder Traversal
+ Evaluates Root Node after checking its left and right Nodes(fully)
+ Bottom to Top
+ Prints first: **Leaf** Node 
```cpp
void postOrder(tree *l)
{
    if (!l)
        return;
    postOrder(l->left);
    postOrder(l->right);
    cout<<l->value<<' ';
   //this node has been scanned fully(it's left and right nodes have been evalulated before it's evaluated)
}
```
## InOrder Traversal
+ Evaluates Left Subtree at first
+ After Left Subtree is fully evaluated -> Root Node gets Evaluated -> right subtree to Root Node gets Evaluated
+ Prints first: **Left Subtree**
```cpp
void inOrder(tree *l)
{
    if (!l)
        return;
    inOrder(l->left);
    cout << l->value << ' '; // once the left subtree is fully evaluated
    inOrder(l->right);
}
```
## LevelOrder Traversal
+ Evaluates every root node and pushes its left and right child into the queue
+ Once every node is checked and the queue is empty,it stops
```cpp
void LvlO(tree *k)
{
    if (!k)
        throw "Null tree";
    int Qs = 1;
    queue<tree *> Q;
    Q.push(k);
    while (!Q.empty())
    {
        tree *curr = Q.front();
        cout<<curr->value<<' ';
        Q.pop();
        Qs--;
        if (curr->left)
            Q.push(curr->left);
        if (curr->right)
            Q.push(curr->right);
        if (!Qs)
        {
            Qs = Q.size();
            cout << endl;
        }
    }
}
 ```
