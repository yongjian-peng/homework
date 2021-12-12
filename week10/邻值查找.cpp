/**
 * acwing [136.] 邻值查找
 *
给定一个长度为 n 的序列 A，A 中的数各不相同。

对于 A 中的每一个数 Ai，求：

min1≤j<i|Ai−Aj|
以及令上式取到最小值的 j（记为 Pi）。若最小值点不唯一，则选择使 Aj 较小的那个。

输入格式
第一行输入整数 n，代表序列长度。

第二行输入 n 个整数A1…An,代表序列的具体数值，数值之间用空格隔开。

输出格式
输出共 n−1 行，每行输出两个整数，数值之间用空格隔开。

分别表示当 i 取 2∼n 时，对应的 min1≤j<i|Ai−Aj| 和 Pi 的值。

输入样例：
3
1 5 3
输出样例：
4 1
2 1

链接：https://www.acwing.com/problem/content/138/

 */
#include<iostream>
#include<set>
#include <bits/stdc++.h>


using namespace std;

const int N = 1e5 + 10;
int n, a;
set<pair<int, int>> s; // 值 下标
int main() {
    cin >> n >> a;
    s.insert({a, 1});
    for (int i = 2; i <= n; i++) {
        cin >> a;
        s.insert({a, i});
        set<pair<int, int> >::iterator it = s.find({a, i});
        pair<int, int> ans;
        ans.first = 0x3f3f3f3f;

        if (++it != s.end()) {
            ans = {(*it).first - a, (*it).second};
        }
        it--;
        // 要找一个最接近的，也就是差值最小的
        if (it-- != s.begin() && ans.first >= a - (*it).first) {
            ans = {a - (*it).first, (*it).second};
        }
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
