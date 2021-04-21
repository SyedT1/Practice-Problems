## PreOrder Traversal
+ Evaluates Root Node before moving to children
+ Top to bottom
+ **Prints first**:root Node 
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
+ Prints first:leaf Node 

## InOrder Traversal
+ Evaluates Left Subtree at first
+ After Left Subtree is fully evaluated -> Root Node gets Evaluated -> right subtree to Root Node gets Evaluated
