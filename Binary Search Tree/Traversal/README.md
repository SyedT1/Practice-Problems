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
    ```diff
     - this node here has been scanned fully. He has nothing to hide like the brand All Clear says "Nothing to hide"
    ```
    */
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
