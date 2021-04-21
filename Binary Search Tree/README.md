**Either use struct**:
```cpp
struct tree{
   int value;
   tree *left = nullptr, *right = nullptr;
};
```

**or** :
```cpp
class tree{
   public:
     int value;
     tree *left = nullptr, *right = nullptr;
};
```
**for declaration**
