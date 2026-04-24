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

## Exercise 15.14
>Given the classes from the previous exercise and the following objects, determine which function is called at run time:

```cpp
base bobj;     base *bp1 = &bobj;    base &br1 = bobj;
derived dobj;  base *bp2 = &dobj;    base &br2 = dobj;
(a) bobj.print();  (b) dobj.print();  (c) bp1->name();
(d) bp2->name();   (e) br1.print();   (f) br2.print();
```
 
(e), (f) are called at run time. (a), (b) are objects and (c), (d) are not virtual functions so they are called at complie time.

## [Exercise 15.15](ex15.15/main.cpp)
>Define your own versions of Disc_quote and Bulk_quote.

[Disc_quote](ex15.15.16.17/disc_quote.h) | [Bulk_quote](ex15.15.16.17/bulk_quote.h)

## Exercise 15.16
>Rewrite the class representing a limited discount strategy, which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from Disc_quote.

[Limit_quote](ex15.15.16.17/limit_quote.h)

## Exercise 15.17

>Try to define an object of type Disc_quote and see what errors you get from the compiler.

```
error: cannot declare variable ‘d’ to be of abstract type ‘Disc_quote’:
    Disc_quote d;

note: because the following virtual functions are pure within ‘Disc_quote’:
    class Disc_quote: public Quote

note: ‘virtual double Disc_quote::net_price(std::size_t) const’:
    virtual double net_price(std::size_t) const override = 0;
```

## Exercise 15.18
>Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed:

```cpp
Base *p = &d1; // d1 has type Pub_Derv
p = &d2;       // d2 has type Priv_Derv
p = &d3;       // d3 has type Prot_Derv
p = &dd1;      // dd1 has type Derived_from_Public
p = &dd2;      // dd2 has type Derived_from_Private
p = &dd3;      // dd3 has type Derived_from_Protected
```

```cpp
Base *p = &d1; // legal
p = &d2;       // illegal
p = &d3;       // illegal
p = &dd1;      // legal
p = &dd2;      // illegal
p = &dd3;      // illegal
```

User code may use the derived-to-base conversion only if D inherits publicly from B. User code may not use the conversion if D inherits from B using either protected or private.

## Exercise 15.19
>Assume that each of the classes from page 612 and page 613 has a member function of the form:
```cpp
void memfcn(Base &b) { b = *this; }
```
For each class, determine whether this function would be legal.

Member functions and friends of D can use the conversion to B regardless of how D inherits from B. The derived-to-base conversion to a direct base class is always accessible to members and friends of a derived class.

Hence, the 3 below are all legal:

* Pub_Derv
* Priv_Derv
* Prot_Derv

Member functions and friends of classes derived from D may use the derived-to-base conversion if D inherits from B using either public or protected. Such code may not use the conversion if D inherits privately from B. 

Hence:

* Derived_from_Public **legal**
* Derived_from_Private **illegal**
* Derived_from_Protected **legal**

## [Exercise 15.20](ex15.20/main.cpp)
>Write code to test your answers to the previous two exercises.

## [Exercise 15.21](ex15.21.22/main.cpp)
>Choose one of the following general abstractions containing a family of types (or choose one of your own). Organize the types into an inheritance hierarchy:
(a) Graphical file formats (such as gif, tiff, jpeg, bmp)
(b) Geometric primitives (such as box, circle, sphere, cone)
(c) C++ language types (such as class, function, member function)

(b) Geometric primitives (such as box, circle, sphere, cone)

## [Exercise 15.22](ex15.21.22/main.cpp)
>For the class you chose in the previous exercise, identify some of the likely virtual functions as well as public and protected members.

## [Exercise 15.23](ex15.23/main.cpp)
>Assuming class D1 on page 620 had intended to override its inherited fcn function, how would you fix that class? Assuming you fixed the class so that fcn matched the definition in Base, how would the calls in that section be resolved?

Add keyword `virtual` to the funciton `int fcn()` in class `Base` and modify the function `int fcn(int);` to `int fcn();` in class `D1`. 

## Exercise 15.24
>What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?

Generally, a base class should define a virtual destructor. The destructor needs to be virtual to allow objects in the inheritance hierarchy to be dynamically allocated.

## Exercise 15.25
>Why did we define a default constructor for Disc_quote? What effect, if any, would removing that constructor have on the behavior of Bulk_quote?

Without it, when building the statement below, the compiler would complain that:

> note: 'Bulk_quote::Bulk_quote()' is implicitly deleted because the default definition would be ill-formed.

The reason is that a constructor taking 4 parameters has been defined, which prevented the compiler generate synthesized version default constructor.

As a result, the default constructor of any class derived from it has been defined as deleted. Thus the default constructor must be defined explicitly so that the derived classes can call it when executing its default constructor.

## [Exercise 15.26](ex15.26/main.cpp)
>Define the Quote and Bulk_quote copy-control members to do the same job as the synthesized versions. 
Give them and the other constructors print statements that identify which function is running. 
Write programs using these classes and predict what objects will be created and destroyed. 
Compare your predictions with the output and continue experimenting until your predictions are reliably correct.

## [Exercise 15.27](ex15.27/bulk_quote.h)
>Redefine your Bulk_quote class to inherit its constructors.

## [Exercise 15.28](ex15.28.29/main.cpp)
>Define a vector to hold Quote objects but put Bulk_quote objects into that vector. Compute the total net_price of all the elements in the vector.

## [Exercise 15.29](ex15.28.29/main.cpp)
>Repeat your program, but this time store shared_ptrs to objects of type Quote. Explain any discrepancy in the sum generated by the this version and the previous program. If there is no discrepancy, explain why there isn’t one.

Since the vector from the previous exercise holds objects, there's no polymorphism happened while calling the virtual function net_price. Essentially, the objects held in it are the Quote subjects of the Bulk_quote objects being pushed back, Thus, the virtual net_price functions called are Quote::net_price. As a result, no discount was applied. The outcome was 9090.

The objects held for this exercise are smart pointers to the Quote objects.In this case, polymorphism happened as expected.The actual virtual functions being called are Bulk_quote::net_price that ensure discount is applied.Thus, the outcome is 6363. It can be found that 30% discount has been applied to the price calculation.
