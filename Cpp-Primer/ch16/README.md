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
