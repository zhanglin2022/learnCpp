#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val)
{
    auto mid = [&]{ return v.begin() + v.size() / 2; };
    for (auto iter = v.begin(); iter != mid(); ++iter)
        if (*iter == some_val)
            ++(iter = v.insert(iter, 2 * some_val));
}

int main()
{
    std::vector<int> v{ 1, 9, 1, 9, 9, 9, 1, 1 };
    double_and_insert(v, 1);
    for (auto i : v) 
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
