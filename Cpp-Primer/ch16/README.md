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
