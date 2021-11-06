/**
 * [1011.] 在 D 天内送达包裹的能力
 *输入：weights = [1,2,3,4,5,6,7,8,9,10], D = 5
输出：15
解释：
船舶最低载重 15 就能够在 5 天内送达所有包裹，如下所示：
第 1 天：1, 2, 3, 4, 5
第 2 天：6, 7
第 3 天：8
第 4 天：9
第 5 天：10

请注意，货物必须按照给定的顺序装运，因此使用载重能力为 14 的船舶并将包装分成 (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) 是不允许的。
 * 链接：https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int weight : weights) {
            left = max(left, weight);
            right += weight;
        }
        while (left < right) {
            int mid = (left + right) >> 1;
            // 判断天数内运的重量
            if (validate(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool validate(vector<int>& weights, int days, int size) {
        int box = 0; // 初始化包裹重量
        int now = 1; // 初始化需要天数
        for (int weight : weights) {
            if (box + weight <= size) {
                box += weight;
            } else {
                now++;
                box = weight;
            }
        }
        return now <= days;
    }
}