/**
 * leetcode [771.] 宝石与石头
 *
 给你一个字符串 jewels 代表石头中宝石的类型，另有一个字符串 stones 代表你拥有的石头。 stones 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

字母区分大小写，因此 "a" 和 "A" 是不同类型的石头。

输入：jewels = "aA", stones = "aAAbbbb"
输出：3

输入：jewels = "z", stones = "ZZ"
输出：0

链接：https://leetcode-cn.com/problems/jewels-and-stones
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解： 把宝石使用set 压入到set数组中，单个循环石头，是否在 set 中 如果存在 则答案 + 1
     */
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for (auto &c : jewels) {
            st.insert(c);
        }
        int ans = 0;
        for (auto &c : stones) {
            if (st.find(c) != st.end())
                ans++;
        }
        return ans;
    }
}