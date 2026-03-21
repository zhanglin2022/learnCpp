## Exercise 14.1
>In what ways does an overloaded operator differ from a built-in opera-tor? In what ways are overloaded operators the same as the built-in operators?

**Differ**
1. We can call an overloaded operator function directly.

2. The overloaded versions of certain operators (specifically logical AND, logical OR, and comma) do not preserve order of evaluation and/or short-circuit evaluation, so it is usually a bad idea to overload them. (Note: Operand-evaluation guarantees consist of order of evaluation and short-circuit evaluation).
> A few operators guarantee the order in which operands are evaluated. Because using an overloaded operator is really a function call, these guarantees do not apply to overloaded operators. In particular, the operand-evaluation guarantees of the logical AND, logical OR, and comma operators are not preserved. 
Moreover, overloaded versions of && or || operators do not preserve short-circuit evaluation properties of the built-in operators. Both operands are always evaluated.

3. An overloaded operator function must either be a member of a class or have at least one parameter of class type.

**Same**
- An overloaded operator has the same precedence and associativity as the corresponding built-in operator.

## Exercise 14.2

[hpp](ex14_02.h) | [cpp](ex14_02.cpp) | [Test](ex14_02_TEST.cpp)

## Exercise 14.3
>Both string and vector define an overloaded == that can be used to
compare objects of those types. Assuming svec1 and svec2 are vectors that hold strings, identify which version of == is applied in each of the following expressions:
```cpp
(a) "cobble" == "stone"    (b) svec1[0] == svec2[0]
(c) svec1 == svec2         (d) "svec1[0] == "stone"
```

(a) neither (b) `string` (c) `vector` (d) `string`

**Reference**
- [Why does the following not invoke the overloaded operator== (const String &, const String &)? “cobble” == “stone”](http://stackoverflow.com/questions/2690737/why-does-the-following-not-invoke-the-overloaded-operator-const-string-con)


## Exercise 14.4
>Explain how to decide whether the following should be class members:
```
(a) %
(b) %=
(c) ++
(d) ->
(e) <<
(f) &&
(g) ==
(h) ()
```

(a) symmetric operator. Hence, non-member
(b) changing state of objects. Hence, member
(c) changing state of objects. Hence, member
(d) = () [] -> must be member
(e) non-member
(f) symetric , non-member
(g) symetric , non-member
(h) = () [] -> must be member

## Exercise 14.5
>In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the following classes. 
Decide what, if any, overloaded operators your class should provide.
```cpp
(a) Book      (b) Date      (c) Employee
(d) Vehicle   (e) Object    (f) Tree
```
Such as `Book` class.

[hpp](ex14_05.h) | [cpp](ex14_05.cpp) | [Test](ex14_05_TEST.cpp)

## Exercise 14.6
>Define an output operator for your Sales_data class.

see [Exercise 14.2](#exercise-142)

## Exercise 14.7

[hpp](ex14_07.h) | [cpp](ex14_07.cpp) | [Test](ex14_07_TEST.cpp)

## Exercise 14.8
>Define an output operator for the class you chose in exercise 7.40 from § 7.5.1 (p. 291).

see [Exercise 14.5](#exercise-145)

## Exercise 14.9
>Define an input operator for your Sales_data class.

see [Exercise 14.2](#exercise-142)

## Exercise 14.10
>Describe the behavior of the Sales_data input operator if given the following input:
```
(a) 0-201-99999-9 10 24.95
(b) 10 24.95 0-210-99999-9
```
(a) correct format.
(b) illegal input. But the `.95` will be converted into a float parsed as `price`. As a result, the data inside will be wrong. Morever, the revenue will be 24 * 0.95 = 22.8.
Output: `10 24 22.8 0.95`

check [Test](ex14_02_TEST.cpp)

## Exercise 14.11: 
>What, if anything, is wrong with the following Sales_data input operator? What would happen if we gave this operator the data in the previous exercise?
```cpp
istream& operator>>(istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
```
It doesn't check the state of istream& in. Nothing Happened.

## Exercise 14.12
>Define an input operator for the class you used in exercise 7.40 from § 7.5.1 (p. 291). Be sure the operator handles input errors.

see [Exercise 14.5](#exercise-145 )

## Exercise 14.13
>Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think Sales_data ought to support? Define any you think the class should include.

Substraction, in order to be able to revert a previously addition.
[hpp](ex14_13.h) | [cpp](ex14_13.cpp) | [Test](ex14_13_TEST.cpp)

## Exercise 14.14
>Why do you think it is more efficient to define operator+ to call operator+= rather than the other way around?

`operator+=` would use an unnecessary temporary object if it were implemented using `operator+`, as you can see in the first line of the operator+ example.

`operator+=` should directly modify the left operand and should not create temporary objects. `operator+` should return a new object, so it is reasonable for it to create a temporary object and reuse the addition logic of operator+=.

```cpp
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;  
    sum += rhs;             
    return sum;
}
```

## Exercise 14.15
>Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not.

[hpp](ex14_15.h) | [hpp](ex14_15.cpp) | [Test](ex14_15_TEST.cpp)

## Exercise 14.16
>Define equality and inequality operators for your StrBlob (§ 12.1.1, p. 456), StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p. 526), and String (§ 13.5, p. 531) classes.

class `StrBlob` & `StrBlobPtr` : [hpp](ex14_16_StrBlob.h) | [cpp](ex14_16_StrBlob.cpp) | [Test](ex14_16_StrBlob_TEST.cpp)

class `StrVec` : [hpp](ex14_16_StrVec.h) | [cpp](ex14_16_StrVec.cpp) | [Test](ex14_16_StrVec_TEST.cpp)

class `String`: [hpp](ex14_16_String.h) | [cpp](ex14_16_String.cpp) | [Test](ex14_16_String_TEST.cpp)

## Exercise 14.17
>Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the equality operators? If so, implement them. If not, explain why not.

see [Exercise 14.15](#exercise-1415)

## Exercise 14.18
>Define relational operators for your StrBlob, StrBlobPtr, StrVec, and String classes.

class `StrBlob` & `StrBlobPtr` : [hpp](ex14_18_StrBlob.h) | [cpp](ex14_18_StrBlob.cpp) | [Test](ex14_18_StrBlob_TEST.cpp)
class `StrVec` : [hpp](ex14_18_StrVec.h) | [cpp](ex14_18_StrVec.cpp) | [Test](ex14_18_StrVec_TEST.cpp)
class `String` : [hpp](ex14_18_String.h) | [cpp](ex14_18_String.cpp) | [Test](ex14_18_String_TEST.cpp)

## Exercise 14.19
>Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the relational operators? If so, implement them. If not, explain why not.

see [Exercise 14.15](#exercise-1415)

## Exercise 14.20
> Define the addition and compound-assignment operators for your Sales_data class.

see [Exercise 14.2](#exercise-142)

##Exercise 14.21
>Write the Sales_data operators so that + does the actual addition and += calls +. Discuss the disadvantages of this approach compared to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p. 564).

```cpp
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    Sales_data old_data;
    *this = old_data + rhs;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}
```

**Disadvantages**: Both `+` and `+=`, uses an temporary object of `Sales_data`. But it is no need for that.

## Exercise 14.22
>Define a version of the assignment operator that can assign a string representing an ISBN to a Sales_data.

[hpp](ex14_22.h) | [cpp](ex14_22.cpp) | [Test](ex14_22_TEST.cpp)

## Exercise 14.23
>Define an initializer_list assignment operator for your version of the StrVec class.

[hpp](ex14_23.h) | [cpp](ex14_23.cpp) | [Test](ex14_23_TEST.cpp)

## Exercise 14.24
>Decide whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.

No, my `Book` class does not need custom copy-assignment and move-assignment operators. It contains only built-in types (unsigned) and standard library types (std::string), all of which already have correct copy and move semantics. 

see [Exercise 14.15](#exercise-1415)

## Exercise 14.25
>Implement any other assignment operators your class should define. Explain which types should be used as operands and why.

[hpp](ex14_25.h) | [cpp](ex14_25.cpp) | [Test](ex14_25_TEST.cpp)

The right oprand is const unsigned, because it should not be changed and is a number.

```cpp
Book& Book::operator=(const unsigned isbn) {
    *this = Book(isbn);
    return *this;
}
```

## Exercise 14.26
>Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.

class `StrVec` : [hpp](ex14_26_StrVec.h) | [cpp](ex14_26_StrVec.cpp) | [Test](ex14_26_StrVec_TEST.cpp)
class `String` : [hpp](ex14_26_String.h) | [cpp](ex14_26_String.cpp) | [Test](ex14_26_String_TEST.cpp)
class `StrBlob` and `StrBlobPtr` : [hpp](ex14_26_StrBlob.h) | [cpp](ex14_26_StrBlob.cpp) | [Test](ex14_26_StrBlob_TEST.cpp)

## Exercise 14.27
>Add increment and decrement operators to your StrBlobPtr class.

[hpp](ex14_27_28_StrBlob.h) | [cpp](ex14_27_28_StrBlob.cpp) | [Test](ex14_27_28_StrBlob_TEST.cpp)

## Exercise 14.28 
>Define addition and subtraction for StrBlobPtr so that these operators implement pointer arithmetic (§ 3.5.3, p. 119).

see [Exercise 14.27](#exercise-1427)

## Exercise 14.29
>We did not define a const version of the increment and decrement operators. Why not?

Because `++` and `--` change the state of the object. Hence, it's meaningless to do so.

## Exercise 14.30
>Add dereference and arrow operators to your StrBlobPtr class and to the ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6 (p. 476). 
Note that the operators in constStrBlobPtr must return const references because the data member in constStrBlobPtr points to a const vector.

[hpp](ex14_30_StrBlob.h) | [cpp](ex14_30_StrBlob.cpp) | [Test](ex14_30_StrBlob_TEST.cpp)

## Exercise 14.31
>Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?

Applying the Rule of 3/5:
There is no dynamic allocation to deal with, so the synthesized destructor is enough. Moreover, no unique is needed(weak_ptr rather than unique_ptr). Hence, the synthesized ones can handle all the corresponding operations.

## Exercise 14.32
>Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for that class.

[hpp](ex14_32.h) | [cpp](ex14_32.cpp)

## Exercise 14.33
>How many operands may an overloaded function-call operator take?

An overloaded operator function has the same number of parameters as the operator has operands. Hence the maximum value should be around 256.
([question on SO](http://stackoverflow.com/questions/21211889/how-many-operands-may-an-overloaded-function-call-operator-take))

## Exercise 14.34
>Define a function-object class to perform an if-then-else operation: 
The call operator for this class should take three parameters. 
It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter.

```cpp
struct Test {
    int operator()(bool b, int iA, int iB) const {
        return b ? iA : iB;
    }
}
```

## [Exercise 14.35](ex14_35.cpp)
>Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read. If the read fails, return the empty string.

## [Exercise 14.36](ex14_36.cpp)
>Use the class from the previous exercise to read the standard input, storing each line as an element in a vector.

## [Exercise 14.37](ex14_37.cpp)
>Write a class that tests whether two values are equal. Use that object and the library algorithms to write a program to replace all instances of a given value in a sequence.

## [Exercise 14.38](ex14_38_39.cpp)
>Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.

## Exercise 14.39
>Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.

see [Exercise 14.38](#exercise-1438)

## [Exercise 14.40](ex14_40.cpp)
>Rewrite the biggies function from § 10.3.2 (p. 391) to use function-object classes in place of lambdas.

## Exercise 14.41
>Why do you suppose the new standard added lambdas? Explain when you would use a lambda and when you would write a class instead.

Lambda is quite handy to use. Lambda can be used when the functor is not used frequently nor complicated, whereas functor is supposed to call more times than lambda or quite complicated to implement as a lambda.

## [Exercise 14.42](ex14_42.cpp)
>Using library function objects and adaptors, define an expression to
(a) Count the number of values that are greater than 1024
(b) Find the first string that is not equal to pooh
(c) Multiply all values by 2

## [Exercise 14.43](ex14_43.cpp)
>Using library function objects, determine whether a given int value is divisible by any element in a container of ints.

## [Exercise 14.44](ex14_44.cpp)
>Write your own version of a simple desk calculator that can handle binary operations.

## Exercise 14.45
>Write conversion operators to convert a Sales_data to string and to double. What values do you think these operators should return?

[hpp](ex14_45.h) | [cpp](ex14_45.cpp) | [Test](ex14_45_TEST.cpp)

## Exercise 14.46
>Explain whether defining these Sales_data conversion operators is a good idea and whether they should be explicit.

It's a bad idea to do so, because these conversion is misleading.`explicit` should be added to prevent implicit conversion.

## Exercise 14.47
>Explain the difference between these two conversion operators:
```cpp
struct Integral {
    operator const int(); // meaningless, it will be ignored by compiler
    operator int() const; // promising that this operator will not change the state of the obj
};
```

## Exercise 14.48
>Determine whether the class you used in exercise 7.40 from § 7.5.1(p. 291) should have a conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain why not.

No, it is unnecessary to add a conversion to bool for class `Book`. Because a `Book` object does not have a natural Boolean meaning.

Its state is defined by multiple attributes (e.g., ISBN, title, author, stock count) that do not collectively imply a true/false value. If you need to check a specific condition (like whether the book is in stock), it is better to provide a named member function, such as `bool in_stock() const`, rather than relying on an implicit conversion.

Exercise 14.49
>Regardless of whether it is a good idea to do so, define a conversion to bool for the class from the previous exercise.

[hpp](ex14_49.h) | [cpp](ex14_49.cpp) | [Test](ex14_49_TEST.cpp)

## Exercise 14.50
>Show the possible class-type conversion sequences for the initializations of ex1 and ex2. Explain whether the initializations are legal or not.
```cpp
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;    // error ambiguous: double or float?
float ex2 = ldObj;  // legal
```

## Exercise 14.51
>Show the conversion sequences (if any) needed to call each version of calc and explain why the best viable function is selected.
```cpp
void calc(int);
void calc(LongDouble);
double dval;
calc(dval); //which calc?
```
best viable function: `void calc(int)`. because class-type conversion is the lowest ranked.

review the order:

1. exact match
2. const conversion
3. promotion
4. arithmetic or pointer conversion
5. class-type conversion

## Exercise 14.52
>Which operator+, if any, is selected for each of the addition expressions? List the candidate functions, the viable functions, and the type conversions on the arguments for each viable function:
```cpp
struct LongDouble {
    //member operator+ for illustration purposes; + is usually a nonmember
    LongDouble operator+(const SmallInt&);
    //other members as in § 14.9.2 (p. 587)
};
LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;
ld = si + ld;
ld = ld + si;
```
`ld = si + ld;` is ambiguous. Multiple built‑in versions of operator+ are viable(e.g., (int, double) vs. (double, int)), and their conversion sequences are equally good, so the compiler cannot select a single best match.

`ld = ld + si;` calls the member version `LongDouble::operator+(const SmallInt&)`. This version provides an exact match for the second argument (si), which is superior to the nonmember version (which requires a user‑defined conversion for si) and to the built‑in versions (which require conversions for both operands).

## Exercise 14.53
>Given the definition of SmallInt on page 588, determine whether the following addition expression is legal. If so, what addition operator is used? If not, how might you change the code to make it legal?
```cpp
SmallInt s1;
double d = s1 + 3.14;
```
ambiguous.

**Fixed**:
```cpp
SmallInt s1;
double d = s1 + SmallInt(3.14);
```
