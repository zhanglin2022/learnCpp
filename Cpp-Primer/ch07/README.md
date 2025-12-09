## [Exercise 7.1](ex7_01.cpp)
## [Exercise 7.2](ex7_02.h)
## [Exercise 7.3](ex7_03.cpp)
## [Exercise 7.4](ex7_04.h)
## [Exercise 7.5](ex7_05.h)

should. The function don't change their value.

## [Exercise 7.6](ex7_06.h)
## [Exercise 7.7](ex7_07.cpp)
## Exercise 7.8
>Why does read define its Sales_data parameter as a plain reference and print define its parameter as a reference to const?

Define `read`'s Sales_data parameter as plain reference since it's intended to change the `revenue`'s value.

Define `print`'s Sales_data parameter as a reference to const since it isn't intended to change any member's value of this object.

## [Exercise 7.9](ex7_09.h)
## Exercise 7.10
> What does the condition in the following if statement do? 
```cpp
if(read(read(cin, data1), data2))
```

we can try to divide it like that:
```cpp
std::istream &firstStep = read(cin, data1);
sdt::istream &secondStep = read(firstStep, data2);
if (secondStep)
```
the condition of the `if` statement would read two Sales_data object at one time.

## Exercise 7.11 [Header](ex7_11.h)|[CPP](ex7_11.cpp)
## [Exercise 7.12](ex7_12.h)
## [Exercise 7.13](ex7_13.cpp)
## Exercise 7.14
>Write a version of the default constructor that explicitly initializes  the members to the values we have provided as in-class initializers.
```cpp
Sales_data() : bookNo(""), units_sold(0) , revenue(0){ }
```

## [Exercise 7.15](ex7_15.h)

## Exercise 7.16
>What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?

There are no restrictions on how often an access specifier may appear.The specified access level remains in effect until the next access specifier or the end of the class body.  
**After a public specifier**: he members which are accessible to all parts of the program.  
**After a private specifier**: The members which are accessible to the member functions of the class but are not accessible to code that uses the class.

## Exercise 7.17
>What, if any, are the differences between using class or struct?

The only difference between using `class` and using `struct` to define a class is the default access level. (`class` : private, `struct` : public)

## Exercise 7.18
>What is encapsulation? Why is it useful?

encapsulation is the separation of implementation from interface. It hides the implementation details of a type. (In C++, encapsulation is enforced by putting the implementation in the private part of a class)

-----

Important advantages:

- User code cannot inadvertently corrupt the state of an encapsulation object.
- The implementation of an encapsulated class can change over time without requiring changes in user-level code.

## Exercise 7.19
>Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.

public include: constructors, `getName()`, `getAddress()`.
private include: `name`, `address`.

the interface should be defined as public, the data shouldn't expose to outside of the class.

## Exercise 7.20
>When are friends useful? Discuss the pros and cons of using friends.

`friend` is a mechanism by which a class grants access to its nonpublic members. They have the same rights as members.

**Pros**:
- the useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
- you can access all the nonpublic members conveniently.
- sometimes, more readable to the users of class.

**Cons**:
- lessens encapsulation and therefore maintainability.
- code verbosity, declarations inside the class, outside the class.

## Exercise 7.21 [Header](ex7_21.h)|[CPP](ex7_21.cpp)
## [Exercise 7.22](ex7_22.h)
## [Exercise 7.23](ex7_23.h)
## [Exercise 7.24](ex7_24.h)

## Exercise 7.25
>Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?

The class below can rely on it. It goes in *Section 7.1.5*:
>..the synthesized versions are unlikely to work correctly for classes that allocate resources that reside outside the class objects themselves.

>Moreover, the synthesized versions for copy, assignment, and destruction work correctly for classes that have **vector or string members**.

Hence the class below which used only built-in type and strings can rely on the default version of copy and assignment. (by @Mooophy)

## [Exercise 7.26](ex7_26.h)
## Exercise 7.27 [Class](ex7_27.h)|[Test](ex7_27_TEST.cpp)
>Add the move, set, and display operations to your version of Screen. Test your class by executing the following code: 
```cpp
Screen myScreen(5, 5, ’X’); 
myScreen.move(4,0).set(’#’).display(cout); 
cout << "\n"; 
myScreen.display(cout); 
cout << "\n";
```

## Exercise 7.28
>What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?

The second call to `display` couldn't print `#` among the output, cause the call to `set` would change the **temporary copy**, not myScreen.

## Exercise 7.29 [Header](ex7_29.h)|[CPP](ex7_29.cpp)

```sh
#with '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
                   ^^^
# without '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
                   ^^^
```

## Exercise 7.30
>It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.

**Pros**

- more explicit
- less scope for misreading
- can use the member function parameter which name is same as the member name.

        void setAddr(const std::string &addr) { this->addr = addr; }

**Cons**

- more to read
- sometimes redundant

        std::string getAddr() const { return this->addr; } // unnecessary

## Exercise 7.31
>Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.

```cpp  
class Y;  
  
class X {  
    Y *y = nullpter;  
};  
  
class Y {  
    X x;  
};  
```

## [Exercise 7.32](ex7_32.h)

Making a member function a friend requires careful structuring

## Exercise 7.33
>What would happen if we gave Screen a size member defined as follows? Fix any problems you identify. 
```cpp
pos Screen::size() const 
{ 
    return height * width; 
}
```

error: unknown type name 'pos'.  
```cpp  
Screen::pos Screen::size() const {  
    return height * width;  
}  
```

## Exercise 7.34
>What would happen if we put the typedef of pos in the Screen class on page 285 as the last line in the class?

There is an error in

    dummy_fcn(pos height)
               ^
    Unknown type name 'pos'

## Exercise 7.35
>Explain the following code, indicating which definition of Type or initVal is used for each use of those names. Say how you would fix any errors.

```cpp
typedef string Type;
Type initVal(); // use `string`
class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // use `double`
    Type initVal(); // use `double`
private:
    int val;
};

Type Exercise::setVal(Type parm) {  // first is `string`, second is `double`
    val = parm + initVal();     // Exercise::initVal()
    return val;
}
```

**fixed**

changed

```cpp
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```
to
```cpp
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

and `Exercise::initVal()` should be defined.

## Exercise 7.36
>The following initializer is in error. Identify and fix the problem. 

```cpp
struct X { 
    X (int i, int j): base(i), rem(base % j) { } 
    int rem, base; 
};
```
`rem` should be initialized first.  

```cpp  
struct X {  
    X (int i, int j): rem(i % j), base(i) {  }  
    int rem, base; };  
```

## Exercise 7.37
>Using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object: 

```cpp
Sales_data first_item(cin); 

int main() { 
    Sales_data next; Sales_data last("9-999-99999-9"); 
}
```

```cpp
Sales_data first_item(cin);   // use Sales_data(std::istream &is) ; its value are up to your input.

int main() {
  Sales_data next;  // use Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0
  Sales_data last("9-999-99999-9"); // use Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
```

## Exercise 7.38
>We might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.

```cpp
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

## Exercise 7.39
>Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?

illegal. cause the call of overloaded 'Sales_data()' is **ambiguous**.

## Exercise 7.40
> Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions. 
(a) Book      (b) Date      (c) Employee 
(d) Vehicle   (e) Object    (f) Tree

```cpp
#include <iostream>
#include <string>

class Book {
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

    explicit Book(std::istream &in) { 
        in >> isbn_ >> name_ >> author_ >> pubdate_;
    }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};
```

## Exercise 7.41 [Header](ex7_41.h)|[Test](ex7_41_TEST.cpp)
## Exercise 7.42
>For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. 
If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. 
Write the class definition for that abstraction.

```cpp
#include <iostream>
#include <string>

class Book {
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :isbn_(isbn), name_(name), author_(author), pubdate_(pubdate)
    { }

    explicit Book(std::istream &in) { 
        in >> isbn_ >> name_ >> author_ >> pubdate_;
    }

private:
    unsigned isbn_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};
```

## [Exercise 7.43](ex7_43.cpp)
## Exercise 7.44
>Is the following declaration legal? If not, why not? 
```cpp
vector<NoDefault> vec(10);
```

illegal, cause there are ten elements, each would be default initialized. But no default initializer for the temporary object.

## Exercise 7.45
>What if we defined the vector in the previous execercise to hold objects of type C?

Legal. cause `C` have the default constructor.

## Exercise 7.46
>Which, if any, of the following statements are untrue? Why? 
(a) A class must provide at least one constructor. 
(b) A default constructor is a constructor with an empty parameter list. 
(c) If there are no meaningful default values for a class, the class should not provide a default constructor. 
(d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

- a) A class must provide at least one constructor. (**untrue**, "The compiler-generated constructor is known as the synthesized default constructor.")
- b) A default constructor is a constructor with an empty parameter list. (**untrue**,  A default constructor is a constructor that is used if no initializer is supplied.What's more, A constructor that supplies default arguments for all its parameters also defines the default constructor)
- c) If there are no meaningful default values for a class, the class should not provide a default constructor. (**untrue**, the class should provide.)
- d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type. (**untrue**, only if our class does not explicitly define **any constructors**, the compiler will implicitly define the default constructor for us.)

## Exercise 7.47
>Explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?

Whether the conversion of a `string` to `Sales_data` is desired **depends on how we think our users will use the conversion**. In this case, it might be okay. The `string` in null_book probably represents a nonexistent ISBN.

Benefits:

- prevent the use of a constructor in a context that requires an implicit conversion
- we can define a constructor which is used only with the direct form of initialization

Drawbacks:

- meaningful only on constructors that can be called with a single argument

## Exercise 7.48
>Assuming the Sales_data constructors are not explicit, what operations happen during the following definitions 
```cpp
string null_isbn("9-999-99999-9"); 
Sales_data item1(null_isbn); 
Sales_data item2("9-999-99999-9"); 
```
>What happens if the Sales_data constructors are explicit?

Both are nothing happened.

## Exercise 7.49
>For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a Sales_data and s is a string: 
```cpp
(a) Sales_data &combine(Sales_data); 
(b) Sales_data &combine(Sales_data&); 
(c) Sales_data &combine(const Sales_data&) const;
```

```cpp
(a) Sales_data &combine(Sales_data); // ok
(b) Sales_data &combine(Sales_data&); // [Error] no matching function for call to 'Sales_data::combine(std::string&)' (`std::string&` can not convert to `Sales_data` type.)  
(c) Sales_data &combine(const Sales_data&) const; // The trailing const mark can't be put here, as it forbids any mutation on data members. This conflicts with combine's semantics.
```

Some detailed explanation about problem (b) :It's wrong. Because `combine`’s parameter is  a non-const reference , we can't  pass a temporary to that parameter. If `combine`’s parameter is  a  reference to const , we can  pass a temporary to that parameter. Like this :`Sales_data &combine(const Sales_data&); `  Here we call the `Sales_data` `combine` member function with a string argument. This call is perfectly legal; the compiler automatically creates a `Sales_data` object from the given string. That newly generated (temporary) `Sales_data` is passed to `combine`.(Also you can read C++ Primer Page 295(English Edition))

## [Exercise 7.50](ex7_50.h)
## Exercise 7.51
>Why do you think vector defines its single-argument constructor as explicit，but string does not?

Such as a function like that:

```cpp
int getSize(const std::vector<int>&);
```

if vector has not defined its single-argument constructor as explicit. we can use the function like:

```cpp
getSize(34);
```

What is this mean? It's very confused.

But the `std::string` is different. In ordinary, we use `std::string` to replace `const char *`(the C language). so when we call a function like that:

```cpp
void setYourName(std::string); // declaration.
setYourName("sun"); // just fine.
```

it is very natural.

## Exercise 7.52
>Using our first version of Sales_data from § 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems. 
```
Sales_data item = {"978-0590353403", 25, 15.99};
```

Sales_data should have no in-class initializers if we want to initialize the data members of an aggregate class by providing a braced list of member initializers:  

FIXED:  
```cpp  
struct Sales_data {  
    std::string bookNo;  
    unsigned units_sold;  
    double revenue;  
};  
```

## [Exercise 7.53](ex7_53.h)

## Exercise 7.54
>Should the members of Debug that begin with set_ be declared as constexpr? If not, why not?

In C++11, constexpr member functions are implicitly const, so the "set_xx" functions, which will modify data members, cannot be declared as constexpr. In C++14, this property no longer holds, so constexpr is suitable.

## Exercise 7.55
>Is the Data class from § 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.

No, cause data member of it are nor all literal type. `std::string` is not a literal type, and it can be verified by following codes:  

```cpp  
#include <string>  
#include <iostream>  
#include <type_traits>  

struct Data {  
    int ival;  
    std::string s;  
};  

int main()  
{  
    // Bool value will be printed in TRUE or FALSE rather than 
    // default 1 or 0 after std::boolalpha is used.
    std::cout << std::boolalpha; 
    std::cout << std::is_literal_type<Data>::value << std::endl;  
    // output: false  
}  
```

## Exercise 7.56
>What is a static class member? What are the advantages of static members? How do they differ from ordinary members?

>What is a static class member?

A class member that is **associated with the class**, rather than with individual objects of the class type.

>What are the advantages of static members?

each object can no need to store a common data. And if the data is changed, each object can use the new value.

>How do they differ from ordinary members?

- a static data member can have **incomplete type**.
- we can use a static member **as a default argument**.

## [Exercise 7.57](ex7_57.h)

## Exercise 7.58
Which, if any, of the following static data member declarations and definitions are errors? Explain why. 
```cpp
// example.h 
class Example { 
public: 
    static double rate = 6.5; 
    static const int vecSize = 20; 
    static vector<double> vec(vecSize); 
}; 
// example.C 
#include "example.h" 
double Example::rate; 
vector<double> Example::vec;
```

```cpp
static double rate = 6.5;
                ^
            rate should be a constant expression.

static vector<double> vec(vecSize);
                            ^
            we may not specify an in-class initializer inside parentheses.
```

Fixed:

```cpp
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```
