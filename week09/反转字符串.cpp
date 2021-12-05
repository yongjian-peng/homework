/**
 * leetcode [344.] 反转字符串
 *
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
链接：https://leetcode-cn.com/problems/reverse-string

 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：字符串以中心为起点，起点左右往外的两个字符更换位置，即反转
        即头和尾交换，往中间移动，当头尾碰到一起，即反转
     */
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
}