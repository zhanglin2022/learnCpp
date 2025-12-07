// Exercise 6.8
//
// Write a header file named Chapter6.h that contains declarations for 
// the functions you wrote for the exercises in § 6.1 (p. 205).
//

int fact(int val);
void interactive_face();
// int abs(int val);

template <typename T>
T abs(T i) {
    return i >= 0 ? i : -1;
}