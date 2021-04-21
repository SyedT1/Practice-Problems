## Problems
1. **Deleting elements within a certain range**
2. **Deleting factors of k-elements** 
3. **Deleting BST keys outside a given range**

## Explanation to 1
```diff
- In order to delete Nodes from a tree we have to bear in mind about these 3 specific cases  
```
**Case 1**: Node to be deleted doesn't have any left and right node(7)  

Exempli gratia:
   
      7
    nl  nl
   
**Case 2**: Node to be deleted has a left or a right node (6)  


Exempli gratia:

       6   
     4  nl  
    nl nl   
 
**Case 3**: Node to be deleted has a left and a right node (7) 

Exempli gratia:

     
          10
       7     11 
     nl nl  nl nl

**Here is the problem** if the following was the scenario 

Exempli gratia:
         
            4
        2        100
      1  nl    55   nl
    nl nl    nl   56
                nl  57
                   nl 59
                 
 **We see that in order to delete node valued 4 we have to replace the value 4 with some value greater or lesser than this**. We have to select a node
 from the **node valued 4's** right which is **node valued 100**. Here we will traverse from 100 to left until a nullptr is discovered to the nodes left.
 We get **node valued 55** by doing that. But the problem is here. **If we were to remove node valued 55 we have to see if it has a subtree to it's right.**
