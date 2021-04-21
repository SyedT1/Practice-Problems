**Either use struct**:
```cpp
struct tree{
   int value;
   tree *left = nullptr, *right = nullptr;
};
```

**OR** :
```cpp
class tree{
   public:
     int value;
     tree *left = nullptr, *right = nullptr;
};
```
