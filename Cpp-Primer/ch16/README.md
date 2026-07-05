## Exercise 16.1
>Define instantiation.

Instantiation is the process of creating a new “instance” of the template using the actual template argument(s) in place of the corresponding template parameter(s).

## [Exercise 16.2](ex16.2.3/main.cpp)
>Write and test your own versions of the compare functions.

## [Exercise 16.3](ex16.2.3/main.cpp)
>Call your compare function on two Sales_data objects to see how your compiler handles errors during instantiation.

## [Exercise 16.4](ex16.4/main.cpp)
>Write a template that acts like the library find algorithm. The function will need two template type parameters, one to represent the function’s iterator parameters and the other for the type of the value. Use your function to find a given value in a vector<int> and in a list<string>.

## [Exercise 16.5](ex16.5/main.cpp)
>Write a template version of the print function from § 6.2.4 (p. 217) that takes a reference to an array and can handle arrays of any size and any element type.

## [Exercise 16.6](ex16.6/main.cpp)
>How do you think the library begin and end functions that take an array argument work? Define your own versions of these functions.

## [Exercise 16.7](ex16.7.8/main.cpp)
>Write a constexpr template that returns the size of a given array.

## Exercise 16.8
>In the “Key Concept” box on page 108, we noted that as a matter of habit C++ programmers prefer using != to using <. Explain the rationale for this habit.

C++ programmers prefer `!=` because it works with all iterator types, while `<` requires random-access iterators.

## Exercise 16.9
>What is a function template? What is a class template?

A function template is a formula from which we can generate type-specific versions of that function.

A class template is a blueprint for generating classes. Class templates differ from function templates in that the compiler  cannot deduce the template parameter type(s) for a class template. Instead, as we’ve seen many times, to use a class template we must supply additional information inside angle brackets following the template’s name (§ 3.3, p. 97).

## Exercise 16.10
>What happens when a class template is instantiated?

The compiler uses these template arguments to instantiate a specific class from the template.

## Exercise 16.11
>The following definition of List is incorrect. How would you fix it?
```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
private:
    ListItem *front, *end;
};
```

Fixed:
```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List
{
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem<elemType> *ptr, elemType value);
    //                  ^^^^^^^^^^  -- template name is not a type, template arguments must be provided

private:
    ListItem<elemType> *front, *end;
    //       ^^^^^^^^ -- template name is not a type, template arguments must be provided
};
```

## Exercise 16.12
>Write your own version of the Blob and BlobPtr templates. including the various const members that were not shown in the text.

[Blob](ex16.12.13/blob.h) | [BlobPtr](ex16.12.13/blobptr.h)

## Exercise 16.13
>Explain which kind of friendship you chose for the equality and relational operators for BlobPtr.

As shown in the class body [BlobPtr](ex16.12.13/blobptr.h).

## [Exercise 16.14](ex16.14.15/main.cpp)
>Write a Screen class template that uses nontype parameters to define the height and width of the Screen.

## Exercise 16.15
>Implement input and output operators for your Screen template. 
Which, if any, friends are necessary in class Screen to make the input and output operators work? 
Explain why each friend declaration, if any, was needed.

According to chapter 14.2.1, `operator<<` and `operator>>` should be a friend of this class.

## [Exercise 16.16](ex16.16/main.cpp)
>Rewrite the StrVec class (§ 13.5, p. 526) as a template named Vec.

## Exercise 16.17
>What, if any, are the differences between a type parameter that is declared as a typename and one that is declared as a class? When must typename be used?

There is no difference. typename and class are interchangeable in the declaration of a type template parameter.

When we want to inform the compiler that a name represents a type, we must use the keyword typename, not class

## Exercise 16.18
>Explain each of the following function template declarations and identify whether any are illegal. Correct each error that you find.
```
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int*);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a);
```

```cpp
template <typename T, typename U, typename V> void f1(T, U, V);
//                   ^^^^^^^^ added to fix the error

template <typename T> T f2(T&);
//                        ^^ delete extra int

template <typename T> inline T foo(T, unsigned int*);
//                   ^^^^^^ inline must be after template

template <typename T> T f4(T, T);
//                   ^ -- return type must be provided

typedef char Ctype;
//          ^^^^^
//the template declatation below hides this typedef
template <typename Ctype> Ctype f5(Ctype a);
```

## [Exercise 16.19](ex16.19.20/main.cpp)
>Write a function that takes a reference to a container and prints the elements in that container. 
Use the container’s size_type and size members to control the loop that prints the elements.

## [Exercise 16.20](ex16.19.20/main.cpp)
>Rewrite the function from the previous exercise to use iterators returned from begin and end to control the loop.

## [Exercise 16.21](ex16.21.22/DebugDelete.h)
>Write your own version of DebugDelete.

## [Exercise 16.22](ex16.21.22/main.cpp)
>Revise your TextQuery programs from § 12.3 (p. 484) so that the shared_ptr members use a DebugDelete as their deleter (§ 12.1.4, p. 468).

## Exercise 16.23
>Predict when the call operator will be executed in your main query program. 
If your expectations and what happens differ, be sure you understand why.

The call operator of DebugDelete is executed every time a shared_ptr (or unique_ptr) that uses DebugDelete as its deleter is destroyed. In the main query program, this happens when:
- The TextQuery object goes out of scope at the end of main, destroying its shared_ptr members file and wordMap.
- Each `shared_ptr<std::set<size_t>>` stored in the map for distinct words is destroyed (one per unique word).
- The static nodata shared_ptr inside the query function is destroyed when the program terminates.

If you expected fewer calls, you might have missed the per-word sets or the static nodata object. The actual output shows one deletion message for every dynamically allocated object managed by DebugDelete.

## [Exercise 16.24](ex16.24/Blob.h)
>Add a constructor that takes two iterators to your Blob template.

## Exercise 16.25
>Explain the meaning of these declarations:
```cpp
// instantiation declaration. The definition of it is somewhere else
extern template class vector<string>;
// instantiation definition. The compiler will generate codes for it.
template class vector<Sales_data>;
```

## Exercise 16.26
>Assuming NoDefault is a class that does not have a default constructor, can we explicitly instantiate vector<NoDefault>? If not, why not?

No, we cannot explicitly instantiate `vector<NoDefault>`.

The reason is that explicit instantiation (`template class vector<NoDefault>;`) instantiates all members of the class template, including constructors and member functions that require the element type to be default-constructible. In C++11 and later, vector has a constructor vector(size_type n) and overloads of resize that require default construction of elements. Since NoDefault lacks a default constructor, the instantiation of these members fails.

(Implicit instantiation, which only instantiates members actually used, would still be allowed as long as no such member is called.)

## Exercise 16.27
>For each labeled statement explain what, if any, instantiations happen. If a template is instantiated, explain why; if not, explain why not.

```cpp
template <typename T> class Stack { };
void f1(Stack<char>);// (a)
class Exercise {
    Stack<double> &rsd;// (b)
    Stack<int>si;// (c)
};
int main() {
    Stack<char> *sc;// (d)
    f1(*sc);// (e)
    int iObj = sizeof(Stack< string >); // (f)
}
```

- (a) `void f1(Stack<char>);`
No instantiation. This is a function declaration; the parameter type is a template specialization, but a declaration does not require the type to be complete. The compiler does not generate code for `Stack<char>` here.

- (b) `Stack<double> &rsd;`
No instantiation. A reference declaration does not need the referenced type to be complete. The template is not instantiated.

- (c) `Stack<int> si;`
Instantiation. Defining an object of type `Stack<int>` requires the class to be complete (the compiler needs to know its size and implicitly generated members like the default constructor). This triggers implicit instantiation of `Stack<int>`.

- (d) `Stack<char> *sc;`
No instantiation. Declaring a pointer does not require the pointed-to type to be complete. The template is not instantiated.

- (e) `f1(*sc);`
Instantiation. The expression `*sc` yields a `Stack<char>` object, which is passed by value to f1. Passing an object by value requires the copy constructor (or move constructor) of `Stack<char>`, so the compiler must instantiate `Stack<char>`.

- (f) `int iObj = sizeof(Stack<string>);`
Instantiation. The sizeof operator requires the size of the type `Stack<string>`, which forces the compiler to implicitly instantiate the template to obtain the complete type information.

In summary, instantiations happen in (c), (e), and (f).

## Exercise 16.28
>Write your own versions of shared_ptr and unique_ptr.

[shared_ptr](ex16.28/shared_pointer.h) | [unique_ptr](ex16.28/unique_pointer.h)

## [Exercise 16.29](ex16.29.30/Blob.h)
>Revise your Blob class to use your version of shared_ptr rather than the library version.

modify:
- std::shared_ptr => CP5::SharedPointer
- std::make_shard => new

## [Exercise 16.30](ex16.29.30/main.cpp)
Rerun some of your programs to verify your shared_ptr and revised Blob classes. 
(Note: Implementing the weak_ptr type is beyond the scope of this Primer, so you will not be able to use the BlobPtr class with your revised Blob.)

## Exercise 16.31
>Explain how the compiler might inline the call to the deleter if we used DebugDelete with unique_ptr.

When a function object (like `DebugDelete`) is used as the deleter for `std::unique_ptr`:
- the deleter type is part of the template parameter.
- The compiler knows the exact type and can see the definition of `operator()` (usually inline). 

Therefore, when the `unique_ptr` destructor calls `deleter(ptr)`, the call can be inlined directly to `delete ptr`, eliminating function call overhead. In contrast, a function pointer holds a runtime address, making inlining impossible.

## Exercise 16.32
>What happens during template argument deduction?

During template argument deduction, the compiler uses types of the arguments in the call to find the template arguments that generate a version of the function that best matches the given call.

## Exercise 16.33
>Name two type conversions allowed on function arguments involved in template argument deduction.

- const conversions: A function parameter that is a reference (or pointer) to a const can be passed a reference (or pointer) to a nonconst object (§ 4.11.2, p. 162).

- Array- or function-to-pointer conversions: If the function parameter is not a reference type, then the normal pointer conversion will be applied to arguments of array or function type. An array argument will be converted to a pointer to its first element. Similarly, a function argument will be converted to a pointer to the function’s type (§ 4.11.2, p. 161).

## Exercise 16.34
>Given only the following code, explain whether each of these calls is legal. If so, what is the type of T? If not, why not?
```cpp
template <class T> int compare(const T&, const T&);
(a) compare("hi", "world"); (b) compare("bye", "dad");
```
(a) illegal. These two types are different, char[3] and char[6].
(b) legal. These two types are the same.

## Exercise 16.35
>Which, if any, of the following calls are errors? If the call is legal, what is the type of T? If the call is not legal, what is the problem?
```cpp
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d;float f;char c;
(a) calc(c, ’c’); (b) calc(d, f);
(c) fcn(c, ’c’); (d) fcn(d, f);
```

(a) legal, T is a char
(b) legal, T is a double
(c) legal, T is a char
(d) illegal, arguments d and f are double and float repectively

## Exercise 16.36
>What happens in the following calls:
```cpp
template <typename T> f1(T, T);
template <typename T1, typename T2> f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
(a) f1(p1, p2);(b) f2(p1, p2);(c) f1(cp1, cp2);
(d) f2(cp1, cp2);(e) f1(p1, cp1);(f) f2(p1, cp1);
```

```cpp
(a) legal, T = int*
(b) legal, T1 = int*, T2 = int*
(c) legal, T = int const*
(d) legal, T1 = int const*, T2 = int const*
(e) illegal, types not match, p1 is int* while cp1 is int const*
(f) legal, T1 is int* and T2 is int const*
```

## Exercise 16.37
>The library max function has two function parameters and returns the larger of its arguments. This function has one template type parameter. Could you call max passing it an int and a double? If so, how? If not, why not?

Yes, just offer an explicit template augment, for example:
```cpp
int a = 3; double b = 3.14;
max<double>(a, b);
```

## Exercise 16.38
>When we call make_shared (§ 12.1.1, p. 451), we have to provide an explicit template argument. Explain why that argument is needed and how it is used.

Without specified type given, make_shared has no possibility to determine how big the size it should allocate, which is the reason.

Depending on the type specified, make_shared allocates proper size of memory space and returns a proper type of shared_ptr pointing to it.

## Exercise 16.39
>Use an explicit template argument to make it sensible to pass two string literals to the original version of compare from § 16.1.1 (p. 652).

```cpp
// function compare from § 16.1.1
template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
```

```cpp
compare<const char*>("hello", "world"); // const char* version
compare<std::string>("hello", "world"); // std::string version
```

## Exercise 16.40
>Is the following function legal? If not, why not? If it is legal, what, if any, are the restrictions on the argument type(s) that can be passed, and what is the return type?
```cpp
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0) {
    // process the range
    return *beg; // return a copy of an element from the range
}
```

It is legal. Only type that support dereference and this + 0 operation can be passed. The return type depends on the what type the operator + returns.

## Exercise 16.41
>Write a version of sum with a return type that is guaranteed to be large enough to hold the result of the addition.

```cpp
template <typename T> 
auto sum(const T a, const T b) -> decltype(a + b) {
    return a + b;
}
```

## Exercise 16.42
>Determine the type of T and of val in each of the following calls:
```cpp
template <typename T> void g(T&& val);
int i = 0; const int ci = i;
(a) g(i);(b) g(ci);(c) g(i * ci);
```

(a) since i is lvalue, T is deduced as int&, val is int& && collapsing to int&.
(b) since ci is lvaue, T is deduced as const int&, val is const int& && collapsing to const int&.
(c) since i * ci is rvalue, T is deduced as int, val is int&& && colapsing to int&&.

## Exercise 16.43
>Using the function defined in the previous exercise, what would the template parameter of g be if we called g(i = ci)?

(i = ci) returns lvalue refering to the object i. Hence T is deduced as int& and val is int& && collapsing to int&. Any change on val changes the object i.

## Exercise 16.44
>Using the same three calls as in the first exercise, determine the types for T if g’s function parameter is declared as T (not T&&). What if g’s function parameter is const T&?

if g’s function parameter is declared as T (not T&&).
                                         ^
    g(i);       --  T is deduced as int
    g(ci);      --  T is deduced as int, const is ignored.
    g(i * ci);  --  T is deduced as int, (i * ci) returns rvalue which is copied to
                    
What if g’s function parameter is const T&?
                                  ^^^^^^^^
    g(i)        --  T is deduced as int  , val : const int&
    g(ci)       --  T is deduced as int  , val : const int&
    g(i * ci)   --  T is deduced as int  , val : const int&(see example on page 687)

## Exercise 16.45
>Given the following template, explain what happens if we call g on a literal value such as 42. What if we call g on a variable of type int?
```cpp
template <typename T> void g(T&& val) { vector<T> v; }
```

if we call g on a literal value such as 42.
    Compiles successfully. T is deduced as int, so `vector<T> v;` becomes `vector<int> v;`, which is valid.

What if we call g on a variable of type int?
    Results in a compilation error. T is deduced as int& (lvalue reference), so `vector<T> v;` becomes `vector<int&> v;`, which is ill-formed. According to the C++ standard, the element type of a standard container (like std::vector) must be an object type and must satisfy the Erasable requirement.

## Exercise 16.46
>Explain this loop from StrVec::reallocate in § 13.5 (p. 530):
```cpp
for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
```

In each iteration, the dereference operator * returns a lvalue which is changed to rvalue by `std::move`, because the member function construct takes rvalue reference rather than lvalue reference.

## [Exercise 16.47](ex16.47/main.cpp)
>Write your own version of the flip function and test it by calling functions that have lvalue and rvalue reference parameters.

## [Exercise 16.48](ex16.48/main.cpp)
>Write your own versions of the debug_rep functions.

## [Exercise 16.49](ex16.49.50/main.cpp)
>Explain what happens in each of the following calls:
```cpp
template <typename T> void f(T);
template <typename T> void f(const T*);
template <typename T> void g(T);
template <typename T> void g(T*);
int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;
g(42);g(p);g(ci);g(p2);
f(42);f(p);f(ci);f(p2);
```

```cpp
g(42); //   g(T)
g(p);  //   g(T*)
g(ci); //   g(T)
g(p2); //   g(T*)
f(42); //   f(T)
f(p);  //   f(T)
f(ci); //   f(T)
f(p2); //   f(const T*)
```

## [Exercise 16.50](ex16.49.50/main.cpp)
>Define the functions from the previous exercise so that they print an identifying message. 
Run the code from that exercise. If the calls behave differently from what you expected, make sure you understand why.

## [Exercise 16.51](ex16.51.52/main.cpp)
>Determine what sizeof...(Args) and sizeof...(rest) return for each call to foo in this section.

```cpp
foo(i, s, 42, d);    // Args = 3, rest = 3
foo(s, 42, "hi");    // Args = 2, rest = 2
foo(d, s);           // Args = 1, rest = 1
foo("hi");           // Args = 0, rest = 0
```

## [Exercise 16.52](ex16.51.52/main.cpp)
>Write a program to check your answer to the previous question.

## [Exercise 16.53](ex16.53/main.cpp)
>Write your own version of the print functions and test them by printing one, two, and five arguments, each of which should have different types.

## Exercise 16.54
>What happens if we call print on a type that doesn’t have an << operator?

It will not compile.

## Exercise 16.55
>Explain how the variadic version of print would execute if we declared the nonvariadic version of print after the definition of the variadic version.

error: no matching function for call to 'print(std::ostream&, const T &t)'

## [Exercise 16.56](ex16.56/main.cpp)
>Write and test a variadic version of errorMsg.

## Exercise 16.57
>Compare your variadic version of errorMsg to the error_msg function in § 6.2.6 (p. 220). What are the advantages and disadvantages of each approach?

The error_msg takes initializer_list as the argument. So only the elements stored in it must be the same or at least convertible. In contrast, the variadic version provides better flexibility.

## Exercise 16.58
>Write the emplace_back function for your StrVec class and for the Vec class that you wrote for the exercises in § 16.1.2 (p. 668).

- StrVec : [hpp](ex16.58/StrVec.h) | [cpp](ex16.58/StrVec.cpp)
- Vec : [hpp](ex16.58/vec.h)

## Exercise 16.59
>Assuming s is a string, explain svec.emplace_back(s).

- s is an lvalue, so template argument deduction yields `Args = std::string&` (reference collapsing).

- `std::forward<Args>(args)...` becomes `std::forward<std::string&>(s)`, which forwards s as an lvalue reference.

- This lvalue reference is passed to `alloc.construct`, which constructs a new `std::string` object directly in the vector’s memory.

- The newly constructed `std::string` uses its copy constructor (which takes `const std::string&`) to copy from `s`.

- Therefore, a copy of `s` is constructed directly in the vector’s memory. No move happens; it’s just a copy.

## Exercise 16.60
>Explain how make_shared (§ 12.1.1, p. 451) works.

```cpp
//shared_ptr that points to an int with value 42
shared_ptr<int> p3 = make_shared<int>(42);
//p4 points to a string with value 9999999999
shared_ptr<string> p4 = make_shared<string>(10, ’9’);
//p5 points to an int that is value initialized (§ 3.3.1 (p. 98)) to 0
shared_ptr<int> p5 = make_shared<int>();
```

`make_shared` should be a variadic template function that forwards all arguments to underlying constructors that allocate and initializes an object in dynamic memory and, at last, build a shared_ptr by wrapping the raw pointer.

## [Exercise 16.61](ex16.61/main.cpp)
>Define your own version of make_shared.

## [Exercise 16.62](ex16.62/main.cpp)
>Define your own version of hash<Sales_data> and define an unordered_multiset of Sales_data objects. Put several transactions into the container and print its contents.

## [Exercise 16.63](ex16.63.64/main.cpp)
>Define a function template to count the number of occurrences of a given value in a vector. Test your program by passing it a vector of doubles, a vector of ints, and a vector of strings.

## [Exercise 16.64](ex16.63.64/main.cpp)
>Write a specialized version of the template from the previous exercise to handle vector<const char*> and a program that uses this specialization.

## [Exercise 16.65](ex16.65/main.cpp)
>In § 16.3 (p. 698) we defined overloaded two versions of debug_rep one had a const char* and the other a char* parameter. Rewrite these functions as specializations.

## Exercise 16.66
>What are the advantages and disadvantages of overloading these debug_rep functions as compared to defining specializations?

Overloading is better than specialization because it changes the function match during overload resolution, involving all candidates directly, whereas specialization does not affect primary template selection and can be silently ignored.
