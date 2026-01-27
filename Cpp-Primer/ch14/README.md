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

# Exercise 14.3
>Both string and vector define an overloaded == that can be used to
compare objects of those types. Assuming svec1 and svec2 are vectors that hold strings, identify which version of == is applied in each of the following expressions:
```cpp
(a) "cobble" == "stone"    (b) svec1[0] == svec2[0]
(c) svec1 == svec2         (d) "svec1[0] == "stone"
```


(a) neither (b) `string` (c) `vector` (d) `string`

