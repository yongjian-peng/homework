/**
 * leetcode [438.] 找到字符串中所有字母异位词
 *
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /* 题解：字符从末尾开始遍历，如果末尾是空格，则过滤掉空格，向前遍历字符遇到空格为止
        如果末尾是字符，向前遍历遇到空格为止
        结果就是 遇到空格结尾 减去 空格开始的 值
     */
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;
        while (end >= 0 && s[end] == ' ')
            end--;
        if (end < 0)
            return 0;
        int start = end;
        // 循环字符 遇到空格的位置
        while (start >= 0 && s[start] != ' ')
            start--;
        return end - start;
    }
}