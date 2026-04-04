## Exercise 15.1
>What is a virtual member?

A virtual member in a base class expects its derived class define its own version. In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2
>How does the protected access specifier differ from private?

* **private member**: base class itself and friend can access
* **protected members**: base class itself, friend and derived classes can access

## Exercise 15.3
>Define your own versions of the Quote class and the print_total function.

[hpp](ex15.3/quote.h) | [cpp](ex15.3/quote.cpp) | [Test](ex15.3/main.cpp)

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

[hpp](ex15.5.6/bulk_quote.h) | [cpp](ex15.5.6/bulk_quote.cpp)

## [Exercise 15.6](ex15.5.6/main.cpp)
>Test your print_total function from the exercises in § 15.2.1 (p. 595) by passing both Quote and Bulk_quote objects o that function.

## [Exercise 15.7](ex15.7/main.cpp)
>Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.

## Exercise 15.8
>Define static type and dynamic type.

The static type of an expression is always known at compile time. 

The dynamic type is the type of the object in memory that the variable or expression represents. The dynamic type may not be known until run time.

## Exercise 15.9
>When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.

The static type of a pointer or reference to a base class may differ from its dynamic type. Anything like this can be an example.

[Exercise 15.9](ex15.9/main.cpp)

## Exercise 15.10
>Recalling the discussion from § 8.1 (p. 311), explain how the program on page 317 that passed an ifstream to the Sales_data read function works.

The function takes a `std::istream` from which `std::ifstream` is derived. Hence the `ifstream` object "is a" i`stream` , which is why it works.

## [Exercise 15.11](ex15.11/main.cpp)
>Add a virtual debug function to your Quote class hierarchy that displays the data members of the respective classes.

```cpp
void Quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "bookNo= " <<this->bookNo << " "
              << "price= " <<this->price<< " ";
}
```

## Exercise 15.12
>Is it ever useful to declare a member function as both override and final? Why or why not?

 Yes. override means overriding the same name virtual function in base class. final means preventing any overriding this virtual function by any derived classes that are more lower at the hierarchy.

Exercise 15.13
>Given the following classes, explain each print function:

```cpp
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) { print(os); os << " " << i; }
private:
    int i;
};
```
>If there is a problem in this code, how would you fix it?

We should add the class scope `base::` and we'd better add `override` for security.

```cpp
class base {
public:
   std::string name() { return basename; }
   virtual void print(std::ostream &os) { os << basename; }
   //      ~~~~~^^^^^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   //  The print here just output the basename of the base.
private:
   std::string basename = "base\n";
};

class derived : public base {
public:
   void print(std::ostream &os) override { base::print(os); os << " derived\n " << i; }
   //   ^^^^^                   ^^^^^^^^   ^^^^^^    --  added to fix this problem
   //  this print wanted to call the print from the base class.
   //  however, the class scope base:: was omitted.As a result
   //  it will cause an infinit recursion.
   //  btw, we can add a keyword `override` to show this function
   //  overrides a virtual function from the base class, although
   //  it is not neccessary, but for security, the more, the better.
private:
   int i;
};
```
