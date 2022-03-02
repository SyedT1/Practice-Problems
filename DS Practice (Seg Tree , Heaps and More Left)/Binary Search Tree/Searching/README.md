## Searching Complexity	
+ <img src="https://latex.codecogs.com/svg.latex?Best\hspace{1.5mm}case&space;:&space;O(1)" title="Best\hspace{1.5mm}case : O(1)" />
+ <img src="https://latex.codecogs.com/svg.latex?Average\hspace{1.5mm}case&space;:&space;log_2(n)" title="Average\hspace{1.5mm}case : log_2(n)" />
+ <img src="https://latex.codecogs.com/svg.latex?Worst\hspace{1.5mm}case&space;:&space;O(n)" title="Worst\hspace{1.5mm}case : O(n)" />
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
