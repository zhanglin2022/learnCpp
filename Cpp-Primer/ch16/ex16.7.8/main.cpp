#include <iostream>

template<typename T, size_t size>
constexpr size_t getSize(T (&arr)[size]) {
    return size;
}

int main() {
    int arr[] = {1, 3, 4, 7};
    std::cout << getSize(arr) << std::endl;
    return 0;
}
