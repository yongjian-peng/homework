#include <bits/stdc++.h>
using namespace std;

class Calculate {
    // 计算器
    public:
        int calculat(string s) {
            // 看到 3 + 2 还不知道要不要算 如果是 3 + 2 * 2 这样的式子 不应该算 应该先算 2 * 2 再算 3 + 4
            // 如果 3 + 2 - 2 这样的式子 应该先算 3 + 2 再算 5 - 2
            // 乘除 有 2 级别 加减有一级别 先算乘除 再算 加减
            // 上一个级别 谁高谁低 如果上一个级别高就说明上一个可以先算
            // 中缀先转后缀 转换 然后再使用后缀调用之前的后缀计算程序
            // 一个符号只需要跟它上一个符号级别比对， 使用栈来存 运算符
            // 如果比完了，发现栈顶级别比较高 它就可以算了，可以出栈，去做运算，或者说转后缀表达式
            // 如果说栈顶这个级别比较低 那算不了，可以把我的新符号入栈，我的压在上面 栈是先进后出的 级别高的先出 先算
            s += " "; // 如果像3+2*2情况 以数字结尾 这个数字还累积在 number 里面 还没有放到 tokens 里面
            vector<string> tokens; // 数字容器
            string number = "";
            bool needsZero = true;
            for (char ch : s) {
                if (ch >= '0' && ch <= '9') {
                    number += ch;
                    needsZero = false;
                    continue;
                } else {
                    if (!number.empty()) {
                        // 后缀转中缀 数字
                        tokens.push_back(number);
                        number = "";
                    }
                }

                if (ch == ' ')
                    continue;// 空格不要
                
                if (ch == '(') {
                    ops.push(ch);
                    needsZero = true;
                    continue;
                }
                if (ch == ')') {
                    while(ops.top() != '(') { // 如果没有遇到 左括号之前 把操作的对象都压入到 tokens 里面去
                        tokens.push_back(string(1, ops.top()));
                        ops.pop();
                    }
                    // 最终把 左括号 pop 掉 所以左括号都不用放入到 我们的 tokens 里面去
                    ops.pop();
                    needsZero = false;
                    continue;
                }
                if ((ch == '+' || ch == '-') && needsZero) {
                    tokens.push_back("0");
                }
                int currRank = getRank(ch);
                while (!ops.empty() && getRank(ops.top()) >= currRank) { // 栈顶级别比我高 栈顶先计算 或者 等号大于或等于的级别一样
                    // 栈顶出栈 参与运算
                    // 除非说 栈顶级别比我低 我就入栈 把你压住 之后 我后进先出 我先算
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(ch); // 当前符号入栈
                needsZero = true;
            }
            // 把栈顶取空 只要栈顶不空 就让栈顶取出运算 同时去 pop
            while (!ops.empty()) {
                tokens.push_back(string(1, ops.top()));
                ops.pop();
            }

            // 最后得到 tokens 后缀表达式 计算
            return evalRPN(tokens);
        }
    // 3 + 2 * 2
    // 运算符栈 + *
    // 后缀表达式： 3  2 2  * + （运算符出栈计算）
    private:
        stack<char> ops;
        stack<long long> s;

        int getRank(char ch) {
            if (ch == '*' || ch == '/')
                return 2;
            if (ch == '+' || ch == '-')
                return 1;
            return 0;
        }
        long long evalRPN(vector<string>& tokens) {
            // 遇到操作符 最近的两个结果计算 最近相关性 最近这两个结果应该从栈里面取 从栈顶取两个来运算
            // 栈里面放的是数字 计算是结果 算出来的结果再放入到栈里面去
            // 遇到数字 入栈
            for (string& token : tokens) {
                if (token == "+" || token == "-" || token == "*" || token == "/") {
                    long long y = s.top();
                    s.pop();
                    long long x = s.top();
                    s.pop();
                    long long z = calc(x, y, token);
                    s.push(z);
                } else {
                    s.push(atoi(token.c_str())); // 字符串转整型
                }
            }
            return s.top();
        }
        int calc(long long x, long long y, string& op) {
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