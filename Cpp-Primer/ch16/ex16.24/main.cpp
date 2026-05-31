#include <iostream>
#include <vector>

#include "Blob.h"

int main() {
    std::vector<int> ivec{0, 2, 4, 6};
    Blob<int> b(ivec.begin(), ivec.end());
    
    return 0;
}