## Exercise 15.1
>What is a virtual member?

A virtual member in a base class expects its derived class define its own version. In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2
>How does the protected access specifier differ from private?

* **private member**: base class itself and friend can access
* **protected members**: base class itself, friend and derived classes can access

## Exercise 15.3
>Define your own versions of the Quote class and the print_total function.

[hpp](ex15.3/Quote.h) | [cpp](ex15.3/Quote.cpp) | [Test](ex15.3/Quote_TEST.cpp)

## Exercise 15.4
>Which of the following declarations, if any, are incorrect? Explain why.
```cpp
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```

(a) **incorrect**, self-derived.
(b) **incorrect**, it is a definition not a declaration.
(c) **incorrect**, A derived class is declared like any other class. The declaration contains the class name but does not include its derivation list.

## Exercise 15.5:
> Define your own version of the Bulk_quote class.

[hpp](ex15.5.6/Bulk_quote.h) | [cpp](ex15.5.6/Bulk_quote.cpp)

