/**
 * @desp 题目描述
 * 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个饱腹度。每个孩子只能吃一个饼干，且只有饼干的饱腹度不小于孩子的饥饿度时，
 * 这个孩子才能吃饱。求解最多有多少孩子可以吃饱。
 * 
 * @example 输入输出样例
 * 输入两个数组，分别代表孩子的饥饿度和饼干的饱腹度。输出可以吃饱的孩子的最大数量。
 * 
 * Input: [1,2], [1,2,3]
 * Output: 2
 * 
 * 在这个样例中，我们可以给两个孩子喂 [1,2]、[1,3]、[2,3] 这三种组合的任意一种。
 * 
 * @solution 题解
 * 因为饥饿度最小的孩子最容易吃饱，所以我们先考虑这个孩子。为了尽量使得剩下的饼干可以满足饥饿度更大的孩子，所以我们应该把大于等于这个孩子
 * 饥饿度的、且大小最小的饼干给这个孩子。满足了这个孩子之后，我们采取同样的策略，考虑剩下孩子里饥饿度最小的孩子，直到没有满足条件的饼干存在。
 * 
 * 简而言之，这里的贪心策略是，给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干。至于具体实现，因为我们需要获得大小关系，一个便捷的方法
 * 就是把孩子和饼干分别排序。这样我们就可以从饥饿度最小的孩子和饱腹度最小的饼干出发，计算有多少个对子可以满足条件。
 */

#include <iostream>
#include <vector>
#include <algorithm>

int findContentChildren(std::vector<int> &children, std::vector<int> &cookies) {
    std::sort(children.begin(), children.end()); // 排序默认是从小到大
    std::sort(cookies.begin(), cookies.end());
    int child_i = 0, cookie_i = 0;
    int n_children = children.size(), n_cookies = cookies.size();
    while (child_i < n_children && cookie_i < n_cookies) {
        if (children[child_i] <= cookies[cookie_i])
            ++child_i;
        ++cookie_i;
    }
    return child_i;
}

int main() {
    std::vector<int> ivec1{1, 4, 3};
    std::vector<int> ivec2{1, 3, 2, 3};
    std::cout << findContentChildren(ivec1, ivec2) << std::endl;

    return 0;
}
