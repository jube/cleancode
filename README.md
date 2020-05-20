# cleancode

A tool to remove good answers from code and replace them with stubs.

## Example

```cpp
int factorial(int n) {
  // <<<<
  if (n <= 1) {
    return 1;
  }

  return n * factorial(n - 1);
  #if 0 // ====
  return 0
  #endif // >>>>
}
```

After `cleancode`:

```cpp
int factorial(int n) {
  return 0
}
```
