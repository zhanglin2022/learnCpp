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

## [Exercise 14.2]()
