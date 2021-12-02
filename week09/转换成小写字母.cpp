/**
 * leetcode [709.] 转换成小写字母
 *
输入：s = "Hello"
输出："hello"

链接：https://leetcode-cn.com/problems/to-lower-case/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：大写字母开始和结尾 范围 65 ～ 90 加 32 就是对应的小写
     */
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 65 && s[i] <= 90) {
                s[i] += 32;
            }
        }
        return s;
    }
}