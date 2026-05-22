#include <iostream>

template <typename T, size_t size>
T* begin(T (&arr)[size]) {
    return arr;
}

template <typename T, size_t size>
T* end(T (&arr)[size]) {
    return arr + size;
}

int main() {
    int arr[] = {2, 4, 5, 8};
    std::cout << *(begin(arr)) << std::endl;
    std::cout << *(end(arr) - 1) << std::endl;
    return 0;
}