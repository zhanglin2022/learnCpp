## Exercise 6.1

**Parameters**: Local variable declared inside the function parameter list.
they are initialized by the **arguments** provided in the each function call.

**Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

## Exercise 6.2
```cpp
(a) string f() {  // return should be string, not int
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }  // function needs return type
(c) int calc(int v1, int v2) { /* ... */ }  // parameter list cannot use same name twice
(d) double square (double x) { return x * x; }  // function body needs braces
```

## [Exercise 6.3](ex6_03.cpp)
## [Exercise 6.4](ex6_04.cpp)
## [Exercise 6.5](ex6_05.cpp)

## Exercise 6.6

**parameter**: **Local variables** declared inside the **function parameter list**;

**local variable**: Variables defined inside a **block**;

**local static variable**: **local static variable（object）** is initialized before the first time execution passes through the object’s definition.**Local statics** are not destroyed when a function ends; they are **destroyed when the program terminates.**

```cpp
// example
size_t count_add(int n)       // n is a parameter.
{
    static size_t ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i is a local variable.
      cout << count_add(i) << endl;

    return 0;
}
```

## [Exercise 6.7](ex6_07.cpp)
## [Exercise 6.8](Chapter6.h)
## Exercise 6.9 [fact.cc](fact.cc) | [factMain.cc](factMain.cc)
## [Exercise 6.10](ex6_10.cpp)
## [Exercise 6.11](ex6_11.cpp)
## [Exercise 6.12](ex6_12.cpp)

`reference` is easier because its form is simpler

## Exercise 6.13

`void f(T)` pass the argument by value. **nothing the function does to the parameter can affect the argument**.
`void f(T&)` pass a reference, will be **bound to** whatever T object we pass.

## Exercise 6.14

a parameter should be a reference type:
```cpp
void reset(int &i)
{
        i = 0;
}
```

a parameter should not be a reference:
```cpp
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```

## Exercise 6.15

>why is `s` a reference to const but `occurs` is a plain reference?

Because `s` should not be changed by this function, but `occurs` result must be calculated by the function.

>Why are these parameters references, but the char parameter `c` is not?

Because `c` may be a temp varable, such as `find_char(s, 'a', occurs)`

>What would happen if we made `s` a plain reference? What if we made `occurs` a reference to const?

`s` could be changed in the function, and `occurs` would not be changed. so `occurs = 0;` is an error.

## Exercise 6.16
```cpp
bool is_empty(const string& s) { return s.empty(); }
```

Since this function doesn't change the argument, "const" shoud be added
before string&s, otherwise this function is misleading and can't be used
with const string or in a const function.

## [Exercise 6.17](ex6_17.cpp)

They do not have the same type. Because the first function dosen't change the parameter string and the sencond function oppsite.

## Exercise 6.18
>Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does. 
(a) A function named compare that returns a bool and has two parameters that are references to a class named matrix. 
(b) A function named change_val that returns a vector<int> iterator and takes two parameters: One is an int and the other is an iterator for a vector<int>.

(a)
```cpp
bool compare(const matrix &m1, cosnt matrix &m2);
```
(b)
```cpp
vector<int>::iterator change_val(int num, vector<int>::iterator &it);
```

## Exercise 6.19
>Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why. 
```cpp
double calc(double); 
int count(const string &, char); 
int sum(vector<int>::iterator, vector<int>::iterator, int); 
vector<int> vec(10); 
(a) calc(23.4, 55.1);      (b) count("abcda", ’a’); 
(c) calc(66);              (d) sum(vec.begin(), vec.end(), 3.8);
```

(a) illegal, only one parameter.
(b) legal.
(c) legal.
(d) legal.

## Exercise 6.20
>When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?

If we can use `const`, just use it. If we make a parameter a plain reference when it could be a reference to `const`,
the reference value maybe changed.

## [Exercise 6.21](ex6_21.cpp)
## [Exercise 6.22](ex6_22.cpp)
## [Exercise 6.23](ex6_23.cpp)

## Exercise 6.24
>Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them. 
```cpp
void print(const int ia[10]) 
{ 
    for (size_t i = 0; i != 10; ++i) 
        cout << ia[i] << endl;
}
```

we can not copy an array so we can not pass an array by value. When we pass an array to a function, we actually pass a pointer to the array's first element.  
  
In this question, `const int a[10]` is same as `const int *`, and the size of array is irrelevant. If we want to pass an array of size 10, we should use reference like this:  
```cpp  
void print(const int (&ia)[10]) { /*...*/ }  
```

## [Exercise 6.25 && Exercise 6.26](ex6_25_26.cpp)
## [Exercise 6.27](ex6_27.cpp)

## Exercise 6.28

The type of `elem` in the `for` loop is `const std::string&`.

## Exercise 6.29
>When you use an initializer_list in a range for would you ever use a reference as the loop control variable? If so, why? If not, why not?


Depends on the type of elements of `initializer_list`. When the type is [PODType](http://en.cppreference.com/w/cpp/concept/PODType), reference is unnecessary. Because `POD` is **cheap to copy**(such as `int`). Otherwise, Using reference(`const`) is the better choice.

## [Exercise 6.30](ex6_30.cpp)
>Compile the version of str_subrange as presented on page 223 to see what your compiler does with the indicated errors.

g++:
```
error: return-statement with no value, in function returning ‘bool’ // error #1
```

## Exercise 6.31
>When is it valid to return a reference? A reference to const?

when you can find the preexisting object that the reference refered.

## Exercise 6.32
>Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it. 
```cpp
int &get(int *arry, int index) { return arry[index]; } 
int main() { 
    int ia[10]; 
    for (int i = 0; i != 10; ++i) 
        get(ia, i) = i; 
}
```

legal, it gave the values (0 ~ 9) to array `ia`.

## [Exercise 6.33](ex6_33.cpp)
## Exercise 6.34
>What would happen if the stopping condition in factorial were 
```cpp
if (val != 0)
```

When the recursion termination condition becomes `var != 0`, two situations can happen :
* case 1 : If the argument is positive, recursion stops at 0.(Note : There is one extra multiplication step though as the combined expression for factorial(5) reads 5 * 4 * 3 * 2 * 1 * 1. In terms of programming languages learning, such subtle difference probably looks quite trivial. In algorithms analysis and proof, however, this extra step may be super important.)  
* case 2 : if the argument is negative, recursion would never stop. As a result, a stack overflow would occur.

## Exercise 6.35
>In the call to factorial, why did we pass val - 1 rather than val--?

the recursive function will always use `val` as the parameter when we pass val--. **a recursion loop** would happen.

## Exercise 6.36
>Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

```cpp
string (&func())[10]
```

## Exercise 6.37
>Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?

```cpp
// type alias
using ArrT = string[10];
ArrT& func1();

// trailing return
auto func2() -> string(&)[10];

// decltype
string arrS[10];
decltype(arrS)& func3();
```

I pefer the first one. because it is more simpler to me.

## Exercise 6.38
>Revise the arrPtr function on to return a reference to the array.

```cpp
decltype(arrStr)& arrPtr(int i)
{
    return (i % 2) ? odd : even;
}
```

## Exercise 6.39
>Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal. 
```cpp
(a) int calc(int, int); 
    int calc(const int, const int); 
(b) int get(); 
    double get(); 
(c) int *reset(int *); 
    double *reset(double *);
```

(a) legal, repeated declarations(without definition) are legal in C++

(b) illegal, only the return type is different

(c) legal, the parameter type is different and return type is changed

## Exercise 6.40
>Which, if either, of the following declarations are errors? Why? 
```cpp
(a) int ff(int a, int b = 0, int c = 0); 
(b) char *init(int ht = 24, int wd, char bckgrnd);
```
(a) no error

(b) Missing default argument on parameter 'wd', 'bckgrnd'.

## Exercise 6.41
>Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer’s intent? Why? 
```cpp
char *init(int ht, int wd = 80, char bckgrnd = ’ ’); 
(a) init(); (b) init(24,10); (c) init(14, ’*’);
```

(a) illegal. No matching function for call to 'init'.

(b) legal, and match.

(c) legal, but not match. `wd` whould be setting to '*'.

## [Exercise 6.42](ex6_42.cpp)
## Exercise 6.43
>Which one of the following declarations and definitions would you put in a header? In a source file? Explain why. 
```cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...} 
(b) void putValues(int *arr, int size);
```

(a): in a header, because it's a inline function.  

(b): in a header, because it's a declaration.

## [Exercise 6.44](ex6_44.cpp)
## Exercise 6.45
>Review the programs you’ve written for the earlier exercises and decide whether they should be defined as inline. If so, do so. If not, explain why they should not be inline.

For example, the function `arrPtr` in Exercise 6.38 and `make_plural` in Exercise 6.42 should be defined as `inline`. But the function `func` in Exercise 6.4 shouldn't. It is not that small and it's only being called once. Hence, it will probably not expand as inline.

## Exercise 6.46
> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

No.

Because `std::string::size()` is not a `constexpr` function and `s1.size() == s2.size()` is not a constant expression.

## [Exercise 6.47](ex6_47.cpp)

```shell  
g++ -D NDEBUG ../ex6_47.cpp -o ex6_47  
```
`-D NDEBUG`

## Exercise 6.48
>Explain what this loop does and whether it is a good use of assert: 
```cpp
string s; 
while (cin >> s && s != sought) { } // empty body 
assert(cin);
```

the loop let user intput a word until the word is `sought`.  
 
No. It isn't a good use of assert. because if user begin to input a word, the `cin` would be always have content. so the `assert` would be always `true`. It is meaningless. using `assert(s == sought)` is better.

## Exercise 6.49
>What is a candidate function? What is a viable function?

candidate function:
>Set of functions that are considered when resolving a function call. (all the functions
with the name used in the call for which a declaration is in scope at the time of the call.)

viable function:
>Subset of the candidate functions that could match a given call.
>It have the same number of parameters as arguments to the call,
and each argument type can be converted to the corresponding parameter type.

## Exercise 6.50
>Given the declarations for f from page 242, list the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous. 
```cpp
(a) f(2.56, 42) (b) f(42) (c) f(42, 0) (d) f(2.56, 3.14)
```

(a) illegal. 2.56 match the `double`, but 42 match the `int`.

(b) match `void f(int)`.

(c) match `void f(int, int)`.

(d) match `void f(double, double = 3.14)`.

## [Exercise 6.51](ex6_51.cpp)
## Exercise 6.52
>Given the following declarations, 
```cpp
void manip(int, int); double dobj;
```
 what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls? 
 ```cpp
 (a) manip(’a’, ’z’); (b) manip(55.4, dobj);
```

(a) Match through a promotion

(b) Arithmetic type conversion

## Exercise 6.53
>Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.
```cpp
(a) int calc(int&, int&); 
    int calc(const int&, const int&); 
(b) int calc(char*, char*); 
    int calc(const char*, const char*); 
(c) int calc(char*, char*); 
    int calc(char* const, char* const);
```

(a)
```cpp
int calc(int&, int&); // calls lookup(int&)
int calc(const int&, const int&); // calls lookup(const int&)
```
(b)
```cpp
int calc(char*, char*); // calls lookup(char*)
int calc(const char*, const char*); // calls lookup(const char *)
```
(c)

illegal. both calls lookup(char*)

## Exercise 6.54
>Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.

```cpp
int func(int a, int b);

using pFunc1 = decltype(func) *;
typedef decltype(func) *pFunc2;
using pFunc3 = int (*)(int a, int b);
using pFunc4 = int(int a, int b);
typedef int(*pFunc5)(int a, int b);
using pFunc6 = decltype(func);

std::vector<pFunc1> vec1;
std::vector<pFunc2> vec2;
std::vector<pFunc3> vec3;
std::vector<pFunc4*> vec4;
std::vector<pFunc5> vec5;
std::vector<pFunc6*> vec6;
```

## [Exercise 6.55 && Exercise 6.56](ex6_55_56.cpp)
