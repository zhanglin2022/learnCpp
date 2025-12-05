## [Exercise 1.1](ex1_01.cpp)

## [Exercise 1.2](ex1_02.cpp)

```
./ex1_02
echo $?

255
```

## [Exercise 1.3](ex1_03.cpp)

## [Exercise 1.4](ex1_04.cpp)

## [Exercise 1.5](ex1_05.cpp)

## Exercise 1.6

> Explain whether the following program fragment is legal.

It's illegal.

**`[Error] expected primary-expression before '<<' token`**

Fixed it: remove the spare semicolons.

```cpp
std::cout << "The sum of " << v1
          << " and " << v2
          << " is " << v1 + v2 << std::endl;
```

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

Example:

```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
  return 0;
}
```

Compiled result(g++):

```
g++ ex1_07.cpp

error: 'cannot' does not a type
```

## [Exercise 1.8](ex1_08.cpp)

> Indicate which, if any, of the following output statements are legal:

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

> After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

Compiled result(g++):
```
g++ ex1_08.cpp

warining: missing terminating " character [enaled by default]
    std::cout << /* "*/" */;
error: missing terminating " character
    std::cout << /* "*/* */;
```

Corrected? just added a quote:

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```

Output:

```sh
    /**/ */ /*
```

## [Exercise 1.9](ex1_09.cpp)

## [Exercise 1.10](ex1_10.cpp)

pre-decrement:
```cpp
int i = 10;  
std::cout << --i << " "; // The output is 9.
```

post-decrement:
```cpp
int i = 10;  
std::cout << i-- << " "; // The output is 10.
```

## [Exercise 1.11](ex1_11.cpp)

## Exercise 1.12

> What does the following for loop do? What is the final value of sum?

```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

the loop sums the numbers from -100 to 100. the final value of sum is zero. 

## Exercise 1.13

> Rewrite the exercises from 1.4.1 (p. 13) using for loops.

**Exercise 1.9**:

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;

    std::cout << "the sum is: " << sum << std::endl;

    return 0;
}
```

**Exercise 1.10**:

```cpp
#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```

**Ex1.11**:

```cpp
#include <iostream>

int main()
{
    int small = 0, big = 0;
    std::cout << "please input two integers:";
    std::cin >> small >> big;

    if (small > big) {
        int tmp = small;
        small = big;
        big = tmp;
    }

    for (int i = small; i <= big; ++i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```

## Exercise 1.14

> Compare and contrast the loops that used a `for` with those using a `while`. Are there advantages or disadvantages to using either form?

A for loop is more simple, which is more suitable for the the situation that number of loop is known. A while loop is more flexible, which is more suitable for the the situation that number of loop is unknown.  

Actually these two loops can be converted into each other.

-----

[A similar question on Stack Overflow](http://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)

## Exercise 1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

Self-training.

## [Exercise 1.16](ex1_16.cpp)

## Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

The output will be that the input value occurs n times(n is the total numbers of input). There output will be that each input value occurs 1 times.

@pzey
If all equal, the count will be printed out. If there are no duplicated values, A new line will be printed when `Enter` clicked.

## [Exercise 1.18](ex1_18.cpp)

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

```
./ex1_18
42 42 42 42 42 42 42 42 42 42 42 42

42 occurs 11 times

./ex1_18
1 2 3 4 5 6 7 8 

1 occurs 1 times
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
5 occurs 1 times
6 occurs 1 times
7 occurs 1 times
8 occurs 1 times
```

## Exercise 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

Same as [ex1_11.cpp](ex1_11.cpp)

## [Exercise 1.20](ex1_20.cpp)

> <http://www.informit.com/title/032174113> contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

Test it using the `data`/`book.txt`:

```sh
ex1_20 </data/book.txt >result.txt
cat result.txt
```

## [Exercise 1.21](ex1_21.cpp)

> Write a program that reads two `Sales_item` objects that have the same ISBN and produces their sum.

The program should check whether the objects have the same ISBN.(check 1.5.2)

## [Exercise 1.22](ex1_22.cpp)

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

Tip: this program will appear in the section 1.6.

```sh
g++ ../ex1_22.cpp -o ex1_22
ex1_22 </data/book.txt >result.txt
cat result.txt
```

## [Exercise 1.23](ex1_23.cpp)

> Write a program that reads several transactions and counts how many transactions occur for each ISBN.

Tip: please review the `1.4.4`.

## Exercise 1.24

> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

`data`/`book.txt` may be used as the records.

```
g++ ../ex1_23.cpp -o ex1_23
ex1_23 </data/book.txt > result.txt
cat result.txt

output:
0-201-78345-X 3 60 20 occurs 2 transactions
0-201-78346-X 1 100 100 occurs 3 transactions
```

## Exercise 1.25

> Using the `Sales_item.h` header from the Web site, compile and execute the bookstore program presented in this section.

```
ex1_22 </data/book.txt > result.txt
cat result.txt
```
