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
    /* 题解：滑动窗口 + 数组模拟hash表
     */
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int resCount = p.size();
        vector<int> pFreq(26);
        for (int i = 0; i < p.size(); i++)
            pFreq[p[i] - 'a']++;
        vector<int> sFreq(26);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            sFreq[c - 'a']++; // 向窗口末尾加入1个新字符

            if (sFreq[c - 'a'] <= pFreq[c - 'a'])
                resCount--;
            if (i >= p.size()) {
                char h = s[i - p.size()]; // 上一轮窗口中最前面的字符
                sFreq[h - 'a']--;
                if (sFreq[h - 'a'] < pFreq[h - 'a'])
                    resCount++;
            }
            if (resCount == 0)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
}