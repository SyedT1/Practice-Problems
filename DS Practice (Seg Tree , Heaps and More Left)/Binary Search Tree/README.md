### Either use _struct_:
```cpp
struct tree{
   int value;
   tree *left = nullptr, *right = nullptr;
};
```

### Or use _class_ :

```cpp
class tree{
   public:
     int value;
     tree *left = nullptr, *right = nullptr;
};
```
**for declaration**
