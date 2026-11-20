/**
 * @desp 题目描述
 * 一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须
 * 得到比身旁孩子更多的糖果。所有孩子至少要有一个糖果。求解最少需要多少个糖果。
 * 
 * @example 输入输出样例
 * 输入是一个数组，表示孩子的评分。输出是最少糖果的数量。
 * 
 * Input: [1,0,2] Output: 5
 * 在这个样例中，最少的糖果分法是 [2,1,2]。
 * 
 * @solution 题解
 * 存在比较关系的贪心策略并不一定需要排序。虽然这一道题也是运用贪心策略，但我们只需要简单的两次遍历即可：把所有孩子的糖果数初始化为 1；先从
 * 左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的糖果数加 1；再从右往左遍历一遍，如果左边孩子的评分比右边
 * 的高，且左边孩子当前的糖果数不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1。通过这两次遍历，分配的糖果就可以满足
 * 题目要求了。这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一侧的大小关系。
 * 
 * 在样例中，我们初始化糖果分配为 [1,1,1]，第一次遍历更新后的结果为 [1,1,2]，第二次遍历更新后的结果为 [2,1,2]。
 */

 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <numeric>

 int candy(std::vector<int> &ratings) {
    int n = ratings.size();
    std::vector<int> candies(n, 1);
    for (int i = 1; i != n; ++i) {
        if (ratings[i] > ratings[i-1])
            candies[i] = candies[i-1] + 1;
    }
    for (int i = n - 1; i != 0; --i) {
        if (ratings[i-1] > ratings[i])
            candies[i-1] = std::max(candies[i-1], candies[i] + 1);
    }
    return std::accumulate(candies.begin(), candies.end(), 0);
 }

 int main() {
    std::vector<int> ivec{1, 0, 2, 1, 0};
    std::cout << candy(ivec) << std::endl;
    return 0;
 }
 