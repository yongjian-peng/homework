/**
 * [70.] 爬楼梯
 *输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

* 链接：https://leetcode-cn.com/problems/climbing-stairs/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：动态规划

    因为 1阶台阶 = 1步 一种方法
        2阶台阶 = 1步 + 1步    2步 两种方法
        3阶台阶 = 1步 + 1步 + 1步    1步 + 2步    2步 + 1步 3种方法 
        记录之前走一步数所需要的方法 和 走两步所需要的方法    
     n 台阶 = n - 1 台阶 + n - 2 台阶 方法的总和
     */
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int a = 1; // 初始化 1阶 方法
        int b = 2; // 初始化 2阶 方法
        for (int i = 3; i <= n; i++) {
            int t = b;
            b = a + b;
            a = t;
        }
        return b;
    }
}