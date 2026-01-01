## Exercise 13.1
>What is a copy constructor? When is it used?

A copy constructor is a constructor which first parameter is a **reference** to the class type and any additional parameters have **default values**.

A copy constructor is a constructor whose first parameter is a reference to the class type and any additional parameters have default values.

It used when we use copy initialization and don't require moove constructor. Copy initialization happens when we
• define variables using an =
• Pass an object as an argument to a parameter of nonreference type 
• Return an object from a function that has a nonreference return type 
• Brace initialize the elements in an array or the members of an aggregate class

## Exercise 13.2
> Explain why the following declaration is illegal:
```cpp
Sales_data::Sales_data(Sales_data rhs);
```

If that parameter were not a reference, then the call would never succeed to call the copy constructor, we’d need to use the copy constructor to copy the argument, but to copy the argument, we’d need to call the copy constructor, and so on indefinitely.

## Exercise 13.3
>What happens when we copy a `StrBlob`? What about `StrBlobPtrs`?

```cpp
// added a public member function to StrBlob and StrBlobPrts
long count() {
    return data.use_count(); // and wptr.use_count();
}

// test codes in main()
StrBlob str({ "hello", "world" });
std::cout << "before: " << str.count() << std::endl; // 1
StrBlob str_cp(str);
std::cout << "after: " << str.count() << std::endl;  // 2

ConstStrBlobPtr p(str);
std::cout << "before: " << p.count() << std::endl; // 2
ConstStrBlobPtr p_cp(p);
std::cout << "after: " << p.count() << std::endl; // 2
```

when we copy a `StrBlob`, the `shared_ptr` member's use_count add one.

when we copy a `StrBlobPrts`, the `weak_ptr` member's use_count isn't changed.(cause the count belongs to `shared_ptr`)

## Exercise 13.4
>Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:
```cpp
Point global;
Point foo_bar(Point arg) // 1
{
    Point local = arg, *heap = new Point(global); // 2, 3
    *heap = local;
    Point pa[ 4 ] = { local, *heap }; // 4, 5
    return *heap; // 6
}
```

## [Exercise 13.5](ex13_05.h)

## Exercise 13.6
>What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?

The copy-assignment operator is function named `operator=` and takes an argument of the same type as the class.

This operator is used when assignment occurred.

The synthesized copy-assignment operator assigns each nonstatic member of the right-hand object to corresponding member of the left-hand object using the copy-assignment operator for the type of that member.

The synthesized copy-assignment operator is synthesized by the compiler when the class does not define its own.

## Exercise 13.7
>What happens when we assign one StrBlob to another? What about StrBlobPtrs?

In both cases, shallow copy will happen. All pointers point to the same address. The `use_count` changed the same as 13.3.

## [Exercise 13.8](ex13_08.h)

## Exercise 13.9
>What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?

The destructor is a member function with the name of the class prefixed by a tilde(~).

As with the copy constructor and the copy-assignment operator, for some classes, the synthesized destructor is defined to disallow objects of the type from being destoryed. Otherwise, the synthesized destructor has an empty function body.

The compiler defines a synthesized destructor for any class that does not define its own destructor.

## Exercise 13.10
>What happens when a StrBlob object is destroyed? What about a StrBlobPtr?

When a `StrBlob` object destroyed, the `use_count` of the dynamic object will decrement. It will be freed if no `shared_ptr` to that dynamic object.

When a `StrBlobPter` object is destroyed the object dynamically allocated will not be freed.

## [Exercise 13.11](ex13_11.h)

## Exercise 13.12
>How many destructor calls occur in the following code fragment?
```cpp
bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
```

3 times. There are `accum`, `item1` and `item2`.

## [Exercise 13.13](ex13_13.cpp)

## Exercise 13.14
>Assume that `numbered` is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named `mysn`. Assuming numbered uses the synthesized copy-control members and given the following function:
```cpp
void f (numbered s) { cout << s.mysn << endl; }
```
what output does the following code produce?
```cpp
numbered a, b = a, c = b;
f(a); f(b); f(c);
```

Three identical numbers.

## Exercise 13.15
>Assume `numbered` has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?

Yes, it does. Because, as described, the newly defined copy constructor can handle such situations as expected.Thus, the output will be three different numbers.

## Exercise 13.16
>What if the parameter in f were const numbered&? Does that change the output? If so, why? What output gets generated?

Yes, the output will change. Beause no copy operation happens within `f`. That is copy constructor will not be called within function `f`. The three output will be three different numbers.

## Exercise 13.17
> Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.

[For 13.14](ex13_17_1.cpp) | [For 13.15](ex13_17_2.cpp) | [For 13.16](ex13_17_3.cpp)

## [Exercise 13.18](ex13_18.h)

## [Exercise 13.19](ex13_19.h)

No, because the case is impossible. Employee can't copy in reality.

## Exercise 13.20
>Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes from § 12.3 (p. 484).

The member (smart pointer and container) will be copied.

## Exercise 13.21
>Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think these classes require.

As synthesized version meet all requirements for this case, no custom version control memebers need to define. Check [#304](https://github.com/Mooophy/Cpp-Primer/issues/304#issuecomment-124081395) for detail.

## [Exercise 13.22](ex13_22.h)

## Exercise 13.23
>Compare the copy-control members that you wrote for the solutions to the previous section’s exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.

Check 13.22.

## Exercise 13.24
>What would happen if the version of `HasPtr` in this section didn’t define a destructor? What if `HasPtr` didn’t define the copy constructor?

If `HasPtr` didn't define a destructor, a memory leak would occur, compiler synthesized destructor does not manage dynamic memory. If `HasPtr` didn't define the copy constructor, we would get pointer-like copy behaviour. The ps pointer would be copied to the left hand side, but ps in the lhs and the rhs would still point to the same string on the heap. 

## Exercise 13.25
>Assume we want to define a version of `StrBlob` that acts like a value. Also assume that we want to continue to use a shared_ptr so that our `StrBlobPtr` class can still use a weak_ptr to the vector. Your revised class will need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy constructor and copy-assignment operators must do. Explain why the class does not need a destructor.

Copy constructor and copy-assignment operator should dynamically allocate memory for its own , rather than share the object with the right hand operand.

`StrBlob` is using smart pointers which can be managed with synthesized destructor, If an object of `StrBlob` is out of scope, the destructor for std::shared_ptr will be called automatically to free the memory dynamically allocated when the `use_count` goes to 0.

## [Exercise 13.26](ex13_26.h)

## [Exercise 13.27](ex13_27.h)

## [Exercise 13.28](ex13_28.h)

## Exercise 13.29
> Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.

`swap(lhs.ps, rhs.ps);` feed the version : `swap(std::string*, std::string*)` and `swap(lhs.i, rhs.i);` feed the version : `swap(int, int)`. Both them can't call `swap(HasPtr&, HasPtr&)`. Thus, the calls don't cause a recursion loop.

## [Exercise 13.30](ex13_30.h)
## Exercise 13.31 [Header](ex13_31.h) | [Test](ex13_31_TEST.cpp)

## Exercise 13.32
>Would the pointerlike version of `HasPtr` benefit from defining a swap function? If so, what is the benefit? If not, why not?

In general specific swap functions can avoid unnecessary memory allocation.As for the pointerlike version, no dynamic memory allocation. Thus, a specific version for it will not improve the performance.

## Exercise 13.33
>Why is the parameter to the `save` and `remove` members of Message a Folder&? Why didn’t we define that parameter as `Folder`? Or `const Folder&`?

Because these operations must also update the given `Folder`. Updating a `Folder` is a job that the `Folder` class controls through its `addMsg` and `remMsg` members, which will add or remove a pointer to a given `Message`, respectively.

## Exercise 13.34 [hpp](ex13_34_36_37.h) | [cpp](ex13_34_36_37.cpp)

## Exercise 13.35
>What would happen if `Message` used the synthesized versions of the copy-control members?

some existing `Folders` will out of sync with the `Message` after assignment.

## Exercise 13.36 [hpp](ex13_34_36_37.h) | [cpp](ex13_34_36_37.cpp)
## Exercise 13.37 [hpp](ex13_34_36_37.h) | [cpp](ex13_34_36_37.cpp)

## Exercise 13.38
>We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?

@Mooophy
The copy and swap is an elegant way when working with dynamicly allocated memory. In the Message class , nothing is allocated dynamically. Thus using this idiom makes no sense and will make it more complicated to implement due to the pointers that point back.

@pezy
In this case, `swap` function is special. It will be clear two `Message`'s folders , then swap members, and added themselves to each folders. But, `Message` assignment operator just clear itself, and copy the members, and added itself to each folders. The `rhs` don't need to clear and add to folders. So, if using copy and swap to define, it will be very inefficiency.

## Exercise 13.39 [hpp](ex13_39.h) | [cpp](ex13_39.cpp)
## Exercise 13.40 [hpp](ex13_40.h) | [cpp](ex13_40.cpp)

## Exercise 13.41
>Why did we use postfix increment in the call to construct inside push_back? What would happen if it used the prefix increment?

	|a|b|c|d|f|..............|
	^	       ^             ^
	elements   first_free    cap

	// if use alloc.construct(first_free++, "g");
	|a|b|c|d|f|g|.............|
	^	         ^            ^
	elements     first_free   cap

	// if use alloc.construct(++first_free, "g");
	|a|b|c|d|f|.|g|............|
	^	       ^ ^             ^
	elements   | first_free    cap
		       |
	    "unconstructed"

## Exercise 13.42
>Test your StrVec class by using it in place of the vector<string> in your TextQuery and QueryResult classes (12.3, p. 484).

- StrVec : [hpp](ex13_42_StrVec.h) | [cpp](ex13_42_StrVec.cpp)
- TextQuery and QueryResult : [hpp](ex13_42_TextQuery.h) | [cpp](ex13_42_TextQuery.cpp)
- Text : [ex13_42.cpp](ex13_42.cpp)

## Exercise 13.43
>Rewrite the free member to use `for_each` and a lambda (10.3.2, p. 388) in place of the for loop to destroy the elements. Which implementation do you prefer, and why?

**Rewrite**

```cpp
// use for loop to destory
void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}
```

```cpp
// use for_each and a lambda to destory
void StrVec::free() {
    if (elements) {
        std::for_each(elements, first_free, [this] (string &rhs)
            { alloc.destroy(&rhs); });
        alloc.deallocate(elements, cap - elements);
    }
}
```

@Mooophy:

The new version is better. Compared to the old one, it doesn't need to worry about the order and decrement. So more straightforward and handy. The only thing to do for using this approach is to add "&" to build the pointers to string pointers.

## Exercise 13.44
>Write a class named String that is a simplified version of the library string class. Your class should have at least a default constructor and a constructor that takes a pointer to a C-style string. Use an allocator to allocate memory that your String class uses.

[hpp](ex13_44.h) | [cpp](ex13_44.cpp) 

more information to see [A trivial String class that designed for write-on-paper in an interview](https://github.com/chenshuo/recipes/blob/fcf9486f5155117fb8c36b6b0944c5486c71c421/string/StringTrivial.h)

## Exercise 13.45
>Distinguish between an rvalue reference and an lvalue reference.

Definition：

- lvalue reference: reference that can bind to **an lvalue**. (Regular reference)
- rvalue reference: reference **to an object that is about to be destroyed**.

We can bind an rvalue reference to expression that require conversion, to literals, or to expressions that return an rvalue, but we cannot directly bind an rvalue reference to an lvalue.

```cpp
int i = 42;
int &r = i; // lvalue reference
int &&rr = i; // rvalue reference (Error: i is a lvalue)
int &r2 = i*42; // lvalue reference (Error: i*42 is a rvalue)
const int &r3 = i*42; // reference to const (bind to a rvalue)
int &&rr2 = i*42; // rvalue reference
```

- lvalue : functions that return lvalue references, assignment, subscript, dereference, and prefix increment/decrement operator.
- rvalue / const reference : functions that return a nonreferences, arithmetic, relational bitwise, postfix increment/decrement operators.

## Exercise 13.46
>Which kind of reference can be bound to the following initializers?
```cpp
int f();
vector<int> vi(100);
int&& r1 = f();
int& r2 = vi[0];
int& r3 = r1;
int&& r4 = vi[0] * f();
```

## Exercise 13.47 [hpp](ex13_47.h) | [cpp](ex13_47.cpp)

## [Exercise 13.48](ex13_48.cpp)

## Exercise 13.49
>Add a move constructor and move-assignment operator to your
StrVec, String, and Message classes.

StrVec : [hpp](ex13_49_StrVec.h) | [cpp](ex13_49_StrVec.cpp)
String : [hpp](ex13_49_String.h) | [cpp](ex13_49_String.cpp)
Message : [hpp](ex13_49_Message.h) | [cpp](ex13_49_Message.cpp)

