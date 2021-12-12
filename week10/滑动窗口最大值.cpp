/**
 * leetcode [58.] 最后一个单词的长度
 *
输入：s = "Hello World"
输出：5

输入：s = "   fly me   to   the moon  "
输出：4

链接：https://leetcode-cn.com/problems/length-of-last-word/
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