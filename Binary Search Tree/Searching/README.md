## Searching Complexity	
+ **Best case:**![O(1)](https://latex.codecogs.com/svg.latex?O%281%29) 
+ **Average case:**![log_2(n)](https://latex.codecogs.com/svg.latex?log_2%28n%29)
+ **Worst case:**![O(n)](https://latex.codecogs.com/svg.latex?O%28n%29)
+ **Besides,complexity varies as per the tree is constructed** 

## Types of Searches
+ **Whether a value exists in the tree or not**
+ **kth Maximum**
+ **kth Minimum**


## Kth Maximum & Kth Minimum (Use InOrder traversal)

**Following is the code to find kth-minimum** 

```cpp
void minimum(int &m, tree *l, int &r)
{
    if (!l)
        return;
    minimum(m, l->left, r);
    --m;
    if (m == 0)
    {
        r = l->value;
    }
    minimum(m, l->right, r);
}
```
**To find kth maximum,things to do with the above code:**  

**Point 1** 

```diff
+ maximum (m,l->right,r); //line to add after return
- minimum (m,l->left,r); //line to remove after above line is added
```

**Point 2**
```diff
+ maximum (m,l->left,r);//line to add after if statement for evaluation of m's value
- minimum (m,l->right,r);//line to remove after the above line is added
```
