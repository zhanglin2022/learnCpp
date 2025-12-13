## Exercise 11.1
>Describe the differences between a map and a vector.

`map` is an associative container whereas `vector` is a sequence container

## Exercise 11.2
>Give an example of when each of list, vector, deque, map, and set might be most useful.

- list : anytime when a doubly-linked list is required.
- vector : anytime when a dynamic array is required.
- deque : [An answer from SO](http://stackoverflow.com/questions/3880254/why-do-we-need-deque-data-structures-in-the-real-world).
    
    1.A nice application of the deque is storing a web browser's history. Recently visited URLs are added to the front of the deque, and the URL at the back of the deque is removed after some specified number of insertions at the front.
    2.Another common application of the deque is storing a software application's list of undo operations.
    3.One example where a deque can be used is the A-Steal job scheduling algorithm.[5] This algorithm implements task scheduling for several processors. A separate deque with threads to be executed is maintained for each processor. To execute the next thread, the processor gets the first element from the deque (using the "remove first element" deque operation). If the current thread forks, it is put back to the front of the deque ("insert element at front") and a new thread is executed. When one of the processors finishes execution of its own threads (i.e. its deque is empty), it can "steal" a thread from another processor: it gets the last element from the deque of another processor ("remove last element") and executes it. - Courtesy Wikipedia
- map : dictionary.
- set : when to keep elements sorted and unique.

## [Exercise 11.3](ex11_03.cpp)
## [Exercise 11.4](ex11_04.cpp)
## Exercise 11.5
>Explain the difference between a map and a set. When might you use one or the other?

The difference is that `set`s contain only the key, while in `map` there is an associated value. Choosing one over the other depends mainly on what the task at hand is. If you want to build a dictionary of all the words that appear in a text, you could use a `set`, but if you also want to count how many times each word appeared then you would need an map. If you don't need to associate that count, it does not make sense to have the `int` that is unnecessary.

## Exercise 11.6
>Explain the difference between a set and a list. When might you use one or the other?

**List**
1. Searching (linear time).
2. Inserting, deleting, moving (takes constant time).
3. Elements may be ordered.
4. Elements may be sorted.
5. Elements may be duplicate.

**Set**
1. Searching (logarithmic in size).
2. Insert and delete (logarithimic in general).
3. Elements are un-ordered.
4. Elements are always sorted from lower to higher.
5. Elements are unique.

## [Exercise 11.7](ex11_07.cpp)
## [Exercise 11.8](ex11_08.cpp)

```
1.No matter what elements you add or remove (unless you add
a duplicate, which is not allowed in a set), it will always
be ordered.

2.A vector has exactly and only the ordering you explicitly
give it. Items in a vector are where you put them. If you put
them in out of order, then they're out of order; you now need
to sort the container to put them back in order.

3.However, if you are constantly inserting and removing items
from the container, vector will run into many issues.

4.The time it takes to insert an item into a vector is proportional 
to the number of items already in the vector. The time it takes 
to insert an item into a set is proportional to the log of the 
number of items. If the number of items is large, that's a huge
difference. Log(100, 000) is 17; that's a major speed improvement. 
The same goes for removal.
```

## Exercise 11.9
>Define a map that associates words with a list of line numbers on which the word might occur.

```cpp
using std::string; using std::list
std::map<string, list<size_t>> words;
```

## [Exercise 11.10](ex11_10.cpp)
>Could we define a map from vector<int>::iterator to int? What about from list<int>::iterator to int? In each case, if not, why not?

```
we can define a map from vector<int>::iterator to int
we can not define a map from list<int>::iterator to int. 
error: no match for ‘operator<’ in '__x < __y'
```

## [Exercise 11.11](ex11_11.cpp)
## [Exercise 11.12 and 11.13](ex11_12_13.cpp)
## [Exercise 11.14](ex11_14.cpp)

## Exercise 11.15
>What are the mapped_type, key_type, and value_type of a map from int to vector< int >?

- mapped_type : vector< int >
- key_type : int
- value_type : std::pair< const int, vector<int> >

## Exercise 11.16
>Using a map iterator write an expression that assigns a value to an element.

```cpp
std::map<int, std::string> map;
map[25] = "Alan";
std::map<int, std::string>::iterator it = map.begin();
it->second = "Wang";
```

## Exercise 11.17
>Assuming c is a multiset of strings and v is a vector
of strings, explain the following calls. Indicate whether each call is legal:

```cpp
copy(v.begin(), v.end(), inserter(c, c.end())); // legal
copy(v.begin(), v.end(), back_inserter(c)); // illegal, no `push_back` in `set`.
copy(c.begin(), c.end(), inserter(v, v.end())); // legal.
copy(c.begin(), c.end(), back_inserter(v)); // legal.
```
## Exercise 11.18
>Write the type of map_it from the loop on page 430 without using auto or decltype.

```cpp
std::map<std::string, size_t>::const_iterator;
```
## Exercise 11.19
>Define a variable that you initialize by calling begin() on the multiset named bookstore from 11.2.2 (p. 425).
Write the variable’s type without using auto or decltype.

```cpp
using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
std::multiset<Sales_data, compareType> bookstore(compareIsbn);
std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
```

## [Exercise 11.20](ex11_20.cpp)
>Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead of subscripting. Which program do you think is easier to write and read? Explain your reasoning.

I think the subscript version is easier, it's short and clean.

## Exercise 11.21
>Assuming word_count is a map from string to size_t and word is a string, explain the following loop:

```cpp
while (cin >> word)
    ++word_count.insert({ word, 0 }).first->second;
```
This code can be explained like this pseudocode:
```python
while reading into word
    if word_count has key word:
        word_count[word] += 1
    else:
        word_count[word] = 0
        word_count[word] += 1
```

## Exercise 11.22
>Given a `map<string, vector<int>>`, write the types used as an argument and as the return value for the version of insert that inserts one element.

```cpp
std::pair<std::string, std::vector<int>>    // argument
std::pair<std::map<std::string, std::vector<int>>::iterator, bool> // return
```

## [Exercise 11.23](ex11_23.cpp)
## [Exercise 11.24](ex11_24.cpp)
>What does the following program do? 

```cpp
map<int, int> m; 
m[0] = 1;
```
add a key-value pair`{0, 1}` into the map.

## [Exercise 11.25](ex11_25.cpp)
>Contrast the following program with the one in the previous exercise 
```cpp
vector<int> v; 
v[0] = 1;
```
Undefined Behavior, since it's trying to dereference an item out of range

## [Exercise 11.26](ex11_26.cpp)
## [Exercise 11.26](ex11_26.cpp)
## Exercise 11.27
>What kinds of problems would you use count to solve? When might you use find instead?

`count`: deal with multimap or multiset.
`find`: deal with the assicaitve contain which has a unique key.

## Exercise 11.28
>Define and initialize a variable to hold the result of calling find on a map from string to vector of int.

```cpp
std::map<std::string, std::vector<int>> m{{"sun", {1}}, {"moon", {2}}};
auto iter = m.find("sun");
```

## Exercise 11.29
>What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?

lower_bound and upper_bound will return equal iterators; both will refer to the point at which the key can be inserted without disrupting the order.

If no matching element is found, then both the first and second iterators refer to the position where this key can be inserted.

## Exercise 11.30
>Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.

pos: a pair
pos.first: the iterator refering to the first element with the matching key
pos.first->second: the value part of the kv of the element with the matching key

## [Exercise 11.31](ex11_31.cpp)
## [Exercise 11.32](ex11_32.cpp)
## [Exercise 11.33](ex11_33.cpp)

## Exercise 11.34
>What would happen if we used the subscript operator instead of find in the transform function?

use the subscript operator instead of find in the transform function:
```cpp
const string& transform(const string &s, const map<string, string> &m)
{
    return m[s];
}
```
The above code won't compile because the subscript operator might insert an element (when the element with the key s is not found), and we may use subscript only on a map that is not const.

## Exercise 11.35
>In buildMap, what effect, if any, would there be from rewriting `trans_map[key] = value.substr(1);` as `trans_map.insert({ key, value.substr(1) })`?

- use subscript operator: if a word does appear multiple times, our loops will put the **last** corresponding phrase into trans_map
- use `insert`: if a word does appear multiple times, our loops will put the **first** corresponding phrase into trans_map

## Exercise 11.36
>Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible.
What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.

If so, a key-value pair will be `{key, " "}`(" ".size() !> 1), which cannot be added into the map. As a result, the key would not be replaced with any string.

## Exercise 11.37
>What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?

Unordered container: 
- No need to maintain the order relationship of elements, with better average performance and usually simpler to use.

Ordered container: 
- Stable time complexity, able to traverse elements sequentially

[A summary](http://www.cs.fsu.edu/~lacher/courses/COP4531/fall13/lectures/containers2/slide04.html)
Ordered Associative Container:
- Standard Traversal encounters elements in sorted order
- Order predicate may be specified
- Default order predicate is "less than", defined using operator< for the element type
- Popular implementations: OrderedVector, BinarySearchTree
- Search operations required to have O(log n) runtime
- Insert, Remove operations should either be seldom used or have O(log n) runtime

Unordered Associative Container
- Standard Traversal encounters elements in unspecified order
- Search, Insert, Remove operations should have average-case constant runtime
- Popular implementations use hashing

## [Exercise 11.38](ex11_38.cpp)
