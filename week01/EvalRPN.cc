#include <bits/stdc++.h>

using namespace std;

class EvalRPN
{
    // 逆波兰表达式
    public:
        long long evalRPN(vector<string>& tokens) {
            // 遇到操作符 最近的两个结果计算 最近相关性最近这两个结果应该从栈里面取 从栈顶取两个来做运算
            // 栈里面放的是数字 是结果 算出来的结果再放回栈里面去
            // 遇到数字 入栈
            for (string& token:tokens) {
                if (token == "+" || token == "-" || token == "*" || token == "/") {
                    long long y = s.top();
                    s.pop();
                    long long x = s.top();
                    s.pop();
                    long long z = calc(x, y, token);
                    s.push(z);
                } else {
                    s.push(atoi(token.c_str())); // 字符串转整数
                }
            }
            return s.top();
        }

    private:
        stack<long long> s;
        int calc(long long x, long long y, string &op)
        {
            if (op == "+")
                return x + y;
            if (op == "-")
                return x - y;
            if (op == "*")
                return x * y;
            if (op == "/")
                return x / y;

            return 0;
        }
};