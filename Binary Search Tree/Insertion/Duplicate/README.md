## Keys to keep in mind once a duplicate is traced
+ the placement of a duplicate node is an arbitrary choice as the node can be placed left or right to the node having similar value/data
+ Suppose the duplicate is to be placed to the right, let check whether the node's right is nullptr or not
+ if its not nullptr create a node that will join the node found duplicate and the right of that node

**What did I mean by the 3rd point?**  
+ Create Node temp
+ temp connects to duplicate nodes left and right nodes
+ temp will be assigned to duplicate node's right
